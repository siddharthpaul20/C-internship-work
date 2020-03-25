#ifndef IPV6HEADER_H
#define IPV6HEADER_H
#include <winsock2.h>
#include <windows.h>
#include<iostream>
//#include<netinet/in.h>
#include "utilityFunctions.h"
#include "allTypeDefHeader.h"

using namespace std;

struct ipV6Header
{
    // uint16 version;     // Version, it is of size 4 bits
    // uint16 trafficClass;    // Priority/ Traffic Class, it is of size 12 bits
    // uint16 flowLabel;       // FlowLabel, it is of size 20 bits
    uint32 versionNdTrafficClassNdFlowLabel;
    uint16 payloadLength;       // Payload Length, it is of size 16 bits
    //uint16 nextHeader;          // nextHeader, it is of size 8 bits
    //uint16 hopLimit;            // hopLimit, it is of size 8 bits
    uint16 nextHeaderNdHopLimit;

    ipV6Address sourceAddress;      // source IP address, it is of size 16 bytes
    ipV6Address destinationAddress;     // destination IP address, it is of size 16 bytes

    ipV6Header()
    {
        versionNdTrafficClassNdFlowLabel = 0;
        payloadLength = 0;
        nextHeaderNdHopLimit = 0;
        // sourceAddress and destinationAddress are already initialized, no need to intialize them
    }

    void displayIPV6HeaderInHexaDecimal()
    {
        printf("\nipV6 Header in HexaDecimal ************************");
        printf("\nipV6 Header Version, Traffic Class, and FlowLabel : 0x%x",versionNdTrafficClassNdFlowLabel);
        printf("\nipV6 Header Payload Length : 0x%x",payloadLength);
        printf("\nipV6 NextHeader and HopLimit : 0x%x",nextHeaderNdHopLimit);
        printf("\nipV6 Source IP address : 0x%x",sourceAddress);
        printf("\nipV6 Destination IP address : 0x%x",destinationAddress);
    }

    void displayIPV6Header()
    {
        printf("\nipV6 Header in Decimal ************************");
        printf("\nipV6 Header Version, Traffic Class, and FlowLabel in Decimal : %d",versionNdTrafficClassNdFlowLabel);
        printf("\nipV6 Header Payload Length in Decimal : %d",ntohs(payloadLength));
        printf("\nipV6 NextHeader and HopLimit in Decimal : %d",ntohs(nextHeaderNdHopLimit));
        printf("\nipV6 NextHeader in Decimal : %d",(ntohs(nextHeaderNdHopLimit)>>8) );
        printf("\nipV6 HopLimit in Decimal : %d",(ntohs(nextHeaderNdHopLimit) & 255));
        printf("\nipV6 Source IP address in Decimal : ");
        printIPAddress(sourceAddress);
        printf("\nipV6 Destination IP address in Decimal : ");
        printIPAddress(destinationAddress);
    }

    void writeIPAddressToCSVFile(fstream *fout)
    {
        char str[8];
        // for sourceAddress
        for(int iteratingIndex = 0; iteratingIndex < 8; iteratingIndex++)
        {
            uint16 twoBytes = ntohs(sourceAddress.ipV6[iteratingIndex]);
            sprintf(str,"%x.",twoBytes);
            *fout<<str;
        }
        *fout<<",";
        // for destinationAddress
        for(int iteratingIndex = 0; iteratingIndex < 8; iteratingIndex++)
        {
            uint16 twoBytes = ntohs(destinationAddress.ipV6[iteratingIndex]);
            sprintf(str,"%x.",twoBytes);
            *fout<<str;
        }
    }
};

#endif // IPV6HEADER_H
