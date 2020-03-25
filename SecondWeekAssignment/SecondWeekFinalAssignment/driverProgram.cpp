#include <iostream>
#include "pcapFileParser.h"

using namespace std;

int main()
{
    char fileName[50];
    printf("\nEnter the pcap file name for parsing : ");
    scanf("%s",&fileName);
    PcapFileParser object;
    object.parse(fileName);
}

