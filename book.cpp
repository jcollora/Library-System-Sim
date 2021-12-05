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

#include "book.h"

using namespace std;

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
Book::Book()
{
   author = "";
   title = "";
   year = 0;
   month = 0;
   count = -1;
   maxCount = -1;
   format = 'H';
   type = '0';
}

// -------------------------------------------------------------------------
/** ~Book()
 * Destructor
 *
 * Deletes book from memory. It's empty, but apparently helps to delete
 * strings
 * @pre None.
 * @post Book instance is deleted
 */
Book::~Book() {}

// -------------------------------------------------------------------------
/** addBook()
 * Add a copy of the book to the collection
 *
 * Adds 1 to the count variable of the book, representing a copy of the book
 * has been returned
 * @pre None.
 * @post count is incremented
 */
bool Book::addBook()
{
   if (count < maxCount) {
      count++;
      return true;
   }
   return false;
}

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
bool Book::removeBook() {
   if (count > 0) {
      count--;
      return true;
   }
   return false;
}

// -------------------------------------------------------------------------
/** addPatron()
 * add patron
 * 
 * adds the given patron from the list of patrons checking out
 * @param patron patron pointer to the desired patron to add
 * @pre patron pointer is not nullptr
 * @post patron item is added to the current list of patrons checking out
 * @return bool indicating status of the add
 */
bool Book::addPatron(const Patron* patron) {
   if (checkouts[patron] >= maxCount) {

      return false;
   }
   checkouts[patron]++;
   return true;
}

// -------------------------------------------------------------------------
/** removePatron
 * remvove patron 
 * 
 * removes the given patron from the list of of patrons checking out
 * @param patron patron pointer to the desired patron to remove
 * @pre patron pointer is not nullptr
 * @post patron item is removed from the current list of patron checkouts
 * @return bool indicating status of the add
 */
bool Book::removePatron(const Patron* patron) {
   if (checkouts[patron] <= 0) {

      return false;
   }
   checkouts[patron]--;
   return true;
}

// -------------------------------------------------------------------------
/** checkAvailability()
 * Check if book is avaiable
 *
 * Checks if a copy of the book is available
 * @pre None.
 * @post None. CONST FUNCTION
 * @return if count > 0, return true, else false
 */
bool Book::checkAvailability() const { return count > 0; }

// -------------------------------------------------------------------------
/** getType()
 * get book type
 *
 * Return the type of book
 * @pre None
 * @post None. const
 * @re
 */
string Book::getType() const { return type; }

// -------------------------------------------------------------------------
/** getTitle()
 * get book title
 * 
 * Return the title of current book
 * @pre None
 * @post None. const
 * @return string representing book title
 */
string Book::getTitle() const { return title; }
