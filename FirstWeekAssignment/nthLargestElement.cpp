// This program is part of C++ training first week assignment
// This program takes input of elements in the array and then finds the nth largest element in the array.
// Time complexity for this program is:
// BestCase : O(nlogn)
// AverageCase : O(nlogn)
// WorstCase : O(n2)
// **************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;

#define maxSize 100005
void quickSort(int inputContainer[],int low,int high);
int partition(int inputContainer[],int low,int high);
void swap(int *a,int *b);

int main()
{
   int inputContainer[maxSize];   // Array storing the input elements
   int sizeOfContainer    // stores the size of inputContainer
      ,nth	 	  // stores the nth largest element to search value input by the user
      ,counter=0	  // keeps track of distinct elements encounted in the sorted array
      ,flagForStop        // this variable is used for identifying that nth largest element is found
      ,choice=0		  // this variable is used for taking choice of user whether want to enter new nth largest element to found value or to exit
      ,inputChoice=0;     // stores the inputChoice - whether want to give input manually or by generating random numbers
   cout<<"\nEnter the number of elements to be inserted in the array = ";
   cin>>sizeOfContainer; //storing size of array
   while(sizeOfContainer>maxSize)
   {
      cout<<"\nEntered size is greater than the maximum size allowed for array.";
      cout<<"\nEnter the number of elements to be inserted in the array = ";
      cin>>sizeOfContainer;
   }
   do
   {
       cout<<"\nDo you manually want to input elements int the array.";
       cout<<"\nPress 1 for : Yes";
       cout<<"\nPress 2 for : No\n";
       cin>>inputChoice;
   }while(inputChoice!=1&&inputChoice!=2);  // loop untill inputChoice is either 1 or 2
   
   if(inputChoice == 1)
   {
       // manually inserting the elements in the array
       for(int iteratingIndex=0;iteratingIndex<sizeOfContainer;iteratingIndex++)
       cin>>inputContainer[iteratingIndex];
   }
   else
   {
      // automatically inserting n elements in the array with the help of random function
      srand(time(0));
      for(int iteratingIndex=0; iteratingIndex < sizeOfContainer;iteratingIndex++)
	 inputContainer[iteratingIndex] = rand(); // rand() generates random number everytime 
   }
   
   // sorting the array
   quickSort(inputContainer,0,sizeOfContainer-1);
   // now printing the sorted array
   cout<<"\nSorted array :\n";
   for(int iteratingIndex=0;iteratingIndex<sizeOfContainer;iteratingIndex++)
     cout<<inputContainer[iteratingIndex]<<" ";
   cout<<"\n";
   while(choice != 2)
   {
      cout<<"\nPress 1 for : Finding nth largest element in the array.";
      cout<<"\nPress 2 for : Exit.\n";
      cin>>choice;
      switch(choice)
      {
	 case 1:
		 cout<<"\nEnter the value of which nth largest to found = ";
   		 cin>>nth;
		 while(nth>maxSize)
		 {
		    cout<<"\nEntered value of nth largest is greater than maximum allowed size for array.";
		    cout<<"\nEnter the value of which nth largest to found = ";
		    cin>>nth; // stores the value of nth largest element to found
		 }
		 counter = 0;  // counter keeps track of number of unique elements encountered till now
		 flagForStop = 0;
		 for(int iteratingIndex=0;iteratingIndex<sizeOfContainer-1;iteratingIndex++) // going till second last element
		 {
		    counter++;  // a distinct unique element is encountered, so incrementing counter
		    if(counter==nth)  // if the distinct unique element is the nth, then show this element of array
		    {
		       cout<<"\nnth largest element is : "<<inputContainer[iteratingIndex]<<"\n";
		       flagForStop=1;  // setting the flagForStop to 1, indicating that we got the nth largest element
		       break;
		    }
		    if(inputContainer[iteratingIndex] == inputContainer[iteratingIndex+1])
		    {
		       while(inputContainer[iteratingIndex] == inputContainer[iteratingIndex+1] && iteratingIndex<sizeOfContainer-1)
		       {
			  iteratingIndex++;
		       }
		    }
		 }
		 // last element is checked manually because, it do not have next element for comparing with next
		 // check manually for last element
		 if(sizeOfContainer>=2)   // this logic is only applicable when array contains more than one element
		 {
		    if(inputContainer[sizeOfContainer-2]!=inputContainer[sizeOfContainer-1])
		    {
			counter++;  // a distinct unique element is encountered, so incrementing counter
			if(counter==nth)  // if the distinct unique element is the nth, then show this element of array
		    	{
		       	   cout<<"\nnth largest element is : "<<inputContainer[sizeOfContainer-1]<<"\n";
		           flagForStop=1;  // setting the flagForStop to 1, indicating that we got the nth largest element
		    	}
		    }
		 }
		 if(sizeOfContainer==1)  // this logic is only applcable when array contains just one element, because no above loop works
                 {
		    counter++;  // a distinct unique element is encountered, so incrementing counter
		    if(counter==nth)  // if the distinct unique element is the nth, then show this element of array
		    {
			cout<<"\nnth largest element is : "<<inputContainer[0]<<"\n";
              		flagForStop=1;  // setting the flagForStop to 1, indicating that we got the nth largest element
		    }
		 }
		 if(flagForStop==0)   // flagForStop was never set means, that we never got nth element
		     cout<<"\nnth largest element does not exist in the array."; 
		 break;
	 case 2:
		 break;
	 default:
		 cout<<"\nInvalid choice entered by the user!";
		 break;
      };
   }
}

void quickSort(int inputContainer[],int low,int high)
{
    if(low < high)
    {
 	/* pi is the partition index, inputContainer[pi] is now at right place */
        int pi = partition(inputContainer,low,high);
  
       // now seperately sort the elements before paritition and after partition
       quickSort(inputContainer,low,pi-1);
       quickSort(inputContainer,pi+1,high);
    }
}

int partition(int inputContainer[],int low,int high)
{
   int pivot = inputContainer[high]; // pivot element
   int indexOfSmallerElement = low-1; // index of smaller element

   for(int iteratingIndex=low; iteratingIndex<= high-1; iteratingIndex++)
   {
      // if current element is smaller than or
      // equal to pivot element
      if(inputContainer[iteratingIndex] <= pivot)
      {
	  indexOfSmallerElement++;   // increment index of smaller element
          swap(&inputContainer[indexOfSmallerElement],&inputContainer[iteratingIndex]);
      }
   }
   swap(&inputContainer[indexOfSmallerElement+1],&inputContainer[high]);
   return  indexOfSmallerElement+1;
}

void swap(int *a, int *b)
{
   int tempVariable = *a;
   *a = *b;
   *b = tempVariable;
}
