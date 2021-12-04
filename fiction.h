/** @file fiction.h
 * @author Joseph Collora and Josh Helzerman
 * 
 * Description:
 *   - A Fiction book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
#include <string>
#include "constants.h"

using namespace std;

class Patron;

class Fiction : public Book
{
public:
   // -------------------------------------------------------------------------
   /** Fiction()
    * Default constructor
    *
    * Creates a fiction book object
    * @pre None.
    * @post Fiction book object exists
    */
   Fiction();

   // -------------------------------------------------------------------------
   /** create()
    * Create Fiction book
    *
    * Creates a Fiction book instance
    * @pre None
    * @post new Fiction book object exists
    * @return reference to new children's book
    *
    */
   Book* create() const;

   // -------------------------------------------------------------------------
   /** operator<()
    * Operator less than overload
    *
    * Compares this book to right-hand fiction book to see if this is less than rhs
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
    * Compares this book to right-hand fiction book to see if this is greater than rhs
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
    * Compares this book to right-hand fiction book to see if this is equal to rhs
    * @param rhs Book to be compared
    * @pre Compare function works
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
   /** displayHeader()
    * Header Display
    * 
    * Displays the header preceeding other displays
    * @param ostream outstream for header
    * @pre None.
    * @post None.
    * @return ostream& 
    */
   virtual ostream& displayHeader(ostream&) const;

private:
   // -------------------------------------------------------------------------
   /** compare()
    * Compare fiction books
    *
    * Compare 2 fiction books. Returns an integer that reflects the comparison
    * @param rhs Book to be compared
    * @pre None
    * @post new Fiction book object exists
    * @return negative int if left book < right.
    * return 0 if equal, return positive int if left > right
    */
   int compare(const Fiction& rhs) const;

   // current patrons checking out the book. max size is maxCount
   
};

#endif