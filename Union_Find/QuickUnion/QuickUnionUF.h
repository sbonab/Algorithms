#ifndef QUICK_UNION_UF_H_
#define QUICK_UNION_UF_H_

#include <iostream>
#include <vector>
using std::vector;

/**
 * Implementation of the weighted quick-union with path compression, WQUPC
*/

class QuickUnionUF {
    
public:

    /**
     * Constructor
     * @param N Number of the nodes
     */
    QuickUnionUF(int N);

    /**
     * Destructor
     */
    virtual ~QuickUnionUF();

    /**
    * [] Returns the id of the parent of the node
    * @param i Index of the node
    */
    int& operator [](int i);
    
    /**
    * Finds whether or not given indices are connected
    * @param i Index of the first node
    * @param j Index of the second node
    */
    bool Connected(int i, int j);

    /**
    * Changes the root of node i to root of node j
    * @param i Index of the first node
    * @param j Index of the second node
    */
    void Union(int i, int j);

    /**
    * Find the root of the node with the passed index
    * @param i Index of the node
    */
    int Root(int i);

    /**
    * Returns the number of the nodes
    */
    int size();

    /**
    * Prints the id of the parents
    */
    void print() const;

private:
    // id vector 
    vector<int> id;
    
    // represents the depth of the tree that the node is part of 
    vector<int> sz;

};

#endif