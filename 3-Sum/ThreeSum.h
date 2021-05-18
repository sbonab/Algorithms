#ifndef THREE_SUM_H_
#define THREE_SUM_H_

#include <vector>

using std::vector;

/**
 * Implementation of solving the 3-SUM problem
 * This is the brute force implementation with O(N^3) time complexity 
*/

class ThreeSum{
public:

    /**
     * Constructor
     * @param v Vector containing integers 
     */
    ThreeSum(vector<int> v);
    
    /**
     * Desstructor
     */
    ~ThreeSum();

    /**
     * Counts the number of triplets that will sum to 0
     */
    int count() const;


private:
    // Vectors to find sum to 0 triplets
    vector<int> v;
};

#endif