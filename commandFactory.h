/**
 * @file commandFactory.h
 * @author Mogul Solutions
 *
 * Description:
 *   -Uses an input stream to read text and create commands based off it
 *   -The factory is associated with a library which commands are made for
 *
 * Assumptions/Implementation:
 *   -If the factory is destroyed, nothing else is deleted with it
 *   -Fetches the command to be made using CommandTypeHashmap
 *   -Delegates initializing a command to the command object.
 */

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H





#include <iostream>

using namespace std;

class Library;
class commandQueue;

class CommandFactory
{

public:
   /** CommandFactory
    * Command Factory Constructor
    *
    * Builds a CommandFactory for the inputted library
    * @param library The library to create commands for
    * @pre None
    * @post Stores private pointer to library
    */
   CommandFactory(Library* library);

   /** ~CommandFactory
    * Command Factory Destructor
    *
    * Destroys the CommandFactory
    * @pre None
    * @post Returns CommandFactory to memory, nothing else
    */
   ~CommandFactory();

   /** createCommands
    * Create Commands
    *
    * Reads the file, creating LibraryCommands and storing them
    * into a CommandQueue
    * @param file Pointer to an input file containing text form of commands
    * @pre file must be properly formatted
    * @post CommandQueue is initialized and filled. Library unchanged.
    * @return A filled CommandQueue object
    */
   CommandQueue* createCommands(ifstream file);

private:
   Library* library;
};

#endif