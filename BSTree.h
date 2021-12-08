/** @file BSTree.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Binary Search Tree data structure that stores items of BSTData type
 *   - Can be queueried to determine if empty
 *   - Can empty itself
 *   - Can insert given items
 *   - Can retrieve a desired node
 *   - Can be queueried for the root node
 *   - Can be displayed to the screen
 *   - Can be converted into an array
 *
 * Implementation:
 *   - Uses nodes with left and right pointers to children nodes
 *   - When converted to an array, stored inorder
 *
 */

#ifndef BSTREE_H
#define BSTREE_H

#include "BSTData.h"
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
/** BSTree Class
 *
 * A binary search tree (BST) that supports the following features:
 *    - Takes data from an istream and generates a BST
 *    - Utilizes equality operators and copy assignment
 *    - Supports output to an ostream (inorder traversal)
 *    - Retreival of tree node data objects and their siblings or parents
 *    - Conversion of tree into an inorder array
 *    - Conversion of sorted array to a balanced tree
 */
//-----------------------------------------------------------------------------
class BSTree
{
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
   friend ostream& operator<<(ostream& os, const BSTree& BSTree);

public:
   //--------------------------------------------------------------------------
   /** Constructor
    * default constructor
    *
    * Creates an empty BSTree object.
    * @pre None.
    * @post BSTree object exists. root is instantiated to NULLPTR
    */
   BSTree();

   //--------------------------------------------------------------------------
   /** Destructor
    * Destructor
    *
    * Deletes the BSTree object by deleting all of it's nodes and the
    * data that they point to. root is set to NULLPTR.
    * @pre BSTree object exists
    * @post BSTree is deleted from memory
    */
   virtual ~BSTree();

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
   bool isEmpty() const;

   //--------------------------------------------------------------------------
   /** makeEmpty
    * Make the tree empty
    *
    * Delete all nodes in the tree. Set root to nullptr.
    * @pre None.
    * @post The tree is empty.
    */
   void makeEmpty();

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
    * @return True if datanode was inserted, false if the data already exists
    * in the tree
    */
   bool insert(BSTData* dataptr);

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
    * @pre must have a node that contains the data you wish to search for in
    * the tree (to be passed into the nodeToFind param). Must also have a node
    * pointer (for foundNode param) to point to the node if it is found in the
    * tree. This pointer should not be pointing to something important.
    * And if it if is the sole pointer to something in the heap, it should not
    * be used here.
    * @post nodeToFind, and the tree are unchanged. foundNode will now either
    * point to the node in the tree or will be left unchanged
    * @return TRUE if the node was found in the tree, false otherwise.
    */
   bool retrieve(const BSTData& nodeToFind, BSTData*& foundNode) const;

   //--------------------------------------------------------------------------
   /** displaySideways
    * Display the tree sideways
    *
    * prints the tree directly to cout as if it had been rotated 90 degrees.
    * @pre None.
    * @post None. the tree is unchanged. cout (the ostream object) will
    * be used to display output during the function.
    */
   void displaySideways() const;

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
   void arrayToBSTree(BSTData* arr[]);

   //--------------------------------------------------------------------------
   /** getRoot()
    * Return Root
    *
    * Simply returns a pointer to the root of the binary search tree
    * @pre None.
    * @post None.
    * @return const BSTData*
    */
   const BSTData* getRoot() const;

private:
   //--------------------------------------------------------------------------
   /** Node struct
    *
    * A BSTree is made up of nodes. These nodes point to left and right nodes.
    * They point to dataNodes that represent the data inside ofthem
    */
   struct Node {
      // The data within a node
      BSTData* data;
      // left subtree pointer
      Node* left;
      // right subtree pointer
      Node* right;
   };

   // the root of the tree
   Node* root;

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
   void sidewaysHelper(Node* current, int level) const;

   //--------------------------------------------------------------------------
   /** makeEmptyHelper
    * Helper for makeEmpty()
    *
    * Recursively traverses the tree. Deleting each node in postOrder order.
    * @param current the current node we are looking at
    * @pre None.
    * @post The tree is empty.
    */
   void makeEmptyHelper(Node* current);

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
   const Node* findNode(const BSTData& nodeToFind, const Node* current) const;

   //--------------------------------------------------------------------------
   /** arrayToBSTreeHelper
    * Helper function for arrayToBSTree
    *
    * Builds a BST by taking the center of the array as a root, then makes it's
    * left and right subtrees halfway from mid to end and halfway from mid to
    * start and etcetra. Like a binary search, but where N nodes are reached. N
    * being the llength of the array with good values. The array is emptied and
    * the current tree is replaced by the balanced tree from this array
    * @param arr An array of BSTData*
    * @param current The current node we are building
    * @param start the starting index for this subtree
    * @param end the ending index for this subtree
    * @pre start > 0. end < size of arr. arr should point to BSTData objects in
    * free store
    * @post all arr pointers are nullptr. The tree is now balanced and contains
    * all nodes from the array
    */
   void arrayToBSTreeHelper(BSTData* arr[], Node*& current, int start,
                            int end);

   void inorderHelper(ostream& os, const Node* node) const;
};

#endif