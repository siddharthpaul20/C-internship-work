#ifndef UTILITYFUNCTIONSHEADER_H
#define UTILITYFUNCTIONSHEADER_H

#include<iostream>
#include<cstdio>
#include<string>
#include <sstream>
#include "allTypeDefHeader.h"


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

#endif
