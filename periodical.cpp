/** @file periodical.cpp
 * @author Joseph Collora and Josh Helzerman
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
#include <iomanip>

using namespace std;

Periodical::Periodical() 
{
    maxCount = 5;
    count = maxCount;
    type = TYPE_PERIODICAL;
    typeCode = PERIODICAL_CODE;
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

bool Periodical::operator!=(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) != 0;
}

bool Periodical::operator<=(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) <= 0;
}

bool Periodical::operator>=(const BSTData& rhs) const {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   return compare(right) >= 0;
}

BSTData& Periodical::operator=(const BSTData& rhs) {
   const Periodical& right = static_cast<const Periodical&>(rhs);
   if (this != &right) {
      author = right.author;
      title = right.title;
      year = right.year;
      
   }
   return *this;
}

Book* Periodical::create() const {
   return new Periodical();
}

bool Periodical::setData(istream& is) {
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
   
   getline(is, title, ',');
   if (title.empty()) {
      getline(is, line);
      return false;
   }
   is >> month; 
 
   is >> year;
   if ( year < 0) {
      getline(is, line);
      return false;
   }

   getline(is, line); //clear line for next data input

   return true;

}

string Periodical::display() const {
   return title; //NEEDS WORK
}

ostream& operator<<(ostream& os, const Periodical& book)
{
   //const Periodical& book = static_cast<const Periodical&>(data);
   os.setf(ios::left, ios::adjustfield);
   os << setw(COUNT_MAX_LENGTH) << book.count
      << setw(TITLE_MAX_LENGTH) << book.title.substr(0, TITLE_MAX_LENGTH)
      << setw(AUTHOR_MAX_LENGTH) << book.author.substr(0, AUTHOR_MAX_LENGTH)
      << setw(YEAR_MAX_LENGTH) << book.year;

   return os;
}
