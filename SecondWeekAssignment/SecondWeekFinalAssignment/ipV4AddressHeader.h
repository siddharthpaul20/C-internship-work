#ifndef IPV4_ADDRESS_HEADER_H
#define IPV4_ADDRESS_HEADER_H
using namespace std;

struct ipV4Address
{
   unsigned int ipV4;

   ipAddress()
   {
       ipV4 = 0;
   }

   bool operator<(const ipV4Address& ipAddr) const
   {
        if(this->ipV4 < ipAddr.ipV4)
            return true;
        else
            return false;
   }

   void writeIPAddressToCSVFile(fstream *fout)
    {
        char str[8];
	    unsigned int temp = ntohl(ipV4);
	    unsigned char bytes[4];
        bytes[0] = temp & 0xFF;
        bytes[1] = (temp >> 8) & 0xFF;
        bytes[2] = (temp >> 16) & 0xFF;
        bytes[3] = (temp >> 24) & 0xFF;
        sprintf(str,"%d.%d.%d.%d", bytes[3], bytes[2], bytes[1], bytes[0]);
        *fout<<str;
        *fout<<",";
    }
};

#endif // IPV4_ADDRESS_HEADER_H
