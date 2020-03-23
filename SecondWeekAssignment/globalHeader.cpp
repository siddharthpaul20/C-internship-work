#include<bits/stdc++.h>
#include "header.h"
#include<netinet/in.h>

using namespace std;

string displayInHex(guint32 variable);
string displayInHex(guint16 variable);
string displayInHex(gint32 variable);
string displayInHex(gullint64 variable);

int main()
{
   ifstream inFile;
   string res;
   // Reading global header
   globalHeader gobj;
   inFile.open("pcapFile1.pcap", ios::binary);
   inFile.read((char*) &gobj.magicNumber,4);
   inFile.seekg(4,ios::beg);
   inFile.read((char*) &gobj.versionMajor,2);
   inFile.seekg(6,ios::beg);
   inFile.read((char*) &gobj.versionMinor,2);
   inFile.seekg(8,ios::beg);
   inFile.read((char*) &gobj.correctionTime,4);
   inFile.seekg(12,ios::beg);
   inFile.read((char*) &gobj.accuracyOfTimestampInCapture,4);
   inFile.seekg(16,ios::beg);
   inFile.read((char*) &gobj.maxLengthOfCapturedPacket,4);
   inFile.seekg(20,ios::beg);
   inFile.read((char*) &gobj.typeOfDataLink,4);

   cout<<"\n"<<gobj.magicNumber<<"\n";
   cout<< "MagicNumber : 0x" << displayInHex(gobj.magicNumber)  << endl;
   cout<< "MajorVersion : 0x" << displayInHex(gobj.versionMajor) << endl;
   cout<< "MinorVersion : 0x" << displayInHex(gobj.versionMinor) << endl;
   cout<< "Timestamp : 0x" << displayInHex(gobj.correctionTime) << endl;
   cout<< "Accuracy of timestamp : 0x" << displayInHex(gobj.accuracyOfTimestampInCapture) << endl;
   cout<< "Capture Maxixmum length : 0x" << displayInHex(gobj.maxLengthOfCapturedPacket) << endl;
   cout<< "Type of packet : 0x" << displayInHex(gobj.typeOfDataLink) << endl;

   // Now reading packet header of packet 1
   packetHeader pobj;
   inFile.seekg(24,ios::beg);
   inFile.read((char*) &pobj.captureTimeInSeconds,4);
   inFile.seekg(28,ios::beg);
   inFile.read((char*) &pobj.captureTimeInMicroSec,4);
   inFile.seekg(32,ios::beg);
   inFile.read((char*) &pobj.captureLength,4);
   inFile.seekg(36,ios::beg);
   inFile.read((char*) &pobj.originalLength,4); 

   
   cout<< "Packet header captureTimeInSeconds : 0x" << displayInHex(pobj.captureTimeInSeconds) << endl;
   cout<< "Packet header captureTimeInMicroSec : 0x" << displayInHex(pobj.captureTimeInMicroSec) << endl;
   cout<< "Packet header captureLength : 0x" << displayInHex(pobj.captureLength) << endl;
   cout<< "Packet header originalLength : 0x" << displayInHex(pobj.originalLength) << endl;

   // Now reading data of packet 1
   // Reading ethernet header of packet 1
   ethernetHeader eobj;
   inFile.seekg(40,ios::beg);
   inFile.read((char*) &eobj.destinationMAC,6);
   inFile.seekg(46,ios::beg);
   inFile.read((char*) &eobj.sourceMAC,6);
   inFile.seekg(52,ios::beg);
   inFile.read((char*) &eobj.ethernetType,2);

   cout<< "Ethernet header of packet destinationMAC : 0x" << displayInHex(eobj.destinationMAC) << endl;
   cout<< "Ethernet header of packet sourceMAC : 0x" << displayInHex(eobj.sourceMAC) << endl;
   cout<< "Ethernet header of packet ethernetType : 0x" << displayInHex(eobj.ethernetType) << endl;

   // Now reading ipV4 Header
   unsigned short tempForVersionNdHeaderLenght=0;
   ipv4Header i4obj;
   inFile.seekg(54,ios::beg);
   inFile.read((char*) &tempForVersionNdHeaderLenght,1);
   i4obj.TOS = 0;
   inFile.seekg(55,ios::beg);
   inFile.read((char*) &i4obj.TOS,1);
   i4obj.totalLength = 0;
   inFile.seekg(56,ios::beg);
   inFile.read((char*) &i4obj.totalLength,2);
   i4obj.identification = 0;
   inFile.seekg(58,ios::beg);
   inFile.read((char*) &i4obj.identification,2);
   unsigned short tempForFlags = 0;
   i4obj.flags = 0;
   inFile.seekg(60,ios::beg);
   inFile.read((char*) &tempForFlags,1);
   i4obj.flags = (tempForFlags & 240)>>4;
   unsigned short tempForFragmentOffset = 0;
   i4obj.fragmentOffset = 0;
   inFile.seekg(60,ios::beg);
   inFile.read((char*) &tempForFragmentOffset,2);
   i4obj.fragmentOffset = tempForFragmentOffset & 4095;
   
   i4obj.TTL = 0;
   inFile.seekg(62,ios::beg);
   inFile.read((char*) &i4obj.TTL,1);
   
   i4obj.protocol = 0;
   inFile.seekg(63,ios::beg);
   inFile.read((char*) &i4obj.protocol,1);
   
   i4obj.headerCheckSum = 0;
   inFile.seekg(64,ios::beg);
   inFile.read((char*) &i4obj.headerCheckSum,2);

   i4obj.sourceAddress = 0;
   inFile.seekg(66,ios::beg);
   inFile.read((char*) &i4obj.sourceAddress,4);

   i4obj.destinationAddress = 0;
   inFile.seekg(70,ios::beg);
   inFile.read((char*) &i4obj.destinationAddress,4);

   cout<< "ipV4 header Version and Header length : 0x" <<displayInHex(tempForVersionNdHeaderLenght);
   i4obj.ipVersionNumber = (tempForVersionNdHeaderLenght & 240)>>4;   // 64 coming in output means 4 : v4
   cout<<"\nipV4 header Version : "<<i4obj.ipVersionNumber;
   i4obj.ipHL = tempForVersionNdHeaderLenght & 15;
   cout<<"\nipV4 header Length : "<<i4obj.ipHL;
   
   cout<< "\nipV4 header Type of service : 0x" << displayInHex(i4obj.TOS);

   cout<<"\nipV4 header Total Length : 0x"<<displayInHex(i4obj.totalLength);
   unsigned short tempTotalLength = ntohs(i4obj.totalLength);
   cout<<"\nipV4 header Total Length in decimal : "<<tempTotalLength;
   cout<<"\nipV4 header identification : 0x"<<displayInHex(i4obj.identification);
   cout<<"\nipV4 header flags : 0x"<<displayInHex(i4obj.flags);
   cout<<"\nipV4 header fragmentOffset : 0x"<<displayInHex(i4obj.fragmentOffset);
   cout<<"\nipV4 header TimeToLive : 0x"<<displayInHex(i4obj.TTL);
   cout<<"\nipV4 header Protocol : 0x"<<displayInHex(i4obj.protocol);
   cout<<"\nipV4 header HeaderCheckSum : 0x"<<displayInHex(i4obj.headerCheckSum);
   cout<<"\nipV4 header Source Address : 0x"<<displayInHex(i4obj.sourceAddress);
   cout<<"\nipV4 header Destination Address : 0x"<<displayInHex(i4obj.destinationAddress);

   // Now reading tcp Header
   tcpHeader tcpHobj;
   tcpHobj.sourcePortNumber = 0;
   inFile.seekg(74,ios::beg);
   inFile.read((char*) &tcpHobj.sourcePortNumber,2);

   tcpHobj.destinationPortNumber = 0;
   inFile.seekg(76,ios::beg);
   inFile.read((char*) &tcpHobj.destinationPortNumber,2);

   tcpHobj.sequenceNumber = 0;
   inFile.seekg(78,ios::beg);
   inFile.read((char*) &tcpHobj.sequenceNumber,4);

   tcpHobj.acknowlegementNumber = 0;
   inFile.seekg(82,ios::beg);
   inFile.read((char*) &tcpHobj.acknowlegementNumber,4);

   tcpHobj.hLenNdReservedBitsNdControlFlags = 0;
   inFile.seekg(86,ios::beg);
   inFile.read((char*) &tcpHobj.hLenNdReservedBitsNdControlFlags,2);

   tcpHobj.windowSize = 0;
   inFile.seekg(88,ios::beg);
   inFile.read((char*) &tcpHobj.windowSize,2);

   tcpHobj.checkSum = 0;
   inFile.seekg(90,ios::beg);
   inFile.read((char*) &tcpHobj.checkSum,2);

   tcpHobj.urgentPointer = 0;
   inFile.seekg(92,ios::beg);
   inFile.read((char*) &tcpHobj.urgentPointer,2);

   cout<<"\nTCP header Source Port Number : 0x"<<displayInHex(tcpHobj.sourcePortNumber);
   cout<<"\nTCP header Destination Port Number : 0x"<<displayInHex(tcpHobj.destinationPortNumber);
   cout<<"\nTCP header Sequence Number : 0x"<<displayInHex(tcpHobj.sequenceNumber);
   cout<<"\nTCP header Acknowlegment Number : 0x"<<displayInHex(tcpHobj.acknowlegementNumber);
   cout<<"\nTCP header Hlen and Reserved bits and Control flags : 0x"<<displayInHex(tcpHobj.hLenNdReservedBitsNdControlFlags);
   unsigned int tempForHlen = tcpHobj.hLenNdReservedBitsNdControlFlags & 61440;
   cout<<"\nExtracting HLEN from above : "<<(tempForHlen>>10) ;
   cout<<"\nTCP header Window size : 0x"<<displayInHex(tcpHobj.windowSize);
   cout<<"\nTCP header CheckSum : 0x"<<displayInHex(tcpHobj.checkSum);
   cout<<"\nTCP header Urgent Pointer : 0x"<<displayInHex(tcpHobj.urgentPointer);
  
   //cout<<"\nbye from the program.";
   
}

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

