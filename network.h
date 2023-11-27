#ifndef _NETWORK_H_
#define _NETWORK_H_

//write prototypes, typedefs and enumerated types here

#endif

enum networkType {INVALID, CLASSA, APRIVATE, LOCALHOST,
                  CLASSB, BPRIVATE, CLASSC, CPRIVATE, CLASSD, CLASSE};

typedef unsigned short int octet;
typedef unsigned int ip;

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4);
void extractOctets(ip ipAd, octet& oct1, octet& oct2, octet& oct3, octet& oct4);
networkType getNetworkType(ip ipAd);