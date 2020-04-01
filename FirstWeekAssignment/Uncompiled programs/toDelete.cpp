#include<bits/stdc++.h>
using namespace std;
void printStr(char str[]);
char* ret(char str[]);

int hexadecimalToDecimal(string hexVal) 
{    
    int len = hexVal.size(); 
      
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
      
    int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='a' && hexVal[i]<='f') 
        { 
            dec_val += (hexVal[i] - 87)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 


int main()
{
   char str[10] = "-12296";
   printStr(str+1);
   char* sss = ret(str);
   printf("\n%s",sss);
   printf("\n************************");
   printf("\n%d\n",hexadecimalToDecimal("3c"));
}
void printStr(char str[])
{
   printf("%s\n",str);
}

char* ret(char str[])
{
   char* ss=str;
   return str;
} 
