/** @file patron.h
 * @author  Joseph Collora and Josh Helzerman
 * 
 * Description:
 * - A patron object represents a unique customer + its id, name, and history
 * - History can be updated (removal and addition)
 * - Can be queried to display its information
 * - Can be compared with other patrons
 * 
 * Implementation:
 * - Some functions are virtual -of BSTData
 * - Patron History stored in a list of strings
 * 
 */

#ifndef PATRON_H
#define PATRON_H

using namespace std;

#include "constants.h"

#include "BSTData.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class LibraryCommand;
class Book;

class Patron : public BSTData 
{
public:
    // -------------------------------------------------------------------------
   /** Patron()
     * Default Constructor
     *
     * Creates a Patron object. Member variables are instantiated to default
     * values. Book requires a book factory in order to be properly instantiated
     * with data
     * @pre None.
     * @post Patron object exists with default member variables
    */
   Patron();

   // -------------------------------------------------------------------------
    /** ~Patron()
     * Destructor
     * 
     * Deletes Patron from memory. It's empty, but apparently helps to delete
     * strings
     * @pre None.
     * @post Patron instance is deleted
    */
   virtual ~Patron();

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
   /** operator<()
    * Operator less than overload
    *
    * Compares this patron to right-hand patron to see if this is less than rhs
    * @param rhs patron to be compared
    * @pre None.
    * @post None. const
    * @return true if this patron is less than rhs, else false
    */
   virtual bool operator<(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator>()
    * Operator greater than overload
    *
    * Compares this patron to right-hand patron to see if this is greater than 
    * rhs
    * @param rhs patron to be compared
    * @pre None.
    * @post None. const
    * @return true if this patron is greater than rhs, else false
    */
   virtual bool operator>(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator==()
    * Operator equal to overloadd
    *
    * Compares this patron to right-hand patron to see if this is equal to rhs
    * @param rhs patron to be compared
    * @pre None.
    * @post None. const
    * @return true if this patron is equal to rhs, else false
    */
   virtual bool operator==(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator!=
    * Inequality Operator
    * 
    * Determines if right and left items are not equivelent
    * @pre Both items being compared exist
    * @post None.
    * @return false returned when left is equal to right, true otherwise
    */
   virtual bool operator!=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator<=()
    *  Less than or equal operator
    * 
    * Determines if the right and left items are equivelent or less than
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is equal to right or
    * if left is less than right, false otherwise
    */
   virtual bool operator<=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator>=()
    *  greater than or equal operator
    * 
    * Determines if the right and left items are equivelent or greater than
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is equal to right or
    * if left is greater than right, false otherwise
    */
   virtual bool operator>=(const BSTData& rhs) const;

   // -------------------------------------------------------------------------
   /** operator=()
    * Copy assignment operator
    * 
    * Copy data from right hand item to left hand item.
    * @pre Items should not be the same item
    * @post left item contains data from rhs, right item is const
    * @return reference to left item
    */
   virtual BSTData& operator=(const BSTData& rhs);
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

      // -------------------------------------------------------------------------
    /** display 
     * display data
     * 
     * returns the data inside node as a string
     * @pre None
     * @post None
     * @return string representing data inside node
    */
    virtual ostream& display(ostream& os) const;

 private:
    // -------------------------------------------------------------------------
    /** compare()
     * Compare patrons
     *
     * Compare 2 patrons. Returns an integer that reflects the comparison
     * @pre None
     * @post new patron object exists
     * @return negative int if left patron < right.
     * return 0 if equal, return positive int if left > right
    */
    int compare(const Patron& rhs) const;

    // id of the patron
    int id;

    // name of the patron
    string lastName;
    string firstName;

    // patron command history vector of commands in history
    vector<const LibraryCommand*> commandHistory;

    // current books checkout out by patron. DOES NOT ALLOW FOR DUPLICATES
    unordered_set<const Book*> currentCheckouts;
};

#endif 