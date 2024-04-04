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

NS_LOG_COMPONENT_DEFINE("CSMA-A");

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

    return 0;
}
