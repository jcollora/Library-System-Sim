/** @file BSTree.h
 * @author Josh Helzerman
 */

#ifndef BSTREE_H
#define BSTREE_H

#include "nodedata.h"
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
   /** Copy constructor
    * Copy constructor
    *
    * Copies the passed BSTree object. The new BSTree has the same structure
    * as the copied tree.
    * @param BSTree The BSTree to be copied. Passed as const
    * @pre None.
    * @post A copy of BSTree now exists.
    */
   BSTree(const BSTree& BSTree);

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
   /** operator=
    * Copy assignment operator
    *
    * Deletes the contents of the current tree. Copies the contents and
    * structure of the right hand BST to the left hand BST.
    * @param rhs tree to be copied
    * @pre None.
    * @post The current tree is now equal to the rhs tree. rhs is unchanged
    * @return a reference to the current tree.
    */
   BSTree& operator=(const BSTree& rhs);

   //--------------------------------------------------------------------------
   /** operator==
    * Equality operator
    *
    * If contents of the current tree and the right hand tree are equal in value
    * and structure return true, else return false
    * @param rhs the tree to be compared with
    * @pre None.
    * @post None. Both trees are unchanged.
    * @return TRUE if both trees are equal, false otherwise.
    */
   bool operator==(const BSTree& rhs) const;

   //--------------------------------------------------------------------------
   /** operator!=
    * Inequality operator
    *
    * If contents of the current tree and the right hand tree are NOT equal in
    * value and structure return true, else return false
    * @param rhs the tree to be compared with
    * @pre None.
    * @post None. Both trees are unchanged.
    * @return TRUE if both trees are NOT equal, false otherwise.
    */
   bool operator!=(const BSTree& rhs) const;

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
   bool insert(NodeData* dataptr);

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
    * And if it if is the sole pointer to something in the heap, it should not
    * be used here.
    * @post nodeToFind, and the tree are unchanged. foundNode will now either
    * point to the node in the tree or will be left unchanged
    * @return TRUE if the node was found in the tree, false otherwise.
    */
   bool retrieve(const NodeData& nodeToFind, NodeData*& foundNode) const;

   //--------------------------------------------------------------------------
   /** getSibling
    * Get sibling of the given node
    *
    * Finds the sibling of a given node and stores a COPY of that sibling in the
    * passed parameter sibling. Returns TRUE if sibling is found, false
    * otherwise.
    * @param node the node that we want to find the sibling of
    * @param sibling initially the contents of this node are unimportant to this
    * function. After the function is run, this node will either be unchanged,
    * or it will be a copy of the sibling node in the tree.
    * @pre must have a node that is equal to the node whose sibling we wish to
    * find in the tree. Must have a node to pass into the sibling parameter that
    * can be filled with a copy of the sibling node.
    * @post the tree and node are unchanged. sibling contains a copy of the
    * sibling node or is unchanged if no node is found.
    * @return true if the sibling was found, false otherwise.
    */
   bool getSibling(const NodeData& node, NodeData& sibling) const;

   //--------------------------------------------------------------------------
   /** getParent
    * Get parent of the given node
    *
    * Finds the parent of a given node and stores a COPY of that parent in the
    * passed parameter parent. Returns TRUE if parent is found, false otherwise.
    * @param child the node that we want to find the parent of
    * @param parent initially the contents of this node are unimportant to this
    * function. After the function is run, this node will either be unchanged,
    * or it will be a copy of the parent node in the tree.
    * @pre must have a node that is equal to the node whose parent we wish to
    * find in the tree. Must have a node to pass into the parent parameter that
    * can be filled with a copy of the parent node.
    * @post the tree and node are unchanged. parent contains a copy of the
    * parent node or is unchanged if no node is found.
    * @return true if the parent was found, false otherwise.
    */
   bool getParent(const NodeData& child, NodeData& parent) const;

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
   /** bstreeToArray
    * Turn BSTree into an Array
    *
    * Fills a passed array of NodeData* using an inorder traversal of the tree.
    * Afterwards, the tree is empty.
    * @param arr The array to hold the nodeData from the tree
    * @pre Must pass an array of NodeData* of at least size 100 into the
    * function.
    * @post The array will now hold all nodeData from the tree inorder. The tree
    * is now empty.
    */
   void bstreeToArray(NodeData* arr[]);

   //--------------------------------------------------------------------------
   /** arrayToBSTree
    * turn array into BSTree
    *
    * Builds a balanced bSTree from a sorted array of NodeData*. Leaves the
    * array with nullptrs.
    * @param arr An array of nodeData*
    * @pre must pass an array of nodeData*
    * @post The current BSTree now contains the nodeDatas from the array,
    * balanced. The old tree was deleted.
    */
   void arrayToBSTree(NodeData* arr[]);

private:
   //--------------------------------------------------------------------------
   /** Node struct
    *
    * A BSTree is made up of nodes. These nodes point to left and right nodes.
    * They point to dataNodes that represent the data inside ofthem
    */
   struct Node {
      // The data within a node
      NodeData* data;
      // left subtree pointer
      Node* left;
      // right subtree pointer
      Node* right;
   };

   //--------------------------------------------------------------------------

   // the root of the tree
   Node* root;

   //--------------------------------------------------------------------------
   /** inorderHelper
    * traverse BSTree inorder
    *
    * Traverses the BSTree inorder recursively. An array is passed into the
    * function, this array will store the contents of the BSTree inorder as
    * DataNode*. The array should be at least size 100.
    * @param current The current node we are traversing
    * @param arr The array to store the pointers to nodeData in the tree inorder
    * @param index the current index we are inserting at it arr
    * @pre must pass an arr of nodeData* of at least size 100.
    * @post arr is filled with pointers to nodeData in the tree, inorder. the
    * tree is unchanged.
    * @return the current index we are at in the array. must be incremented
    * properly, so we return it to each previous recursive call to ensure we
    * are at the proper element. can also be used to know how large the array
    * will be. after the function finishes its recursion.
    */
   int inorderHelper(const Node* current, NodeData* arr[], int index) const;

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
   /** findParentHelper
    * Find parent of a node in the tree.
    *
    * Traverses the tree recursively looking for a parent of the given node
    * child. If parent is found, return parent node up the call stack. else,
    * returns nullptr.
    * @param child The child node we are using to find the parent
    * @param current the current node that we are looking at. assumed to not
    * be nullptr
    * @pre the child nodeData must be comparable with the tree's nodeData.
    * Assumes child is not the root.
    * @post The tree, child, and current nodes are never changed
    * @return a pointer to the parent node. This will be nullptr if the parent
    * node is not found.
    */
   const Node* findParentHelper(const NodeData& child,
                                const Node* current) const;

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
   /** copyTree
    * Create copy of a tree recursively
    *
    * This is a helper function that creates a copy of a tree. It traverses the
    * tree to copy using the current node pointer. At each node, it creates a
    * new node in the copy tree and makes it equal to thecurrent tree.
    * @param current the current node we are looking at in the tree to be copied
    * @param copy a reference to the current node we are looking at in the copy
    * of the tree. this allows us to create the tree as we traverse the other
    * tree.
    * @pre Need to have an empty tree to contain the copies and pass
    * its root into the copy parameter.
    * @post The new tree exists in free memory and should be assigned to a
    * variable and deleted appropriately. the copied tree is unchanged.
    */
   void copyTree(const Node* current, Node*& copy);

   //--------------------------------------------------------------------------
   /** equalityHelper
    * Check equality of two trees
    *
    * Check equality of two trees by checking the equality of each
    * node. node data and node structure must be the same.
    * @param lhs The "left hand" node to be compared
    * @param rhs The "right hand" node to be compared with the left hand node
    * @pre None.
    * @post Trees are unchanged.
    * @return TRUE if all nodes are equal to eachother (values and structure
    * of each tree are the same). Else FALSE
    */
   bool equalityHelper(const Node* lhs, const Node* rhs) const;

   //--------------------------------------------------------------------------
   /** findNode
    * Find node in tree
    * Traverse tree recursively, looking for the node.
    *
    * @param nodeToFind the nodeData to find in the tree
    * @param current the current node we are looking at in the tree
    * @pre nodeToFind should be comparable to the nodeData in the tree
    * @post None. Tree and nodes are unchanged.
    * @return the node we were looking for. return nullptr if not found.
    */
   const Node* findNode(const NodeData& nodeToFind, const Node* current) const;

   //--------------------------------------------------------------------------
   /** arrayToBSTreeHelper
    * Helper function for arrayToBSTree
    *
    * Builds a BST by taking the center of the array as a root, then makes it's
    * left and right subtrees halfway from mid to end and halfway from mid to
    * start and etcetra. Like a binary search, but where N nodes are reached. N
    * being the llength of the array with good values. The array is emptied and
    * the current tree is replaced by the balanced tree from this array
    * @param arr An array of nodeData*
    * @param current The current node we are building
    * @param start the starting index for this subtree
    * @param end the ending index for this subtree
    * @pre start > 0. end < size of arr. arr should point to nodeData objects in
    * free store
    * @post all arr pointers are nullptr. The tree is now balanced and contains
    * all nodes from the array
    */
   void arrayToBSTreeHelper(NodeData* arr[], Node*& current, int start,
                            int end);

   //--------------------------------------------------------------------------
   /** inorderHelper2
    * traverse BSTree inorder
    *
    * Traverses the BSTree inorder recursively. An array is passed into the
    * function, this array will store the contents of the BSTree inorder as
    * DataNode*. The array should be size 100. Deletes tree as it traverses it.
    * @param current The current node we are traversing
    * @param arr The array to store the pointers to copies of nodeData in the
    * tree inorder
    * @param index the current index we are inserting at it arr
    * @pre must pass an arr of nodeData* of at least size 100.
    * @post arr is filled with pointers to nodeData in the tree, inorder. the
    * tree no longer contains nodedata.
    * @return the current index we are at in the array. must be incremented
    * properly, so we return it to each previous recursive call to ensure we
    * are at the proper element. can also be used to know how large the array
    * will be. after the function finishes its recursion.
    */
   int inorderHelper2(Node* current, NodeData* arr[], int index);
};

#endif