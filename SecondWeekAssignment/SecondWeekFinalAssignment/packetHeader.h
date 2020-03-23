#ifndef PACKETHEADER_H
#define PACKETHEADER_H

#include <iostream>
#include "utilityFunctions.h"
#include "allTypeDefHeader.h"
using namespace std;



struct packetHeader				// it is of size 16 bytes
{
	uint32 captureTimeInSeconds;		// timestamp seconds, it is of size 32 bits
	uint32 captureTimeInMicroSec;		// timestamp microseconds, it is of size 32 bits
	uint32 captureLength;			// number of octets of packets saved in file, it is of size 32 bits
	uint32 originalLength;			// actual length of packet, it is of size 32 bits

	packetHeader()
	{
		captureTimeInSeconds = 0;
		captureTimeInMicroSec = 0;
		captureLength = 0;
		originalLength = 0;
	}

	void displayPacketHeaderInHexaDecimal()
	{
		printf("\nPacket header captureTimeInSeconds : 0x%x", captureTimeInSeconds );
   		printf("\nPacket header captureTimeInMicroSec : 0x%x", captureTimeInMicroSec );
   		printf("\nPacket header captureLength : 0x%x", captureLength );
   		printf("\nPacket header originalLength : 0x%x", originalLength);
	}

	void displayPacketHeader()
	{
		//cout<< "Packet header captureTimeInSeconds : 0x" << displayInHex(pobj.captureTimeInSeconds) << endl;
   		//cout<< "Packet header captureTimeInMicroSec : 0x" << displayInHex(pobj.captureTimeInMicroSec) << endl;
		cout<<"\n*******IN DECIMAL VALUE ************";
		cout<<"\nPacket header captureLength in Decimal: " << hexadecimalToDecimal(displayInHex(captureLength));
   		cout<<"\nPacket header originalLength in Decimal: " << hexadecimalToDecimal(displayInHex(originalLength)) << endl;
	}
	
};

#endif
