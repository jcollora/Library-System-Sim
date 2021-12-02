/** @file BSTree.cpp
 * @author Josh Helzerman
 */

#include "BSTree.h"
#include "BSTData.h"
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 100;

//--------------------------------------------------------------------------
/** Constructor
 * default constructor
 *
 * Creates an empty BSTree object.
 * @pre None.
 * @post BSTree object exists. root is instantiated to NULLPTR
 */
BSTree::BSTree() { root = nullptr; }

//--------------------------------------------------------------------------
/** Destructor
 * Destructor
 *
 * Deletes the BSTree object by deleting all of it's nodes and the
 * data that they point to. root is set to NULLPTR.
 * @pre BSTree object exists
 * @post BSTree is deleted from memory
 */
BSTree::~BSTree() { makeEmpty(); }

//--------------------------------------------------------------------------
/** makeEmpty
 * Make the tree empty
 *
 * Delete all nodes in the tree. Set root to nullptr.
 * @pre None.
 * @post The tree is empty.
 */
void BSTree::makeEmpty()
{
   makeEmptyHelper(root);
   root = nullptr;
}

//--------------------------------------------------------------------------
/** makeEmptyHelper
 * Helper for makeEmpty()A
 *
 * Recursively traverses the tree. Deleting each node in postOrder order.
 * @param current the current node we are looking at
 * @pre None.
 * @post The tree is empty.
 */
void BSTree::makeEmptyHelper(Node* current)
{
   if (current == nullptr) {
      return;
   }
   makeEmptyHelper(current->left);
   makeEmptyHelper(current->right);

   delete current->data;

   delete current;
}

//--------------------------------------------------------------------------
/** isEmpty
 * Is the tree empty?
 *
 * Checks if the BSTree is empty by checking the root pointer. If root
 * points to nullptr, then return true. else, false.
 * @pre None.
 * @post None. BSTree is unchanged.
 * @return bool that is true if BSTree is empty, false otherwise.
 */
bool BSTree::isEmpty() const { return root == nullptr; }


//--------------------------------------------------------------------------
/** insert
 * Insert data node into tree
 *
 * Inserts a data node into the tree into the proper sorted position. If the
 * data already exists in the tree, the new data will not be inserted
 * @param data the dataNode to be inserted
 * @pre data should be a node that holds data that can be compared with the
 * data already in the tree.
 * @post The tree now contains the data node given in proper sorted position
 * @return True if datanode was inserted, false if the data already exists in
 * the tree
 */
bool BSTree::insert(BSTData* dataptr)
{
   Node* ptr = new Node; // exception is thrown if memory is not allocated

   ptr->data = dataptr;

   ptr->left = ptr->right = nullptr;
   if (isEmpty()) {
      root = ptr;
   } else {
      Node* current = root;
      bool inserted = false;

      // if item is less than current item, insert in left subtree,
      // otherwise insert in right subtree
      while (!inserted) {
         if (*ptr->data < *current->data) {
            if (current->left == nullptr) { // at leaf, insert left
               current->left = ptr;
               dataptr = nullptr;
               inserted = true;
            } else
               current = current->left; // one step left
         } else if (*ptr->data == *current->data) {

            delete ptr;

            return false;
         } else {
            if (current->right == nullptr) { // at leaf, insert right
               current->right = ptr;
               dataptr = nullptr;
               inserted = true;
            } else
               current = current->right; // one step right
         }
      }
   }

   return true;
}

//--------------------------------------------------------------------------
/** operator<<
 * Overloaded output operator
 *
 * Displays the BST in inorder traversal in an ostream object.
 * @param os The ostream object taking the data.
 * @param BSTree the BSTree object to be displayed
 * @pre None.
 * @post BSTree data is now in the ostream object.
 * @return the ostream object now containing the BSTree data to be
 * displayed.
 */
ostream& operator<<(ostream& os, const BSTree& BSTree)
{
   
   BSTree.inorderHelper(os, BSTree.root);
   
   return os;
}

void BSTree::inorderHelper(ostream&os, const Node* node) const {
   if (node == nullptr) {
      return;
   }
   inorderHelper(os, node->left);
   node->data->display(os);
   cout << endl;
   inorderHelper(os, node->right);
}


//--------------------------------------------------------------------------
/** retrieve
 * Retrieve Node
 *
 * finds the specified dataNode in the tree. Returns true if the node is
 * found, false otherwise. The node is returned via the pointer passed by
 * reference into the function (the 2nd parameter).
 * @param nodeToFind A dataNode equal to the node that we are looking for
 * within the tree.
 * @param foundNode A reference to a data node pointer. This initially
 * contains nothing of importance to this function, but if the node is found
 * within the tree, this pointer in this parameter will point to the node.
 * @pre must have a node that contains the data you wish to search for in the
 * tree (to be passed into the nodeToFind param). Must also have a node
 * pointer (for foundNode param) to point to the node if it is found in the
 * tree. This pointer should not be pointing to something important.
 * And if it if is the sole pointer to something in the heap, it should not be
 * used here.
 * @post nodeToFind, and the tree are unchanged. foundNode will now either
 * point to the node in the tree or will be left unchanged
 * @return TRUE if the node was found in the tree, false otherwise.
 */
bool BSTree::retrieve(const BSTData& nodeToFind, BSTData*& foundNode) const
{
   const Node* found = findNode(nodeToFind, root);
   if (found == nullptr) {
      return false;
   }
   foundNode = found->data;
   return true;
}

//--------------------------------------------------------------------------
/** findNode
 * Find node in tree
 * Traverse tree recursively, looking for the node.
 *
 * @param nodeToFind the BSTData to find in the tree
 * @param current the current node we are looking at in the tree
 * @pre nodeToFind should be comparable to the BSTData in the tree
 * @post None. Tree and nodes are unchanged.
 * @return the node we were looking for. return nullptr if not found.
 */
const BSTree::Node* BSTree::findNode(const BSTData& nodeToFind,
                                       const Node* current) const
{
   if (current == nullptr) {
      return nullptr;
   }
   if (*current->data == nodeToFind) {
      return current;
   }

   const Node* temp = findNode(nodeToFind, current->left);
   if (temp == nullptr) {
      temp = findNode(nodeToFind, current->right);
   }

   return temp;
}

//--------------------------------------------------------------------------
/** displaySideways
 * Display the tree sideways
 *
 * prints the tree directly to cout as if it had been rotated 90 degrees.
 * @pre None.
 * @post None. the tree is unchanged. cout (the ostream object) will
 * be used to display output during the function.
 */
void BSTree::displaySideways() const { sidewaysHelper(root, 0); }

//--------------------------------------------------------------------------
/** sidwaysHelper
 * Print the tree sideways
 *
 * A helper function called by displaySideways that traverses the tree and
 * prints data from nodes in a way taht makes the tree look like it was
 * rotated 90 degrees.
 * @param current The current node
 * @param level the current level
 * @pre None.
 * @post cout may or may not have a new value printed to it
 */
void BSTree::sidewaysHelper(Node* current, int level) const
{
   if (current != nullptr) {
      level++;
      sidewaysHelper(current->right, level);

      // indent for readability, same number of spaces per depth level
      for (int i = level; i >= 0; i--) {
         cout << "      ";
      }
      if (current != nullptr) {
         current->data->display(cout); // display information of object
         cout << endl;
      }
      sidewaysHelper(current->left, level);
   }
}

//--------------------------------------------------------------------------
/** arrayToBSTree
 * turn array into BSTree
 *
 * Builds a balanced bSTree from a sorted array of BSTData*. Leaves the
 * array with nullptrs.
 * @param arr An array of BSTData*
 * @pre must pass an array of BSTData*
 * @post The current BSTree now contains the BSTDatas from the array,
 * balanced. The old tree was deleted.
 */
void BSTree::arrayToBSTree(BSTData* arr[])
{
   makeEmpty();
   int count = 0;
   while (arr[count] != nullptr && count < 100) {
      count++;
   }

   arrayToBSTreeHelper(arr, root, 0, count - 1);
}

//--------------------------------------------------------------------------
/** arrayToBSTreeHelper
 * Helper function for arrayToBSTree
 *
 * Builds a BST by taking the center of the array as a root, then makes it's
 * left and right subtrees halfway from mid to end and halfway from mid to start
 * and etcetra. Like a binary search, but where N nodes are reached. N being the
 * llength of the array with good values. The array is emptied and the current
 * tree is replaced by the balanced tree from this array
 * @param arr An array of BSTData*
 * @param current The current node we are building
 * @param start the starting index for this subtree
 * @param end the ending index for this subtree
 * @pre start > 0. end < size of arr. arr should point to BSTData objects in
 * free store
 * @post all arr pointers are nullptr. The tree is now balanced and contains all
 * nodes from the array
 */
void BSTree::arrayToBSTreeHelper(BSTData* arr[], Node*& current, int start,
                                  int end)
{
   if (end < start || start > end) {
      return;
   }
   int currentIndex = (start + end) / 2;
   if (arr[currentIndex] == nullptr) {
      return;
   }
   current = new Node();

   current->data = arr[currentIndex];
   arr[currentIndex] = nullptr;
   current->left = nullptr;
   current->right = nullptr;
   arrayToBSTreeHelper(arr, current->left, start, currentIndex - 1);
   arrayToBSTreeHelper(arr, current->right, currentIndex + 1, end);
}

const BSTData* BSTree::getRoot() const {
   return root->data;
}