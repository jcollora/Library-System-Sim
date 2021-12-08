/** @file displayPatronHistory.cpp
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. displays patron's book history
 *
 * Implementation
 *   - inherits from Command interface.
 *   - displays patron book history
 */

#include "displayPatronHistory.h"
#include "bookDatabase.h"
#include "constants.h"
#include "patron.h"
#include <iostream>
#include <string>

using namespace std;

// -------------------------------------------------------------------------
/** DisplayPatronHistory()
 * Default Constructor
 *
 * Constructs a display patron book history command object with default
 * values
 * @pre None.
 * @post DisplayPatronHistory command object exists
 */
DisplayPatronHistory::DisplayPatronHistory(BookDatabase* books,
                                           PatronDatabase* patrons)
{
   bookDB = books;
   patronDB = patrons;
   type = TYPE_DISPLAY_PATRON;
   commandCode = DISPLAY_PAT_CODE;
}

// -------------------------------------------------------------------------
/** execute()
 * Execute display patron history command
 *
 * Prints patron history
 * @pre The patron should exist in the system
 * @post None. patron is unchanged
 */
bool DisplayPatronHistory::execute()
{

   patron->display(cout);
   cout << endl;
   delete this;
   return true;
}

/** create()
 * Create Library Command (factory)
 *
 * Create a library command of the appropriate type
 * this function is pure virtual
 * @pre None
 * @post a new library command exists
 */
LibraryCommand* DisplayPatronHistory::create() const
{
   return new DisplayPatronHistory(bookDB, patronDB);
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
bool DisplayPatronHistory::initialize(istream& is)
{ // put errors here
   string patronID, line;
   is >> patronID;
   patron = patronDB->getPatron(patronID);
   getline(is, line);
   if (patron == nullptr) {
      cout << "PATRON HISTORY COMMAND INPUT ERROR: PATRON " << patronID
           << " does not exist." << endl;
      return false;
   }

   return true;
}