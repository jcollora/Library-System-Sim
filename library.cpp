/** @file library.cpp
 * @author Joseph Collora and Josh Helzerman
 *
 * Description:
 *   - Library class is an object that includes pointers to both the patron and
 *     the book database. 
 *   - The class processes all of the commands that are come
 *     from an input data stream
 *  
 * Implementation:
 *   - ...
 *   
 */ 

#include "library.h"
#include "commandFactory.h"
#include "commandQueue.h"
#include "bookDatabase.h"
#include "patronDatabase.h"

#include <iostream>



using namespace std;


Library::Library() {
   bookDB = nullptr;
   patronDB = nullptr;
   //commandQueue = nullptr;
   //commandFactory = nullptr;
}

Library::~Library() {
   delete bookDB;
   delete patronDB;
   //delete commandQueue;
   //delete commandFactory;
}

void Library::processCommands(istream& is) {

}
