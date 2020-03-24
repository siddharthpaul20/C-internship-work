#ifndef PCAP_FILE_H
#define PCAP_FILE_H

#include "allTypeDefHeader.h"

class PcapFile
{
    //char fileName[30];
    ullint64 totalPacketCount;
    ullint64 ipv4PacketCount;
    ullint64 ipv6PacketCount;
    ullint64 tcpPacketCount;
    ullint64 udpPacketCount;

    public :
    PcapFile()
    {
        //strcpy(this.fileName,fileName);
        totalPacketCount = 0;
        ipv4PacketCount = 0;
        ipv6PacketCount = 0;
        tcpPacketCount = 0;
        udpPacketCount = 0;
    }

   /* PcapFile(char* fileName)
    {
        //strcpy(this.fileName,fileName);
        totalPacketCount = 0;
        ipv4PacketCount = 0;
        ipv6PacketCount = 0;
        tcpPacketCount = 0;
        udpPacketCount = 0;
    } */

    void incrementTotalPacketCount()
    {
        ++totalPacketCount;
    }
    void incrementIpv4PacketCount()
    {
        ++ipv4PacketCount;
    }

    void incrementIpv6PacketCount()
    {
        ++ipv6PacketCount;
    }

    void incrementTcpPacketCount()
    {
        ++tcpPacketCount;
    }

    void incrementUdpPacketCount()
    {
        ++udpPacketCount;
    }

    ullint64 getTotalPacketCount()
    {
        return totalPacketCount;
    }
    ullint64 getIpv4PacketCount()
    {
        return ipv4PacketCount;
    }

    ullint64 getIpv6PacketCount()
    {
        return ipv6PacketCount;
    }

    ullint64 getTcpPacketCount()
    {
        return tcpPacketCount;
    }

    ullint64 getUdpPacketCount()
    {
        return udpPacketCount;
    }

};

#endif // PCAP_FILE_H
