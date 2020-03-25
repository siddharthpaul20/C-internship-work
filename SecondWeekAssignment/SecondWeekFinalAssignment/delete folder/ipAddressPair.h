#ifndef IP_ADDRESS_PAIR_H
#define IP_ADDRESS_PAIR_H

#include <cstring>

struct ipAddressPair
{
   unsigned char sourceIp[16];
   unsigned char destinationIp[16];

    bool operator<(const ipAddressPair& ipAddr) const
    {
        if(memcmp(this->sourceIp,ipAddr.sourceIp,16)<0)
            return true;
        else
        {
            if(memcmp(this->sourceIp,ipAddr.sourceIp,16) > 0)
                return false;
            else
            {
                if(memcmp(this->destinationIp,ipAddr.destinationIp,16)<0)
                    return true;
                else
                    return false;
            }
        }
    }
};

#endif // IP_ADDRESS_PAIR_H
