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
#include "bookDatabase.h"
#include "commandFactory.h"
#include "library.h"
#include "patronDatabase.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// -------------------------------------------------------------------------
/** createLibrary()
 * Create Library Object
 * Creates a library object populated with a database of patrons and books
 * and passes it. It uses factory objects to build books, and builds patrons
 * directly into their databse
 * @param books stream in for book data line by line
 * @param patrons
 * @pre None.
 * @post None.
 * @return Library object that includes two populated databases
 *         patron and book
 */
Library* LibraryBuilder::createLibrary(istream& books, istream& patrons)
{
   Library* newLib = new Library();
   BookDatabase* newBookDB = new BookDatabase();

   while (!books.eof()) {
      string line;
      stringstream inputLine;
      getline(books, line);
      if (line.empty()) {
         continue;
      }
      inputLine.str(line);
      if (!newBookDB->insertNewBook(inputLine)) {
         cout << endl;
      }
   }

   PatronDatabase* newPatronDB = new PatronDatabase();

   while (!patrons.eof()) {
      string line;
      stringstream inputLine;
      getline(patrons, line);
      if (line.empty()) {
         continue;
      }
      inputLine.str(line);
      if (!newPatronDB->insertNewPatron(inputLine)) {
         cout << endl;
      }
   }

   newLib->bookDB = newBookDB;
   newLib->patronDB = newPatronDB;
   newLib->commandFactory = new CommandFactory(newBookDB, newPatronDB);

   return newLib;
}
