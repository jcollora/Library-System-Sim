

#include <cassert>

#include "BSTree.h"
#include "bookDatabase.h"
#include "fiction.h"
#include "library.h"
#include "libraryBuilder.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

   ifstream inBooks("data4books.txt");
   if (!inBooks) {
      cout << "Books file could not be opened." << endl;
      return 1;
   }
   ifstream inPatrons("data4patrons.txt");
   if (!inPatrons) {
      cout << "Patrons file could not be opened." << endl;
      return 1;
   }

   LibraryBuilder build;

   istream books();
   Library* lib = build.createLibrary(inBooks, inPatrons);

   ifstream inCommands("data4commands.txt");
   if (!inCommands) {
      cout << "Commands file could not be opened." << endl;
      return 1;
   }

   lib->processCommands(inCommands);

   delete lib;

   return 0;
}
