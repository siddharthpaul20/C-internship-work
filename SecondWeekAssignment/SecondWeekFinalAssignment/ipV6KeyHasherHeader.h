#ifndef IPV6_KEY_HASHER_HEADER_H
#define IPV6_KEY_HASHER_HEADER_H

#include "ipV6AddressHeader.h"

namespace std
{
    template<>
    //struct ipV6KeyHasher
    struct hash<ipV6Address>
    {
        size_t operator()( const ipV6Address& ip ) const
        {
            // Compute individual hash values for first, second and third
            // http://stackoverflow.com/a/1646913/126995
            size_t res = 17;
            res = res * 31 + hash<unsigned short>()( ip.ipV6[0] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[1] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[2] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[3] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[4] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[5] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[6] );
            res = res * 31 + hash<unsigned short>()( ip.ipV6[7] );

            return res;
        }
    };

}

#endif // IPV6_KEY_HASHER_HEADER_H

