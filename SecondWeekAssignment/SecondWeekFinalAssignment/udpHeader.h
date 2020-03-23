#ifndef UDPHEADER_H
#define UDPHEADER_H
#include<iostream>
#include<netinet/in.h>
#include "utilityFunctions.h"
#include "allTypeDefHeader.h"
using namespace std;


struct udpHeader
{
	uint16 sourcePortNumber;
	uint16 destinationPortNumber;
	uint16 length;
	uint16 checkSum;

	udpHeader()
	{
		sourcePortNumber = 0;
		destinationPortNumber = 0;
		length = 0;
		checkSum = 0;
	}

	void displayUdpHeaderInHexaDecimal()
	{
		printf("\nUDP header Source Port Number : 0x%x", sourcePortNumber);
		printf("\nUDP header Destination Port Number : 0x%x", destinationPortNumber);
		printf("\nUDP header Length : 0x%x", length);
		printf("\nUDP header Checksum : 0x%x", checkSum);
	}

	void displayUdpHeader()
	{
		cout<<"\nUDP header Source Port Number in decimal : "<<ntohs(sourcePortNumber);
		cout<<"\nUDP header Destination Port Number in decimal : "<<ntohs(destinationPortNumber);
		cout<<"\nUDP header Length in decimal : "<<ntohs(length);
		cout<<"\nUDP header Checksum in decimal : "<<ntohs(checkSum);
	}
};

#endif
