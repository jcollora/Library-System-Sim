/** @file book.h
 *
 * Description:
 *   - A book object represents a unique book and the number of copies available
 * for that book at any given time
 *   - Can be queried to display its information
 *   - Can be queried to see if there are any available copies
 *   - Can be compared with other books
 *   - number of available books can be changed
 *
 *
 * Implementation:
 *   - This is an abstract class
 *   - Some functions are virtual and some are pure virtual
 *   - One book object can represent multiple copies of the same book using the
 * count member variable
 *   - count can be decreased or increased
 */

#include "book.h"

using namespace std;


Book::Book() {
   author = "";
   title = "";
   year = 0;
   month = 0;
   count = -1;
   maxCount = -1;
   format = "Hardcover";
   checkouts = nullptr;
}