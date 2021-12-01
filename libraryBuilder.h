/** @file libraryBuilder.h
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

#ifndef LIBRARYBUILDER_H
#define LIBRARYBUILDER_H

using namespace std;

#include "commandFactory.h"
#include "patronDatabase.h"
#include <iostream>

class libraryBuilder 
{
public:
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
     * 
     */
    Library createLibrary(ifstream& books, ifstream& patrons);

private:
    // Factory for books component of library
    BookFactory bookFactory;
    // Factory for patron component of library
    PatronDatabase patronFactory;
};

#endif
