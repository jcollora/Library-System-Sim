/** @file children.h
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - A children book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#ifndef CHILDREN_H
#define CHILDREN_H

#include "book.h"
#include "constants.h"
#include <string>

using namespace std;

class Patron;

class Children : public Book
{
public:
   // -------------------------------------------------------------------------
   /** children()
    * Default constructor
    *
    * Creates a children book object
    * @pre None.
    * @post children book object exists
    */
   Children();

   virtual ~Children();

   // -------------------------------------------------------------------------
   /** create()
    * Create childrens book
    *
    * Creates a childrens book instance
    * @pre None
    * @post new childrens book object exists
    * @return reference to new children's book
    */
   Book* create() const;

   // -------------------------------------------------------------------------
   /** operator<()
    * Operator less than overload
    *
    * Compares this book to right-hand book to see if this is less than rhs
    * @param rhs Book to be compared
    * @pre Compare function works
    * @post None. const
    * @return true if this book is less than rhs, else false
    */
   virtual bool operator<(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator>()
    * Operator greater than overload
    *
    * Compares this book to right-hand book to see if this is greater than rhs
    * @param rhs Book to be compared
    * @pre Compare function works
    * @post None. const
    * @return true if this book is greater than rhs, else false
    */
   virtual bool operator>(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator==()
    * Operator equal to overload
    *
    * Compares this book to right-hand book to see if this is equal to rhs
    * @param rhs Book to be compared
    * @pre None.
    * @post None. const
    * @return true if this book is equal to rhs, else false
    */
   virtual bool operator==(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator!=
    * Inequality Operator
    *
    * Determines if right and left items are not equivelent
    * @param rhs Book to be compared
    * @pre Compare function works
    * @post None.
    * @return false returned when left is equal to right, true otherwise
    */
   virtual bool operator!=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator<=()
    *  Less than or equal operator
    *
    * Determines if the right and left items are equivelent or less than
    * @param rhs Book to be compared
    * @pre Compare function works
    * @post None.
    * @return true returned when left is equal to right or
    * if left is less than right, false otherwise
    */
   virtual bool operator<=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator>=()
    *  greater than or equal operator
    *
    * Determines if the right and left items are equivelent or greater than
    * @param rhs Book to be compared
    * @pre Compare function works
    * @post None.
    * @return true returned when left is equal to right or
    * if left is greater than right, false otherwise
    */
   virtual bool operator>=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator=()
    * Copy assignment operator
    *
    * Copy data from right hand item to left hand item.
    * @param rhs Book who's data will be duplicated
    * @pre Items should not be the same item
    * @post left item contains data from rhs, right item is const
    * @return reference to left item
    */
   virtual BSTData& operator=(const BSTData& rhs);

   // -------------------------------------------------------------------------
   /** setData()
    * input data into node
    *
    * Take data from inputStream and put into node members
    * @param is stream line of data for book
    * @pre must have a properly formatted input file
    * @post line of input is read. BSTData contains line data
    * @return true if line of data was read, false if no line or bad format
    */
   virtual bool setData(istream& is);

   // -------------------------------------------------------------------------
   /** display()
    * Display book information
    *
    * Display book information in easy-to-read columns.
    * Displayed in order: Title, author, type, month published, year published
    * Virtual function, can be overridden
    * @param ostream outstream for book information
    * @pre None.
    * @post None. const function
    * @return ostream&
    */
   virtual ostream& display(ostream& os) const;

   // -------------------------------------------------------------------------
   /** display Countless
    * display without count
    *
    * returns the data inside node as a string, excludes count
    * @param os ostream that will contain string to print
    * @pre None
    * @post None
    * @return string representing data inside node
    */
   virtual ostream& displayCountless(ostream& os) const;

   // -------------------------------------------------------------------------
   /** displayHeader()
    * Header Display
    *
    * Displays the header preceeding other displays
    * @param ostream outstream containing header string
    * @pre None.
    * @post None.
    * @return ostream&
    */
   virtual ostream& displayHeader(ostream&) const;

private:
   // -------------------------------------------------------------------------
   /** compare()
    * Compare children books
    *
    * Compare 2 children books. Returns an integer that reflects the comparison
    * @param rhs Book to be compared
    * @pre None
    * @post new children book object exists
    * @return negative int if left book < right.
    * return 0 if equal, return positive int if left > right
    */
   int compare(const Children& rhs) const;

   // current patrons checking out the book. max size is maxCount
   Patron* checkouts[5];
};

#endif