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

using namespace std;

Patron::Patron() {}
Patron::~Patron() {}

bool Patron::addBook(Book* book)
{
   currentCheckouts[book]++;
   return true;
}

bool Patron::removeBook(Book* book)
{
   if (currentCheckouts[book] <= 0) {
      cout << "ERROR: Patron " << id
           << "tried to return a book it did not have titled "
           << book->getTitle() << endl;

      return false;
   }
   currentCheckouts[book]--;
   return true;
}

string Patron::displayPatron() const
{
   return firstName + " " + lastName; // Finish during commands
}

string Patron::displayPatronHistory() const
{
   return "Book"; // Finish during commands
}

int Patron::compare(const Patron& rhs) const
{
   int comparison = id.compare(rhs.id);

   return comparison;
}

bool Patron::operator<(const BSTData& rhs) const
{
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) < 0;
}

bool Patron::operator>(const BSTData& rhs) const
{
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) > 0;
}

bool Patron::operator==(const BSTData& rhs) const
{
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) == 0;
}

bool Patron::operator!=(const BSTData& rhs) const
{
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) != 0;
}

bool Patron::operator<=(const BSTData& rhs) const
{
   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) <= 0;
}

bool Patron::operator>=(const BSTData& rhs) const
{

   const Patron& right = static_cast<const Patron&>(rhs);
   return compare(right) >= 0;
}

BSTData& Patron::operator=(const BSTData& rhs)
{
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

bool Patron::setData(istream& is)
{
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

ostream& Patron::display(ostream& os) const { 
    os << patron

    return os; }

string Patron::getID() const { return id; }

void Patron::addCommand(LibraryCommand* command)
{
   // insert at the end of the command history singly linked list
   commandHistory.insert_after(commandHistory.end(), command);
}
