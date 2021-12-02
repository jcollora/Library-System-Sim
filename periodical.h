/** @file periodical.h
 * @author Joseph Collora and Josh Helzerman
 * 
 * Description:
 *   - A Periodical book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"
#include <string>
#include "constants.h"

using namespace std;

class Patron;

class Periodical : public Book
{
public:
   // -------------------------------------------------------------------------
   /** Periodical()
    * Default constructor
    *
    * Creates a Periodical book object
    * @pre None.
    * @post Periodical book object exists
    */
   Periodical();

   // -------------------------------------------------------------------------
   /** create()
    * Create Periodical book
    *
    * Creates a Periodical book instance
    * @pre None
    * @post new Periodical book object exists
    * @return reference to new children's book
    *
    */
   Book* create() const;

   // -------------------------------------------------------------------------
   /** display()
    * Display book information
    *
    * Display book information in easy-to-read columns.
    * Displayed in order: Title, author, type, month published, year published
    * Virtual function, can be overridden
    * @pre None.
    * @post None. const function
    * @return String representing book data
    */
   virtual ostream& display(ostream& os) const;

   // -------------------------------------------------------------------------
   /** operator<()
    * Operator less than overload
    *
    * Compares this book to right-hand book to see if this is less than rhs
    * @param rhs Book to be compared
    * @pre None.
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
    * @pre None.
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

   // --------------------------------------------------------------------------
   /** operator!=
    * Inequality Operator
    * 
    * Determines if right and left items are not equivelent
    * @pre Both items being compared exist
    * @post None.
    * @return false returned when left is equal to right, true otherwise
    */
   virtual bool operator!=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator<=()
    *  Less than or equal operator
    * 
    * Determines if the right and left items are equivelent or less than
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is equal to right or
    * if left is less than right, false otherwise
    */
   virtual bool operator<=(const BSTData& rhs) const;

   // --------------------------------------------------------------------------
   /** operator>=()
    *  greater than or equal operator
    * 
    * Determines if the right and left items are equivelent or greater than
    * @pre Both items being compared exist
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
    * @pre must have a properly formatted input file
    * @post line of input is read. BSTData contains line data
    * @return true if line of data was read, false if no line or bad format
    */
   virtual bool setData(istream& is);

   virtual ostream& displayHeader(ostream&) const;

private:
   // -------------------------------------------------------------------------
   /** compare()
    * Compare periodical books
    *
    * Compare 2 periodical books. Returns an integer that reflects the comparison
    * @pre None
    * @post new periodical book object exists
    * @return negative int if left book < right.
    * return 0 if equal, return positive int if left > right
    */
   int compare(const Periodical& rhs) const;

   // current patrons checking out the book. max size is maxCount
   Patron* checkouts[5];
};

#endif