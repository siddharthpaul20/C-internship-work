// This program is part of C++ training First week assignment
// This program takes input in two arrays, and then merge the two arrays in sorted order.
// Time complexity for this program is:
// BestCase : O(nlogn)
// AverageCase : O(nlogn)
// WorstCase : O(n2)
// *******************************************************************************************

#include<bits/stdc++.h>
using namespace std;

#define maxSize 100005
void quickSort(int array[],int low,int high);
int partition(int array[],int low,int high);
void swap(int *a,int *b);

int main()
{
   int array1[maxSize]   //array1, input array
      ,array2[maxSize]   //array2, input array
      ,array3[maxSize];  //array3, contains the combined elements of array1 and array2 in sorted order
   int iteratingIndexForArray1   // this variable is used for iterating over the array1 in while loop
      ,iteratingIndexForArray2   // this variable is used for iterating over the array2 in while loop
      ,iteratingIndexForArray3   // this variable is used for iterating over the array3 in while loop
      ,sizeOfArray1     // this variable is used for storing size of array1
      ,sizeOfArray2     // this variable is used for storing size of array2
      ,sizeOfArray3     // this variable is used for storing size of array3
      ,inputChoice=0    // stores the inputChoice - whether want to give input manually or by generating random numbers
      ,printChoice=0;   // stores the printChoice - whether want to print in asecending or descending order.
   do
   {
      cout<<"\nEnter the number of elements to be inserted in the array 1 = ";
      cin>>sizeOfArray1;
      while(sizeOfArray1>maxSize)
      {
         cout<<"\nEntered size is greater than the maximum size allowed for array.";
         cout<<"\nEnter the number of elements to be inserted in the array 1 = ";
         cin>>sizeOfArray1;
      }
      cout<<"\nEnter the number of elements to be inserted in the array 2 = ";
      cin>>sizeOfArray2;
      while(sizeOfArray2>maxSize)
      {
         cout<<"\nEntered size is greater than the maximum size allowed for array.";
         cout<<"\nEnter the number of elements to be inserted in the array 2 = ";
         cin>>sizeOfArray2;
      }
      sizeOfArray3 = sizeOfArray1+sizeOfArray2;
      if(sizeOfArray3> maxSize)
      {
         cout<<"\nThe combined array size is greater than the maximum allowed size for array.";
      }
   }while(sizeOfArray3>maxSize);   // loop while sum of size of array1 and array2 is not less than maxSize

   // now taking input in the arrays
   do
   {
       cout<<"\nDo you manually want to input elements in the array1 and array2.";
       cout<<"\nPress 1 for : Yes";
       cout<<"\nPress 2 for : No";
       cin>>inputChoice;
   }while(inputChoice!=1&&inputChoice!=2);  // loop untill inputChoice is either 1 or 2
   
   if(inputChoice == 1)
   {
       // manually inserting the elements in the array
       cout<<"\nEnter "<<sizeOfArray1<<" elements in the array 1 :\n";
       for(int index=0; index<sizeOfArray1; index++)
       cin>>array1[index];

       cout<<"\nEnter "<<sizeOfArray2<<" elements in the array 2 :\n";
       for(int index=0;index<sizeOfArray2;index++)
       cin>>array2[index];
   }
   else
   {
      // automatically inserting n elements in the array with the help of random function
      srand(time(0));
      for(int index=0; index < sizeOfArray1; index++)
	 array1[index] = rand(); // rand() generates random number everytime 
      for(int index=0; index < sizeOfArray2; index++)
	 array2[index] = rand(); // rand() generates random number everytime
   }

   // sorting array 1
   quickSort(array1,0,sizeOfArray1-1);
   // sorting array 2
   quickSort(array2,0,sizeOfArray2-1);
   
   // initializing the iteratingIndexes to the start of their respecive array
   iteratingIndexForArray1=0;
   iteratingIndexForArray2=0;
   iteratingIndexForArray3=0;
   
   while(iteratingIndexForArray1<sizeOfArray1 && iteratingIndexForArray2<sizeOfArray2)  // loop untill neither of array1 and array2 terminates
   {
      if(array1[iteratingIndexForArray1]<array2[iteratingIndexForArray2])  // if current element of array1 is smaller, then append the array1 current element to array3
      {
	 array3[iteratingIndexForArray3] = array1[iteratingIndexForArray1];
	 iteratingIndexForArray1++;
	 iteratingIndexForArray3++;
      }
      else
      {
	 if(array1[iteratingIndexForArray1]>=array2[iteratingIndexForArray2])  // if current element of array2 is smaller, then append the array2 current element to array3
	 {
	    array3[iteratingIndexForArray3] = array2[iteratingIndexForArray2];
	    iteratingIndexForArray2++;
	    iteratingIndexForArray3++;
	 }
      }
   }
   // any one of the two arrays out of array1 or array2 got terminated,
   // now just to need to remaining elements of the other array which do not got terminated
   
   while(iteratingIndexForArray1<sizeOfArray1)   // if array1 not got terminated, then append the remaining elements of array1 to array1
   {
      array3[iteratingIndexForArray3]= array1[iteratingIndexForArray1];
      iteratingIndexForArray1++;
      iteratingIndexForArray3++;
   }
   while(iteratingIndexForArray2<sizeOfArray2)    // if array2 not got terminated, then append the remaining elements of array2 to array3
   {
      array3[iteratingIndexForArray3]= array2[iteratingIndexForArray2];
      iteratingIndexForArray2++;
      iteratingIndexForArray3++;
   }
   
   // now printing array3
   // ask user for ascending order or descending order
   do
   {
       cout<<"\nPress 1 for : Print Sorted combined array of array1 & array2 in ascending order.";
       cout<<"\nPress 2 for : Print Sorted combined array of array1 & array2 in descending order.";
       cin>>printChoice;
   }while(printChoice!=1&&printChoice!=2);
   if(printChoice==1)
   {
       cout<<"\nAscending order sorted combined array of array1 & array2 is :\n";
       for(int index=0;index<sizeOfArray3;index++)
       cout<<array3[index]<<" ";
       cout<<"\n";
   }
   if(printChoice==2)
   {
       cout<<"\nDescending order sorted combined array of array1 & array2 is :\n";
       for(int index=sizeOfArray3-1;index>=0;index--)
       cout<<array3[index]<<" ";
       cout<<"\n";
   }
}

void quickSort(int array[],int low,int high)
{
    if(low < high)
    {
 	/* pi is the partition index, array[pi] is now at right place */
        int partitionIndex = partition(array,low,high);
  
       // now seperately sort the elements before paritition and after partition
       quickSort(array,low,partitionIndex-1);
       quickSort(array,partitionIndex+1,high);
    }
}

int partition(int array[],int low,int high)
{
   int pivot = array[high]; // pivot element
   int indexOfSmallerElement = low-1; // index of smaller element

   for(int iteratingIndex=low; iteratingIndex<= high-1; iteratingIndex++)
   {
      // if current element is smaller than or
      // equal to pivot element
      if(array[iteratingIndex] <= pivot)
      {
	  indexOfSmallerElement++;   // increment index of smaller element
          swap(&array[indexOfSmallerElement],&array[iteratingIndex]);
      }
   }
   swap(&array[indexOfSmallerElement+1],&array[high]);
   return  indexOfSmallerElement+1;
}

void swap(int *a, int *b)  // swap the values of the arguments
{
   int tempVariable = *a;
   *a = *b;
   *b = tempVariable;
}
