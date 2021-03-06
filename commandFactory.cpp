/** @file commandFactory.h
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - Uses an input stream to read text and create commands based off it
 *   - The factory is associated with a library which commands are made for
 *
 * Assumptions/Implementation:
 *   - If the factory is destroyed, nothing else is deleted with it
 *   - Fetches the command to be made using CommandTypeHashmap
 *   - Delegates initializing a command to the command object.
 */

#include "commandFactory.h"

#include "checkoutBook.h"
#include "constants.h"
#include "displayLibrary.h"
#include "displayPatronHistory.h"
#include "libraryCommand.h"
#include "returnBook.h"
#include <forward_list>
#include <iostream>

using namespace std;

// -------------------------------------------------------------------------
/** CommandFactory
 * Command Factory Constructor
 *
 * Builds a CommandFactory for the inputted library
 * @param books book DB command uses
 * @param patrons patron DB command uses
 * @pre None
 * @post Stores private pointer to library
 */
CommandFactory::CommandFactory(BookDatabase* books, PatronDatabase* patrons)
{
   bookDB = books;
   patronDB = patrons;

   commandTypes[CHECKOUT_CODE - HASH_START] = new CheckoutBook(books, patrons);
   commandTypes[RETURN_CODE - HASH_START] = new ReturnBook(books, patrons);
   commandTypes[DISPLAY_LIB_CODE - HASH_START] =
       new DisplayLibrary(books, patrons);
   commandTypes[DISPLAY_PAT_CODE - HASH_START] =
       new DisplayPatronHistory(books, patrons);
}

// -------------------------------------------------------------------------
/** ~CommandFactory
 * Command Factory Destructor
 *
 * Destroys the CommandFactory
 * @pre None
 * @post Returns CommandFactory to memory, nothing else
 */
CommandFactory::~CommandFactory()
{
   for (const LibraryCommand* comm : commandTypes) {
      if (comm != nullptr) {
         delete comm;
      }
   }
}

// -------------------------------------------------------------------------
/** createCommands
 * Create Commands
 *
 * Reads the file, creating LibraryCommands and storing them
 * into a CommandQueue
 * @param is Pointer to an input file containing text form of commands
 * @pre file must be properly formatted
 * @post CommandQueue is initialized and filled. Library unchanged.
 * @return A filled CommandQueue object
 */
LibraryCommand* CommandFactory::createCommand(istream& is)
{
   LibraryCommand* comm = nullptr;
   char type = is.get();
   string line;
   int index = type - HASH_START;
   if (index < 0 || index >= HASH_SIZE) { // ERROR
      cout << "COMMAND INPUT ERROR: Command type " << type
           << " does not exist." << endl;
      getline(is, line);
      return nullptr; // character is out of range
   }
   if (commandTypes[index] == nullptr) { // ERROR
      cout << "COMMAND INPUT ERROR: Command type " << type
           << " does not exist." << endl;
      getline(is, line);
      return nullptr; // no command type doesnt exist
   }
   comm = commandTypes[index]->create();

   is.get();
   if (!comm->initialize(is)) {
      delete comm;
      return nullptr;
   }

   return comm;
}
