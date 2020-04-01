// This program is part of C++ training first week assignment
// This program takes two large integers containing upto 4096 digits, and perfroms addition operation.
// ********************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

#define maxSize 4096
char answer[maxSize];    // stores the answer of addition operation

void additionOfTwoPositiveNumber(char num1[],char num2[]);
void additionOfTwoNegativeNumber(char num1[],char num2[]);
void additionOfNegativeNdPositiveNumber(char num1[],char num2[]);
char* subtractTwoPositiveNumber(char num1[],char num2[]);
void swap(char** num1, char** num2);        // swap the two number
bool isSmaller(char num1[],char num2[]);    // checks if num1 is smaller than num2?

void cleaningAPositiveNumber(char num[]);   // removes preceding 0's
void cleaningANegativeNumber(char num[]);   // removes 0's between '-' and first non zero digit

int main()
{
    char num1[maxSize]   // stores number1
        ,num2[maxSize];  // stores number2
    printf("\nProgram for addition of two numbers.");
    printf("\nEnter number 1 = ");
    scanf("%s",&num1);
    printf("\nEnter number 2 = ");
    scanf("%s",&num2); 
    printf("\n");
    
   if(num1[0]=='-'&&num2[0]=='-')   // when both the num1 and num2 are negative
   {
	// cleaning the num1, when num1 is of format -0002
        cleaningANegativeNumber(num1);
	// cleaning the num2, when num2 is of format -0002
        cleaningANegativeNumber(num2);

        printf("\nnum1 --> %s\nnum2 --> %s\n",num1,num2);
	//perform addition of two negative numbers
        additionOfTwoNegativeNumber(num1,num2);
   }
   else
   {
       
       if(num1[0]=='-'||num2[0]=='-')   // when either of the num1 or num2 is negative
       {
	   // when num1 is negative
	   if(num1[0]=='-')
	   {
	       // cleaning the num1, when num1 is of format -0002
	       cleaningANegativeNumber(num1);
	       // cleaning the num2, when num2 is of format 0002, num2 is positive number
               cleaningAPositiveNumber(num2);
	   }
	   else    // when num1 is positive, then num2 is negative number
	   {
	       // cleaning the num2, when num2 is of format -0002
	       cleaningANegativeNumber(num2);
	       // cleaning the num1, when num1 is of format 0002, since num1 is positive number
	       cleaningAPositiveNumber(num1);
	   }

           printf("\nnum1 --> %s\nnum2 --> %s\n",num1,num2);
	   //perform subtraction of one positive number and a negative number.
           additionOfNegativeNdPositiveNumber(num1,num2);
       }
       else    // when num1 and num2 both are not negative
       {
	  if(num1[0]!='-'&&num2[0]!='-')    //when num1 & num2 both are positive
          {
	      // cleaning the num1, when num1 is of format 0002, since num1 is positive number
	      cleaningAPositiveNumber(num1);
              // cleaning the num2, when num2 is of format 0002, num2 is positive number
              cleaningAPositiveNumber(num2);
	      
	      // perform addition of two positive number
	      additionOfTwoPositiveNumber(num1,num2);
	  }
       }
   }
   

}

void additionOfTwoPositiveNumber(char num1[],char num2[])
{
   //printf("\nInside function additionOfTwoPositiveNumber.");
   int sizeOfNum1,sizeOfNum2,sizeOfAnswer,differenceOfSize,sum,carry=0;
   sizeOfNum1 = strlen(num1);
   sizeOfNum2 = strlen(num2);
   
   // when size of num2 is greater than the size of num1, swap the 2
   if(sizeOfNum2 > sizeOfNum1)
   {
      swap(&num1,&num2);
   }
   // now always sizeOfNum1 >= sizeOfNum2
   // again assigning sizeOfNum bcoz any change may happen
   sizeOfNum1 = strlen(num1);
   sizeOfNum2 = strlen(num2);   
   differenceOfSize = sizeOfNum1 - sizeOfNum2;
   // Now adding digits of num1 and num2 starting from rightmost digits
   int iteratingIndexOfAnswer = -1;   // index responsible for appending char in answer char array.
   for(int iteratingIndexOfNum2 = sizeOfNum2-1; iteratingIndexOfNum2 >= 0; iteratingIndexOfNum2--)
   {
       sum = (num1[iteratingIndexOfNum2+differenceOfSize]-'0') + (num2[iteratingIndexOfNum2]-'0') + carry;  // computing sum of corressponding digits
       answer[++iteratingIndexOfAnswer] = sum%10 + '0';
       carry = sum/10;
   }
   
   // now adding remaining digits of num1[]
   for(int iteratingIndexOfNum1 = sizeOfNum1 - sizeOfNum2 - 1; iteratingIndexOfNum1 >=0; iteratingIndexOfNum1--)
   {
       sum = (num1[iteratingIndexOfNum1]-'0') + carry;   //computing sum
       answer[++iteratingIndexOfAnswer] = sum%10 + '0';
       carry = sum/10;
   }
   // now adding remaing carry
   if(carry)
   {
      answer[++iteratingIndexOfAnswer] = carry+'0';
   }
   // now appending '\0' at the end of answer char[]
   answer[++iteratingIndexOfAnswer] = '\0';
   sizeOfAnswer = iteratingIndexOfAnswer;
   printf("\nResult of Addition ----> : ");
   for(int iteratingIndex = sizeOfAnswer-1; iteratingIndex >=0; iteratingIndex--)
   {
       printf("%c",answer[iteratingIndex]);
   }
   printf("\n");
   
}

void additionOfTwoNegativeNumber(char num1[],char num2[])
{
   //printf("\nInside function additionOfTwoNegativeNumber.");
   int sizeOfNum1,sizeOfNum2,sizeOfAnswer,differenceOfSize,sum,carry=0;
   sizeOfNum1 = strlen(num1);
   sizeOfNum2 = strlen(num2);
   // when size of num2 is greater than the size of num1, swap the 2
   if(sizeOfNum2 > sizeOfNum1)
   {
      swap(&num1,&num2);
      //printf("\nInside swap.");
      //printf("\nNumber 1 : %s",num1);
      //printf("\nNumber 2 : %s",num2);
   }
   // now always sizeOfNum1 >= sizeOfNum2
   // again assigning sizeOfNum bcoz any change may happen
   sizeOfNum1 = strlen(num1);
   sizeOfNum2 = strlen(num2);   
   differenceOfSize = sizeOfNum1 - sizeOfNum2;
   // Now adding digits of num1 and num2 starting from rightmost digits
   int iteratingIndexOfAnswer = -1;   // index responsible for appending char in answer char array.
   for(int iteratingIndexOfNum2 = sizeOfNum2-1; iteratingIndexOfNum2 >= 1; iteratingIndexOfNum2--)   // gone till index 1, bcoz index 0 contains '0'
   {
       sum = (num1[iteratingIndexOfNum2+differenceOfSize]-'0') + (num2[iteratingIndexOfNum2]-'0') + carry;  // computing sum of corressponding digits
       answer[++iteratingIndexOfAnswer] = sum%10 + '0';
       carry = sum/10;
   }
   
   // now adding remaining digits of num1[]
   for(int iteratingIndexOfNum1 = sizeOfNum1 - sizeOfNum2 - 1; iteratingIndexOfNum1 >=1; iteratingIndexOfNum1--)   // gone till index 1, bcoz index 0 contains '0'
   {
       sum = (num1[iteratingIndexOfNum1]-'0') + carry;
       answer[++iteratingIndexOfAnswer] = sum%10 + '0';
       carry = sum/10;
   }
   // now adding remaing carry
   if(carry)
   {
      answer[++iteratingIndexOfAnswer] = carry+'0';
   }
   // adding '-' at the last of answer, to make it negative number
   answer[++iteratingIndexOfAnswer]='-';
   sizeOfAnswer = iteratingIndexOfAnswer + 1;
   printf("\nResult of Addition ----> : ");
   for(int iteratingIndex = sizeOfAnswer-1; iteratingIndex >=0; iteratingIndex--)
   {
       printf("%c",answer[iteratingIndex]);
   }
   printf("\n");
}

void additionOfNegativeNdPositiveNumber(char num1[],char num2[])
{
   //printf("\nInside function additionOfNegativeNdPositiveNumber.");
   // first identifying the number containing '-' sign
   if(num1[0]=='-')
   {
       char* answer=subtractTwoPositiveNumber(num1+1,num2);
       int sizeOfAnswer = strlen(answer);
       if(isSmaller(num1+1,num2))
       {
          // num1 which is negative is smaller in magnitude
          // answer will contain no '-' sign
          printf("\nResult of Addition ----> : ");
          for(int iteratingIndex = sizeOfAnswer-1; iteratingIndex >=0; iteratingIndex--)
          {
             printf("%c",answer[iteratingIndex]);
          }
          printf("\n"); 
       }
       else
       {
	  // num1 which is negative is larger in magnitude
          // answer will contain '-' sign
	  printf("\nResult of Addition ----> : -");
          for(int iteratingIndex = sizeOfAnswer-1; iteratingIndex >=0; iteratingIndex--)
          {
             printf("%c",answer[iteratingIndex]);
          }
          printf("\n");
       }
   }
   else   // num2[0] is equal to '-'
   {
       char* answer=subtractTwoPositiveNumber(num1,num2+1);
       int sizeOfAnswer = strlen(answer);
       if(isSmaller(num1,num2+1))
       {
          // num1 which is positive is smaller in magnitude
          // answer will contain '-' sign
          printf("\nResult of Addition ----> : -");
          for(int iteratingIndex = sizeOfAnswer-1; iteratingIndex >=0; iteratingIndex--)
          {
             printf("%c",answer[iteratingIndex]);
          }
          printf("\n");
       }
       else
       {
	  // num1 which is positive is larger in magnitude
          // answer will contain no '-' sign
	  printf("\nResult of Addition ----> : ");
          for(int iteratingIndex = sizeOfAnswer-1; iteratingIndex >=0; iteratingIndex--)
          {
             printf("%c",answer[iteratingIndex]);
          }
          printf("\n");
       }
   }
}

char* subtractTwoPositiveNumber(char num1[],char num2[])
{
   // first make sure num1 is greater than num2
   if(isSmaller(num1,num2))   // checks whether num1 isSmaller than num2 ?
   {
      swap(&num1,&num2);
   }
   
   // now num1 is greater (or equal) than num2 in size as well as valuewise
   int sizeOfNum1,sizeOfNum2,sizeOfAnswer,differenceOfSize,sub,carry=0;
   sizeOfNum1 = strlen(num1);
   sizeOfNum2 = strlen(num2);
   differenceOfSize = sizeOfNum1 - sizeOfNum2;
   // Now subtracting digits of num1 and num2 starting from rightmost digits
   int iteratingIndexOfAnswer = -1;
   for(int iteratingIndexOfNum2 = sizeOfNum2-1; iteratingIndexOfNum2 >= 0; iteratingIndexOfNum2--)   // gone till index 1, bcoz index 0 contains '0'
   {
       sub = (num1[iteratingIndexOfNum2+differenceOfSize]-'0') - (num2[iteratingIndexOfNum2]-'0') - carry;
       if(sub < 0)
       {
	  answer[++iteratingIndexOfAnswer] = (sub+10) + '0';
          carry = 1;  
       }
       else
       {
	  answer[++iteratingIndexOfAnswer] = sub + '0';
          carry = 0;
       }
   }
   
   // now  remaining digits of num1[]
   for(int iteratingIndexOfNum1 = sizeOfNum1 - sizeOfNum2 - 1; iteratingIndexOfNum1 >=0; iteratingIndexOfNum1--)   // gone till index 1, bcoz index 0 contains '0'
   {
       if(num1[iteratingIndexOfNum1] =='0' && carry)
       {
           answer[++iteratingIndexOfAnswer] = '9';
           continue;
       }
       sub = (num1[iteratingIndexOfNum1]-'0') - carry;
       if(iteratingIndexOfNum1 >0 || sub > 0)
       {
	  answer[++iteratingIndexOfAnswer] = sub + '0';
            
       }
       carry = 0;
   }
   answer[++iteratingIndexOfAnswer]='\0';
   return answer;
}

void swap(char** num1, char** num2)
{
    char* tempVariable;
    tempVariable=*num2;
    *num2 = *num1;
    *num1 = tempVariable;
}

bool isSmaller(char num1[],char num2[])   // checks whether num1 isSmaller than num2 ?
{
    int sizeOfNum1,sizeOfNum2;
    sizeOfNum1 = strlen(num1);
    sizeOfNum2 = strlen(num2);
    if(sizeOfNum2 > sizeOfNum1)   // when size of num2 is greater, then num1 is smaller
       return true;
    else
    {
       if(sizeOfNum1==sizeOfNum2)   // when size of num1 and num2 are equal
       {
	  // compare individual digits, and as soon as we get digit of num2 > digit of num1, we return true
	  for(int iteratingIndex = 0;iteratingIndex < sizeOfNum1;iteratingIndex++)
	  {
	     if(num1[iteratingIndex] < num2[iteratingIndex])
                return true;
	     else
	     {
		if(num1[iteratingIndex] > num2[iteratingIndex])  // we get digit of num1 > digit of num2, we return false, since here num1 is greater than num2
   		    return false;
	     }
	  }
          // reached till here means num1 is equal to num2
          return false;
       }
       else
       {
	   // sizeOfNum1 is strictly greater than sizeOfNum2
  	   return false;
       }
    }
}

void cleaningAPositiveNumber(char num[])
{
    // cleaning the num1, when num1 is of format 0002, since num1 is positive number
    if(num[0]=='0')
    {
	int iteratingIndexForNum = 0;   // starting with 0th index, since at 0th index no '-' is present
	while(num[iteratingIndexForNum]=='0')
             iteratingIndexForNum++;
        // now shifiting right hand side digits of starting non-usefuls zeroes in place of preceding zeroes
	int indexForRemovingZerosFromNum = 0;
        while(num[iteratingIndexForNum]!='\0')
        {
	    num[indexForRemovingZerosFromNum] = num[iteratingIndexForNum];
	    ++iteratingIndexForNum;
	    ++indexForRemovingZerosFromNum;
	}
        // apending '\0' at last of num1
	           num[indexForRemovingZerosFromNum] = '\0';
    }
}

void cleaningANegativeNumber(char num[])
{
    // cleaning the num, when num is of format -0002
    if(num[1]=='0')
    {
	int iteratingIndexForNum = 1;
	while(num[iteratingIndexForNum]=='0')   // starting with 1th index, since at 0th index '-' is present
              iteratingIndexForNum++;
        // now shifiting right hand side digits of starting non-usefuls zeroes in place of preceding zeroes
	int indexForRemovingZerosFromNum = 1;
        while(num[iteratingIndexForNum]!='\0')
        {
	    num[indexForRemovingZerosFromNum] = num[iteratingIndexForNum];
	    ++iteratingIndexForNum;
	    ++indexForRemovingZerosFromNum;
	}
        // apending '\0' at last of num1
	num[indexForRemovingZerosFromNum] = '\0';
    }
}
