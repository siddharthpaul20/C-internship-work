#ifndef IPV6_ADDRESS_HEADER_H
#define IPV6_ADDRESS_HEADER_H


#include "allTypeDefHeader.h"

using namespace std;

struct ipV6Address
{
    uint16 ipV6[8];

    ipV6Address()
    {
        ipV6[0] = 0;
        ipV6[1] = 0;
        ipV6[2] = 0;
        ipV6[3] = 0;
        ipV6[4] = 0;
        ipV6[5] = 0;
        ipV6[6] = 0;
        ipV6[7] = 0;
    }


    void writeIPAddressToCSVFile(fstream *fout)
    {
        char str[8];

        for(int iteratingIndex = 0; iteratingIndex < 8; iteratingIndex++)
        {
            uint16 twoBytes = ntohs(ipV6[iteratingIndex]);
            sprintf(str,"%x.",twoBytes);
            *fout<<str;
        }
        *fout<<",";

    }

    bool operator==(const ipV6Address &other) const
    {
        return (   this->ipV6[0] == other.ipV6[0]
                && this->ipV6[1] == other.ipV6[1]
                && this->ipV6[2] == other.ipV6[2]
                && this->ipV6[3] == other.ipV6[3]
                && this->ipV6[4] == other.ipV6[4]
                && this->ipV6[5] == other.ipV6[5]
                && this->ipV6[6] == other.ipV6[6]
                && this->ipV6[7] == other.ipV6[7]);
    }

    bool operator<(const ipV6Address& ipAddr) const
    {
         if(this->ipV6[0] < ipAddr.ipV6[0])
             return true;
         else
             {
                 if(this->ipV6[0] > ipAddr.ipV6[0])
                    return false;
                 else
                 {
                     if(this->ipV6[1] < ipAddr.ipV6[1])
                        return true;
                     else
                     {
                         if(this->ipV6[1] > ipAddr.ipV6[1])
                            return false;
                         else
                         {
                             if(this->ipV6[2] < ipAddr.ipV6[2])
                                return true;
                             else
                             {
                                 if(this->ipV6[2] > ipAddr.ipV6[2])
                                    return false;
                                 else
                                 {
                                     if(this->ipV6[3] < ipAddr.ipV6[3])
                                        return true;
                                     else
                                     {
                                         if(this->ipV6[3] > ipAddr.ipV6[3])
                                            return false;
                                         else
                                         {
                                             if(this->ipV6[4] < ipAddr.ipV6[4])
                                                return true;
                                             else
                                             {
                                                 if(this->ipV6[4] > ipAddr.ipV6[4])
                                                    return false;
                                                 else
                                                 {
                                                     if(this->ipV6[5] < ipAddr.ipV6[5])
                                                        return true;
                                                     else
                                                     {
                                                         if(this->ipV6[5] > ipAddr.ipV6[5])
                                                            return false;
                                                         else
                                                         {
                                                             if(this->ipV6[6] < ipAddr.ipV6[6])
                                                                return true;
                                                             else
                                                             {
                                                                 if(this->ipV6[6] > ipAddr.ipV6[6])
                                                                    return false;
                                                                 else
                                                                 {
                                                                     if(this->ipV6[7] < ipAddr.ipV6[7])
                                                                        return true;
                                                                     else
                                                                        return false;
                                                                 }
                                                             }
                                                         }
                                                     }
                                                 }
                                             }
                                         }
                                     }
                                 }
                             }
                         }
                     }
                 }
             }
    }

};
#endif // IPV6_ADDRESS_HEADER_H
