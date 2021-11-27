/** @file children.cpp
 *
 * Description:
 *   - A children book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#include "BSTData.h"
#include "children.h"
#include "book.h"

using namespace std;

Children::Children() 
{
    maxCount = 5;
    count = maxCount;
}

int Children::compare(const Children& rhs) const {
    int compare = title.compare(rhs.title);
    if(compare == 0) {
        compare = author.compare(rhs.author);
    }
    return compare;
}

bool Children::operator<(const BSTData& rhs) const {
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) < 0;
}

bool Children::operator>(const BSTData& rhs) const {
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) > 0;
}

bool Children::operator==(const BSTData& rhs) const {
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) == 0;
}

string Children::displayBook() const {
   return title; //placeholder!!!!!
}

Book* Children::create() const {
   return new Children();
}