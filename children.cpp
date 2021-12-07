/** @file children.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - A children book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#include "children.h"
#include "BSTData.h"
#include "book.h"
#include <iomanip>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

// -------------------------------------------------------------------------
/** children()
 * Default constructor
 *
 * Creates a children book object
 * @pre None.
 * @post children book object exists
 */
Children::Children()
{
   maxCount = 5;
   count = maxCount;
   type = TYPE_CHILDREN;
   typeCode = CHILDREN_CODE;
}

Children::~Children() {}

// -------------------------------------------------------------------------
/** create()
 * Create childrens book
 *
 * Creates a childrens book instance
 * @pre None
 * @post new childrens book object exists
 * @return reference to new children's book
 */
Book* Children::create() const { return new Children(); }

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
int Children::compare(const Children& rhs) const
{
   int compare = title.compare(rhs.title);
   if (compare == 0) {
      compare = author.compare(rhs.author);
   }
   return compare;
}

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
bool Children::operator<(const BSTData& rhs) const
{
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) < 0;
}

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
bool Children::operator>(const BSTData& rhs) const
{
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) > 0;
}

// -------------------------------------------------------------------------
/** operator==()
 * Operator equal to overload
 *
 * Compares this book to right-hand book to see if this is equal to rhs
 * @param rhs Book to be compared
 * @pre Compare function works
 * @post None. const
 * @return true if this book is equal to rhs, else false
 */
bool Children::operator==(const BSTData& rhs) const
{
   const Children& right = static_cast<const Children&>(rhs);
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
bool Children::operator!=(const BSTData& rhs) const
{
   const Children& right = static_cast<const Children&>(rhs);
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
bool Children::operator<=(const BSTData& rhs) const
{
   const Children& right = static_cast<const Children&>(rhs);
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
bool Children::operator>=(const BSTData& rhs) const
{
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) >= 0;
}

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
BSTData& Children::operator=(const BSTData& rhs)
{
   const Children& right = static_cast<const Children&>(rhs);
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
 * @param is stream line of data for book
 * @pre must have a properly formatted input file
 * @post line of input is read. BSTData contains line data
 * @return true if line of data was read, false if no line or bad format
 */
bool Children::setData(istream& is)
{
   string line;
   is.get();
   char form = is.get();
   if (is.peek() == ' ') {
      if (form != format) {
         cout << type << " BOOK INPUT ERROR: " << form
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
   string s1 = "";
   string s2 = "";
   getline(data, s1, ',');
   data.get();
   getline(data, s2, ',');
   data >> year;

   if (year) { // book

      author = s1;
      title = s2;

   } else { // command
      title = s1;
      author = s2;
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
 * @param ostream outstream for book information
 * @pre None.
 * @post None. const function
 * @return ostream&
 */
ostream& Children::display(ostream& os) const
{
   // const Children& book = static_cast<const Children&>(data);
   os.setf(ios::left, ios::adjustfield);
   os << setw(COUNT_BUFFER) << count << setw(TITLE_BUFFER)
      << title.substr(0, TITLE_MAX_LENGTH) << setw(AUTHOR_BUFFER)
      << author.substr(0, AUTHOR_MAX_LENGTH) << setw(YEAR_BUFFER) << year;

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
ostream& Children::displayCountless(ostream& os) const
{
   os.setf(ios::left, ios::adjustfield);
   os << setw(TITLE_BUFFER) << title.substr(0, TITLE_MAX_LENGTH)
      << setw(AUTHOR_BUFFER) << author.substr(0, AUTHOR_MAX_LENGTH)
      << setw(YEAR_BUFFER) << year;

   return os;
}

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
ostream& Children::displayHeader(ostream& os) const
{
   os.setf(ios::left, ios::adjustfield);

   os << type << " BOOKS" << endl;
   os << setw(COUNT_BUFFER) << "AVAIL" << setw(TITLE_BUFFER) << "TITLE"
      << setw(AUTHOR_BUFFER) << "AUTHOR" << setw(YEAR_BUFFER) << "YEAR";

   return os;
}
