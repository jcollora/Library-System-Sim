/** @file displayLibrary.cpp
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. displays all books in library, sorted
 *
 * Implementation
 *   - inherits from Command interface.
 *   - displays all books in library in sorted order
 */

#include "displayLibrary.h"

#include <string>
#include "constants.h"
#include "bookDatabase.h"

using namespace std;

// -------------------------------------------------------------------------
   /** DisplayLibrary()
    * Default Constructor
    *
    * Constructs a display library command object with default values
    * @pre None.
    * @post DisplayLibrary command object exists
    */
DisplayLibrary::DisplayLibrary(BookDatabase* books, PatronDatabase* patrons) {
   patronDB = patrons;
   bookDB = books;
   type = TYPE_DISPLAY_LIB;
   commandCode = DISPLAY_LIB_CODE;

}

// -------------------------------------------------------------------------
   /** execute()
    * Execute display library command
    *
    * Prints all books in library in sorted order
    * @pre The library object should have books inputed
    * @post None. library is unchanged
    */
void DisplayLibrary::execute() {
   bookDB->displayAll();
   delete this;
}

/** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
LibraryCommand* DisplayLibrary::create() const {
   return new DisplayLibrary(bookDB, patronDB);
}

/** initialize()
    * initialize command with data
    *
    * Uses a string to put data into the command
    * @pre string must be formatted properly
    * @post the command now contains the data from the string
    * @return string is not formmatedd correctly return false,
    * else return true
    */
bool DisplayLibrary::initialize(istream& is) {
   string line;
   getline(is, line);
   return true;
}