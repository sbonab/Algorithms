#include "QuickUnionUF.h"

QuickUnionUF::QuickUnionUF(int N){
    for (int i = 0; i < N; ++i){
        id.push_back(i);
        sz.push_back(1);
    }
};

QuickUnionUF::~QuickUnionUF(){};

int& QuickUnionUF::operator[](int i){ return id[i]; }

void QuickUnionUF::Union(int i, int j){
    if (Connected(i,j)){ return; }
    
    // getting the roots of the nodes
    int ri = Root(i);
    int rj = Root(j);

    // always merge the shorter tree to the longer one
    if (sz[ri] > sz[rj]) { 
        id[rj] = ri; 
    }

    // depth only increases when two trees of the same depth are merged
    else if (sz[ri] == sz[rj]) { 
        id[rj] = ri; 
        ++sz[ri];
    }
    else { 
        id[ri] = rj; 
    }
}

bool QuickUnionUF::Connected(int i, int j) { return Root(i) == Root(j); }

int QuickUnionUF::Root(int i) {
    while (id[i] != i){
        // make every other node in path to re-point to its grandparent
        id[i] = id[id[i]];

        i = id[i];
    }
    return i;
}

int QuickUnionUF::size(){ return id.size(); }

void QuickUnionUF::print() const {
    
    for (auto& i : id){
        std::cout << i << " ";
    }
}

