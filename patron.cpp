/** @file patron.h
 * @author  Joseph Collora and Josh Helzerman
 *
 * Description:
 * - A patron object represents a unique customer + its id, name, and history
 * - History can be updated (removal and addition)
 * - Can be queried to display its information
 * - Can be compared with other patrons
 *
 * Implementation:
 * - Some functions are virtual -of BSTData
 * - Patron History stored in a list of strings
 *
 */
#include "patron.h"
#include "book.h"
#include <string>
#include <iomanip>
#include "libraryCommand.h"
#include <list>

using namespace std;

// -------------------------------------------------------------------------
/** Patron()
 * Default Constructor
 *
 * Creates a Patron object. Member variables are instantiated to default
 * values. Book requires a book factory in order to be properly instantiated
 * with data
 * @pre None.
 * @post Patron object exists with default member variables
 */
Patron::Patron() {
   id = "";
   lastName = "";
   firstName = "";
}

// -------------------------------------------------------------------------
/** Patron(ID)
 * Constructor with ID
 * 
 * Alternate constructor for patron that instantiates ID field to the given 
 * string value.
 * 
 * @param id string of characters that make up the desired patron ID
 * @pre None.
 * @post Patron object exists with given ID value
 */
Patron::Patron(string newID) {
   id = newID;
   lastName = "";
   firstName = "";
}

// -------------------------------------------------------------------------
/** ~Patron()
 * Destructor
 * 
 * Deletes Patron from memory. It's empty, but apparently helps to delete
 * strings
 * @pre None.
 * @post Patron instance is deleted
 */
Patron::~Patron() {

}

// -------------------------------------------------------------------------
/** compare()
 * Compare patrons
 *
 * Compare 2 patrons. Returns an integer that reflects the comparison
 * @pre None
 * @post new patron object exists
 * @return negative int if left patron < right.
 * return 0 if equal, return positive int if left > right
 */
int Patron::compare(const Patron& rhs) const {
   int comparison = id.compare(rhs.id);

   return comparison;
}

// -------------------------------------------------------------------------
/** addBook()
 * Add book to currentCheckouts
 * @param book the book to checkout
 * @pre Book object must exist and should have available copies, 
 * Book's count will need to be updated if this is successful
 * @post if successful, the book is added to the set of currentCheckouts
 * (notes for command: book will decrease in count if success, book points 
 * to patron command
 * will add itself to the patron command history if success)
 * @return True only if patron does not already have the book
 */
bool Patron::addBook(Book* book) {
   currentCheckouts[book]++;
   
   return true;
}

// -------------------------------------------------------------------------
/** removeBook()
 * @param book the book to return
 * @pre Book should exist
 * @post If successful, book is removed from currentCheckouts.
 * (notes for comand: book count++, book no longer points to patron,
 *  command adds itself to patron)
 * @return true only if Patron had the book checked out
 */
bool Patron::removeBook(Book* book) {
   if (currentCheckouts[book] <= 0) {

      return false;
   }
   currentCheckouts[book]--;
   return true;
}

// -------------------------------------------------------------------------
/** operator<()
 * Operator less than overload
 *
 * Compares this patron to right-hand patron to see if this is less than rhs
 * @param rhs patron to be compared
 * @pre None.
 * @post None. const
 * @return true if this patron is less than rhs, else false
 */
bool Patron::operator<(const BSTData& rhs) const {
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) < 0;
}

// -------------------------------------------------------------------------
/** operator>()
 * Operator greater than overload
 *
 * Compares this patron to right-hand patron to see if this is greater than 
 * rhs
 * @param rhs patron to be compared
 * @pre None.
 * @post None. const
 * @return true if this patron is greater than rhs, else false
 */
bool Patron::operator>(const BSTData& rhs) const {
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) > 0;
}

// -------------------------------------------------------------------------
/** operator==()
 * Operator equal to overloadd
 *
 * Compares this patron to right-hand patron to see if this is equal to rhs
 * @param rhs patron to be compared
 * @pre None.
 * @post None. const
 * @return true if this patron is equal to rhs, else false
 */
bool Patron::operator==(const BSTData& rhs) const {
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) == 0;
}

// -------------------------------------------------------------------------
/** operator!=
 * Inequality Operator
 * 
 * Determines if right and left items are not equivelent
 * @pre Both items being compared exist
 * @post None.
 * @return false returned when left is equal to right, true otherwise
 */
bool Patron::operator!=(const BSTData& rhs) const {
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) != 0;
}

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
bool Patron::operator<=(const BSTData& rhs) const {
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) <= 0;
}

// -------------------------------------------------------------------------
/** operator>=()
 *  greater than or equal operator
 * 
 * Determines if the right and left items are equivelent or greater than
 * @pre Both items being compared exist
 * @post None.
 * @return true returned when left is equal to right or
 * if left is greater than right, false otherwise
 */
bool Patron::operator>=(const BSTData& rhs) const {

   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) >= 0;
}

// -------------------------------------------------------------------------
/** operator=()
 * Copy assignment operator
 * 
 * Copy data from right hand item to left hand item.
 * @pre Items should not be the same item
 * @post left item contains data from rhs, right item is const
 * @return reference to left item
 */
BSTData& Patron::operator=(const BSTData& rhs) {
   const Patron& right = static_cast<const Patron&>(rhs);
   if (this != &right) {
      id = right.id;
      lastName = right.lastName;
      firstName = right.firstName;
      commandHistory = right.commandHistory;
      currentCheckouts = right.currentCheckouts;
   }

   return *this;
}

// -------------------------------------------------------------------------
/** setData()
 * input data into node
 * 
 * Take data from inputStream and put into node members
 * @pre must have a properly formatted input file
 * @post line of input is read. BSTData contains line data
 * @return true if line of data was read, false if no line or bad format
 */
bool Patron::setData(istream& is) { //put errors HERE
   if (is.eof()) {
      return false;
   }
   is >> id;
      if (is.eof()) {
      return false;
   }
   is >> lastName;
   if (is.eof()) {
      return false;
   }
   is >> firstName;

   string line;
   getline(is, line);

   return true;
}

// -------------------------------------------------------------------------
/** display()
 * display data
 * 
 * returns the data inside node as a string
 * @pre None
 * @post None
 * @return string representing data inside node
 */
ostream& Patron::display(ostream& os) const {
   os.setf(ios::left, ios::adjustfield);
   os << id << " " << lastName << ", " << firstName << ":" << endl;
   for (const LibraryCommand* comm : commandHistory) {
      comm->display(os);
      os << endl;
   }

   return os;
}

// -------------------------------------------------------------------------
/** getID()
 * get ID
 * 
 * returns the string id of the current patron instance
 * @pre None
 * @post None
 * @return string representing patron's unique ID 
 */
string Patron::getID() const { return id; }

// -------------------------------------------------------------------------
/** addCommand
 * add command 
 * 
 * Adds the command item to the forward list of commands that represent the
 * current patron's history of attempted commands
 * @param command command item to be inserted into the patron's history
 * @pre None
 * @post command item is properly inserted into the history forward_list
 * @return None
 */
void Patron::addCommand(LibraryCommand* command) {
   // insert at the end of the command history singly linked list
   commandHistory.push_back(command);
}
