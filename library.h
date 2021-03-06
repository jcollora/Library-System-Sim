/** @file library.h
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

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>

#include <queue>

class CommandQueue;
class CommandFactory;
class BookDatabase;
class PatronDatabase;
class LibraryCommand;

using namespace std;

class Library
{

   friend class LibraryBuilder;

public:
   // -------------------------------------------------------------------------
   /** Library()
    * Default Constructor
    * Constructs a Library object with default values for the patron database
    * @pre None.
    * @post Library object exists
    */
   Library();

   // -------------------------------------------------------------------------
   /** ~Library()
    * Destructor
    * Deletes the libary and its member variables
    * @pre None.
    * @post Library object and member variables deleted
    */
   ~Library();

   // -------------------------------------------------------------------------
   /** processComands()
    * This method is responsible for processing all of the library commands
    * that are provided by the ifstream
    * @pre None.
    * @param is an input file stream
    *                 a stream of data used for reading input from a file
    * @post commands are executed based on the parameter
    */
   void processCommands(istream& is);

private:
   // this member class is the d-base that holds all of the books for library
   BookDatabase* bookDB;
   // this memebr class is the d-base that holds all of the patrons for library
   PatronDatabase* patronDB;

   // Factory for creating commands and queue for execution order
   CommandFactory* commandFactory;

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
   void executeCommands(queue<LibraryCommand*>& commands);
};

#endif
