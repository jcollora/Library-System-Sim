

using namespace std;

#include <cassert>

#include "bookDatabase.h"
#include "BSTree.h"
#include "fiction.h"
#include "libraryBuilder.h"
#include "library.h"
#include <iostream>

int main() {
   LibraryBuilder build;
   Library* lib = build.createLibrary();

   return 0;
}

