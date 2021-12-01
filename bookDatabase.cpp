/** @file bookDatabase.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   BookDatabase holds all of the children, periodical, and fiction books that
 *   are inserted from the book factory. As well as it is able to display them 
 *   and retrieve a book
 *
 */

#include "BSTree.h"
#include "book.h"
#include "BookDatabase.h"
#include <vector>

using namespace std;

BookDatabase::BookDatabase() {
   
   for (int i = 0; i < HASH_SIZE; i++) {
      bookLibrary.resize(HASH_SIZE);
      bookLibrary[i] = new BSTree(); //make it fixed size using final const HASH_SIZE?
   }
}

BookDatabase::~BookDatabase() {
   for (int i = 0; i < HASH_SIZE; i++) {
      
      delete bookLibrary[i];
      
   }
}

bool BookDatabase::insertNewBook(istream& is) {
   Book* newBook = bookFactory.createBook(is);
   if (newBook == nullptr) {
      return false;
   }
   int index = bookFactory.getHash(*newBook);
   return bookLibrary[index]->insert(newBook);

}

Book* BookDatabase::getBook(istream& is) const {
   Book* bookToFind = bookFactory.createBook(is);
   if (bookToFind == nullptr) {
      return nullptr;
   }
   BSTData* bookFound = nullptr;

   int index = bookFactory.getHash(*bookToFind);
   bookLibrary[index]->retrieve(*bookToFind, bookFound);

   return (Book*)bookFound;

}

void BookDatabase::displayAll() const {
   for (BSTree* tree : bookLibrary) {
      cout << tree;
   }
}