/** @file bookfactory.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - A BookFactory object represents the factory class that creates Book
 *     objects in their different subtypes to be stored in the books database.
 *   - Can create a book and correctly classify it as the right type using
 *     string data provided by the LibraryBuilder.
 *   - Holds three types of books: Fiction, Periodicals, and Children.
 *
 *
 * Implementation:
 *   - This a factory class following the factory design pattern.
 *   - Contains one function used to create and classify a book using
 *     string data.
 *   - Classifies each type of book and creates the correct sub-class of
 *     book for each string passed in.
 */

#include "book.h"
#include "fiction.h"
#include "periodical.h"
#include "children.h"
#include <iostream>
#include "bookfactory.h"
#include "constants.h"

using namespace std;

// -------------------------------------------------------------------------
/** BookFactory()
 * Default constructor
 * 
 * Constructs BookFactory instance, instantiates hashmap
 * @pre None.
 * @post BookFactory exists
 */
BookFactory::BookFactory() {
   // type's Ascii value - hash_start ascii value (defined in constants.h)
   bookTypes[FICTION_CODE - HASH_START] = new Fiction();
   bookTypes[PERIODICAL_CODE - HASH_START] = new Periodical();
   bookTypes[CHILDREN_CODE - HASH_START] = new Children();

}

// -------------------------------------------------------------------------
/** ~BookFactory()
 * Destructor
 * 
 * Deletes the books in the hashmap before deleting self
 * @pre None.
 * @post this BookFactory, its hashmap, and the Books it pointed to are 
 * deleted
 */
BookFactory::~BookFactory() {
   for (const Book* ptr : bookTypes) {
      if (ptr != nullptr) { 
         delete ptr;
      }
   }
}

// -------------------------------------------------------------------------
/** createBook()
 * Builder Function
 *
 * Creates a Book using the data provided as string input and creates it
 * using the correct book subclass. Inserts in to the bookTypes array and
 * returns a pointer to the Book just inserted.
 * @param is the istream used to build a book
 * @pre string bookString.
 * @post Book pointer.
 */
Book* BookFactory::createBook(istream& is) const {
   char type = toupper(is.get());
   
   string line;
   int index = type - HASH_START;
   if (index < 0 || index >= HASH_SIZE) { //ERROR
      cout << "BOOK INPUT ERROR: not a recognized type." << endl;
      getline(is, line);
      return nullptr; //character is out of range
   }
   if (bookTypes[index] == nullptr) { //ERROR
      cout << "BOOK INPUT ERROR: " << type << " is not a recognized type." << endl;
      getline(is, line);
      return nullptr; //no booktype exists
   }

   Book* newBook = bookTypes[index]->create();

   if (!newBook->setData(is)) { //improper input
      delete newBook;
      return nullptr;
   }

   return newBook;
}

// -------------------------------------------------------------------------
/** getHash()
 * get hash
 * 
 * turn the type of book into a hash key.
 * @param book the book that we want to get the key for
 * @pre None
 * @post None
 * @return int representing hash key/index of book type
 */
int BookFactory::getHash(const Book& book) const {
   string type = book.getType();
   return type[0] - HASH_START;
}


