#include <bits/stdc++.h>
#include <netinet/in.h>

using namespace std;

typedef unsigned int guint32;
typedef unsigned short guint16;
typedef int gint32;
typedef unsigned long long int gullint64;
typedef unsigned char guchar8;

string displayInHex(guint32 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}
string displayInHex(guint16 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}
string displayInHex(gint32 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}
string displayInHex(gullint64 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}

string displayInHex(unsigned char variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}

unsigned int hexadecimalToDecimal(string hexVal) 
{    
    int len = hexVal.size(); 
      
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
      
    unsigned int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='a' && hexVal[i]<='f') 
        { 
            dec_val += (hexVal[i] - 87)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
}

unsigned long long int hexadecimalToDecimalForLongLongInt(string hexVal) 
{    
    int len = hexVal.size(); 
      
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
      
    unsigned long long int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='a' && hexVal[i]<='f') 
        { 
            dec_val += (hexVal[i] - 87)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
}

void printIPAddress(unsigned int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;   
    printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);      
}

void printMACAddress(unsigned long long int macAddress)
{
    unsigned char bytes[6];
    bytes[0] = macAddress & 0xFF;
    bytes[1] = (macAddress >> 8) & 0xFF;
    bytes[2] = (macAddress >> 16) & 0xFF;
    bytes[3] = (macAddress >> 24) & 0xFF;
    bytes[4] = (macAddress >> 32) & 0xFF; 
    bytes[5] = (macAddress >> 40) & 0xFF; 
    //bytes[6] = (macAddress >> 48) & 0xFF;
    //bytes[7] = (macAddress >> 56) & 0xFF; 
    //printf("%d.%d.%d.%d.%d.%d.%d.%d\n", bytes[7], bytes[6], bytes[5], bytes[4], bytes[3], bytes[2], bytes[1], bytes[0]);
    printf("%x.%x.%x.%x.%x.%x\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5]);
           
}

struct globalHeader					// it is of size 24 bytes
{
	guint32 magicNumber;  				// 'A1B2C3D4' means the endianess is correct
	guint16 versionMajor;   	 		// major number of the file format
	guint16 versionMinor;   			// minor number of the file format
	gint32 correctionTime;	   			// correction time in seconds from UTC to local time(0)
	guint32 accuracyOfTimestampInCapture;        	// accuracy of timestamps in capture(0)
	guint32 maxLengthOfCapturedPacket;           	// max length of captured packet
	guint32 typeOfDataLink;      			// type of data link (1= ethernet)
	
	globalHeader()
	{
		guint32 magicNumber = 0;
		guint16 versionMajor = 0;
		guint16 versionMinor = 0;
		gint32 correctionTime = 0;
		guint32 accuracyOfTimestampInCapture = 0;
		guint32 maxLengthOfCapturedPacket = 0;
		guint32 typeOfDataLink = 0;
	}
};

struct packetHeader				// it is of size 16 bytes
{
	guint32 captureTimeInSeconds;		// timestamp seconds, it is of size 32 bits
	guint32 captureTimeInMicroSec;		// timestamp microseconds, it is of size 32 bits
	guint32 captureLength;			// number of octets of packets saved in file, it is of size 32 bits
	guint32 originalLength;			// actual length of packet, it is of size 32 bits

	packetHeader()
	{
		captureTimeInSeconds = 0;
		captureTimeInMicroSec = 0;
		captureLength = 0;
		originalLength = 0;
	}

	void displayPacketHeaderInHexaDecimal()
	{
		printf( "\nPacket header captureTimeInSeconds : 0x%x", captureTimeInSeconds );
   		printf( "\nPacket header captureTimeInMicroSec : 0x%x", captureTimeInMicroSec );
   		printf( "\nPacket header captureLength : 0x%x", captureLength );
   		printf( "\nPacket header originalLength : 0x%x", originalLength);
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

struct ethernetHeader				// it is of size 14 bytes
{
	gullint64 destinationMAC;			// Destination MAC address, it is of size 48 bits
	gullint64 sourceMAC;				// Source MAC address, it is of size 48 bits
	guint16 ethernetType;			// Ehternet Type, it is of size 16 bits

	ethernetHeader()
	{
		gullint64 destinationMAC = 0;
		gullint64 sourceMAC = 0;
		guint16 ethernetType = 0;
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

struct ipv4Header
{
	//guint16 ipVersionNumber;			// IP Version number, it is of size 4 bits
	//guint16 ipHL;				// IP Header length, it is of size 4 bits
	guint16 ipVersionNumberNdHeaderLength;
	guint16 TOS;					// Type of service, it is of size 8 bits
	guint16 totalLength;				// Total length, it is of size 16 bits
	guint16 identification;			// Identification, it is of size 16 bits
	//guint16 flags;				// Flags, it is of size 4 bits
	//guint16 fragmentOffset;			// FragmentOffset, it is of size 12 bits
	guint16 flagsNdFragmentOffset;
	guint16 TTL;					// Time to Live, it is of size 8 bits
	guint16 protocol;				// Protocol, it is of size 8 bits
	guint16 headerCheckSum;			// HeaderChecksum, it is of size 16 bits
	guint32 sourceAddress;			// SourceAddress, it is of size 32 bits
	guint32 destinationAddress;			// DestinationAddress, it is of size  32 bits

	ipv4Header()
	{
		guint16 ipVersionNumberNdHeaderLength = 0;
		guint16 TOS = 0;
		guint16 totalLength = 0;
		guint16 identification = 0;
		guint16 flagsNdFragmentOffset = 0;
		guint16 TTL = 0;
		guint16 protocol = 0;
		guint16 headerCheckSum = 0;
		guint32 sourceAddress = 0;
		guint32 destinationAddress = 0;
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
   		cout<<"\nipV4 header Source Address : 0x"<<displayInHex(sourceAddress);
   		cout<<"\nipV4 header Destination Address : 0x"<<displayInHex(destinationAddress);
	}

	void displayIPV4Header()
	{
		cout<<"\nIpV4 Header in decimal *************************";
		cout<< "ipV4 header Version and Header length : 0x" <<displayInHex(ipVersionNumberNdHeaderLength); 
		cout<<"\nipV4 header Version in Decimal: "<<((ipVersionNumberNdHeaderLength & 240)>>4);
		cout<<"\nipV4 header Length in Decimal: "<<(ipVersionNumberNdHeaderLength & 15);
		cout<< "\nipV4 header Type of service in Decimal: " << ntohs(TOS);
		cout<<"\nipV4 header Total Length in decimal : "<<ntohs(totalLength);
		cout<<"\nipV4 header identification in decimal : "<<ntohs(identification);
		cout<<"\nipV4 header flags in decimal : "<<( ( flagsNdFragmentOffset & 61440 ) >> 12 );
 		cout<<"\nipV4 header fragmentOffset in decimal : "<<ntohs( flagsNdFragmentOffset & 4095 );  // fragment offset is coming wrong
		cout<<"\nipV4 header TimeToLive in decimal : "<<ntohs((TTL<<8));   //  Now ttl is coming write
		cout<<"\nipV4 header Protocol in decimal : "<<ntohs((protocol<<8));
		cout<<"\nipV4 header HeaderCheckSum in decimal : "<<ntohs(headerCheckSum);
		cout<<"\nipV4 header Source Address in decimal : ";
		printIPAddress(ntohl(sourceAddress));
		cout<<"\nipV4 header Destination Address in decimal : ";
		printIPAddress(ntohl(destinationAddress));
	}
};

struct tcpHeader
{
	guint16 sourcePortNumber;			// sourcePortNumber, it is of size 16 bits
	guint16 destinationPortNumber;		// destinationPortNumber, it is of size 16 bits
	guint32 sequenceNumber;			// sequenceNumber, it is of size 32 bits
	guint32 acknowlegementNumber;		// acknowlegementNumber, it is of size 32 bits
	guint16 hLenNdReservedBitsNdControlFlags;   // Hlen is of size 4 bits and Reserved bits are of size 3 bits , last 9 bits are control flag bit
	guint16 windowSize;				// windowSize, it is of size 16 bits
	guint16 checkSum;				// checkSum, it is of size 16 bits
	guint16 urgentPointer;			// urgentPointer, it is of size 16 bits

	tcpHeader()
	{
		guint16 sourcePortNumber = 0;
		guint16 destinationPortNumber = 0;
		guint32 sequenceNumber = 0;
		guint32 acknowlegementNumber = 0;
		guint16 hLenNdReservedBitsNdControlFlags = 0;
		guint16 windowSize = 0;
		guint16 checkSum = 0;
		guint16 urgentPointer = 0;
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

struct udpHeader
{
	guint16 sourcePortNumber;
	guint16 destinationPortNumber;
	guint16 length;
	guint16 checkSum;

	udpHeader()
	{
		guint16 sourcePortNumber = 0;
		guint16 destinationPortNumber = 0;
		guint16 length = 0;
		guint16 checkSum = 0;
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

