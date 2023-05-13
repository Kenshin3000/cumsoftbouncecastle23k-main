/*
QUESTION THREE - Linked List in a Binary Tree

PLEASE READ THIS SECTION IN ITS ENTIRETY!

You are required to write a function that takes the root of a binary tree and the head of a linked list. 
This function returns true if there is a consecutive downwards path to the elements of the linked list in the tree, false otherwise.


Below are several examples of linked lists either existing or not existing in the binary tree below.

            10
           / \
          4   9
         /\   /
        7  2  8        
       /  / \
      5  6  12
           / \                    
          17  15
            \
             3
9 -> 8   True
The linked list that looks like 9 -> 8 exists in the binary tree above.

10 -> 4 -> 2 -> 12 -> 15 True
The linked list that looks like 10 -> 4 -> 2 -> 12 -> 15 exists in the binary tree above.

12 -> 3 -> 17 False
The linked list that looks like 12 -> 3 -> 17 does NOT in the binary tree above.

4 -> 2 -> 3 False
The linked list that looks like 4 -> 2 -> 3 does NOT in the binary tree above.


A binary tree will be made up of the following struct:
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
};

The linked list will be made up of the following struct:
struct ListNode
{
  int val;
  ListNode* next;
};

You are required to write a function that conforms to the following function signature:

bool LinkedListInTree(TreeNode* binaryTreeHead, ListNode* linkedListHead);


Your answer will be run against a suite of test cases; please consider all potential scenarios.
For example, if both the head of the binary tree and the head of the linked list are nullptr, return true.

Additional information:
 - You are free to use a single helper method whose function signature is not constrained. 
 - Both the contents of the LinkedListInTree(TreeNode*, ListNode*) method and the single helper method will be copied from Rextester.
 - Your code will be run against a MSVC compiler (C++17)
 - If you need to make any assumptions, please include them as a comment in the method.
 - Assume that STL is available to be used.
 - We recommend you write your code in an IDE of your choice (Visual Studio 2019 is preferred, but not required) before pasting your answer down below.

Once you are done, please click "Fork it", and paste the corresponding link into the FlexiQuiz response section associated with this question.
*/

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
};

struct ListNode
{
  int val;
  ListNode* next;
};

bool depthFS(TreeNode* binaryTreeHead, ListNode* linkedListHead){
    // This function checks in a depth first search whether the linked list head corresponds to the first value
    // of the linked list and then iterates in both branches of the tree

    // Return false if no path to follow
    if(!binaryTreeHead) return false;

    // Return true if the zero set
    if(!linkedListHead) return true;

    return linkedListHead->val == binaryTreeHead->val && (depthFS(binaryTreeHead->left, linkedListHead->next) ||
                                                          depthFS(binaryTreeHead->right, linkedListHead->next));
}

bool LinkedListInTree(TreeNode* binaryTreeHead, ListNode* linkedListHead)
{
    // Recursively check for a starting point in the tree and try to iterate through the list successfully

    // Return false if no path to follow
    if(!binaryTreeHead) return false;

    // Return true if the zero set
    if(!linkedListHead) return true;

    return depthFS(binaryTreeHead, linkedListHead) or LinkedListInTree(binaryTreeHead->right, linkedListHead) or LinkedListInTree(binaryTreeHead->left, linkedListHead);
}
