#include<iostream>
#include <string.h>
#include <map>
using namespace std;

union ip
{
    unsigned int ipv4;
    unsigned short ipv6[8];

    // We compare Test objects by their ids.
    bool operator<(const ip& t1) const
    {
         if(this->ipv4 < t1.ipv4)
            return true;
         else
            return false;
    }
    /*bool operator<(const ip& t1) const
    {
         if(memcmp(this->ipv6,t1.ipv6,8)<0)
            return true;
         else
            return false;
    }*/
};

int main()
{
    map <ip,int> mymap;
    ip i;
    i.ipv6[0]=3890; i.ipv6[1]=3890; i.ipv6[2]=3890; i.ipv6[3]=3890; i.ipv6[4]=3890; i.ipv6[5]=3890; i.ipv6[6]=3890; i.ipv6[7]=3890;
    ip ii= {1234};
    ip iii={5878};
    mymap[i]=1;
    mymap[ii]=2;
    mymap[i]++;
    mymap[iii]=0;
    mymap[iii]++;
    mymap[iii]++;
    mymap[iii]++;
    // Printing Test objects in sorted order
    for (auto x : mymap)
        cout << x.first << " " << x.second << endl;
        cout<<"\nbye";
    return 0;
}
