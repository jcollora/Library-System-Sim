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

using namespace std;

Patron::Patron() {

}
Patron::~Patron() {
    
}

bool Patron::addBook(const Book* book) {
    
    return true;
}



bool removeBook(const Book* book) {
    return true;
}

string Patron::displayPatron() const {
    return firstName + " " + lastName; // Finish during commands
}

string Patron::displayPatronHistory() const {
    return "Book"; // Finish during commands
}

int Patron::compare(const Patron& rhs) const {
    int comparison = id - rhs.id;
    if (comparison == 0) {
      string c = firstName + " " + lastName;
      string c2 = rhs.firstName + " " + rhs.lastName;
      comparison = c.compare(c2);
    }
    // check command history
    // check current checkouts
    return comparison;
}

bool Patron::operator<(const BSTData& rhs) const {

    return true;
}


bool Patron::operator>(const BSTData& rhs) const {

    return true;
}


bool Patron::operator==(const BSTData& rhs) const {

    return true;
}


bool Patron::operator!=(const BSTData& rhs) const {

    return true;
}


bool Patron::operator<=(const BSTData& rhs) const {

    return true;
}


bool Patron::operator>=(const BSTData& rhs) const {

    return true;
}

BSTData& Patron::operator=(const BSTData& rhs) {


    return *this;
}

bool Patron::setData(istream& is) {


    return true;
}

string Patron::display() const {

    return "";
}

