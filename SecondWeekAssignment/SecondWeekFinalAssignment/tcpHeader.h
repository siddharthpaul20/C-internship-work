#ifndef TCPHEADER_H
#define TCPHEADER_H

#include<iostream>
#include "utilityFunctions.h"
#include<netinet/in.h>
#include "allTypeDefHeader.h"
using namespace std;

struct tcpHeader
{
	uint16 sourcePortNumber;			// sourcePortNumber, it is of size 16 bits
	uint16 destinationPortNumber;		// destinationPortNumber, it is of size 16 bits
	uint32 sequenceNumber;			// sequenceNumber, it is of size 32 bits
	uint32 acknowlegementNumber;		// acknowlegementNumber, it is of size 32 bits
	uint16 hLenNdReservedBitsNdControlFlags;   // Hlen is of size 4 bits and Reserved bits are of size 3 bits , last 9 bits are control flag bit
	uint16 windowSize;				// windowSize, it is of size 16 bits
	uint16 checkSum;				// checkSum, it is of size 16 bits
	uint16 urgentPointer;			// urgentPointer, it is of size 16 bits

	tcpHeader()
	{
		sourcePortNumber = 0;
		destinationPortNumber = 0;
		sequenceNumber = 0;
		acknowlegementNumber = 0;
		hLenNdReservedBitsNdControlFlags = 0;
		windowSize = 0;
		checkSum = 0;
		urgentPointer = 0;
	}

	void displayTcpHeaderInHexaDecimal()
	{
		cout<<"\nTCP header Source Port Number : 0x"<<displayInHex(sourcePortNumber);
		cout<<"\nTCP header Destination Port Number : 0x"<<displayInHex(destinationPortNumber);
		cout<<"\nTCP header Sequence Number : 0x"<<displayInHex(sequenceNumber);
		cout<<"\nTCP header Acknowlegment Number : 0x"<<displayInHex(acknowlegementNumber);
		cout<<"\nTCP header Hlen and Reserved bits and Control flags : 0x"<<displayInHex(hLenNdReservedBitsNdControlFlags);
		unsigned int tempForHlen = hLenNdReservedBitsNdControlFlags & 61440;
		cout<<"\nExtracting HLEN from above : "<<(tempForHlen>>10) ;
		cout<<"\nTCP header Window size : 0x"<<displayInHex(windowSize);
		cout<<"\nTCP header CheckSum : 0x"<<displayInHex(checkSum);
		cout<<"\nTCP header Urgent Pointer : 0x"<<displayInHex(urgentPointer);
	}

	void displayTcpHeader()
	{
		cout<<"\nTCP HEADER IN DECIMAL *****************************************************";
		cout<<"\nTCP header Source Port Number in decimal : "<<ntohs(sourcePortNumber);
		cout<<"\nTCP header Destination Port Number in decimal : "<<ntohs(destinationPortNumber);
		cout<<"\nTCP header Sequence Number in decimal : "<<ntohl(sequenceNumber);
		cout<<"\nTCP header Acknowlegment Number in decimal : "<<ntohl(acknowlegementNumber);
		cout<<"\nTCP header Hlen and Reserved bits and Control flags in decimal : "<<ntohs(hLenNdReservedBitsNdControlFlags);
		unsigned int tempForHlen = hLenNdReservedBitsNdControlFlags & 61440;
		cout<<"\nExtracting HLEN from above : "<<(tempForHlen>>10) ;
		cout<<"\nTCP header Window size in decimal : "<<ntohs(windowSize);
		cout<<"\nTCP header CheckSum in decimal : "<<ntohs(checkSum);
		cout<<"\nTCP header Urgent Pointer in decimal : "<<ntohs(urgentPointer);
	}

};

#endif
