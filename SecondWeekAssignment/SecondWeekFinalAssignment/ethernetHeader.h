#ifndef ETHERNETHEADER_H
#define ETHERNETHEADER_H

#include<iostream>
#include "utilityFunctions.h"
#include "allTypeDefHeader.h"

using namespace std;

struct ethernetHeader				// it is of size 14 bytes
{
	unsigned char[6] destinationMAC;			// Destination MAC address, it is of size 48 bits
	unsigned char[6] sourceMAC;				// Source MAC address, it is of size 48 bits
	uint16 ethernetType;			// Ehternet Type, it is of size 16 bits

	ethernetHeader()
	{
		destinationMAC = 0;
		sourceMAC = 0;
		ethernetType = 0;
	}

	void displayEthernetHeaderInHexaDecimal()
	{
		cout<<"Ethernet header of packet destinationMAC : 0x" << displayInHex(destinationMAC) << endl;
   		cout<<"Ethernet header of packet sourceMAC : 0x" << displayInHex(sourceMAC) << endl;
   		cout<<"Ethernet header of packet ethernetType : 0x" << displayInHex(ethernetType) << endl;
	}

	void displayEthernetHeader()
	{
		cout<<"\n*******IN DECIMAL VALUE ************";
		//cout<< "\nEthernet header of packet destinationMAC in Decimal: " << hexadecimalToDecimal(displayInHex(ntohl(eobj.destinationMAC))) << endl;
		cout<< "\nEthernet header of packet destinationMAC in Decimal: ";
		printMACAddress(destinationMAC);
        	printf("\n");
   		cout<< "Ethernet header of packet sourceMAC in Decimal: ";
		printMACAddress(sourceMAC);
        	printf("\n");
   		//cout<< "Ethernet header of packet ethernetType in Decimal: " << displayInHex(ntohs(eobj.ethernetType)) << endl;  // No use of printing 0800 hexadecimal value
																// to user to identify ipV4 header
	}

};

#endif
