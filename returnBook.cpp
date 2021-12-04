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

ReturnBook::ReturnBook()
{
   patron = nullptr;
   book = nullptr;
}

LibraryCommand* ReturnBook::create() const { return new ReturnBook(); }

bool ReturnBook::initialize(istream& is)
{
   string patronID, line;
   is >> patronID;
   patron = patronDB->getPatron(patronID);
   is.get();
   if (patron == nullptr) {
      getline(is, line);
      return false;
   }
   book = bookDB->getBook(is);
   if (book == nullptr) {
      getline(is, line);
      return false;
   }
   getline(is, line);
   return true;
}

void ReturnBook::execute()
{
   if (!book->removePatron(patron)) {
      cout << "ERROR: Patron " << patron->getID()
           << " cannot return book they didn't check out titled: "
           << book->getTitle() << endl;
   }
   
   if (!book->addBook()) {
      cout << "ERROR: Patron " << patron->getID()
           << "Can't return book, library contains max books titled: "
           << book->getTitle() << endl;
      book->addPatron(patron); //undo removePatron
      return;
   }
   if (!patron->removeBook(book)) {
      cout << "ERROR: Patron " << patron->getID()
           << "Does not hold the book they want to return titled: " 
           << book->getTitle() << endl;
      book->addPatron(patron); //undo removePatron
      book->removeBook(); // undo addBook
      return;
   }
   patron->addCommand(this); //if all functions successfull, store command
}
