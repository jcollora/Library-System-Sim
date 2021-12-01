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
   BookDatabase* newbookDB = new BookDatabase();
   do {
      newbookDB->insertNewBook(books);

   } while (!books.eof());

   PatronDatabase* newpatronDB = new PatronDatabase();

   do {
      newpatronDB->insertNewPatron(patrons);

   } while (!patrons.eof());

   newLib->bookDB = newbookDB;
   newLib->patronDB = newpatronDB;

   return newLib;

}