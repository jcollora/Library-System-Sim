/** @file fiction.cpp
 *
 * Description:
 *   - A Fiction book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book and BSTNode
 * class
 */

#include "BSTData.h"
#include "fiction.h"
#include "book.h"
#include <iostream>

using namespace std;

Fiction::Fiction()
{
   maxCount = 5;
   count = maxCount;
   type = 'F'; //ACII = 70

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

bool Fiction::operator!=(const BSTData& rhs) const {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) != 0;
}

bool Fiction::operator<=(const BSTData& rhs) const {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) <= 0;
}

bool Fiction::operator>=(const BSTData& rhs) const {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   return compare(right) >= 0;
}

BSTData& Fiction::operator=(const BSTData& rhs) {
   const Fiction& right = static_cast<const Fiction&>(rhs);
   if (this != &right) {
      author = right.author;
      title = right.title;
      year = right.year;
      
   }
   return *this;
}

Book* Fiction::create() const {
   return new Fiction();
}

bool Fiction::setData(istream& is) {
   string line; 
   
   is.get();
   char form = is.get();
   if (is.peek() == ' ') {
      if (form != format) {
         getline(is, line);
         return false;
      }
      is.get();
   } else {
      is.unget();
   }
   
   
   getline(is, author, ',');
   if (author.empty()) {
      getline(is, line);
      return false;
   }
   is.get();
   getline(is, title, ',');
      if (title.empty()) {
      getline(is, line);
      return false;
   }
 
   is >> year;
   if ( year < 0) {
      getline(is, line);
      return false;
   }

   getline(is, line); //clear line for next data input

   return true;


}

string Fiction::display() const {
   return title; //NEEDS WORK
}
