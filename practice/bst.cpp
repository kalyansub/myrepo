/* Code to learn how to build Binary Search Tree and associated funtions.
   This topic seems to be a frequently occurring theme in SW interviews;
   Points to note: A binary tree is made of nodes, where each node contains a
   "left" pointer, a "right" pointer, and a data element. The "root" pointer 
    points to the topmost node in the tree. The left and right pointers recursively 
    point to smaller "subtrees" on either side. A Binary Search Tree (BST) is a special
    case of a Binary Tree, where nodes are sorted in some order, e.g., the top most 
   (root) node is the largest, the next smaller or equal (<=) node gets added to the 
   left and the next larger node (>) (compared to the root), gets added to the right, 
   and so forth recursively, until there are no more nodes.
   BSTs are fast at insert and lookup, as they basically use a binary search to find
   a node in O(log(N)) time.Therefore BSTs are good for dictionary problems.

   $Author$: Kalyan Subramanian
   $email$: kalyan dot sub at gmail
   $Date$: Aug 21, 2014.
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/* Basic Binary Tree structure: the current node (parent) has a left child and 
   a right child node 
*/
typedef struct Node Node;
typedef struct Node* NodePtr;
struct Node
{
    int data;
    NodePtr left;
    NodePtr right;
};

//function prototypes:
NodePtr createNode(int data);
NodePtr insert(NodePtr node, int data);
NodePtr build123a();
NodePtr build123b();
NodePtr build123c();
int sizeOfTree( NodePtr node);
int maxDepth(NodePtr node);
int minValue(NodePtr node);

inline int maximum(int a, int b)
{
    return (a>b)?a:b;
}


// Helper function that alloates and inserts a node in the BST
NodePtr createNode(int data)
{
 NodePtr node = new(Node); 
 node->data = data;
 node->left = NULL;
 node->right = NULL;

 return(node);
}

/*
 Given a BST tree and a datum, inserts a new node
 with the given datum in the correct place in the tree.
 Returns the new root pointer which the caller should
 then use...
*/
NodePtr insert(NodePtr node, int data)
{
    if (node == NULL)
    {
        return (createNode(data));
    }
    else
    {
       if (data <= node->data) // lte case, go left
       {
           node->left =  insert(node->left, data);
       }
       else// gt case, go right
       {
           node->right= insert(node->right, data);
       }
    }
    return node;
}

NodePtr build123a()
{
    NodePtr root = createNode(2);
    NodePtr lChild = createNode(1);
    NodePtr rChild = createNode(3);
    
    root->left = lChild;
    root->right = rChild;

    return root;
}

NodePtr build123b()
{
    NodePtr root = NULL;

    root = createNode(2);
    root->left = createNode(1); 
    root->right = createNode(3); 

    return root;
}

NodePtr build123c()
{
     NodePtr root = NULL;
     root = insert(root, 2);
     root = insert(root, 1);
     root = insert(root, 3);

     return root;
}

/* Calculate the number of nodes in the tree */
int sizeOfTree( NodePtr node)
{
    int numNodes;
    
    if ( node == NULL )
    {
        numNodes = 0;
    }
    else
    {
        numNodes = sizeOfTree( node->left) + 1 + sizeOfTree( node-> right);
    }
    return numNodes;
}

/* Given a binary tree, find a datum: return true if the datum is foound in one of the
   nodes of the tree; recusively traverse the nodes, choosing left or right by comparing the
   sought for value to the current node: 
*/
static int lookup(NodePtr startNode, int target)
{
    cout << "lookup(): startNode->data = " << startNode->data << "\n";
    // 1. base case: empty tree, so retrun false right away:
    if (startNode == NULL)
    {
        return false;
    } 
    else
    {
        if ( target == startNode->data ) // if we found it here, great !
        {
            cout << "lookup(): got it !\n";
            return true;
        }
        if (target < startNode->data) // lte case, recurse left
        {
            cout << "lookup(): going left: target =" << target << "data = " << startNode->data << "\n";
            return (lookup(startNode->left, target));
        }
        else  // gt case, recurse right
        {
            cout << "lookup(): going right: target =" << target << "data = " << startNode->data << "\n";
            return (lookup(startNode->right, target));
        }
    }
}

/* Find the maximum depth of the BST: remember, the top node counts as 1 too! */
int maxDepth(NodePtr node)
{
    int maxD;

    if (node == NULL)
    {
       maxD = 0;
    }
    else
    {
        int leftD  = maxDepth(node->left);
        int rightD = maxDepth(node->right);

        maxD = (maximum(leftD, rightD) + 1);
    }

   return maxD;
}

/* Find the smallest value of the data stored in the BST: NB: you DON'T have to search the entire
   tree, since it is stored with decreasing values on the eft branches...*/
int minValue(NodePtr node)
{
    NodePtr cur = node;
   /* Start with the current node and travel left till you hit a NULL: 
      the smallest item is a minimum value naturally!
    */ 
    while(cur->left != NULL)
    {
        cur = cur->left;
    } 
    return cur->data;
}
 
/* Inorder traversal: from root to left child, right child ... 
   prints the data elements in increasing sorted order.
*/
void printTree(NodePtr node)
{
   if( node == NULL ) 
   { 
       cout << "\n";
       return;
   } 
   printTree(node->left);
   cout <<  node->data << "," ;
   printTree(node->right); 
}

/* Postorder traversal: from leaf left child, right child, parent ... 
   prints the data elements in decreasing sorted order.
*/
void postOrderprintTree(NodePtr node)
{
   if( node == NULL ) 
   { 
       cout << "\n";
       return;
   } 
   /* First recursively travel each subtree, left then right: */
   printTree(node->left);
   printTree(node->right); 
   /* Thn deal with the parent node */
   cout <<  node->data << "," ;
}

/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum. Strategy: subtract the node value from the sum when 
 recursing down, and check to see if the sum is 0 when you run out of tree.
*/
int hasPathSum(NodePtr node, int sum)
{
    // return true if we ran out of tree and the sum went down to 0
    if(node == NULL)
    {
        return sum==0;
    }
    else //otherwise, check both subtrees
    {
        int subTreeSum = sum - node->data;
        return (hasPathSum(node->left, subTreeSum) || \
                 hasPathSum(node->right, subTreeSum));
    }
}

int main(int argc, char* argv[])
{
   NodePtr aNode = build123a(); 
   int target = 3;
   int size = sizeOfTree(aNode);

   cout << "size of tree so far is " << size << "\n";
   if (lookup(aNode, 3))
   {
       cout << "Found " << target << "\n";
   }
   else
   {
       cout << "Could not find " << target << "\n";
   }

   cout << "maximum depth of the BST = " << maxDepth(aNode) << "\n";

   cout << "minimum value in the BST = " << minValue(aNode) << "\n";
   
   insert(aNode, 5);
   insert(aNode, 4);
   insert(aNode, 7);
   insert(aNode, 8);
   insert(aNode, 6);

   cout << "Inorder traversal of BST: " ;
   printTree(aNode) ;

   cout << "Postorder traversal of BST: " ;
   postOrderprintTree(aNode) ;
   cout << "hasPathSum(aNode, 11) returned : " << hasPathSum(aNode, 11) << "\n";
   return 0;
}
