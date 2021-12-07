/** @file returnBook.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. returns book from patron to library
 *
 * Implementation
 *   - inherits from Command interface.
 *   - adds a copy of an existing book to the library
 */

#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include "libraryCommand.h"
#include <string>

class Patron;
class Book;

using namespace std;

class ReturnBook : public LibraryCommand
{
public:
   // -------------------------------------------------------------------------
   /** ReturnBook()
    * Default Constructor
    *
    * Constructs a return book command object with default values
    * @pre None.
    * @post ReturnBook command object exists
    */
   ReturnBook(BookDatabase* books, PatronDatabase* patrons);

   // -------------------------------------------------------------------------
   /** execute()
    * Execute return book command
    *
    * updates the patron's current books and increments the book's count
    * @pre The patron and book should exist in the system
    * @post patron and book are updated accordingly
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
};

#endif