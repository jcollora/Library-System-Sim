/** @file checkoutBook.cpp
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. checks out book for patron from library
 *
 * Implementation
 *   - inherits from Command interface.
 *   - removes a copy of an existing book to the library
 */



#include "checkoutBook.h"
#include <iostream>
#include "constants.h"
#include "book.h"
#include "patron.h"

using namespace std;

// ------------------------------------------------------------------------
   /** CheckoutBook()
    * Default Constructor
    *
    * Constructs a checkout book command object with default values
    * @pre None.
    * @post CheckoutBook command object exists
    */
CheckoutBook::CheckoutBook(BookDatabase* books, PatronDatabase* patrons) {
   bookDB = books;
   patronDB = patrons;
   type = TYPE_CHECKOUT;
   commandCode = CHECKOUT_CODE;
}

// -------------------------------------------------------------------------
   /** execute()
    * Execute checkout book command
    *
    * adds selected book to the patron's current books and decrements the
    * book's count. It searches for the book by creating a book with the
    * bookID. then comparing that to books in the BST
    * @pre The patron and book should exist in the system
    * @post patron and book are updated accordingly
    */
void CheckoutBook::execute() {
   

   if (!book->removeBook()) {
      cout << "CHECKOUT COMMAND EXECUTIONERROR: Patron " << patron->getID()
           << "Can't checkout book, library contains no books left titled: "
           << book->getTitle() << endl;
      delete this;
      return;
   }
   patron->addBook(book);
   patron->addCommand(this); //if all functions successfull, store command
}

/** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
LibraryCommand* CheckoutBook::create() const {
   return new CheckoutBook(bookDB, patronDB);
}
