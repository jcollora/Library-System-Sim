/** @file periodical.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - A Periodical book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#include "BSTData.h"
#include "periodical.h"
#include "book.h"
#include <iomanip>

using namespace std;

// -------------------------------------------------------------------------
/** Periodical()
 * Default constructor
 *
 * Creates a Periodical book object
 * @pre None.
 * @post Periodical book object exists
 */
Periodical::Periodical() 
{
    maxCount = 5;
    count = maxCount;
    type = TYPE_PERIODICAL;
    typeCode = PERIODICAL_CODE;
}

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
Book* Periodical::create() const {
   return new Periodical();
}

// -------------------------------------------------------------------------
/** compare()
 * Compare periodical books
 *
 * Compare 2 periodical books. Returns an integer that reflects the comparison
 * @param rhs Book to be compared
 * @pre None
 * @post new periodical book object exists
 * @return negative int if left book < right.
 * return 0 if equal, return positive int if left > right
 */
int Periodical::compare(const Periodical& rhs) const {
    int comparison = year - rhs.year;
    if(comparison == 0) {
        comparison = month - rhs.month;
        if(comparison == 0) 
            comparison = title.compare(rhs.title);
    }
    return comparison;
}

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
bool Periodical::operator<(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) < 0;
}

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
bool Periodical::operator>(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) > 0;
}

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
bool Periodical::operator==(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) == 0;
}

// --------------------------------------------------------------------------
/** operator!=
 * Inequality Operator
 * 
 * Determines if right and left items are not equivelent
 * @param rhs Book to be compared
 * @pre Both items being compared exist
 * @post None.
 * @return false returned when left is equal to right, true otherwise
 */
bool Periodical::operator!=(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) != 0;
}

// -------------------------------------------------------------------------
/** operator<=()
 *  Less than or equal operator
 * 
 * Determines if the right and left items are equivelent or less than
 * @param rhs Book to be compared
 * @pre Both items being compared exist
 * @post None.
 * @return true returned when left is equal to right or
 * if left is less than right, false otherwise
 */
bool Periodical::operator<=(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) <= 0;
}

// --------------------------------------------------------------------------
/** operator>=()
 *  greater than or equal operator
 * 
 * Determines if the right and left items are equivelent or greater than
 * @param rhs Book to be compared
 * @pre Both items being compared exist
 * @post None.
 * @return true returned when left is equal to right or
 * if left is greater than right, false otherwise
 */
bool Periodical::operator>=(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
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
BSTData& Periodical::operator=(const BSTData& rhs) {
   const Periodical& right = static_cast<const Periodical&>(rhs);
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
bool Periodical::setData(istream& is) { //ERRORS
   string line; 
   
   is.get();
   char form = is.get();
   if (is.peek() == ' ') {
      if (form != format) {
         getline(is, line);
         return false;
      }
      is.get();
   } else {
      is.unget();
   }
   
   getline(is, title, ',');
   if (title.empty()) {
      getline(is, line);
      return false;
   }
   is >> month; 
 
   is >> year;
   if ( year < 0) {
      getline(is, line);
      return false;
   }

   getline(is, line); //clear line for next data input

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
ostream& Periodical::display(ostream& os) const {
      os.setf(ios::left, ios::adjustfield);
   os << setw(COUNT_BUFFER) << count
      << setw(MONTH_BUFFER) << month
      << setw(YEAR_BUFFER) << year
      << setw(TITLE_BUFFER) << title.substr(0, TITLE_MAX_LENGTH);
   
   return os;
}

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
ostream& Periodical::displayHeader(ostream& os) const {
         os.setf(ios::left, ios::adjustfield);

         os << type << " BOOKS" << endl;
       os << setw(COUNT_BUFFER) << "AVAIL"
      << setw(MONTH_BUFFER) << "MONTH"
      << setw(YEAR_BUFFER) << "YEAR"
      << setw(TITLE_BUFFER) << "TITLE";

      return os;

}


