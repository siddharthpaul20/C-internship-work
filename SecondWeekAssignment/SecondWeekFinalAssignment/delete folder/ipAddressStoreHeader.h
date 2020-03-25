#ifndef IP_ADDRESS_STORE_HEADER_H
#define IP_ADDRESS_STORE_HEADER_H

#include <cstring>

struct ipAddress
{
   unsigned char ip[16];

        bool operator<(const ipAddress& ipAddr) const
        {
             if(memcmp(this->ip,ipAddr.ip,16)<0)
                return true;
             else
                return false;
        }
};
#endif // IP_ADDRESS_STORE_HEADER_H
