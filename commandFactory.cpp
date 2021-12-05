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

#include <forward_list>
#include "libraryCommand.h"
#include "constants.h"
#include <iostream>
#include "checkoutBook.h"
#include "returnBook.h"
#include "displayLibrary.h"
#include "displayPatronHistory.h"


using namespace std;

// -------------------------------------------------------------------------
/** CommandFactory
 * Command Factory Constructor
 *
 * Builds a CommandFactory for the inputted library
 * @param library The library to create commands for
 * @pre None
 * @post Stores private pointer to library
 */
CommandFactory::CommandFactory(BookDatabase* books, PatronDatabase* patrons) {
   bookDB = books;
   patronDB = patrons;

   commandTypes[CHECKOUT_CODE] = new CheckoutBook();
   commandTypes[RETURN_CODE] = new ReturnBook();
   commandTypes[DISPLAY_LIB_CODE] = new DisplayLibrary();
   commandTypes[DISPLAY_PAT_CODE] = new DisplayPatronHistory();

}

// -------------------------------------------------------------------------
/** ~CommandFactory
 * Command Factory Destructor
 *
 * Destroys the CommandFactory
 * @pre None
 * @post Returns CommandFactory to memory, nothing else
 */
CommandFactory::~CommandFactory() {
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
 * @param file Pointer to an input file containing text form of commands
 * @pre file must be properly formatted
 * @post CommandQueue is initialized and filled. Library unchanged.
 * @return A filled CommandQueue object
*/
LibraryCommand* CommandFactory::createCommand(istream& is) {
   LibraryCommand* comm = nullptr;
   char type = is.get();
   comm = commandTypes[type - HASH_START]->create();
   if (comm == nullptr) { //ERROR: command type doesnt exist
      return comm;
   }
   is.get();
   comm->initialize(is);

   return comm;

}

