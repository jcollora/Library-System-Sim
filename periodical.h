/** @file periodical.h
 * @author Josh Helzerman and Joseph Collora
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
   /** displayBook()
    * Display book information
    *
    * Display book information in easy-to-read columns.
    * Displayed in order: Title, author, type, month published, year published
    * Virtual function, can be overridden
    * @pre None.
    * @post None. const function
    * @return String representing book data
    */
   virtual string displayBook() const;

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