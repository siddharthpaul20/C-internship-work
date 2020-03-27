#ifndef IPV4_KEY_HASHER_HEADER_H
#define IPV4_KEY_HASHER_HEADER_H

#include "ipV4AddressHeader.h"

namespace std
{
    template<>
    //struct ipV4KeyHasher
    struct hash<ipV4Address>
    {
        size_t operator()( const ipV4Address& ip ) const
        {
            // Compute individual hash values for first, second and third
            // http://stackoverflow.com/a/1646913/126995
            size_t res = 17;
            res = res * 31 + hash<unsigned int>()( ip.ipV4 );
            return res;
        }
    };

}

#endif // IPV4_KEY_HASHER_HEADER_H
