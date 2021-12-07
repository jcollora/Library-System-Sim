/** @file bookDatabase.h
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - BookDatabase holds all of the children, periodical, and fiction books
 *     that are inserted from the book factory.
 *   - As well as it is able to display them
 *     and retrieve a book
 *
 * Implementation:
 *   -  Contains an array of pointers to BSTrees, each element reprisents a
 *      hashed value corresponding to booktype
 *   -  Uses a "Book Factory" to produce books to insert
 *
 */

#include "bookDatabase.h"
#include "BSTree.h"
#include "book.h"
#include "constants.h"
#include <iomanip>
#include <vector>

using namespace std;

// ------------------------------------------------------------------------
/** BookDatabase()
 * Default Constructor
 *
 * Constructs a BookDatabase object with default values
 *
 * @pre None.
 * @post BookDatabase object exists
 */
BookDatabase::BookDatabase()
{
   for (int i = 0; i < HASH_SIZE; i++) {
      bookShelf[i] =
          new BSTree(); // make it fixed siz e using final const HASH_SIZE?
   }
}

// ------------------------------------------------------------------------
/** ~BookDatabase()
 * Destructor
 *
 * Destructs instance as well as BSTrees in array
 * @pre None
 * @post this instance and all BSTree instances in the array are deleted
 */
BookDatabase::~BookDatabase()
{
   for (int i = 0; i < HASH_SIZE; i++) {
      delete bookShelf[i];
   }
}

//-------------------------------------------------------------------------
/** insertNewBook()
 * Insert Method
 *
 * Inserts the given book into the correct BST
 * @param is book input
 * @pre None
 * @post newBook is added to the right BST, if successful
 * @return true if newBook was successfully inserted
 */
bool BookDatabase::insertNewBook(istream& is)
{
   Book* newBook = bookFactory.createBook(is);
   if (newBook == nullptr) {
      return false;
   }
   int index = bookFactory.getHash(*newBook);

   if (!bookShelf[index]->insert(newBook)) {
      cout << "BOOK INPUT ERROR (DUPLICATE BOOK): Book titled " << endl
           << newBook->getTitle().substr(0, TITLE_MAX_LENGTH)
           << " already exists in this library." << endl;
      delete newBook;
      return false;
   }
   return true;
}

//-------------------------------------------------------------------------
/** getBook(String bookId)
 *
 * Return a book object based on the information that is passed in if it is in
 * a BST
 *
 * @param is input used to find book
 * @pre None.
 * @post None. const function
 * @return Book* representing the Book object that they are looking for if
 * found
 */
Book* BookDatabase::getBook(istream& is) const
{
   Book* bookToFind = bookFactory.createBook(is);
   if (bookToFind == nullptr) {
      return nullptr;
   }
   BSTData* bookFound = nullptr;

   int index = bookFactory.getHash(*bookToFind);
   bookShelf[index]->retrieve(*bookToFind, bookFound);
   delete bookToFind;
   return (Book*)bookFound;
}

//--------------------------------------------------------------------------
/** displayAll() const
 *
 * Displays all of the books that have been inserted in the database.
 *
 * The books are printed based on their class memeber variables
 *
 * @pre None.
 * @post None. const function
 */
void BookDatabase::displayAll() const
{
   for (BSTree* tree : bookShelf) {
      if (!tree->isEmpty()) {
         cout << endl;

         const BSTData* data = tree->getRoot();
         const Book* book = static_cast<const Book*>(data);
         book->displayHeader(cout);
         cout << endl;
      }
      cout << *tree;
   }
}