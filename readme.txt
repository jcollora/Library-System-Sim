1. All functions work accourding to specifications. 
Books and Patrons are properly created and inserted. 
Commands are compiled from the command file, correct commands are inserted
into a command queue. After all commands are compiled, each command in the
queue is exected. Specific error messages are printed if command data cannot be
compiled and then again if the command cannot be executed. 
No memory leaks.

2. Book factory hashtable, has book types in it, uses character 
ascii code to get a hash key that allows the factory to 
determine the book type from a line of bookinput, returns an empty 
new book of the correct type to be filled.

   BSTree hashtable in BookDatabase is a array full of empty BSTrees.
   Nodes are inserted into the tree based on their book type code. this code
   is an ASCII character that is used as a hash key to determine the BSTree
   that contains books with the same code.

   Command Factory uses a hashtable to determine what command to build, 
   functions exactly like book factory hashtable except it returns new
   commands rather than new books.

3. Inside main.cpp:
      book data = data4books.txt.
      LibraryBuilder.createLibrary(book data).

   Inside LibraryBuilder.cpp:
      createLibrary(book data):
         for each LINE in book data:
            bookDB.insertNewBook(LINE).
         endfor
   
   Inside bookDatabase.cpp [bookDB]:
      insertNewBook(LINE):
         newBook = bookFactory.createBook(LINE).
         get hash code of newBook.
         insert newBook in bookShelf [the BSTree].

   Inside bookFactory.cpp:
      createBook(LINE):
         create new book of proper type.
         put data from line into book.

4. Inside main.cpp:
      command data = data4commands.txt.
      Library.processCommands(command data).

   Inside library.cpp
      processCommands(command data):
         for each LINE in command data:
            newCommand = commandFactory.createCommand(LINE).
            push newCommand to command queue.
         endfor
         executeCommands(command queue).

      executeCommands(command queue):
         while queue is not empty:
            pop command from queue (FIFO).
            execute command.
         endwhile

5. When printing books, instead of gracefully implementing both cases where 
one excludes the book count we made two distinct methods.

6. In our implementations of BSTData (inside patron, fiction, children, ..) 
we used a compare method which returns an int value indicating the state of 
comparisson between the current instance and the rhs. The rest of our 
comparisson operators simply invoke it and return true or false depending 
on the integer returned. This saved us from writing a ton of code for the 
operators, and it works every time.

We are also very proud of how we used C++ RegEx to help the periodical
class's input function to determine whether it was receiving input
from book data file or command data file, as these two files
input into Periodical in different orders

The last thing we are proud of was how we used a constants header file, 
that we would include whenever a constant value would be needed, which 
makes it easy expand out in many ways. Including adding new items to 
the library in the future. No magic numbers/phrases are used 
(except for error messages)
