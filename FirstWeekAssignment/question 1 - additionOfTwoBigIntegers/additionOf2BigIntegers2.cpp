// This program is part of C++ training first week assignment
// This program takes two large integers containing upto 4096 digits, and perfroms addition operation.
// ********************************************************************************************************

#include <iostream>
#include "bigInteger.h"
using namespace std;

#define maxSize 4096

int main()
{
    char num1[maxSize]   // stores number1
        ,num2[maxSize];  // stores number2

    BigInteger object;

    printf("\nProgram for addition of two numbers.");
    printf("\nEnter number 1 = ");
    scanf("%s",&num1);
    printf("\nEnter number 2 = ");
    scanf("%s",&num2);
    printf("\n");

   if(num1[0]=='-'&&num2[0]=='-')   // when both the num1 and num2 are negative
   {
	// cleaning the num1, when num1 is of format -0002
        object.cleaningANegativeNumber(num1);
	// cleaning the num2, when num2 is of format -0002
        object.cleaningANegativeNumber(num2);

        printf("\nnum1 --> %s\nnum2 --> %s\n",num1,num2);
	//perform addition of two negative numbers
        object.additionOfTwoNegativeNumber(num1,num2);
   }
   else
   {

       if(num1[0]=='-'||num2[0]=='-')   // when either of the num1 or num2 is negative
       {
           // when num1 is negative
           if(num1[0]=='-')
           {
               // cleaning the num1, when num1 is of format -0002
               object.cleaningANegativeNumber(num1);
               // cleaning the num2, when num2 is of format 0002, num2 is positive number
               object.cleaningAPositiveNumber(num2);
           }
           else    // when num1 is positive, then num2 is negative number
           {
               // cleaning the num2, when num2 is of format -0002
               object.cleaningANegativeNumber(num2);
               // cleaning the num1, when num1 is of format 0002, since num1 is positive number
               object.cleaningAPositiveNumber(num1);
           }

               printf("\nnum1 --> %s\nnum2 --> %s\n",num1,num2);
               //perform subtraction of one positive number and a negative number.
               object.additionOfNegativeNdPositiveNumber(num1,num2);
           }
       else    // when num1 and num2 both are not negative
       {
          if(num1[0]!='-'&&num2[0]!='-')    //when num1 & num2 both are positive
          {
              // cleaning the num1, when num1 is of format 0002, since num1 is positive number
              object.cleaningAPositiveNumber(num1);
                  // cleaning the num2, when num2 is of format 0002, num2 is positive number
              object.cleaningAPositiveNumber(num2);

              // perform addition of two positive number
              object.additionOfTwoPositiveNumber(num1,num2);
          }
       }
   }


}

