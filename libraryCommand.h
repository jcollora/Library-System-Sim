/** @file librarycommand.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Class that encapsulates a variety of LibraryCommands that the library
 * manager can execute
 *
 * Implementation:
 *   - this is an abstract class and must be implemented in the child classes
 *   - this class is similar to an interface in Java
 *
 */

#ifndef LIBRARYCOMMAND_H
#define LIBRARYCOMMAND_H


#include "patronDatabase.h"
#include <iostream>

class Library;
class PatronDatabase;
class BookDatabase;
class Book;

using namespace std;

class LibraryCommand
{
public:
   // -------------------------------------------------------------------------
   /** LibraryCommand()
    * Defaul Constructor
    *
    * Constructs a LibraryCommand object.
    * @pre None.
    * @post LibraryCommand object exists
    */
   LibraryCommand();

   // -------------------------------------------------------------------------
   /** execute()
    * Execute LibraryCommand
    *
    * Executes this LibraryCommand object. This is pure virtual and must be
    * implemented in derived classes
    * @pre TBD
    * @post TBD
    */
   virtual void execute() = 0;

   /** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
   virtual LibraryCommand* create() const = 0;

   /** initialize()
    * initialize command with data
    *
    * Uses a string to put data into the command
    * @pre string must be formatted properly
    * @post the command now contains the data from the string
    * @return string is not formmatedd correctly return false,
    * else return true
    */
   virtual bool initialize(istream& is);

   string getType() const;

   virtual void display(ostream& os) const;

protected:
   // pointer to library object that this command exists in
   Library* library;

   PatronDatabase* patronDB;
   BookDatabase* bookDB;

   char commandCode;

   string type;

   // ID of patron this command uses
   Patron* patron;

   // ID of book this command uses
   Book* book;


   
};

#endif