1. All functions work accourding to specifications. Books and Patrons are properly created and inserted. Commands are built and executed via queue and print out specific error messages for improper inputs. No memory leaks.

2. Book factory hashtable, has book types in it, uses character ascii to determine type from a line of bookinput, returns an empty new book of the correct type to be filled.

   BSTree hashtable in BookDatabase to determine the right BSTree to insert a newly made book, uses ascii to create the key.

   Command Factory uses a hashtable to determine what command to build, functions exactly like book factory hashtable except it returns commands and not new books.

3. LibraryBuilder.createLibrary(books[data4books], patrons[data4patrons])  -> bookDB.insertNewBook(inputLine) -> index = bookFactory.getHash(*newBook) -> (BSTData)bookshelf[index]->insert(newBook)

4. Library.processCommands(istream)-> commandFactory.createCommand(inputLine) -> commandTypes[hashkey]->create() -> (returns command*) -> Library.commandQueue.push(returned command)

Command data is read in library, which then compiles it into queue of commands to simulate the natural flow of command entry. The library iterates through queue and calls each command item's execution function in its own method "executeCommands()."

5. When printing books, instead of gracefully implementing both cases where one excludes the book count we made two distinct methods.

6. In our implementations of BSTData (inside patron, fiction, children, ..) we used a compare method which returns an int value indicating the state of comparisson between the current instance and the rhs. The rest of our comparisson operators simply invoke it and return true or false depending on the integer returned. This saved us from writing a ton of code for the operators, and it works every time.

We are also very proud of how we used C++ RegEx to distinguish between a book printing its member variables in the order meant for display and displayPatronHistory.

The last thing we are proud of was how we used a constants header file, that we would include whenver a constant value would be needed, which makes it easy expand out in many ways. Including adding new items to the library in the future.
 	