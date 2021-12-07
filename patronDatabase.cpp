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
#include "BSTree.h"
#include "patron.h"

using namespace std;

// -------------------------------------------------------------------------
/** PatronDatabase()
 * Default Constructor
 * Constructs a PatronDatabase object with default values
 * @pre None.
 * @post PatronDatabase object exists
 *
 */
PatronDatabase::PatronDatabase() { patronBST = new BSTree(); }

// -------------------------------------------------------------------------
/** ~PatronDatabase()
 * Destructor
 * Destroys all instances of new "BSTrees"
 * @pre Current instance of PatronDatabase exists
 * @post All new allocations of memory are deleted
 */
PatronDatabase::~PatronDatabase() { delete patronBST; }

//--------------------------------------------------------------------------
/** createPatron(Patron customer)
 * createPatron
 * Creates a patron based on the contentse of the given customer
 * @param customer a patron to be created
 * @pre None
 * @post customer is created as a Patron object
 * @return true if it was successfully created
 */
bool PatronDatabase::insertNewPatron(istream& is)
{
   Patron* newPatron = new Patron();

   if (!newPatron->setData(is)) {
      cout << "PATRON INPUT ERROR: IMPROPER PATRON FORMAT." << endl;
      delete newPatron;
      return false;
   }

   if (!patronBST->insert(newPatron)) {
      cout << "PATRON INPUT ERROR (DUPLICATE PATRON): Patron "
           << newPatron->getID() << " already exists in library." << endl;
      return false;
   }

   return true;
}

//--------------------------------------------------------------------------
/** getPatron(String patronId)
 * Return a Patron object based on the information that is passed in
 * @param patronID the ID used to find the patron
 * @pre None.
 * @post None. const function
 * @return Patron* representing the Patron object that they are looking for if
 * found
 */
Patron* PatronDatabase::getPatron(string patronId) const
{
   Patron patronFinder(patronId);
   BSTData* foundPatron = nullptr;
   patronBST->retrieve(patronFinder, foundPatron);

   return (Patron*)foundPatron;
}