/** @file patronDatabase.h
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - Patron database is a database that holds all the patrons that will be 
 *     interacting with the library. 
 *   - The class allows you to create new patrons
 *     and retrieve a patron based on the Patron object that you pass in
 *  
 * Implementation:
 *   - Database of patrons exists as a "BSTree"
 * 
 */
#include "patronDatabase.h"
#include "patron.h"

using namespace std;

// const/destr unneccessary?

bool PatronDatabase::insertNewPatron(istream& is) {
    Patron* insert;
    bool inserted = insert->setData(is);
    return inserted;
}

Patron* PatronDatabase::getPatron(string patronId) const {
    // string id? or other patron...

    return new Patron();
}