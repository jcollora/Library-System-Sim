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
#include <string>
#include "constants.h"
#include "bookDatabase.h"
#include <iostream>
#include "patron.h"

using namespace std;

DisplayPatronHistory::DisplayPatronHistory() {
   type = TYPE_DISPLAY_PATRON;
   commandCode = DISPLAY_PAT_CODE;
}

void DisplayPatronHistory::execute() {
   patron->display(cout);
}

LibraryCommand* DisplayPatronHistory::create() const {
   return new DisplayPatronHistory();
}

bool DisplayPatronHistory::initialize(istream& is) { //put errors here
   string patronID, line;
   is >> patronID;
   patron = patronDB->getPatron(patronID);
   getline(is, line);
   if (patron == nullptr) {
      return false;
   }
   

   return true;
}