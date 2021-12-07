/** @file displayPatronHistory.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. displays patron's book history
 *
 * Implementation
 *   - inherits from Command interface.
 *   - displays patron book history
 */

#ifndef DISPLAYPATRONHISTORY_H
#define DISPLAYPATRONHISTORY_H

#include "library.h"
#include "libraryCommand.h"
#include <string>

using namespace std;

class DisplayPatronHistory : public LibraryCommand
{
public:
   // -------------------------------------------------------------------------
   /** DisplayPatronHistory()
    * Default Constructor
    *
    * Constructs a display patron book history command object with default
    * values
    * @pre None.
    * @post DisplayPatronHistory command object exists
    */
   DisplayPatronHistory(BookDatabase* books, PatronDatabase* patrons);

   // -------------------------------------------------------------------------
   /** execute()
    * Execute display patron history command
    *
    * Prints patron history
    * @pre The patron should exist in the system
    * @post None. patron is unchanged
    */
   virtual bool execute();

   /** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
   virtual LibraryCommand* create() const;

   /** initialize()
    * initialize command with data
    *
    * Uses a string to put data into the command
    * @pre string must be formatted properly
    * @post the command now contains the data from the string
    * @return string is not formmatedd correctly return false,
    * else return true
    */
   virtual bool initialize(istream& is);
};

#endif