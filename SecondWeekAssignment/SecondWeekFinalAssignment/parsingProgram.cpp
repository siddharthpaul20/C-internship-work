#include<iostream>
#include<fstream>
#include "headerForAllStructs.h"

using namespace std;

int main()
{
   ifstream inFile;
   long long int readerPointer = 0,skipPacketPointer;
   long long int packetCount = 0;
   string res;
   // Reading global header
   globalHeader gobj;

   inFile.open("pcapFile1.pcap", ios::binary);

   inFile.read((char*) &gobj.magicNumber,4);
   readerPointer+=4;
   inFile.read((char*) &gobj.versionMajor,2);
   readerPointer+=2;
   inFile.read((char*) &gobj.versionMinor,2);
   readerPointer+=2;
   inFile.read((char*) &gobj.correctionTime,4);
   readerPointer+=4;
   inFile.read((char*) &gobj.accuracyOfTimestampInCapture,4);
   readerPointer+=4;
   inFile.read((char*) &gobj.maxLengthOfCapturedPacket,4);
   readerPointer+=4;
   inFile.read((char*) &gobj.typeOfDataLink,4);
   readerPointer+=4;

   cout<<"\n"<<gobj.magicNumber<<"\n";
   cout<< "MagicNumber : 0x" << displayInHex(gobj.magicNumber)  << endl;
   //cout<< "MagicNumber in int : " << gobj.magicNumber  << endl;
   cout<< "MajorVersion : 0x" << displayInHex(gobj.versionMajor) << endl;
   cout<< "MinorVersion : 0x" << displayInHex(gobj.versionMinor) << endl;
   cout<< "Timestamp : 0x" << displayInHex(gobj.correctionTime) << endl;
   cout<< "Accuracy of timestamp : 0x" << displayInHex(gobj.accuracyOfTimestampInCapture) << endl;
   cout<< "Capture Maxixmum length : 0x" << displayInHex(gobj.maxLengthOfCapturedPacket) << endl;
   cout<< "Type of packet : 0x" << displayInHex(gobj.typeOfDataLink) << endl;
   //cout<< "Type of packet in int : " << gobj.typeOfDataLink << endl;
   if(gobj.magicNumber==2712847316 && gobj.typeOfDataLink == 1)
   {
	printf("\nhi\n");
	// file is pcap file
	// now reading packets int pcap file
        //int counterForTesting = 3046;
	while(inFile.peek() != EOF)   // while end of file is not reached
	//while(counterForTesting--)
	{
		cout<<"\nPacketCount ==========> "<<++packetCount<<"  -----------------> "<<readerPointer<<"\n";
		// Now reading packet header of packet 1
		packetHeader pobj;

		inFile.read((char*) &pobj.captureTimeInSeconds,4);
		readerPointer+=4;
   		inFile.read((char*) &pobj.captureTimeInMicroSec,4);
		readerPointer+=4;
   		inFile.read((char*) &pobj.captureLength,4);
		readerPointer+=4;
   		inFile.read((char*) &pobj.originalLength,4); 
		readerPointer+=4;
   		
		pobj.displayPacketHeaderInHexaDecimal();

		pobj.displayPacketHeader();

		skipPacketPointer = readerPointer;
   		// Now reading data of packet 1
   		// Reading ethernet header of packet 1
   		ethernetHeader eobj;

   		inFile.read((char*) &eobj.destinationMAC,6);
 		readerPointer+=6;
   		inFile.read((char*) &eobj.sourceMAC,6);
 		readerPointer+=6;
   		inFile.read((char*) &eobj.ethernetType,2);
		readerPointer+=2;

		eobj.displayEthernetHeaderInHexaDecimal();
   		
		eobj.displayEthernetHeader();

		if(eobj.ethernetType==8)   // packet contains ipV4 header
		{
			// Now reading ipV4 Header
   			ipv4Header i4obj;

   			//unsigned short tempForVersionNdHeaderLenght=0;
  			inFile.read((char*) &i4obj.ipVersionNumberNdHeaderLength,1);
			readerPointer+=1;

   			inFile.read((char*) &i4obj.TOS,1);
			readerPointer+=1;

   			inFile.read((char*) &i4obj.totalLength,2);
			readerPointer+=2;

   			inFile.read((char*) &i4obj.identification,2);
			readerPointer+=2;

   			
   			inFile.read((char*) &i4obj.flagsNdFragmentOffset,2);
			readerPointer+=2;
   
   			inFile.read((char*) &i4obj.TTL,1);
   			readerPointer+=1;

   			inFile.read((char*) &i4obj.protocol,1);
  			readerPointer+=1;
 
   			inFile.read((char*) &i4obj.headerCheckSum,2);
			readerPointer+=2;

   			inFile.read((char*) &i4obj.sourceAddress,4);
			readerPointer+=4;

   			inFile.read((char*) &i4obj.destinationAddress,4);
			readerPointer+=4;

			i4obj.displayIPV4HeaderInHexaDecimal();
   			
			i4obj.displayIPV4Header();
			//**************** IPV4 header read successfully **********************************

			// Now reading tcp header or udp header
			if(hexadecimalToDecimal(displayInHex(i4obj.protocol))==6)
			{
				// Reading TCP Header
				// Now reading tcp Header
				tcpHeader tcpHobj;

				inFile.read((char*) &tcpHobj.sourcePortNumber,2);
				readerPointer+=2;

				tcpHobj.destinationPortNumber = 0;
				inFile.read((char*) &tcpHobj.destinationPortNumber,2);
				readerPointer+=2;

				inFile.read((char*) &tcpHobj.sequenceNumber,4);
				readerPointer+=4;

				inFile.read((char*) &tcpHobj.acknowlegementNumber,4);
				readerPointer+=4;

				inFile.read((char*) &tcpHobj.hLenNdReservedBitsNdControlFlags,2);
				readerPointer+=2;

				inFile.read((char*) &tcpHobj.windowSize,2);
				readerPointer+=2;

				inFile.read((char*) &tcpHobj.checkSum,2);
				readerPointer+=2;

				inFile.read((char*) &tcpHobj.urgentPointer,2);
				readerPointer+=2;

				tcpHobj.displayTcpHeaderInHexaDecimal();
				
				tcpHobj.displayTcpHeader();
			}
			else
			{
				if(hexadecimalToDecimal(displayInHex(i4obj.protocol))==17)
				{
					// Reading UDP Header
					udpHeader udpHobj;

					inFile.read((char*) &udpHobj.sourcePortNumber,2);
					readerPointer+=2;

					inFile.read((char*) &udpHobj.destinationPortNumber,2);
					readerPointer+=2;

					inFile.read((char*) &udpHobj.length,2);
					readerPointer+=2;

					inFile.read((char*) &udpHobj.checkSum,2);
					readerPointer+=2;

					udpHobj.displayUdpHeaderInHexaDecimal();
					udpHobj.displayUdpHeader();
				}
			}
			
			// at last when tcp or udp header is read
			unsigned int tempPacketLength = hexadecimalToDecimal(displayInHex(pobj.captureLength));
			cout<<"\n-----------------> "<<tempPacketLength<<"\n";
			readerPointer=skipPacketPointer+tempPacketLength;
			cout<<"\n-----------------> "<<readerPointer<<"\n";
			inFile.seekg(readerPointer,ios::beg);
		}
		else
		{
			unsigned int tempPacketLength = hexadecimalToDecimal(displayInHex(pobj.captureLength));
			inFile.seekg(skipPacketPointer+tempPacketLength,ios::beg);
			readerPointer=skipPacketPointer+tempPacketLength;
		}
	}  // end of while	
	      
   }
   else  // file is not pcap type
   {
	printf("\nThe file given is not of pcap type.\n");
   }
}


