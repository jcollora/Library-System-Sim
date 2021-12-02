/** @file libraryBuilder.cpp
 * @author Joseph Collora and Josh Helzerman
 * 
 * Description:
 *   - Builds the library from a file and returns a resulting library with
 *     its included databases.
 * 
 * Implementation:
 *   - Library contents are streamed into a file
 *   - Library items operate with their own indipendent input files
 * 
 */

#include "libraryBuilder.h"
#include <iostream>
#include "library.h"
#include "bookDatabase.h"
#include "patronDatabase.h"



using namespace std;

Library* LibraryBuilder::createLibrary(istream& books, istream& patrons) {
   Library* newLib = new Library();
   BookDatabase* newBookDB = new BookDatabase();
   while (!books.eof()) {
      newBookDB->insertNewBook(books);
      
      

   }
   newBookDB->displayAll(); //test code. delete this
   PatronDatabase* newPatronDB = new PatronDatabase();

   while (!patrons.eof()) {
      newPatronDB->insertNewPatron(patrons);

   }

   newLib->bookDB = newBookDB;
   newLib->patronDB = newPatronDB;

   return newLib;

}