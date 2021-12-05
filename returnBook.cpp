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
#include "libraryCommand.h"
#include <iostream>
#include <string>
#include "patron.h"
#include "constants.h"
#include "book.h"
#include "bookDatabase.h"
#include "constants.h"

ReturnBook::ReturnBook(BookDatabase* books, PatronDatabase* patrons)
{

   patronDB = patrons;
   bookDB = books;
   type = TYPE_RETURN;
   commandCode = RETURN_CODE;
}

LibraryCommand* ReturnBook::create() const { return new ReturnBook(bookDB, patronDB); }


void ReturnBook::execute()
{
   
   
   if (!book->addBook()) {
      cout << "ERROR: Patron " << patron->getID()
           << "Can't return book, library contains max books titled: "
           << book->getTitle() << endl;
      
      return;
   }
   if (!patron->removeBook(book)) {
      cout << "ERROR: Patron " << patron->getID()
           << "Does not hold the book they want to return titled: " 
           << book->getTitle() << endl;
      
      book->removeBook(); // undo addBook
      return;
   }
   patron->addCommand(this); //if all functions successfull, store command
}
