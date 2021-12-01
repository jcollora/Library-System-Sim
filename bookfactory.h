/** @file bookfactory.h
 * @author Joseph Collora and Josh Helzerman
 * 
 * Description:
 *   - A BookFactory object represents the factory class that creates Book
 *     objects in their different subtypes to be stored in the books database.
 *   - Can create a book and correctly classify it as the right type using
 *     string data provided by the LibraryBuilder.
 *   - Holds three types of books: Fiction, Periodicals, and Children.
 *
 * Implementation:
 *   - This a factory class following the factory design pattern.
 *   - Contains one function used to create and classify a book using
 *     string data.
 *   - Classifies each type of book and creates the correct sub-class of
 *     book for each string passed in.
 */

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

#include "book.h"
#include <iostream>
#include "constants.h"

using namespace std;

class BookFactory
{
public:
   // -------------------------------------------------------------------------
   /** BookFactory()
    * Default constructor
    * 
    * Constructs BookFactory instance, instantiates hashmap
    * @pre None.
    * @post BookFactory exists
    */
   BookFactory();

   // -------------------------------------------------------------------------
   /** ~BookFactory()
    * Destructor
    * 
    * Deletes the books in the hashmap before deleting self
    * @pre None.
    * @post this BookFactory, its hashmap, and the Books it pointed to are 
    * deleted
    */
   ~BookFactory();

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
   Book* createBook(istream& is) const;

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
   int getHash(const Book& book) const;

private:
   // Array of subclasses of Book object to classify each book as its correct
   //  type.
   const Book* bookTypes[HASH_SIZE] {};

};

#endif