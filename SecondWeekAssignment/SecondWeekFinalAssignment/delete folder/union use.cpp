#include<iostream>
#include <string.h>
#include <map>
using namespace std;

union ip
{
    char ipv4[6];
    char ipv6[18];

    // We compare Test objects by their ids.
    bool operator<(const ip& t1) const
    {
         if(strcmp(this->ipv4,t1.ipv4)<0)
            return true;
         else
            return false;
    }
    bool operator<(const ip& t1) const
    {
         if(strcmp(this->ipv6,t1.ipv6)<0)
            return true;
         else
            return false;
    }
};

int main()
{
    map <ip,int> mymap;
    ip i={"abce"};
    ip ii= {"efgh"};
    ip iii={"aaa"};
    mymap[i]=1;
    mymap[ii]=2;
    mymap[i]++;
    mymap[iii]=0;
    mymap[iii]++;
    mymap[iii]++;
    mymap[iii]++;
    // Printing Test objects in sorted order
    for (auto x : mymap)
        cout << x.first.ipv4 << " " << x.second << endl;
        cout<<"\nbye";
    return 0;
}
