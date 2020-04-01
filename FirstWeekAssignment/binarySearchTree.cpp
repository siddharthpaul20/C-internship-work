// This program is part of C++ training first week assignment.
// This program takes input elements and insert it into the Binary Search tree, and provides user with the functionality of inorder,preorder,postorder traversal
// and insertion and deletion of elements option to the user.
// In this program BST is impllemented with the help of array.
// Array implementation has a limitation that, when elements are inserted in increasing order, then BST grows only in one direction,
// and in such case at one point it is not able to insert next element in the array, inspite of having empty spaces (in left childs of each node).
// NOTE :- This program is tested on many testcases
// this program misbehaves after no. of nodes in the binary search tree exceeds 100, when all the elements are inserted in increasing order
//***************************************************************************************************************************************************************

#include<bits/stdc++.h>

using namespace std;

#define maxSize 100005
void insertIntoTree(int element,int array[],int *sizeOfTree);   // insert an element into the BST
void inorderTraversal(int array[],int startRoot);   // do inorder traversal of BST
void preorderTraversal(int array[],int startRoot);  // do preorder traversal of BST
void postorderTraversal(int array[],int startRoot);   // do postorder traversal of BST
void deleteElementFromBinarySearchTree(int array[],int element,int *sizeOfTree);   // delete an element from the BST
int maxElementFromLeft(int array[],int startRoot);   // finds the maximum element from the left subtree of a node
int minElementFromRight(int array[],int startRoot);  // finds the minimum element from the right subtree of a node
int main()
{
   // const int maxSize = 100005;
   int array[maxSize];
   int sizeOfArray   // stores the size of array
      ,element	     // stores the input element for the array
      ,choice	     // stores the choice of operation that user want to perform
      ,sizeOfTree=0  // stores the size of tree
      ,inputChoice=0;  // stores the inputChoice - whether want to give input manually or by generating random numbers
   // initialise the array using INT_MIN, so that we can tell whether array[i] is assigned a value or not
   for(int index=0;index<maxSize;index++)
   {
      array[index] = INT_MIN;
   }
   
   cout<<"Enter the number of nodes to be present in the binary search tree = ";
   cin>>sizeOfArray;
   while(sizeOfArray > maxSize) // loop untill the size of the array entered is less than the maximum size allowed for array
   {
      cout<<"\nEntered size is greater than maximum size of array allowed to be created!!!";
      cout<<"\nEnter the number of nodes to be present in the binary search tree = ";
      cin>>sizeOfArray;
   }

   // Inserting elements in the binary search tree
   do
   {
       cout<<"\nDo you manually want to input elements int the array.";
       cout<<"\nPress 1 for : Yes";
       cout<<"\nPress 2 for : No";
       cin>>inputChoice;
   }while(inputChoice!=1&&inputChoice!=2);  // loop untill inputChoice is either 1 or 2
   
   if(inputChoice == 1)
   {
       // manually inserting the elements in the binary search tree
       for(int index=0;index<sizeOfArray;index++)
       {
          cin>>element;
          insertIntoTree(element,array,&sizeOfTree);
       }
   }
   else
   {
      // automatically inserting n elements in the binary search tree with the help of random function
      srand(time(0));
      for(int index=0;index<sizeOfArray;index++)
       {
          element = rand(); // rand() generates random number everytime
          insertIntoTree(element,array,&sizeOfTree);
       }
   }
   
   // showing choices to the user untll exit
   do
   {
      cout<<"\nSelect any of the options from below :";
      cout<<"\n Press 1 for : Inorder traversal of binary search tree.";
      cout<<"\n Press 2 for : Preorder traversal of binary search tree.";
      cout<<"\n Press 3 for : Postorder traversal of binary search tree.";
      cout<<"\n Press 4 for : Insert a new element in  binary search tree.";
      cout<<"\n Press 5 for : Delete a element from binary search tree.";
      cout<<"\n Press 6 for : Exit.\n";
      cin>>choice;
      switch(choice) 
      {
	   case 1:
	   	   cout<<"\nInorder traversal of binary search tree : \n";
		   inorderTraversal(array,0);
		   break;
	   case 2:
		   cout<<"\nPreorder traversal of binary search tree : \n";
		   preorderTraversal(array,0);
		   break;
	   case 3:
		   cout<<"\nPostorder traversal of binary search tree : \n";
		   postorderTraversal(array,0);
		   break;
	   case 4:
		   cout<<"\nInsert a new element in the binary search tree : \n";
                   cout<<"\nEnter the element to be inserted in the binary search tree :";
                   cin>>element;
                   insertIntoTree(element,array,&sizeOfTree);
	 	   break;
	   case 5:
		   cout<<"\nDelete a element from the binary search tree :";
		   cout<<"\nEnter the element to delete from binary search tree :\n";
		   cin>>element;
		   deleteElementFromBinarySearchTree(array,element,&sizeOfTree);
		   break;
           case 6:
		   cout<<"\nExiting the program.\n";
		   break;
	   default:
		   cout<<"\nInvalid choice selected by the user!!!";
		   break;
      };
      //cout<<"\n"<<sizeOfTree<<"\n";

   }while(choice!=6);
   

   cout<<"\n bye from the program";
   
   return 0;
}

void insertIntoTree(int element, int array[],int* sizeOfTree)
{
   int parent = 0;  // parent is variable used for iterating over tree, assinging the index of root of BST
   if(array[parent]==INT_MIN)   // If BST is not assigned any value, means BST is empty
   {
      array[parent] = element;   // assign the element to the root of the BST.
      (*sizeOfTree)++;
      return;
   }
   while(parent < maxSize)   // loop for whole arrary. Its inefficient need to improve performance here.
   {
      if(array[parent] == INT_MIN)  // If the arr[parent] is not assigned any value
      {
	array[parent] = element;    // then assign the value to the arr[parent] and return
	(*sizeOfTree)++;
        return;
      }
      if(array[parent] < element)   // If the arr[parent] is assigned, then go to left or right child based on
      {				  // whether element is greater or less than the root.
	parent = 2 * parent + 2;  // going to right child of root
      }
      else
      {
	if(array[parent] >= element)
    	{
	    parent = 2 * parent + 1;   // going to left child of root
	}
      }
   }

   if(parent>= maxSize)   // if reached the index out of array, display the failure message.
   {
       cout<<"\nNew element cannot be inserted due to no empty space in binary search tree.";
       return;
   }
}

void inorderTraversal(int array[],int startRoot)
{
   if(array[0] == INT_MIN)
   {
      cout<<"\nBinary search tree is empty.";
      return ;
   }
   // write further logic here
   // first check if left child exists or not
   // if startRoot is not null then proceed further 
   if(array[startRoot] == INT_MIN)
   {
      return;
   }
   if(array[ 2 * startRoot + 1 ] != INT_MIN)
   {
     // left child exists
     inorderTraversal(array,2*startRoot+1);
   }
   // now print parent node
   cout<<" "<<array[startRoot];
   // now check if right child exists or not
   if( array[ 2 * startRoot + 2 ] != INT_MIN)
   {
      inorderTraversal(array,2*startRoot+2);
   }
}

void preorderTraversal(int array[], int startRoot)
{
   if(array[0] == INT_MIN)
   {
      cout<<"\nBinary search tree is empty.";
      return ;
   }
   // if startRoot is not null then proceed further
   if(array[startRoot] == INT_MIN)
   {
      return;
   }
   cout<<" "<<array[startRoot];
   // first check if left child exists or not
   if(array[ 2 * startRoot + 1 ] != INT_MIN)
   {
     // left child exists
      preorderTraversal(array,2*startRoot+1);
   }
   // now check if right child exists or not
   if( array[ 2 * startRoot + 2 ] != INT_MIN)
   {
      preorderTraversal(array,2*startRoot+2);
   }

}

void postorderTraversal(int array[],int startRoot)
{
   if(array[0] == INT_MIN)
   {
      cout<<"\nBinary search tree is empty.";
      return ;
   }
   // if startRoot is not null then proceed further
   if(array[startRoot] == INT_MIN)
   {
      return;
   }
   // first check if left child exists or not
   if(array[ 2 * startRoot + 1 ] != INT_MIN)
   {
     // left child exists
      postorderTraversal(array,2*startRoot+1);
   }
   // now check if right child exists or not
   if( array[ 2 * startRoot + 2 ] != INT_MIN)
   {
      postorderTraversal(array,2*startRoot+2);
   }
   cout<<" "<<array[startRoot];
}

void deleteElementFromBinarySearchTree(int array[],int element,int* sizeOfTree)
{
   if(array[0] == INT_MIN)
   {
      cout<<"\nBinary Search Tree is empty.";
      return;
   }
   int parent = 0;   // parent variable is used for iterating over the BST
   while(parent < maxSize)  // loop for whole arrary. Its inefficient need to improve performance here.
   {
      if(array[parent] == element)   // when element to be deleted is matched withe the element at array[parent]
      {
	
	// here we need to write deletion logic
	// when no child exists
	if(array[ 2 * parent + 1 ] == INT_MIN && array[ 2 * parent + 2 ] == INT_MIN)
	{
	   array[parent] = INT_MIN;  // simply replace array[parent] value with default value for deleting
	   (*sizeOfTree)--;   // reducing size of tree after deleting
	}

	// when only left child exists
	if(array[ 2 * parent + 1 ] != INT_MIN && array[ 2 * parent + 2 ] == INT_MIN)
	{
	   // find maximum elementn from left child tree
	   int maxElementFromLeftValue = maxElementFromLeft(array, 2 * parent + 1);   // finding maximum element from left subtree of root
	   deleteElementFromBinarySearchTree(array,maxElementFromLeftValue,sizeOfTree);   // then first delete the maximum element at left subtree of root
	   array[parent] = maxElementFromLeftValue;    //replace the value at array[parent] with maximum element from left subtree of root,in otherword deleting array[parent]
	}
	// when only right child exists
	if(array[ 2 * parent + 1 ] == INT_MIN && array[ 2 * parent + 2 ] != INT_MIN)
	{
	   // find minimum element from right child tree
	   int minElementFromRightValue = minElementFromRight(array, 2 * parent + 2);   // finding minimum element from right subtree of root
	   deleteElementFromBinarySearchTree(array,minElementFromRightValue,sizeOfTree);   // then first delete the minimum element at right subtree of root
	   array[parent] = minElementFromRightValue;  //replace the value at array[parent] with minimum element from right subtree of root,in otherword deleting array[parent]
	}
	// when both child exists
	if(array[ 2 * parent + 1 ] != INT_MIN && array[ 2 * parent + 2 ] != INT_MIN)
	{
	   // find minimum elementn from right child tree
	   int minElementFromRightValue = minElementFromRight(array, 2 * parent + 2);   // finding minimum element from right subtree of root
	   deleteElementFromBinarySearchTree(array,minElementFromRightValue,sizeOfTree);   // then first delete the minimum element at right subtree of root
	   array[parent] = minElementFromRightValue;   //replace the value at array[parent] with minimum element from right subtree of root,in otherword deleting array[parent]
	}
	

        return ;
      }
      else       // if array[parent] is not matched with elemen to delete, then proceed to left or right child of root.
      {
	  if(array[parent] < element)
          {
	    parent = 2 * parent + 2;  // poroceeding to right child of root.
          }
          else
          {
	     if(array[parent] >= element)   // proceeding to left child of root.
    	     {
	        parent = 2 * parent + 1;
	     }
          }
      }
   }

}

int maxElementFromLeft(int array[],int startRoot)  // finds maximum element from the left subtree of root
{
   int maxElement = array[startRoot];
   int parent = 2 * startRoot + 2;

   while(array[parent] != INT_MIN)  // loop untill the rightmost leave in the left subtree is reached and update maxElement
   {
      maxElement = array[parent];
      parent = 2 * parent + 2;
   }
   return maxElement;
}

int minElementFromRight(int array[],int startRoot)  // finds minimum element from the right subtree of root
{
   int minElement = array[startRoot];
   int parent = 2 * startRoot + 1;

   while(array[parent] != INT_MIN)  // loop untill the  leftmost leave in the right subtree is reached and update minElement
   {
      minElement = array[parent];
      parent = 2 * parent + 1;
   }
   return minElement;
}
