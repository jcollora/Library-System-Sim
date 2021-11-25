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

}

int Fiction::compare(const Fiction& rhs) const {
   int comparison = author.compare(rhs.author);
   if (comparison == 0) {
      comparison = title.compare(rhs.title);
   }

   return comparison;
}

bool Fiction::operator<(const BSTData& rhs) const {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) < 0;
}

bool Fiction::operator>(const BSTData& rhs) const {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) > 0;
}

bool Fiction::operator==(const BSTData& rhs) const {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) == 0;
}
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) == 0;
}