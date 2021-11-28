/** @file bookDatabase.h
 *  @author Mogul Solutions
 *
 * Description:
 *   BookDatabase holds all of the children, periodical, and fiction books that
 *   are inserted from the book factory. As well as it is able to display them 
 *   and retrieve a book
 *
 */
#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include "BSTree.h"
#include "book.h"
#include "bookfactory.h"

using namespace std;

class BookDatabase
{
    public:

    // -------------------------------------------------------------------------
    /** BookDatabase()
    * Default Constructor
    *
    * Constructs a BookDatabase object with default values
    * 
    * @pre None.
    * @post BookDatabase object exists
    */
    BookDatabase();

    //--------------------------------------------------------------------------
    /** insertNewBook()
    * Insert Method
    *
    * Inserts the given book into the correct BST
    * @param is book input
    * @pre None
    * @post newBook is added to the right BST, if successful
    * @return true if newBook was successfully inserted
    */
    bool insertNewBook(istream& is);
    
    //--------------------------------------------------------------------------
    /** getBook(String bookId)
    * 
    * Return a book object based on the information that is passed in if it is in a BST
    * 
    * @param is input used to find book
    * @pre None.
    * @post None. const function
    * @return Book* representing the Book object that they are looking for if found
    */
    Book* getBook(istream& is) const;
    
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
    void displayAll() const;

    private:
    //below are all the class memeber variables used in this class
    
   BSTree* bookLibrary[26] {};

   BookFactory bookFactory;

     

};

#endif