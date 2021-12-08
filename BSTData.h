/** @file BSTData.h
 * @author Joseph Collora and Josh Helzerman
 *
 *  Description:
 *  - Interface for objects that defines comparison operators to compare data
 *    within the Binary Search Trees
 *  - Includes comparison operators (<,>,=)
 *  - Includes no data members
 *
 *  Implementation:
 *  - Methods implemented and overwritten by books/types and patrons (pure
 *    virtual)
 */

#ifndef BSTDATA_H
#define BSTDATA_H

#include <iostream>
#include <string>

using namespace std;

class BSTData
{
public:
   // -------------------------------------------------------------------------
   /** ~BSTData
    * Destructor
    *
    * Deletes BSTData from memory
    * @pre None.
    * @post BSTData instance is deleted
    */
   virtual ~BSTData();

   // -------------------------------------------------------------------------
   /** operator<()
    *  Less Than Operator
    *
    * Determines if the left side item is less than the right
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is less than right, false otherwise
    */
   virtual bool operator<(const BSTData& rhs) const = 0;

   // -------------------------------------------------------------------------
   /** operator>()
    *  Greater Than Operator
    *
    * Determines of the left side item is greater than the right
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is greater than right, false otherwise
    */
   virtual bool operator>(const BSTData& rhs) const = 0;

   // -------------------------------------------------------------------------
   /** operator==()
    *  Equivelence Operator
    *
    * Determines if the right and left items are equivelent
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is equal to right, false otherwise
    */
   virtual bool operator==(const BSTData& rhs) const = 0;

   // -------------------------------------------------------------------------
   /** operator!=
    * Inequality Operator
    *
    * Determines if right and left items are not equivelent
    * @pre Both items being compared exist
    * @post None.
    * @return false returned when left is equal to right, true otherwise
    */
   virtual bool operator!=(const BSTData& rhs) const = 0;

   // -------------------------------------------------------------------------
   /** operator<=()
    *  Less than or equal operator
    *
    * Determines if the right and left items are equivelent or less than
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is equal to right or
    * if left is less than right, false otherwise
    */
   virtual bool operator<=(const BSTData& rhs) const = 0;

   // -------------------------------------------------------------------------
   /** operator>=()
    *  greater than or equal operator
    *
    * Determines if the right and left items are equivelent or greater than
    * @pre Both items being compared exist
    * @post None.
    * @return true returned when left is equal to right or
    * if left is greater than right, false otherwise
    */
   virtual bool operator>=(const BSTData& rhs) const = 0;

   // -------------------------------------------------------------------------
   /** operator=()
    * Copy assignment operator
    *
    * Copy data from right hand item to left hand item.
    * @pre Items should not be the same item
    * @post left item contains data from rhs, right item is const
    * @return reference to left item
    */
   virtual BSTData& operator=(const BSTData& rhs) = 0;

   // -------------------------------------------------------------------------
   /** setData()
    * input data into node
    *
    * Take data from inputStream and put into node members
    * @pre must have a properly formatted input file
    * @post line of input is read. BSTData contains line data
    * @return true if line of data was read, false if no line or bad format
    */
   virtual bool setData(istream& is) = 0;

   // -------------------------------------------------------------------------
   /** display
    * display data
    *
    * returns the data inside node as a string
    * @param os ostream that will contain string to print
    * @pre None
    * @post None
    * @return string representing data inside node
    */
   virtual ostream& display(ostream& os) const = 0;
};

#endif