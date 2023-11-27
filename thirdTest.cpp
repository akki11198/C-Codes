
#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/mobility-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/yans-wifi-helper.h"
#include "ns3/ssid.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("ThirdScriptExample");

int main(int argc, char *argv[])
{
    bool verbose = true;
    uint32_t nCsma = 4;
    uint32_t nWifi0 = 3;
    uint32_t nWifi1 = 4;
    bool tracing = false;

    CommandLine cmd(__FILE__);
    cmd.AddValue("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
    cmd.AddValue("nWifi0", "Number of wifi STA devices", nWifi0);
    cmd.AddValue("nWifi1", "Number of wifi STA devices", nWifi1);
    cmd.AddValue("verbose", "Tell echo applications to log if true", verbose);
    cmd.AddValue("tracing", "Enable pcap tracing", tracing);

    cmd.Parse(argc, argv);

    if (nWifi0 > 18)
    {
        std::cout << "nWifi0 should be 18 or less; otherwise grid layout exceeds the bounding box" << std::endl;
        return 1;
    }
    if (nWifi1 > 18)
    {
        std::cout << "nWifi1 should be 18 or less; otherwise grid layout exceeds the bounding box" << std::endl;
        return 1;
    }

    if (verbose)
    {
        LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
        LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
    }

    NodeContainer p2pNodes0, p2pNodes1;
    p2pNodes0.Create(2);
    p2pNodes1.Create(2);

    PointToPointHelper pointToPoint;
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

    NetDeviceContainer p2pDevices0, p2pDevices1;
    p2pDevices0 = pointToPoint.Install(p2pNodes0);
    p2pDevices1 = pointToPoint.Install(p2pNodes1);

    NodeContainer csmaNodes;
    csmaNodes.Add(p2pNodes0.Get(1));
    csmaNodes.Create(nCsma);
    csmaNodes.Add(p2pNodes1.Get(0));

    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

    NetDeviceContainer csmaDevices;
    csmaDevices = csma.Install(csmaNodes);

    NodeContainer wifiStaNodes0, wifiStaNodes1;
    wifiStaNodes0.Create(nWifi0);
    wifiStaNodes1.Create(nWifi1);
    NodeContainer wifiApNode0 = p2pNodes0.Get(0);
    NodeContainer wifiApNode1 = p2pNodes1.Get(1);

    YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
    YansWifiPhyHelper phy;
    phy.SetChannel(channel.Create());

    WifiHelper wifi;
    wifi.SetRemoteStationManager("ns3::AarfWifiManager");

    WifiMacHelper mac;
    Ssid ssid = Ssid("ns-3-ssid");
    mac.SetType("ns3::StaWifiMac",
                "Ssid", SsidValue(ssid),
                "ActiveProbing", BooleanValue(false));

    NetDeviceContainer staDevices0, staDevices1;
    staDevices0 = wifi.Install(phy, mac, wifiStaNodes0);
    staDevices1 = wifi.Install(phy, mac, wifiStaNodes1);

    mac.SetType("ns3::ApWifiMac",
                "Ssid", SsidValue(ssid));

    NetDeviceContainer apDevices0, apDevices1;
    apDevices0 = wifi.Install(phy, mac, wifiApNode0);
    apDevices1 = wifi.Install(phy, mac, wifiApNode1);

    MobilityHelper mobility;

    mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                  "MinX", DoubleValue(0.0),
                                  "MinY", DoubleValue(0.0),
                                  "DeltaX", DoubleValue(5.0),
                                  "DeltaY", DoubleValue(10.0),
                                  "GridWidth", UintegerValue(3),
                                  "LayoutType", StringValue("RowFirst"));

    mobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
                              "Bounds", RectangleValue(Rectangle(-50, 50, -50, 50)));
    mobility.Install(wifiStaNodes0);
    mobility.Install(wifiStaNodes1);

    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(wifiApNode0);
    mobility.Install(wifiApNode1);

    InternetStackHelper stack;
    stack.Install(csmaNodes);
    stack.Install(wifiApNode0);
    stack.Install(wifiApNode1);
    stack.Install(wifiStaNodes0);
    stack.Install(wifiStaNodes1);

    Ipv4AddressHelper address;

    address.SetBase("10.1.1.0", "255.255.255.0");
    address.Assign(staDevices0);
    address.Assign(apDevices0);

    address.SetBase("10.1.2.0", "255.255.255.0");
    Ipv4InterfaceContainer p2pInterfaces0;
    p2pInterfaces0 = address.Assign(p2pDevices0);

    address.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer csmaInterfaces;
    csmaInterfaces = address.Assign(csmaDevices);

    address.SetBase("10.1.4.0", "255.255.255.0");
    Ipv4InterfaceContainer p2pInterfaces1;
    p2pInterfaces1 = address.Assign(p2pDevices1);

    address.SetBase("10.1.5.0", "255.255.255.0");
    address.Assign(staDevices1);
    address.Assign(apDevices1);

    UdpEchoServerHelper echoServer(9);

    ApplicationContainer serverApps = echoServer.Install(csmaNodes.Get(0));
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(0), 9);
    echoClient.SetAttribute("MaxPackets", UintegerValue(1));
    echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApps00 =
        echoClient.Install(wifiStaNodes0.Get(0));
    clientApps00.Start(Seconds(2.0));
    clientApps00.Stop(Seconds(10.0));

    ApplicationContainer clientApps01 =
        echoClient.Install(wifiStaNodes0.Get(1));
    clientApps01.Start(Seconds(2.0));
    clientApps01.Stop(Seconds(10.0));

    ApplicationContainer clientApps02 =
        echoClient.Install(wifiStaNodes0.Get(2));
    clientApps02.Start(Seconds(2.0));
    clientApps02.Stop(Seconds(10.0));

    ApplicationContainer clientApps1 =
        echoClient.Install(wifiStaNodes1.Get(0));
    clientApps1.Start(Seconds(2.0));
    clientApps1.Stop(Seconds(10.0));

    ApplicationContainer clientApps2 = echoClient.Install(p2pNodes0.Get(0));
    clientApps2.Start(Seconds(2.0));
    clientApps2.Stop(Seconds(10.0));

    ApplicationContainer clientApps3 = echoClient.Install(p2pNodes0.Get(1));
    clientApps3.Start(Seconds(2.0));
    clientApps3.Stop(Seconds(10.0));

    ApplicationContainer clientApps4 = echoClient.Install(p2pNodes1.Get(0));
    clientApps4.Start(Seconds(2.0));
    clientApps4.Stop(Seconds(10.0));

    ApplicationContainer clientApps5 = echoClient.Install(p2pNodes1.Get(1));
    clientApps5.Start(Seconds(2.0));
    clientApps5.Stop(Seconds(10.0));

    ApplicationContainer clientApps6 = echoClient.Install(csmaNodes.Get(1));
    clientApps6.Start(Seconds(2.0));
    clientApps6.Stop(Seconds(10.0));

    ApplicationContainer clientApps7 = echoClient.Install(csmaNodes.Get(2));
    clientApps7.Start(Seconds(2.0));
    clientApps7.Stop(Seconds(10.0));

    ApplicationContainer clientApps8 = echoClient.Install(csmaNodes.Get(3));
    clientApps8.Start(Seconds(2.0));
    clientApps8.Stop(Seconds(10.0));

    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    Simulator::Stop(Seconds(10.0));

    if (tracing == true)
    {
        pointToPoint.EnablePcapAll("third");
        phy.EnablePcap("third", apDevices0.Get(0));
        csma.EnablePcap("third", csmaDevices.Get(0), true);
    }

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}
