#ifndef IPV6_ADDRESS_HEADER_H
#define IPV6_ADDRESS_HEADER_H

#include "allTypeDefHeader.h"

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
};
#endif // IPV6_ADDRESS_HEADER_H
