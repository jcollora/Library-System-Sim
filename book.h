/** @file book.h
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - A book object represents a unique book and the number of copies available
 *     for that book at any given time
 *   - Can be queried to display its information
 *   - Can be queried to see if there are any available copies
 *   - Can be compared with other books
 *   - number of available books can be changed
 *
 * Implementation:
 *   - This is an abstract class
 *   - Some functions are virtual and some are pure virtual
 *   - One book object can represent multiple copies of the same book using the
 *     count member variable
 *   - count can be decreased or increased
 */

#ifndef BOOK_H
#define BOOK_H

#include "BSTData.h"
#include <string>
#include <unordered_map>

class BSTData;
class Patron;

using namespace std;

// needs inheritance to BST data. book factory should befriend book for
// instantiation
class Book : public BSTData
{
public:
   // -------------------------------------------------------------------------
   /** Book()
    * Default Constructor
    *
    * Creates a book object. Member variables are instantiated to default
    * values. Book requires a book factory in order to be properly instantiated
    * with data
    * @pre None.
    * @post Book object exists with default member variables
    */
   Book();

   // -------------------------------------------------------------------------
    /** ~Book()
     * Destructor
     * 
     * Deletes book from memory. It's empty, but apparently helps to delete
     * strings
     * @pre None.
     * @post Book instance is deleted
    */
   virtual ~Book();

   // -------------------------------------------------------------------------
   /** addBook()
    * Add a copy of the book to the collection
    *
    * Adds 1 to the count variable of the book, representing a copy of the book
    * has been returned
    * @pre None.
    * @post count is incremented
    */
   void addBook();

   // -------------------------------------------------------------------------
   /** removeBook()
    * Remove a book from collection
    *
    * Subtracts 1 from count variable of book, a copy of the book has been
    * checked out.
    * @pre must have a copy of the book available. count > 0
    * @post count--
    * @return true if book was available, false otherwise
    */
   bool removeBook();

   bool addPatron(const Patron* patron);

   bool removePatron(const Patron* patron);

   // -------------------------------------------------------------------------
   /** checkAvailability()
    * Check if book is avaiable
    *
    * Checks if a copy of the book is available
    * @pre None.
    * @post None. CONST FUNCTION
    * @return if count > 0, return true, else false
    */
   bool checkAvailability() const;

   // -------------------------------------------------------------------------
   /** create()
    * Create book (for factory)
    *
    * Creates a book instance
    * @pre None
    * @post new book object exists
    * @return reference to new children's book
    *
    */
   virtual Book* create() const = 0;

   // -------------------------------------------------------------------------
   /** getType()
    * get book type
    * 
    * Return the type of book
    * @pre None
    * @post None. const
    * @return char representing book type
    */
   string getType() const; 

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
   virtual ostream& displayHeader(ostream&) const = 0;

   string Book::getTitle() const;

protected:
   // author of book
   string author;

   // title of book
   string title;

   // year book was published
   int year;

   // month book was published
   int month;

   // copies of book available
   int count;

   // Total number of books available
   int maxCount;

   // format of book
   char format;

   // book type;
   string type;

   char typeCode;

   // map of patrons holding a book and the number of books they hold
   unordered_map<const Patron*, int> checkouts;
};

#endif