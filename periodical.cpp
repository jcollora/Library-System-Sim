/** @file periodical.cpp
 *
 * Description:
 *   - A Periodical book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book class
 */

#include "BSTData.h"
#include "periodical.h"
#include "book.h"

using namespace std;

Periodical::Periodical() 
{
    maxCount = 5;
    count = maxCount;
}

int Periodical::compare(const Periodical& rhs) const {
    int comparison = year - rhs.year;
    if(comparison == 0) {
        comparison = month - rhs.month;
        if(comparison == 0) 
            comparison = title.compare(rhs.title);
    }
    return comparison;
}

bool Periodical::operator<(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) < 0;
}

bool Periodical::operator>(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) > 0;
}

bool Periodical::operator==(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) == 0;
}

string Periodical::displayBook() const {
   return title; //placeholder!!!!!
}

Book* Periodical::create() const {
   return new Periodical();
}