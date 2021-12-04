/** @file librarycommand.cpp
 * @author Josh Helzerman
 *
 * Description:
 *   - Class that encapsulates a variety of LibraryCommands that the library
 * manager can execute
 *
 * Implementation:
 *   - this is an abstract class and must be implemented in the child classes
 *   - this class is similar to an interface in Java
 *
 */

#include "libraryCommand.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "book.h"

LibraryCommand::LibraryCommand() {
   patron = nullptr;
   book = nullptr;
   library = nullptr;
   type = "";
   commandCode = 0;
}

string LibraryCommand::getType() const { return type; }

void LibraryCommand::display(ostream& os) const{
   os.setf(ios::left, ios::adjustfield);
   os << "  " << setw(COMMAND_BUFFER) << type;
   book->display(os);
}