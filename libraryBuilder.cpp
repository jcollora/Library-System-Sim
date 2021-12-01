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



using namespace std;

Library* LibraryBuilder::createLibrary(ifstream& books, ifstream& patrons) {
   Library* newLib = new Library();

   return newLib;

}