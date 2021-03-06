/** @file fiction.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - A Fiction book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book and BSTNode
 * class
 */

#include "fiction.h"
#include "BSTData.h"
#include "book.h"
#include "constants.h"
#include <iomanip>
#include <iostream>
#include <sstream>

#include <regex>

class Patron;

using namespace std;

// -------------------------------------------------------------------------
/** Fiction()
 * Default constructor
 *
 * Creates a fiction book object
 * @pre None.
 * @post Fiction book object exists
 */
Fiction::Fiction()
{
   maxCount = 5;
   count = maxCount;
   type = TYPE_FICTION; // ACII = 70
   typeCode = FICTION_CODE;
}

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
Book* Fiction::create() const { return new Fiction(); }

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
int Fiction::compare(const Fiction& rhs) const
{
   int comparison = author.compare(rhs.author);
   if (comparison == 0) {
      comparison = title.compare(rhs.title);
   }

   return comparison;
}

// -------------------------------------------------------------------------
/** operator<()
 * Operator less than overload
 *
 * Compares this book to right-hand fiction book to see if this is less than
 * rhs
 * @param rhs Book to be compared
 * @pre Compare function works
 * @post None. const
 * @return true if this book is less than rhs, else false
 */
bool Fiction::operator<(const BSTData& rhs) const
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) < 0;
}

// -------------------------------------------------------------------------
/** operator>()
 * Operator greater than overload
 *
 * Compares this book to right-hand fiction book to see if this is greater than
 * rhs
 * @param rhs Book to be compared
 * @pre Compare function works
 * @post None. const
 * @return true if this book is greater than rhs, else false
 */
bool Fiction::operator>(const BSTData& rhs) const
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) > 0;
}

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
bool Fiction::operator==(const BSTData& rhs) const
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) == 0;
}

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
bool Fiction::operator!=(const BSTData& rhs) const
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) != 0;
}

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
bool Fiction::operator<=(const BSTData& rhs) const
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) <= 0;
}

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
bool Fiction::operator>=(const BSTData& rhs) const
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) >= 0;
}

// -------------------------------------------------------------------------
/** operator=()
 * Copy assignment operator
 *
 * Copy data from right hand item to left hand item.
 * @param rhs Book to be compared
 * @pre Items should not be the same item
 * @post left item contains data from rhs, right item is const
 * @return reference to left item
 */
BSTData& Fiction::operator=(const BSTData& rhs)
{
   const Fiction& right = static_cast<const Fiction&>(rhs);
   if (this != &right) {
      author = right.author;
      title = right.title;
      year = right.year;
   }
   return *this;
}

// -------------------------------------------------------------------------
/** setData()
 * input data into node
 *
 * Take data from inputStream and put into node members
 * @param is line of fiction book data
 * @pre must have a properly formatted input file
 * @post line of input is read. BSTData contains line data
 * @return true if line of data was read, false if no line or bad format
 */
bool Fiction::setData(istream& is)
{
   string line;

   is.get();
   char form = is.get();
   if (is.peek() == ' ') {
      if (form != format) {
         cout << type << "BOOK INPUT ERROR: " << form
              << " is not a recognized format." << endl;
         getline(is, line);
         return false;
      }
      is.get();
   } else {
      is.unget();
   }
   stringstream data;
   getline(is, line);
   data.str(line);

   getline(data, author, ',');
   data.get();
   getline(data, title, ',');

   data >> year;

   if (year < 0) {
      cout << TYPE_FICTION << " BOOK INPUT ERROR: For book titled " << endl
           << title.substr(0, TITLE_MAX_LENGTH) << ","
           << " year " << year << " is not a valid year." << endl;
      return false;
   }

   return true;
}

// -------------------------------------------------------------------------
/** display()
 * Display book information
 *
 * Display book information in easy-to-read columns.
 * Displayed in order: Title, author, type, month published, year published
 * Virtual function, can be overridden
 * @param os outstream for book information
 * @pre None.
 * @post None. const function
 * @return ostream&
 */
ostream& Fiction::display(ostream& os) const
{
   os.setf(ios::left, ios::adjustfield);
   os << setw(COUNT_BUFFER) << count << setw(AUTHOR_BUFFER)
      << author.substr(0, AUTHOR_MAX_LENGTH) << setw(TITLE_BUFFER)
      << title.substr(0, TITLE_MAX_LENGTH) << setw(YEAR_BUFFER) << year;

   return os;
}

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
ostream& Fiction::displayCountless(ostream& os) const
{
   os.setf(ios::left, ios::adjustfield);
   os << setw(AUTHOR_BUFFER) << author.substr(0, AUTHOR_MAX_LENGTH)
      << setw(TITLE_BUFFER) << title.substr(0, TITLE_MAX_LENGTH)
      << setw(YEAR_BUFFER) << year;

   return os;
}

// -------------------------------------------------------------------------
/** displayHeader()
 * Header Display
 *
 * Displays the header preceeding other displays
 * @param os outstream for header
 * @pre None.
 * @post None.
 * @return ostream&
 */
ostream& Fiction::displayHeader(ostream& os) const
{
   os.setf(ios::left, ios::adjustfield);

   os << type << " BOOKS" << endl;
   os << setw(COUNT_BUFFER) << "AVAIL" << setw(AUTHOR_BUFFER) << "AUTHOR"
      << setw(TITLE_BUFFER) << "TITLE" << setw(YEAR_BUFFER) << "YEAR";

   return os;
}
