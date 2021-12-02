/** @file fiction.cpp
 * @author Joseph Collora and Josh Helzerman
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
#include <iomanip>
#include "constants.h"


using namespace std;

Fiction::Fiction()
{
   maxCount = 5;
   count = maxCount;
   type = TYPE_FICTION; //ACII = 70
   typeCode = FICTION_CODE;

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

ostream& Fiction::display(ostream& os) const {
      os.setf(ios::left, ios::adjustfield);
   os << setw(COUNT_BUFFER) << count
      << setw(AUTHOR_BUFFER) << author.substr(0, AUTHOR_MAX_LENGTH)
      << setw(TITLE_BUFFER) << title.substr(0, TITLE_MAX_LENGTH)
      << setw(YEAR_BUFFER) << year;

   return os;
}

ostream& Fiction::displayHeader(ostream& os) const {
         os.setf(ios::left, ios::adjustfield);

         os << type << " BOOKS" << endl;
         os << setw(COUNT_BUFFER) << "AVAIL"
      << setw(AUTHOR_BUFFER) << "AUTHOR"
      << setw(TITLE_BUFFER) << "TITLE"
      << setw(YEAR_BUFFER) << "YEAR";

      return os;
         
}


