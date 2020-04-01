#ifndef BST_CLASS_HEADER_H
#define BST_CLASS_HEADER_H

#include <cstdio>
//#include <iostream>

struct node     // this is a structure representing a single node in the Binary Search Tree.
{
    int data;       // this field stores the integer data inside the single node of BST.
    node *left,     // this field stores the address of left child inside the single node of BST.
         *right;    // this field stores the address of right child inside the single node of BST.

    node()          // no argument constructor.
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    node(int element)       // single argument constructor
    {
        data = element;
        left = nullptr;
        right = nullptr;
    }
};

class BST       // class BST to represent a Binary Search Tree.
{
    node* root;     // private data member storing the address of root node (type struct node) of BST.
public :
    BST()       // constructor for class BST
    {
        root=nullptr;
    }

    node* getRoot()
    {
        return root;
    }
    bool insertIntoTree(int element);           // method to insert a new element in the BST.
    void startInorderTraversal();               // method to start and print inorder traversal of BST.
    void inorderTraversal(node*);               // method to carry out inorder traversal of BST.
    void startPreOrderTraversal();              // method to start and print preorder traversal of BST.
    void preorderTraversal(node*);              // method to carry out preorder traversal of BST.
    void startPostOrderTraversal();             // method to start and print postorder traversal of BST.
    void postorderTraversal(node*);             // method to carry out postorder traversal of BST.
    node* deleteElementFromBST(node *root,int x);      // method to delete an element from the BST.
    node* FindMinElementFromRightSubtree(node *root);      // method to find out minimum element from right subtree of current node.
};

bool BST::insertIntoTree(int element)           // method to insert a new element in the BST.
{
    // first checking whether the root element is pointing to null pointer
    if(root==nullptr)
    {
        // BST is empty.
        // Inserting the new element at the root
        node *temp;
        temp = new(std::nothrow) node(element);
        if(!temp)       // checking memory is allocated to temp or not.
        {
            // nullptr is returned by new
            // memory is not allocated to the node
            printf("\nElement insertion failed.");
            return false;
        }
        else
        {
            // memory is allcoated to the temp node.
            root = temp;    // assigning the temp node to root.
        }
    }
    else
    {
        // BST root is not empty
        // finding the correct position to insert the element
        node *currentNode;      // defining currentNode , pointer to node type, used to iterate over the BST.
        currentNode = root;     // start iterating from the root node of the BST.

        node *temp;             // creating a pointer to node type, temp variable used to store the address of new node containing the element
        temp = new(std::nothrow) node(element);
        if(!temp)       // checking memory is allocated to temp or not.
        {
            // nullptr is returned by new
            // memory is not allocated to the node
            printf("\nElement insertion failed.");
            return false;
        }
        else
        {
            // memory is allcoated to the node.
            while(currentNode != nullptr)       // loop for iterating over BST to find correct position to insert the element.
            {
                if( currentNode->data >= element )      // checking currentNode value is greater or equal than element
                {
                    // element value is less than or equal to the current node
                    // so move to left subtree of the current node
                    if(currentNode->left!=nullptr)      // checking if left child of currentNode exists or not
                    {
                        // left child of currentNode exists
                        currentNode = currentNode->left;    // moving to left child of currentNode
                    }
                    else
                    {
                        // left child of subtree do not exists
                        // now inserting the element at its correct position
                        currentNode->left = temp;
                        break;      // break from the while loop, since element inserted successfully.
                    }
                }
                else
                {
                    // element value is strictly greater than the current node
                    // so move to right subtree of the current node
                    if(currentNode->right!=nullptr)      // checking if right child of currentNode exists or not
                    {
                        // right child of currentNode exists
                        currentNode = currentNode->right;    // moving to right child of currentNode
                    }
                    else
                    {
                        // right child of subtree do not exists
                        // now inserting the element at its correct position
                        currentNode->right = temp;
                        break;      // break from the while loop, since element inserted successfully
                    }
                }
            }   // end of while

        }
    }

    return true;
}   // end of insertIntoTree() method


void BST :: startInorderTraversal()         // method to start and print inorder traversal of BST.
{
    printf("\nInorder Traversal of the Binary Search Tree :\n");
    inorderTraversal(root);         // calling method inorderTraversal() to carry out inorderTraversal.
    printf("\n");
}
void BST :: inorderTraversal(node *currentNode)     // method to carry out inorder traversal of BST.
{
    if(currentNode == nullptr)
    {
        // do nothing
        return ;
    }
    else
    {
        // currentNode is not equal to nullptr
        if( currentNode->left != nullptr)
            inorderTraversal(currentNode->left);
        printf("%d ",currentNode->data);
        if( currentNode->right != nullptr)
            inorderTraversal(currentNode->right);
    }
    return;
}

void BST :: startPreOrderTraversal()         // method to start and print PreOrder traversal of BST.
{
    printf("\nPre Order Traversal of the Binary Search Tree :\n");
    preorderTraversal(root);         // calling method PreOrderTraversal() to carry out PreOrderTraversal.
    printf("\n");
}
void BST :: preorderTraversal(node *currentNode)     // method to carry out PreOrder traversal of BST.
{
    if(currentNode == nullptr)
    {
        // do nothing
        return ;
    }
    else
    {
        // currentNode is not equal to nullptr
        printf("%d ",currentNode->data);
        preorderTraversal(currentNode->left);
        preorderTraversal(currentNode->right);
    }
    return;
}

void BST :: startPostOrderTraversal()         // method to start and print Postrder traversal of BST.
{
    printf("\nPost Order Traversal of the Binary Search Tree :\n");
    postorderTraversal(root);         // calling method PostOrderTraversal() to carry out PostOderTraversal.
    printf("\n");
}
void BST :: postorderTraversal(node *currentNode)     // method to carry out PostOrder traversal of BST.
{
    if(currentNode == nullptr)
    {
        // do nothing
        return ;
    }
    else
    {
        // currentNode is not equal to nullptr
        postorderTraversal(currentNode->left);
        postorderTraversal(currentNode->right);
        printf("%d ",currentNode->data);
    }
    return;
}


node* BST :: deleteElementFromBST(node *currentNode,int element)    // method to delete an element from the BST.
{
    // check if currentNode is pointing to nullptr or not
    if(currentNode==nullptr)
    {
        // CurrentNode is pointing to null pointer.
        printf("\nBinary Search Tree is Empty.");
        return root;
    }
    else
    {
        // root node is not empty
       if( currentNode->data > element )       // if data of currentNode is greater than element value
        currentNode->left= deleteElementFromBST(currentNode->left, element);    // move currentNode to its left child
       else
       {
           if( currentNode->data < element )       // if data of currentNode is less than element value
            currentNode->right= deleteElementFromBST( currentNode->right, element);    // move currentNode to its right child
           else
           { //ELEMENT MATCHED, that is, currentNode->data = element true

               if(currentNode == root )     // checking if the currentNode to be deleted is root node or not
               {
                   // currentNode is root node
                   if( root->left==nullptr && root->right==nullptr )
                   {
                       // when both the child of the currentNode do not exist
                       delete root;      // deleting the node pointed by currentNode, and freeing up the space.
                       root=nullptr;     // assigning null pointer to currentNode
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       return currentNode;
                   }

                   if( currentNode->left!=nullptr && currentNode->right==nullptr )
                   {
                       // when left child exists and right child do not exists.
                       node *temporaryNode= currentNode;        // temporaryNode to store address of currentNode
                       currentNode= currentNode->left;          // make currentNode jump to its left child.
                       delete temporaryNode;            // Deleting the earlier currentNode and freeing up its space.
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       root = currentNode;      // updating root node
                       return currentNode;
                   }

                   if( currentNode->left==nullptr && currentNode->right!=nullptr )
                   {
                       // when right child exists and left child do not exists.
                       node *temporaryNode= currentNode;        // temporaryNode to store address of currentNode
                       currentNode= currentNode->right;          // make currentNode jump to its right child.
                       delete temporaryNode;            // Deleting the earlier currentNode and freeing up its space.
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       root = currentNode;      // updating root node
                       return currentNode;
                   }
                   else
                   {  //BOTH THE CHILEDS EXISTS
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       node *temp;      // temporary node containing the node which is having minimum element from right subtree of currentNode
                       temp= FindMinElementFromRightSubtree(currentNode->right);    // finding and assigning minimum element from right subtree.
                       currentNode->data= temp->data;       // assigning minimum element value from right subtree to currentNode data.
                       currentNode->right= deleteElementFromBST( currentNode->right,temp->data);

                   }  //BOTH THE CHILDS EXISTS
               }
               else
               {
                   if( currentNode->left==nullptr && currentNode->right==nullptr )
                   {
                       // when both the child of the currentNode do not exist
                       delete currentNode;      // deleting the node pointed by currentNode, and freeing up the space.
                       currentNode=nullptr;     // assigning null pointer to currentNode
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       return currentNode;
                   }

                   if( currentNode->left!=nullptr && currentNode->right==nullptr )
                   {
                       // when left child exists and right child do not exists.
                       node *temporaryNode= currentNode;        // temporaryNode to store address of currentNode
                       currentNode= currentNode->left;          // make currentNode jump to its left child.
                       delete temporaryNode;            // Deleting the earlier currentNode and freeing up its space.
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       return currentNode;
                   }

                   if( currentNode->left==nullptr && currentNode->right!=nullptr )
                   {
                       // when right child exists and left child do not exists.
                       node *temporaryNode= currentNode;        // temporaryNode to store address of currentNode
                       currentNode= currentNode->right;          // make currentNode jump to its right child.
                       delete temporaryNode;            // Deleting the earlier currentNode and freeing up its space.
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       return currentNode;
                   }
                   else
                   {  //BOTH THE CHILEDS EXISTS
                       printf("\n%d was DELETED SUCCESSFULLY.",element);
                       node *temp;      // temporary node containing the node which is having minimum element from right subtree of currentNode
                       temp= FindMinElementFromRightSubtree(currentNode->right);    // finding and assigning minimum element from right subtree.
                       currentNode->data= temp->data;       // assigning minimum element value from right subtree to currentNode data.
                       currentNode->right= deleteElementFromBST( currentNode->right,temp->data);

                   }  //BOTH THE CHILDS EXISTS
               }

           } //ELEMENT MATCHED
       }
    }
}
node* BST :: FindMinElementFromRightSubtree(node *parentNode)      // method to find out minimum element from right subtree of current node.
{
    node *currentNode = parentNode;     // currentNode variable is used for traverse the BST from parentNode to reach its leftmost child
    while( currentNode->left != nullptr )
        currentNode = currentNode->left;       // update currentNode to point its left child when it is non-empty.
    return (currentNode);       // returning the leftmost child of parentNode.
}


#endif // BST_CLASS_HEADER_H
