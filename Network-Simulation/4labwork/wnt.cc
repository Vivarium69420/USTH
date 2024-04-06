// Wireless Network Topology
//
//  Wifi 10.1.2.0
// ST1  ST2   AP
//  *    *    *
//  |    |    |   10.1.1.0
// n1   n2   n3 -------------  n4
//              Point-to-Point
#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ssid.h"
#include "ns3/yans-wifi-helper.h"
#include <ns3/flow-monitor-helper.h>
#include <ns3/ipv4-flow-classifier.h>
#include <ns3/net-device-container.h>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("WNT-A");

int
main(int argc, char* argv[])
{
    bool verbose = true;
    uint32_t nWifi = 2;
    bool tracing = true;

    CommandLine cmd(__FILE__);
    cmd.AddValue("nWifi", "Number of wifi STA devices", nWifi);
    cmd.AddValue("verbose", "Tell echo applications to log if true", verbose);
    cmd.AddValue("tracing", "Enable pcap tracing", tracing);

    cmd.Parse(argc, argv);

    // The underlying restriction of 18 is due to the grid position
    // allocator's configuration; the grid layout will exceed the
    // bounding box if more than 18 nodes are provided.
    if (nWifi > 18)
    {
        std::cout << "nWifi should be 18 or less; otherwise grid layout exceeds the bounding box"
                  << std::endl;
        return 1;
    }

    if (verbose)
    {
        LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
        LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
    }

    /*
     * Set up the point-to-point communication channel between
     * the wifi network and a simple single server node
     * */

    NodeContainer p2pNodes;
    p2pNodes.Create(2);

    PointToPointHelper pointToPoint;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

    /*
     * Wifi Network Topology
     * Two sta nodes, and one Ap node that will be the first node of the
     * point-to-point channel
     * */

    NodeContainer wifiStaNodes;
    wifiStaNodes.Create(nWifi);
    NodeContainer wifiApNode = p2pNodes.Get(1);

    // Wifi channel and the wifi physical layer
    YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
    YansWifiPhyHelper phy;
    phy.SetChannel(channel.Create());

    // Setup the Mac address
    WifiMacHelper mac;
    Ssid ssid = Ssid("ns-3-ssid");

    WifiHelper wifi;

    NetDeviceContainer staDevices;
    mac.SetType("ns3::StaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false));
    staDevices = wifi.Install(phy, mac, wifiStaNodes);

    NetDeviceContainer apDevices;
    mac.SetType("ns3::ApWifiMac", "Ssid", SsidValue(ssid));
    apDevices = wifi.Install(phy, mac, wifiApNode);

    // Net device for the Ap and server node
    NetDeviceContainer p2pDevices;
    p2pDevices = pointToPoint.Install(wifiApNode.Get(0), p2pNodes.Get(0));

    MobilityHelper mobility;

    mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                  "MinX",
                                  DoubleValue(0.0),
                                  "MinY",
                                  DoubleValue(0.0),
                                  "DeltaX",
                                  DoubleValue(5.0),
                                  "DeltaY",
                                  DoubleValue(10.0),
                                  "GridWidth",
                                  UintegerValue(3),
                                  "LayoutType",
                                  StringValue("RowFirst"));

    mobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
                              "Bounds",
                              RectangleValue(Rectangle(-50, 50, -50, 50)));
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");

    mobility.Install(wifiStaNodes);
    mobility.Install(wifiApNode);

    /* Set up the IP */
    InternetStackHelper stack;
    stack.Install(p2pNodes.Get(0));
    stack.Install(wifiApNode);
    stack.Install(wifiStaNodes);

    Ipv4AddressHelper address;

    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer p2pInterfaces;
    p2pInterfaces = address.Assign(p2pDevices);

    address.SetBase("10.1.2.0", "255.255.255.0");
    address.Assign(staDevices);
    address.Assign(apDevices);

    UdpEchoServerHelper echoServer(9);

    ApplicationContainer serverApps = echoServer.Install(p2pNodes.Get(0));
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    // Create two UdpEchoClientHelper instances for the two stations in scenario 2
    // You can comment out the second client if you want to test with only one client for scenario 1
    UdpEchoClientHelper echoClient1(p2pInterfaces.GetAddress(0), 9);
    echoClient1.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient1.SetAttribute("Interval", TimeValue(Seconds(0.05)));
    echoClient1.SetAttribute("PacketSize", UintegerValue(1024));

    UdpEchoClientHelper echoClient2(p2pInterfaces.GetAddress(0), 9);
    echoClient2.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient2.SetAttribute("Interval", TimeValue(Seconds(0.05)));
    echoClient2.SetAttribute("PacketSize", UintegerValue(1024));

    // Install the clients on the respective station nodes
    ApplicationContainer clientApps1 = echoClient1.Install(wifiStaNodes.Get(0));
    clientApps1.Start(Seconds(2.0));
    clientApps1.Stop(Seconds(10.0));

    ApplicationContainer clientApps2 = echoClient2.Install(wifiStaNodes.Get(1));
    clientApps2.Start(Seconds(2.0));
    clientApps2.Stop(Seconds(10.0));

    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    // Install FlowMonitor on all nodes
    FlowMonitorHelper flowmon;
    Ptr<FlowMonitor> monitor = flowmon.InstallAll();

    AsciiTraceHelper ascii;
    phy.EnableAsciiAll(ascii.CreateFileStream("mytrace.tr"));

    if (tracing)
    {
        phy.SetPcapDataLinkType(WifiPhyHelper::DLT_IEEE802_11_RADIO);
        pointToPoint.EnablePcapAll("third");
        for (uint32_t i = 0; i < wifiStaNodes.GetN(); ++i)
        {
            phy.EnablePcap("third", staDevices.Get(i));
        }
    }

    Simulator::Stop(Seconds(10.0));
    Simulator::Run();

    // Print per flow statistics
    monitor->CheckForLostPackets();

    Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier>(flowmon.GetClassifier());
    std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats();

    for (auto i = stats.begin(); i != stats.end(); ++i)
    {
        Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow(i->first);

        std::cout << "Flow " << i->first << " (" << t.sourceAddress << " -> "
                  << t.destinationAddress << ")\n";
        std::cout << "  Tx Packets: " << i->second.txPackets << "\n";
        std::cout << "  Rx Packets: " << i->second.rxPackets << "\n";
        std::cout << "  Delivery Ratio: " << i->second.rxPackets * 1.0 / i->second.txPackets
                  << "\n";
        std::cout << "  Average Delay: " << i->second.delaySum.GetSeconds() / i->second.rxPackets
                  << "\n";
    }

    Simulator::Destroy();
    return 0;
}
