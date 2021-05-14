#include "QuickFindUF.h"

QuickFindUF::QuickFindUF(int N){
    for (int i = 0; i < N; ++i){
        id.push_back(i);
    }
};

QuickFindUF::~QuickFindUF(){};

int& QuickFindUF::operator[](int i){ return id[i]; }

void QuickFindUF::Union(int i, int j){
    auto id_i = id[i];
    auto id_j = id[j];
    if (id_i != id_j){
        for (auto& id_t:id){
            if (id_t == id_i){ id_t = id_j; }
        }
    }
}

bool QuickFindUF::Connected(int i, int j) const { return id[i] == id[j]; }

int QuickFindUF::size(){ return id.size(); }

void QuickFindUF::print() const {
    
    for (auto& i : id){
        std::cout << i << " ";
    }
}

