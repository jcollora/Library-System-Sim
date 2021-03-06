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
#include "book.h"
#include "bookDatabase.h"
#include "patron.h"
#include "patronDatabase.h"
#include <iomanip>
#include <iostream>
#include <string>

// -------------------------------------------------------------------------
/** LibraryCommand()
 * Defaul Constructor
 *
 * Constructs a LibraryCommand object.
 * @pre None.
 * @post LibraryCommand object exists
 */
LibraryCommand::LibraryCommand()
{
   patron = nullptr;
   book = nullptr;
   patronDB = nullptr;
   bookDB = nullptr;
   type = "";
   commandCode = 0;
}

// -------------------------------------------------------------------------
/** ~LibraryCommand()
 * Destructor
 *
 * Deletes command from memory. It's empty, but apparently helps to delete
 * @pre None.
 * @post LibraryCommand instance is deleted
 */
LibraryCommand::~LibraryCommand() {}

/** initialize()
 * initialize command with data
 *
 * Uses a string to put data into the command
 * @pre string must be formatted properly
 * @post the command now contains the data from the string
 * @return string is not formmatedd correctly return false,
 * else return true
 */
bool LibraryCommand::initialize(istream& is) // put errors here
{
   string patronID, line;
   is >> patronID;
   patron = patronDB->getPatron(patronID);
   is.get();
   if (patron == nullptr) {
      cout << type << " COMMAND INPUT ERROR: " << patronID
           << " is not a recognized patron." << endl;
      getline(is, line);
      return false;
   }
   book = bookDB->getBook(is);
   if (book == nullptr) {
      cout << type << " COMMAND INPUT ERROR: "
           << "The Book is not recognized." << endl;

      return false;
   }

   return true;
}

// -------------------------------------------------------------------------
/** getType()
 * get command type
 *
 * Return the type of book
 * @pre None
 * @post None. const
 * @return char representing command type
 */
string LibraryCommand::getType() const { return type; }

// -------------------------------------------------------------------------
/** display()
 * Display book information
 *
 * Display command information in east to read columns
 * @param ostream outstream containing commands to display
 * @pre None.
 * @post None. const function
 */
void LibraryCommand::display(ostream& os) const
{
   if (book == nullptr) {
      return;
   }

   os.setf(ios::left, ios::adjustfield);
   os << "  " << setw(COMMAND_BUFFER) << type;
   book->displayCountless(os);
}