/** @file patron.h
 * @author Joseph Collora
 * 
 * Description:
 * - A patron object represents a unique customer + its id, name, and history
 * - History can be updated (removal and addition)
 * - Can be queried to display its information
 * - Can be compared with other patrons
 * - 
 * 
 * Implementation:
 * - Some functions are virtual -of BSTData
 * - Patron History stored in a list of strings
 */

#ifndef PATRON_H
#define PATRON_H

using namespace std;

#include "BSTData.h"
#include <string>

class Patron : public BSTData 
{
    public:
    // constr / destr ?

    // -------------------------------------------------------------------------
   /** addBook()
    * @pre 
    * @post 
    */
   void addBook();

   // -------------------------------------------------------------------------
   /** removeBook()
    * @pre
    * @post 
    * @return 
    */
   bool removeBook();

    // -------------------------------------------------------------------------
    /** displayPatron()
    * @pre None.
    * @post None. const function
    * @return 
    */
   string displayPatron() const;

    private:
    // id of the patron
    int id;

    // name of the patron
    string name;

    // patron command history -list of strings
    // wip : "List of Strings"

};

#endif 