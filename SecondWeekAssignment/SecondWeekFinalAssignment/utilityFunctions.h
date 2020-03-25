#ifndef UTILITYFUNCTIONSHEADER_H
#define UTILITYFUNCTIONSHEADER_H

#include<iostream>
#include<cstdio>
#include<string>
#include <sstream>
#include<winsock2.h>
#include<windows.h>
#include "allTypeDefHeader.h"
#include "ipV6AddressHeader.h"


using namespace std;

string displayInHex(uint32 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}
string displayInHex(uint16 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}
string displayInHex(int32 variable)
{
   stringstream ss;
   ss<< hex << variable;
   string res = ss.str();
   return res;
}
string displayInHex(ullint64 variable)
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

void printIPAddress(unsigned char ip[])   // till not used this method anywhere
{

    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
}

void printIPAddress(ipV6Address ip)
{

    printf("%x.%x.%x.%x.%x.%x.%x.%x\n", ntohs(ip.ipV6[0]), ntohs(ip.ipV6[1]), ntohs(ip.ipV6[2]), ntohs(ip.ipV6[3]), ntohs(ip.ipV6[4]), ntohs(ip.ipV6[5]), ntohs(ip.ipV6[6]), ntohs(ip.ipV6[7]) );
}

void printMACAddress(unsigned char bytes[])
{
    //unsigned char bytes[6];
    //bytes[0] = bytes[0] & 0xFF;
    //bytes[1] = bytes[0] & 0xFF;
    //bytes[2] = bytes[0] & 0xFF;
    //bytes[3] = bytes[0] & 0xFF;
    //bytes[4] = bytes[0] & 0xFF;
    //bytes[5] = bytes[0] & 0xFF;
    //bytes[6] = (macAddress >> 48) & 0xFF;
    //bytes[7] = (macAddress >> 56) & 0xFF;
    //printf("%d.%d.%d.%d.%d.%d.%d.%d\n", bytes[7], bytes[6], bytes[5], bytes[4], bytes[3], bytes[2], bytes[1], bytes[0]);
    printf("%x.%x.%x.%x.%x.%x\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5]);

}

#endif
