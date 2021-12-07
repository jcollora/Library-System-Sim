/** @file returnBook.cpp
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. returns book from patron to library
 *
 * Implementation
 *   - inherits from Command interface.
 *   - adds a copy of an existing book to the library
 */

#include "returnBook.h"
#include "book.h"
#include "bookDatabase.h"
#include "constants.h"
#include "libraryCommand.h"
#include "patron.h"
#include <iostream>
#include <string>

// -------------------------------------------------------------------------
/** ReturnBook()
 * Default Constructor
 *
 * Constructs a return book command object with default values
 * @pre None.
 * @post ReturnBook command object exists
 */
ReturnBook::ReturnBook(BookDatabase* books, PatronDatabase* patrons)
{

   patronDB = patrons;
   bookDB = books;
   type = TYPE_RETURN;
   commandCode = RETURN_CODE;
}

// -------------------------------------------------------------------------
/** execute()
 * Execute return book command
 *
 * updates the patron's current books and increments the book's count
 * @pre The patron and book should exist in the system
 * @post patron and book are updated accordingly
 */
void ReturnBook::execute()
{

   if (!book->addBook()) {
      cout << "RETURN COMMAND EXECUTION ERROR: Patron " << patron->getID()
           << "Can't return book, library contains max books titled: "
           << book->getTitle() << endl;
      delete this;
      return;
   }
   if (!patron->removeBook(book)) {
      cout << "RETURN COMMAND EXECUTION ERROR: Patron " << patron->getID()
           << " Can't return book, because they did not checkout book titled: "
           << book->getTitle() << endl;

      book->removeBook(); // undo addBook
      delete this;
      return;
   }
   patron->addCommand(this); // if all functions successfull, store command
}

/** create()
 * Create Library Command (factory)
 *
 * Create a library command of the appropriate type
 * this function is pure virtual
 * @pre None
 * @post a new library command exists
 */
LibraryCommand* ReturnBook::create() const
{
   return new ReturnBook(bookDB, patronDB);
}