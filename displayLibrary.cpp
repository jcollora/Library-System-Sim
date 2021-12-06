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

DisplayLibrary::DisplayLibrary(BookDatabase* books, PatronDatabase* patrons) {
   patronDB = patrons;
   bookDB = books;
   type = TYPE_DISPLAY_LIB;
   commandCode = DISPLAY_LIB_CODE;

}

void DisplayLibrary::execute() {
   bookDB->displayAll();
   delete this;
}

LibraryCommand* DisplayLibrary::create() const {
   return new DisplayLibrary(bookDB, patronDB);
}

bool DisplayLibrary::initialize(istream& is) {
   string line;
   getline(is, line);
   return true;
}