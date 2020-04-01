// This program is part of C++ Training First Week Assignment
// This program takes input from the user in integer array, and print all the unique elements in the array in sorted order
// Time complexity of this proram is O(nlogn)
//****************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

#define maxSize 10005

int main()
{
   int inputContainer[maxSize];   // Array storing the input elements
   int sizeOfContainer    // stores the size of inputContainer
      ,inputChoice=0;     // stores the inputChoice - whether want to give input manually or by generating random numbers
   printf("\nEnter the number of elements to be inserted in the array : ");
   scanf("%d",&sizeOfContainer);    // seting size of inputContainer
   while(sizeOfContainer>maxSize)   // loop untill size of inputContainer is within the maximum size allowed for array.
   {
      printf("\nEntered number of elements is greater than the maximum size allowed for array.");
      printf("\nEnter the number of elements to be inserted in the array : ");
      scanf("%d",&sizeOfContainer);   
   }
   do  // loop untill the inputChoice is neither 1 nor 2
   {
       printf("\nDo you manually want to input elements int the array.");
       printf("\nPress 1 for : Yes");
       printf("\nPress 2 for : No");
       scanf("%d",&inputChoice);
   }while(inputChoice!=1&&inputChoice!=2);  // loop untill inputChoice is either 1 or 2
   if(inputChoice == 1)
   {
       // manually inserting the elements in the array
       for(int iteratingIndex=0;iteratingIndex<sizeOfContainer;iteratingIndex++)
         scanf("%d",&inputContainer[iteratingIndex]);
   }
   else
   {
      // automatically inserting n elements in the array with the help of random function
      srand(time(0));
      for(int iteratingIndex=0; iteratingIndex < sizeOfContainer;iteratingIndex++)
	 inputContainer[iteratingIndex] = rand()%100; // rand() generates random number everytime 
   }
  
   // first sort the array using stl sort function
   sort(inputContainer,inputContainer+sizeOfContainer);

   // Now iterating over the array and finding the unique elements
   printf("\nUnique elements of the array are :\n");
   for(int iteratingIndex =0; iteratingIndex < sizeOfContainer-1; iteratingIndex++)   // Here iterating till second last element
   {
       if(inputContainer[iteratingIndex]==inputContainer[iteratingIndex+1])   // this index element is not unique
       {
	   // this index element is not unique, so skip all its duplicates residing beside it
           while(iteratingIndex<sizeOfContainer && inputContainer[iteratingIndex]==inputContainer[iteratingIndex+1])
		iteratingIndex++;
       }
       else
       {
	   // Element is unique, print this unique element
	   printf("%d ",inputContainer[iteratingIndex]);
       }
   }
   
   // for last element
   int indexOfLastele = sizeOfContainer-1;
   if(sizeOfContainer > 1 && inputContainer[indexOfLastele]!=inputContainer[indexOfLastele-1])
   {
       // last element is unique, print this unique element
       printf("%d ",inputContainer[indexOfLastele]);
   }
   printf("\n");

}
