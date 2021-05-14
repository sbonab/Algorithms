#ifndef QUICK_FIND_UF_H_
#define QUICK_FIND_UF_H_

#include <iostream>
#include <vector>
using std::vector;

class QuickFindUF {
    
public:

    /**
     * Constructor
     * @param N Number of the objects
     */
    QuickFindUF(int N);

    /**
     * Destructor
     */
    virtual ~QuickFindUF();

    /**
    * [] Returns the id of the object
    * @param i Index of the object
    */
    int& operator [](int i);
    
    /**
    * Finds whether or not given indices are connected
    * @param i Index of the first object
    * @param j Index of the second object
    */
    bool Connected(int i, int j) const;

    /**
    * Changes any index with id[i] to id[j]
    * @param i Index of the first object
    * @param j Index of the second object
    */
    void Union(int i, int j);

    /**
    * Returns the number of the objects
    */
    int size();

    /**
    * Prints the id of the objects
    */
    void print() const;

private:
    // id vector 
    vector<int> id;

};

#endif