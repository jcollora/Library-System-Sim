/** @file patron.h
 * @author Joseph Collora
 * 
 * Description:
 * - A patron object represents a unique customer + its id, name, and history
 * - History can be updated (removal and addition)
 * - Can be queried to display its information
 * - Can be compared with other patrons
 * - 
 * 
 * Implementation:
 * - Some functions are virtual -of BSTData
 * - Patron History stored in a list of strings
 */

#ifndef PATRON_H
#define PATRON_H

using namespace std;

#include "BSTData.h"
#include <string>
#include <vector>
#include "constants.h"
#include "libraryCommand.h"
#include <unordered_set>

#include "book.h"

class Patron : public BSTData 
{
    public:
    // constr / destr need these

    // -------------------------------------------------------------------------
   /** addBook()
    * Add book to currentCheckouts
    * @param book the book to checkout
    * @pre Book object must exist and should have available copies, 
    * Book's count will need to be updated if this is successful
    * @post if successful, the book is added to the set of currentCheckouts
    * (notes for command: book will decrease in count if success, book points 
    * to patron command
    * will add itself to the patron command history if success)
    * @return True only if patron does not already have the book
    */
    bool addBook(const Book* book);

   // -------------------------------------------------------------------------
   /** removeBook()
    * @param book the book to return
    * @pre Book should exist
    * @post If successful, book is removed from currentCheckouts.
    * (notes for comand: book count++, book no longer points to patron,
    *  command adds itself to patron)
    * @return true only if Patron had the book checked out
    */
   bool removeBook(const Book* book);

    // -------------------------------------------------------------------------
    /** displayPatron()
    * @pre None.
    * @post None. const function
    * @return "ID   LastName, FirstName" as a string
    */
   string displayPatron() const;

// -------------------------------------------------------------------------
    /** displayPatronHistory()
    * @pre None.
    * @post None. const function
    * @return string of commands in commandHistory
    */  
    string displayPatronHistory() const;

// -------------------------------------------------------------------------
    /** setData()
     * input data into node
     * 
     * Take data from inputStream and put into node members
     * @pre must have a properly formatted input file
     * @post line of input is read. BSTData contains line data
     * @return true if line of data was read, false if no line or bad format
    */
    virtual bool setData(istream& is);


    private:
    // id of the patron
    int id;

    // name of the patron
    string lastName;

    string firstName;

    // patron command history -list of strings
    // wip : "List of Strings"

    vector<const LibraryCommand*> commandHistory;

    // current books checkout out by patron. DOES NOT ALLOW FOR DUPLICATES
    unordered_set<const Book&> currentCheckouts;
};

#endif 