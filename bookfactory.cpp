/** @file bookfactory.cpp
 * @author Omar Ahmed
 *
 * Description:
 *   - A BookFactory object represents the factory class that creates Book
 *  objects in their different subtypes to be stored in the books database.
 *   - Can create a book and correctly classify it as the right type using
 * string data provided by the LibraryBuilder.
 *   - Holds three types of books: Fiction, Periodicals, and Children.
 *
 *
 * Implementation:
 *   - This a factory class following the factory design pattern.
 *   - Contains one function used to create and classify a book using
 * string data.
 *   - Classifies each type of book and creates the correct sub-class of
 * book for each string passed in.
 */

#include "book.h"
#include "fiction.h"
#include "periodical.h"
#include "children.h"
#include <iostream>
#include "bookfactory.h"

using namespace std;

BookFactory::BookFactory() {
   bookTypes['F' - 65] = new Fiction();
   bookTypes['P' - 65] = new Periodical();
   bookTypes['C' - 65] = new Children();

}

BookFactory::~BookFactory() {
   for (Book* ptr : bookTypes) {
      if (ptr != nullptr) {
         delete ptr;
      }
   }
   
}

Book* BookFactory::createBook(istream& is) const {
   char type = is.get();
   
   int index = type - 65;
   if (index < 0 || index > 25) {
      return nullptr; //character is out of range
   }
   if (bookTypes[index] == nullptr) {
      return nullptr; //no booktype exists
   }

   Book* newBook = bookTypes[index]->create();

   

   if (!newBook->setData(is)) { //improper input
      delete newBook;
      return nullptr;
   }

   return newBook;
}

int BookFactory::getHash(const Book& book) const {
   char type = book.getType();
   return type - 65;
}




