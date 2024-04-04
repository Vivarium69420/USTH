#include "ns3/applications-module.h"
#include <ns3/core-module.h>
#include <ns3/csma-module.h>
#include <ns3/internet-module.h>
#include <ns3/network-module.h>

// Default Network Topology
//
//  n0  n1  n2
//   |   |   |
//   =========
//  LAN 10.1.1.0

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("CSMA-B");

int
main(int argc, char* argv[])
{
    unsigned nCsma = 3;
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    Time::SetResolution(Time::NS);
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    NodeContainer csmaNodes;
    csmaNodes.Create(nCsma);

    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

    NetDeviceContainer csmaDevices;
    csmaDevices = csma.Install(csmaNodes);

    InternetStackHelper stack;
    stack.Install(csmaNodes);

    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer csmaInterfaces;
    csmaInterfaces = address.Assign(csmaDevices);

    // Create echo server on node 2
    UdpEchoServerHelper echoServer(9);
    ApplicationContainer serverApps = echoServer.Install(csmaNodes.Get(2));
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    // Create echo client on node 0, sending to node 2
    UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(2), 9);
    echoClient.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient.SetAttribute("Interval", TimeValue(Seconds(0.1)));
    echoClient.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApps = echoClient.Install(csmaNodes.Get(0));
    clientApps.Start(Seconds(2.0));
    clientApps.Stop(Seconds(10.0));

    // Enable pcap tracing on node 1
    csma.EnablePcap("node1", csmaDevices.Get(1), true);

    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
