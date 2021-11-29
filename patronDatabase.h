/** @file patronDatabase.h
 *  @author Mogul Solutions
 *
 * Description:
 *   - Patron database is a database that holds all the patrons that will be 
 *     interacting with the library. The class allows you to create new patrons
 *     and retrieve a patron based on the Patron object that you pass in
 *
 * 
 */
#ifndef PATRONDATABASE_H
#define PATRONDATABASE_H

#include "patron.h"
#include <vector>
#include "constants.h"
#include "BSTree.h"
#include <iostream>

class PatronDatabase{
    public:

    // -------------------------------------------------------------------------
    /** PatronDatabase()
    * Default Constructor
    *
    * Constructs a PatronDatabase object with default values
    * 
    * @pre None.
    * @post PatronDatabase object exists
    */
    PatronDatabase();

    //Destructor needed

    //--------------------------------------------------------------------------
    /** createPatron(Patron customer)
    * createPatron
    *
    * Creates a patron based on the contentse of the given customer
    * @param customer a patron to be created
    * @pre None
    * @post customer is created as a Patron object
    * @return true if it was successfully created
    */
    bool insertNewPatron(istream& is);

    //--------------------------------------------------------------------------
    /** getPatron(String patronId)
    * 
    * Return a Patron object based on the information that is passed in
    * @param patronID the ID used to find the patron
    * @pre None.
    * @post None. const function
    * @return Patron* representing the Patron object that they are looking for if found
    */
    Patron* getPatron(string patronId) const;

    private:
    //the variable below is a class member variable
    //this is a BST of patrons
    BSTree patronBST;

};

#endif