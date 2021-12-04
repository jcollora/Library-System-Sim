/** @file patronDatabase.h
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - Patron database is a database that holds all the patrons that will be 
 *     interacting with the library. 
 *   - The class allows you to create new patrons
 *     and retrieve a patron based on the Patron object that you pass in
 *  
 * Implementation:
 *   - Database of patrons exists as a "BSTree"
 * 
 */
#ifndef PATRONDATABASE_H
#define PATRONDATABASE_H

#include "constants.h"
#include <istream>
#include <vector>

using namespace std;

class Patron;
class BSTree;

class PatronDatabase
{
public:
    /** 
    // -------------------------------------------------------------------------
    /** PatronDatabase()
     * Default Constructor
     * Constructs a PatronDatabase object with default values
     * @pre None.
     * @post PatronDatabase object exists
     * 
     */
    PatronDatabase();

    // -------------------------------------------------------------------------
    /** ~PatronDatabase() 
     * Destructor
     * Destroys all instances of new "BSTrees"
     * @pre Current instance of PatronDatabase exists
     * @post All new allocations of memory are deleted
     */
    ~PatronDatabase(); 

    //--------------------------------------------------------------------------
    /** createPatron(Patron customer)
     * createPatron
     * Creates a patron based on the contentse of the given customer
     * @param customer a patron to be created
     * @pre None
     * @post customer is created as a Patron object
     * @return true if it was successfully created
     */
    bool insertNewPatron(istream& is);

    //--------------------------------------------------------------------------
    /** getPatron(String patronId)
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
    BSTree* patronBST;

};

#endif