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
    int deleteElementFromBST(int element);      // method to delete an element from the BST.
    void startInorderTraversal();               // method to start and print inorder traversal of BST.
    void inorderTraversal(node*);               // method to carry out inorder traversal of BST.
    void startPreOrderTraversal();              // method to start and print preorder traversal of BST.
    void preorderTraversal(node*);              // method to carry out preorder traversal of BST.
    void startPostOrderTraversal();             // method to start and print postorder traversal of BST.
    void postorderTraversal(node*);             // method to carry out postorder traversal of BST.
    int minElementFromRight(node*);             // method to find out minimum element from right subtree of current node.
    int maxElementFromLeft(node*);              // method to find out maximum element from left subtree of current node.
    node* deletion(node *root,int x);
    node* FindMIN(node *root);
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

int BST :: deleteElementFromBST(int element)
{
    // first checking whether the root element is pointing to null pointer
    if(root == nullptr)
    {
        printf("\nBinary Search Tree is empty. Cannot delete element.");
        return INT_MIN;
    }
    // proceding from here when root do not point to null pointer.
    node *parentNode;
    node *currentNode;
    currentNode = root;
    parentNode = currentNode;
    while(currentNode!=nullptr)
    {
        if(currentNode->data == element)
        {
            // delete this node
            if(currentNode->left==nullptr&&currentNode->right==nullptr)
            {
                int tempVariableToReturnValue = currentNode->data;
                //currentNode = nullptr;
                delete currentNode;
                currentNode = nullptr;
                printf("\nDeleting --> %d from the BST.",tempVariableToReturnValue);
                return tempVariableToReturnValue;
            }
            if(currentNode->left!=nullptr&&currentNode->right==nullptr)
            {
                int tempVariableToReturnValue = currentNode->data;
                node *tempVariableToStoreCurrentNode = currentNode;
                currentNode = currentNode->left;
                delete tempVariableToStoreCurrentNode;
                return tempVariableToReturnValue;
            }
            if(currentNode->left==nullptr&&currentNode->right!=nullptr)
            {
                int tempVariableToReturnValue = currentNode->data;
                node *tempVariableToStoreCurrentNode = currentNode;
                currentNode = currentNode->right;
                delete tempVariableToStoreCurrentNode;
               return tempVariableToReturnValue;
            }
            // when both child exists
            if(currentNode->left!=nullptr&&currentNode->right!=nullptr)
            {
                int tempVariableToReturnValue = currentNode->data;
               // find minimum element from right child tree
               int minElementFromRightValue = minElementFromRight(currentNode->right);   // finding minimum element from right subtree of root
               deleteElementFromBST(minElementFromRightValue);   // then first delete the minimum element at right subtree of root
               currentNode->data = minElementFromRightValue;   //replace the value at array[parent] with minimum element from right subtree of root,in otherword deleting array[parent]
               return tempVariableToReturnValue;
            }
        }
        else
        {
            if(currentNode->data > element)
            {
                if(currentNode->left!=nullptr)
                {
                    //parentNode = currentNode;
                    //if(parentNode->left->data==element)
                        //parentNode->left = nullptr;
                    currentNode= currentNode->left;
                }
                else
                    break;
            }
            else
            {
                if(currentNode->right!=nullptr)
                {
                    //parentNode = currentNode;
                    //if(parentNode->right->data==element)
                        //parentNode->right = nullptr;
                    currentNode= currentNode->right;
                }
                else
                    break;
            }
        }
    }
    return INT_MIN;
}


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
        inorderTraversal(currentNode->left);
        printf("%d ",currentNode->data);
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


int BST :: minElementFromRight(node *parentNode)             // method to find out minimum element from right subtree of current node.
{
    node *currentNode;
    currentNode = parentNode;
    while(currentNode->left!=nullptr)      // loop untill the left most child of parentNode is reached.
        currentNode = currentNode->left;
    return currentNode->data;               // return value of left most child of parentNode.
}

int BST :: maxElementFromLeft(node *parentNode)              // method to find out maximum element from left subtree of current node.
{
    node *currentNode;
    currentNode = parentNode;
    while(currentNode->right!=nullptr)      // loop untill the right most child of parentNode is reached.
        currentNode = currentNode->right;
    return currentNode->data;               // return value of right most child of parentNode.
}


node* BST::deletion(node *root,int x)
{
    if(root==nullptr)
    {
        std::cout<<"\nBinary Search Tree is Empty.";
        return root;
    }
    else
    {
       if(root->data>x)
        root->left=deletion(root->left,x);
       else
       {
           if(root->data<x)
            root->right=deletion(root->right,x);
           else
           { //ELEMENT MATCHED
               if(root->left==nullptr&&root->right==nullptr)
               {
                   delete root;
                   root=nullptr;
                   std::cout<<"\n"<<x<<" was DELETED SUCCESSFULLY.";
                   return root;
               }
               if(root->left!=nullptr&&root->right==nullptr)
               {
                   node *temp=root;
                   root=root->left;
                   delete temp;
                   std::cout<<"\n"<<x<<" was DELETED SUCCESSFULLY.";
                   return root;
               }
               else
               {  //BOTH THE CHILEDS EXISTS
                   std::cout<<"\n"<<x<<" was DELETED SUCCESSFULLY.";
                   node *temp;
                   temp=FindMIN(root->right);
                   root->data=temp->data;
                   root->right=deletion(root->right,temp->data);

               }  //BOTH THE CHILDS EXISTS
           } //ELEMENT MATCHED
       }
    }
}
node* BST::FindMIN(node *root)
{
    node *t=root;
    while(t->left!=nullptr)
        t=t->left;
    return (t);
}


#endif // BST_CLASS_HEADER_H
