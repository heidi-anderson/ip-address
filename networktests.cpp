#include "..\\catch_amalgamated.hpp"
#include "network.h"

using namespace Catch;

/* compressOctets Test Cases*/
TEST_CASE("compressOctets - testing a class a ip address")
{
    octet oct1 = 122, // 0111 1010
          oct2 = 144, // 1001 0000
          oct3 = 23,  // 0001 0111
          oct4 = 12;  // 0000 1100

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2056263436 == resultIP);
}

TEST_CASE("compressOctets - testing a class a ip address again")
{
    octet oct1 = 127, 
        oct2 = 0, 
        oct3 = 0, 
        oct4 = 1; 
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2130706433 == resultIP);
}


TEST_CASE("compressOctets - testing a class b ip address")
{
    octet oct1 = 151,
          oct2 = 159,
          oct3 = 15,
          oct4 = 20;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2543783700 == resultIP);
}

TEST_CASE("compressOctets - testing a class c ip address")
{
    octet oct1 = 201, // 1100 1001
        oct2 = 134, // 1000 0110
        oct3 = 35,  // 0010 0011
        oct4 = 17;  // 0001 0001

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3381011217 == resultIP);
}

TEST_CASE("compressOctets - testing a class d ip address")
{
    octet oct1 = 235, // 1110 1011
        oct2 = 134, // 1000 0110
        oct3 = 25,  // 0001 1001
        oct4 = 47;  // 0010 1111

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3951434031 == resultIP);
}

TEST_CASE("compressOctets - testing a class e ip address")
{
    octet oct1 = 255, // 1111 1111
        oct2 = 234, // 1110 1010
        oct3 = 215,  // 1101 0111
        oct4 = 147;  // 1001 0011

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(4293580691 == resultIP);
}

/* extractOctets Test cases */
TEST_CASE("extractOctets - testing a class a ip to octet")
{
    ip theIP = 2056263436;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(122 == oct1);
    CHECK(144 == oct2);
    CHECK(23 == oct3);
    CHECK(12 == oct4);
}

TEST_CASE("extractOctets - testing a class b ip to octet")
{
    ip theIP = 2543783700;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(151 == oct1);
    CHECK(159 == oct2);
    CHECK(15 == oct3);
    CHECK(20 == oct4);
}

TEST_CASE("extractOctets - testing a class a ip to octet again")
{
    ip theIP = 2130706433;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(127 == oct1);
    CHECK(0 == oct2);
    CHECK(0 == oct3);
    CHECK(1 == oct4);
}

TEST_CASE("extractOctets - testing a class c ip to octet")
{
    ip theIP = 3381011217;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(201 == oct1);
    CHECK(134 == oct2);
    CHECK(35 == oct3);
    CHECK(17 == oct4);
}

TEST_CASE("extractOctets - testing a class d ip to octet")
{
    ip theIP = 3951434031;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(235 == oct1);
    CHECK(134 == oct2);
    CHECK(25 == oct3);
    CHECK(47 == oct4);
}

TEST_CASE("extractOctets - testing a class e ip to octet")
{
    ip theIP = 4293580691;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(255 == oct1);
    CHECK(234 == oct2);
    CHECK(215 == oct3);
    CHECK(147 == oct4);
}

/* getNetworkType Test Cases */
TEST_CASE("getNetworkType - GIVEN classifying a Class B network including B private")
{
    ip theIP = compressOctets(151, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSB == classified);

    theIP = compressOctets(172, 18, 4, 20);
    classified = getNetworkType(theIP);
    REQUIRE(BPRIVATE == classified);
}

TEST_CASE("getNetworkType - classifying a Class B network including B private")
{
    ip theIP = compressOctets(161, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSB == classified);

    theIP = compressOctets(172, 25, 4, 20);
    classified = getNetworkType(theIP);
    REQUIRE(BPRIVATE == classified);
}

TEST_CASE("getNetworkType - classifying a Class A network including A private")
{
    ip theIP = compressOctets(81, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSA == classified);

    theIP = compressOctets(10, 18, 4, 20);
    classified = getNetworkType(theIP);
    REQUIRE(APRIVATE == classified);
}


TEST_CASE("getNetworkType - classifying a Class C network including C private")
{
    ip theIP = compressOctets(210, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSC == classified);

    theIP = compressOctets(192, 168, 4, 20);
    classified = getNetworkType(theIP);
    REQUIRE(CPRIVATE == classified);
}

TEST_CASE("getNetworkType - classifying a Class D")
{
    ip theIP = compressOctets(230, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSD == classified);
}

TEST_CASE("getNetworkType - classifying a Class E")
{
    ip theIP = compressOctets(250, 159, 15, 20);
    networkType classified = getNetworkType(theIP);
    REQUIRE(CLASSE == classified);
}


