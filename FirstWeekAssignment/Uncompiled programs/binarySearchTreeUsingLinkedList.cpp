// This program is part of C++ training first week assignment.
// This program takes input elements and insert it into the Binary Search tree, and provides user with the functionality of inorder,preorder,postorder traversal
// and insertion and deletion of elements option to the user.
// In this program BST is implemented with the help of linked list.

// This program has limitation that, when elements are inserted in increasing order,
// than the BST grows in one direction only, causing time complexity of search operation O(n).
//***************************************************************************************************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BSTClassHeader.h"     /* this header file contains defination of class BST, and struct node.
                                defination of following methods are present inside BST class :-
                                1) insertIntoTree(int)
                                2) startInorderTraversal()
                                3) startPreOrderTraversal()
                                4) startPostOrderTraversal()
                                5) deleteElementFromBST(int)
                                */

using namespace std;

enum userInsertionChoice    // first switch case, case's name
{
    manual=1,   // manual, means manual insertion of elements in the binary search tree.
    automatic,  // automatic, means randomly generated integers insertion  in the binary search tree
};

enum userChoice     // second switch case, case's name
{
    insertElementIntoTree=1,    // Name of case : insert a new element in BST case.
    inorderTraversalOfBST,      // Name of case : inorder traversal of BST.
    preorderTraversalOfBST,     // Name of case : preorder traversal of BST.
    postorderTraversalOfBST,    // Name of case : postorder traversal of BST.
    deleteElementFromBST,       // Name of case : delete element from BST.
    exitFromProgram,            // Name of case : exit from program.
};

int main()
{
    BST object;     // creating object named 'object' of class BST.
    int choice = 0,     // this variable is only use for taking input of second switch case choice.
        insertionChoice = INT_MIN,      // this variable is only use for taking input of first switch case choice.
        intialNumberOfNodes = 0,        // this variable is only use for storing intial number of nodes in the BST.
        element;                        // this variable is used taking input of element to be inserted in BST.

    printf("\nCreateing a new Binary Search Tree :\n");
    printf("\nEnter the number of nodes to be intially inserted in the binary search tree = ");
    scanf("%d",&intialNumberOfNodes);
    do      // loop untill user does not input valid insertion choice 1 nor 2.
    {
        printf("\nPlease select any of the options from below :");
        printf("\nPress 1 for : Inserting initial nodes manually.");
        printf("\nPress 2 for : Inserting initial nodes automatically with random numbers.");
        scanf("%d",&insertionChoice);
        if(insertionChoice!=manual && insertionChoice!= automatic)
            printf("\nIncorrect input entered by the user. Please enter again.");
    }while(insertionChoice!=manual && insertionChoice!= automatic);

    if(insertionChoice == manual)   // checking does user want to manually input elements in the BST
    {
        printf("\nEnter %d elements to be inserted in the binary search tree :\n",intialNumberOfNodes);
        for(int iteratingIndex = 0; iteratingIndex < intialNumberOfNodes ; iteratingIndex++ )
        {
            scanf("%d",&element);
            object.insertIntoTree(element);     // inserting the element into the BST.
        }
    }
    if(insertionChoice == automatic)    // checking does user want to insert randomly generated integers into the BST.
    {
        // automatically inserting n elements in the binary search tree with the help of random function
        srand(time(0));
        for(int index=0; index<intialNumberOfNodes ; index++)
        {
            element = rand(); // rand() generates random number everytime
            printf("%d ==> ",element);
            object.insertIntoTree(element);     // inserting the element into the BST.
        }
    }
    do
    {
        printf("\nPlease select any of the options from below :");
        printf("\nPress 1 for : Inserting an element into the Binary Search Tree.");
        printf("\nPress 2 for : Inorder Traversal of Binary Search Tree.");
        printf("\nPress 3 for : Preorder Traversal of Binary Search Tree.");
        printf("\nPress 4 for : Postorder Traversal of Binary Search Tree.");
        printf("\nPress 5 for : Deleting an element from the Binary Search Tree.");
        printf("\nPress 6 for : Exit from the program.");
        scanf("%d",&choice);
        switch(choice)
        {

        case insertElementIntoTree:
            printf("\nEnter an element to be inserted in the binary search tree = ");
            scanf("%d",&element);
            object.insertIntoTree(element);     // inserting a new element into the BST.
            break;

        case inorderTraversalOfBST:
            object.startInorderTraversal();     // print inorder traversal of BST.
            break;

        case preorderTraversalOfBST:
            object.startPreOrderTraversal();    // print preorder traversal of BST.
            break;

        case postorderTraversalOfBST:           // print postorder traversal of BST.
            object.startPostOrderTraversal();
            break;

        case deleteElementFromBST:
            printf("\nEnter the element to delete from the binary search tree = ");
            scanf("%d",&element);
            object.

            deletion(object.getRoot(),element);
            /*
            if(object.deleteElementFromBST(element) == INT_MIN)     // deleting the entered element from BST, if it is present in the BST
                printf("\n%d element is not present in the binary search tree.",element);   // element is not present in the BST.
            else
                printf("\n%d element is successfully deleted from the binary search tree.",element);    // element successfully deleted.
            */
            break;

        case exitFromProgram:       // exit from the do while loop choice.
            break;

        default:        // if user input any other integer other than 1,2,3,4,5 or 6.
            printf("\nInvalid input entered by the user..");
            break;
        } // enod of swotcj
    }while(choice != exitFromProgram);

    return 0;   // return value by main()
}   // end of main()
