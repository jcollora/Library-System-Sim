/** @file children.cpp
 * @author Joseph Collora and Josh Helzerman
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
#include <string>


using namespace std;

Children::Children() 
{
    maxCount = 5;
    count = maxCount;
    type = TYPE_CHILDREN;
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

bool Children::operator!=(const BSTData& rhs) const {
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) != 0;
}

Book* Children::create() const {
   return new Children();
}

bool Children::operator<=(const BSTData& rhs) const {
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) <= 0;
}

bool Children::operator>=(const BSTData& rhs) const {
   const Children& right = static_cast<const Children&>(rhs);
   return compare(right) >= 0;
}

BSTData& Children::operator=(const BSTData& rhs) {
   const Children& right = static_cast<const Children&>(rhs);
   if (this != &right) {
      author = right.author;
      title = right.title;
      year = right.year;
      
   }
   return *this;
}

bool Children::setData(istream& is) {
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

string Children::display() const {
   return title; //NEEDS WORK
}
