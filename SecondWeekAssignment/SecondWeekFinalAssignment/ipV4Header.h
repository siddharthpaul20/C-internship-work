#ifndef IPV4HEADER_H
#define IPV4HEADER_H
#include <winsock2.h>
#include <windows.h>
#include<iostream>
//#include<netinet/in.h>
#include "ipV4AddressHeader.h"
#include "utilityFunctions.h"
#include "allTypeDefHeader.h"

using namespace std;

struct ipv4Header
{
	//guint16 ipVersionNumber;			// IP Version number, it is of size 4 bits
	//guint16 ipHL;				// IP Header length, it is of size 4 bits
	uint16 ipVersionNumberNdHeaderLength;
	uint16 TOS;					// Type of service, it is of size 8 bits
	uint16 totalLength;				// Total length, it is of size 16 bits
	uint16 identification;			// Identification, it is of size 16 bits
	//guint16 flags;				// Flags, it is of size 4 bits
	//guint16 fragmentOffset;			// FragmentOffset, it is of size 12 bits
	uint16 flagsNdFragmentOffset;
	uint16 TTL;					// Time to Live, it is of size 8 bits
	uint16 protocol;				// Protocol, it is of size 8 bits
	uint16 headerCheckSum;			// HeaderChecksum, it is of size 16 bits
	//uint32 sourceAddress;			// SourceAddress, it is of size 32 bits
	//uint32 destinationAddress;			// DestinationAddress, it is of size  32 bits
	ipV4Address sourceAddress;
	ipV4Address destinationAddress;

	ipv4Header()
	{
		ipVersionNumberNdHeaderLength = 0;
		TOS = 0;
		totalLength = 0;
		identification = 0;
		flagsNdFragmentOffset = 0;
		TTL = 0;
		protocol = 0;
		headerCheckSum = 0;
		//sourceAddress = 0;    No need to intialize this, as they are already intialized
		//destinationAddress = 0;     No need to intialize this, as they are already intialized
	}

	void displayIPV4HeaderInHexaDecimal()
	{
		cout<< "ipV4 header Version and Header length : 0x" <<displayInHex(ipVersionNumberNdHeaderLength);
   		//i4obj.ipVersionNumber = (i4obj.ipVersionNumberNdHeaderLength & 240)>>4;   // 64 coming in output means 4 : v4
   		cout<<"\nipV4 header Version : "<<((ipVersionNumberNdHeaderLength & 240)>>4);
   		//i4obj.ipHL = i4obj.ipVersionNumberNdHeaderLength & 15;
   		cout<<"\nipV4 header Length : "<<(ipVersionNumberNdHeaderLength & 15);

   		cout<< "\nipV4 header Type of service : 0x" << displayInHex(TOS);

   		cout<<"\nipV4 header Total Length : 0x"<<displayInHex(totalLength);
   		unsigned short tempTotalLength = ntohs(totalLength);
   		cout<<"\nipV4 header Total Length in decimal : "<<tempTotalLength;
   		cout<<"\nipV4 header identification : 0x"<<displayInHex(identification);
   		cout<<"\nipV4 header flags : 0x"<<displayInHex( ( flagsNdFragmentOffset & 61440 ) >> 12 );
   		cout<<"\nipV4 header fragmentOffset : 0x"<<displayInHex( flagsNdFragmentOffset & 4095 );
   		cout<<"\nipV4 header TimeToLive : 0x"<<displayInHex(TTL);
   		cout<<"\nipV4 header Protocol : 0x"<<displayInHex(protocol);
   		cout<<"\nipV4 header HeaderCheckSum : 0x"<<displayInHex(headerCheckSum);
   		cout<<"\nipV4 header Source Address : 0x"<<displayInHex(sourceAddress.ipV4);
   		cout<<"\nipV4 header Destination Address : 0x"<<displayInHex(destinationAddress.ipV4);
	}

	void displayIPV4Header()
	{
		cout<<"\nIpV4 Header in decimal *************************";
		cout<< "ipV4 header Version and Header length : 0x" <<displayInHex(ipVersionNumberNdHeaderLength);
		cout<<"\nipV4 header Version in Decimal: "<<((ipVersionNumberNdHeaderLength & 240)>>4);
		cout<<"\nipV4 header Length in Decimal: "<<(ipVersionNumberNdHeaderLength & 15);
		cout<<"\nipV4 header Type of service in Decimal: " << ntohs(TOS);
		cout<<"\nipV4 header Total Length in decimal : "<<ntohs(totalLength);
		cout<<"\nipV4 header identification in decimal : "<<ntohs(identification);
		cout<<"\nipV4 header flags in decimal : "<<( ( flagsNdFragmentOffset & 61440 ) >> 12 );
 		cout<<"\nipV4 header fragmentOffset in decimal : "<<ntohs( flagsNdFragmentOffset & 4095 );  // fragment offset is coming wrong
		cout<<"\nipV4 header TimeToLive in decimal : "<<ntohs((TTL<<8));   //  Now ttl is coming write
		cout<<"\nipV4 header Protocol in decimal : "<<ntohs((protocol<<8));
		cout<<"\nipV4 header HeaderCheckSum in decimal : "<<ntohs(headerCheckSum);
		cout<<"\nipV4 header Source Address in decimal : ";
		printIPAddress(ntohl(sourceAddress.ipV4));
		cout<<"\nipV4 header Destination Address in decimal : ";
		printIPAddress(ntohl(destinationAddress.ipV4));
	}

	void writeIPAddressToCSVFile(fstream* fout)
	{
	    char str[9];
	    unsigned int ip = ntohl(sourceAddress.ipV4);
	    unsigned char bytes[4];
        bytes[0] = ip & 0xFF;
        bytes[1] = (ip >> 8) & 0xFF;
        bytes[2] = (ip >> 16) & 0xFF;
        bytes[3] = (ip >> 24) & 0xFF;
        sprintf(str,"%d.%d.%d.%d", bytes[3], bytes[2], bytes[1], bytes[0]);
        *fout<<str;
        *fout<<",";
        ip = ntohl(destinationAddress.ipV4);
        bytes[0] = ip & 0xFF;
        bytes[1] = (ip >> 8) & 0xFF;
        bytes[2] = (ip >> 16) & 0xFF;
        bytes[3] = (ip >> 24) & 0xFF;
        sprintf(str,"%d.%d.%d.%d", bytes[3], bytes[2], bytes[1], bytes[0]);
        *fout<<str;

	}
};

#endif

