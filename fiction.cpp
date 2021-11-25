/** @file fiction.cpp
 *
 * Description:
 *   - A Fiction book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book and BSTNode
 * class
 */

#include "fiction.h"
#include "book.h"

using namespace std;

Fiction::Fiction()
{
   maxCount = 5;
   count = maxCount;
   checkouts Patron*[maxCount];
}

