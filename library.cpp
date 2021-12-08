/** @file library.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - Library class is an object that includes pointers to both the patron and
 *     the book database.
 *   - The class processes all of the commands that are come
 *     from an input data stream
 *
 * Implementation:
 *   - Books, patrons, and commands stored in: a BookDatabase, PatronDatabase, 
 *     and CommandFactory respectively
 *   - Executes commands with a queue to simmulate patrons entering commands
 *     in a set order
 *
 */

#include "library.h"
#include "bookDatabase.h"
#include "commandFactory.h"
#include "libraryCommand.h"
#include "patronDatabase.h"
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

// -------------------------------------------------------------------------
/** Library()
 * Default Constructor
 * Constructs a Library object with default values for the patron database
 * @pre None.
 * @post Library object exists
 */
Library::Library()
{
   bookDB = nullptr;
   patronDB = nullptr;
   commandFactory = nullptr;
}

// -------------------------------------------------------------------------
/** ~Library()
 * Destructor
 * Deletes the libary and its member variables
 * @pre None.
 * @post Library object and member variables deleted
 */
Library::~Library()
{
   delete bookDB;
   delete patronDB;

   delete commandFactory;
}

// -------------------------------------------------------------------------
/** processComands()
 * This method is responsible for processing all of the library commands that
 * are provided by the ifstream
 * @pre None.
 * @param ifstream an input file stream
 *                 a stream of data used for reading input from a file
 * @post commands are executed based on the parameter
 */
void Library::processCommands(istream& is)
{
   queue<LibraryCommand*> commandQueue;

   while (!is.eof()) {

      string line;
      stringstream inputLine;
      getline(is, line);
      if (line.empty()) {
         continue;
      }
      inputLine.str(line);
      LibraryCommand* comm = commandFactory->createCommand(inputLine);
      if (comm != nullptr) {
         commandQueue.push(comm);
      } else {
         cout << endl;
      }
   }

   executeCommands(commandQueue);
}

// -------------------------------------------------------------------------
/** executeCommands()
 * Execute Command Queue
 * 
 * Takes a command out of the front of the queue and invokes its execute 
 * method, thereby simmulating the natural order of patron command 
 * execution.
 * @param commands queue of commands to be iteratively executed
 * @pre None.
 * @post Commandqueue is empty
 */
void Library::executeCommands(queue<LibraryCommand*>& commands)
{
   while (!commands.empty()) {
      LibraryCommand* comm = commands.front();
      commands.pop();
      if (!comm->execute()) {
         cout << endl;
      }
   }
}
