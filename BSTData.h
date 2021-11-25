/** @file BSTData.h
 *  @author Joseph Collora
 * 
 *  Description:
 *  - Interface for objects that defines comparison operators to compare data
 *    within the Binary Search Trees
 *  - Includes comparison operators (<,>,=)
 *  - Includes no data members 
 * 
 *  Implementation:
 *  - Methods implemented and overwritten by books/types and patrons (pure virtual)
 */

#ifndef BSTDATA_H
#define BSTDATA_H

using namespace std;

class BSTData {
    public:
    // -------------------------------------------------------------------------
    /** operator<()
     *  Less Than Operator
     * 
     * Determines if the left side item is less than the right
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is less than right, false otherwise
     */
    virtual bool operator<(const BSTData&) const = 0;

    // -------------------------------------------------------------------------
    /** operator>()
     *  Greater Than Operator
     * 
     * Determines of the left side item is greater than the right
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is greater than right, false otherwise
     */
    virtual bool operator>(const BSTData&) const = 0;

    // -------------------------------------------------------------------------
    /** operator==()
     *  Equivelence Operator
     * 
     * Determines if the right and left items are equivelent
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is equal to right, false otherwise
     */
    virtual bool operator==(const BSTData&) const = 0;

};

#endif BSTData