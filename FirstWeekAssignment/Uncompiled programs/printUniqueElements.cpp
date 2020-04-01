#include<bits/stdc++.h>
using namespace std;

#define maxSize 100005

int main()
{
   int arr[maxSize];
   int n,inputChoice=0,uniqueFlag;
   cout<<"\nEnter the number of elements to be inserted in the array : ";
   cin>>n;
   while(n>maxSize)
   {
      cout<<"\nEntered number of elements is greater than the maximum size allowed for array.";
      cout<<"\nEnter the number of elements to be inserted in the array : ";
      cin>>n;
   }
   do
   {
       cout<<"\nDo you manually want to input elements int the array.";
       cout<<"\nPress 1 for : Yes";
       cout<<"\nPress 2 for : No";
       cin>>inputChoice;
   }while(inputChoice!=1&&inputChoice!=2);  // loop untill inputChoice is either 1 or 2
   
   if(inputChoice == 1)
   {
       // manually inserting the elements in the array
       for(int iteratingIndex=0;iteratingIndex<n;iteratingIndex++)
       cin>>arr[iteratingIndex];
   }
   else
   {
      // automatically inserting n elements in the array with the help of random function
      srand(time(0));
      for(int iteratingIndex=0; iteratingIndex < n;iteratingIndex++)
	 arr[iteratingIndex] = rand(); // rand() generates random number everytime 
   }
   
   cout<<"\nUnique elements in the array are :\n";
   for(int outIndex=0;outIndex<n;outIndex++)
   {
       uniqueFlag = 1;
       for(int innerIndex=0;innerIndex<n;innerIndex++)   // Applying bussiness logic on each element of array.
       {
	  if(arr[outIndex]==arr[innerIndex] && outIndex !=innerIndex)  // comparing the outIndex element with all the elements in the array except itself
             uniqueFlag=0;					       // for finding whether its unique or not.
       }
       if(uniqueFlag==1)
          cout<<" "<<arr[outIndex];
   }
   cout<<"\n";
}
