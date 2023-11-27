#include "network.h"

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4)
{
    return (oct1 << 24) | (oct2 << 16) | (oct3 << 8) | (oct4 << 0);
}

void extractOctets(ip ipAd, octet& oct1, octet& oct2, octet& oct3, octet& oct4)
{
    oct1 = (ipAd >> 24) & 0xff; // 1111 1111
    oct2 = (ipAd >> 16) & 0xff;
    oct3 = (ipAd >> 8) & 0xff;
    oct4 = (ipAd >> 0) & 0xff;
}

networkType getNetworkType(ip ipAd)
{
    octet oct1, oct2, oct3, oct4;
    
    extractOctets(ipAd, oct1, oct2, oct3, oct4);

    if (oct1 == 127)
    {
        return LOCALHOST;
    }

    if (oct1 == 10)
    {
        return APRIVATE;
    }

    if (oct1 <= 127 && oct1 >= 1)
    {
        return CLASSA;
    }

    if (oct1 == 172 && (oct2 >= 16 && oct2 <= 31))
    {
            return BPRIVATE;
    }

    if (oct1 >= 128 && oct1 <= 191)
    {
        return CLASSB;
    }

    if (oct1 == 192 && oct2 == 168)
    {
        return CPRIVATE;
    }

    if (oct1 >= 192 && oct1 <= 223)
    {
        return CLASSC;
    }

    if (oct1 >= 224 && oct1 <= 239)
    {
        return CLASSD;
    }

    if (oct1 >= 240 && oct1 <= 255)
    {
        return CLASSE;
    }

    return INVALID;
}