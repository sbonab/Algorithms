/**
 * This is an implementation of finding all a, b, c, d < n that a^3 + b^3 = c^3 + d^3
 * Time Complexity: O(n^2 log n)
 * Space Complexity: O(n)
 * If you consider a matrix of i^3 + j^3 for i and j in 1..n, it is never wise to keep 
 *  two elements from the same row or the same column since one of them would be definitely
 *  bigger than the other.
 */
 
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Pair {
public:
    Pair(){};
    Pair(int i, int j): i(i), j(j){};

    int cubeSum(){
        return i*i*i + j*j*j;
    }

    bool compare(const Pair& p){
        return (i == p.i && j == p.j) || (i == p.j && j == p.i);
    }

    bool taxiCab(Pair& p){
        return (this->cubeSum() == p.cubeSum()) && !this->compare(p);
    }

    bool less(Pair& p){
        return this->cubeSum() < p.cubeSum();
    }

    int i {};
    int j {};
};

class Compare {
public:
    bool operator()(Pair& p1, Pair& p2){
        return p1.less(p2);
    }
};

vector<pair<Pair, Pair>> TaxiCab(int num){
    vector<pair<Pair, Pair>> vec {};
    // occupancy booleans to keep track of row/column occupancy
    vector<bool> row_occup(num);
    vector<bool> col_occup(num);
    std::priority_queue<Pair, vector<Pair>, Compare> pq {};
    
    // initializing the priority queue
    int i {num - 1}, j{num - 1};
    pq.push(Pair(i,j));
    row_occup.at(i) = true;
    col_occup.at(j) = true;

    Pair prev_p(-1,-1);
    while(!pq.empty()){
        auto p = pq.top();
        std::cout << "Popping the pair i,j = " << p.i << ", " << p.j << '\n';
        pq.pop();
        if (p.taxiCab(prev_p)){
            // taxican pairs detected!
            vec.push_back(std::make_pair(p, prev_p));
            std::cout << "Detected a taxi cab number : " << p.cubeSum() << " = " << p.i << "^3 + " << p.j << "^3 = " << prev_p.i << "^3 + "<< prev_p.j << "^3\n";
        }
        prev_p = p;

        // updating the occupancy booleans
        row_occup[p.i] = false;
        col_occup[p.j] = false;

        // Appending adjacent pairs to the popped one
        int new_i = p.i - 1;
        int new_j = p.j - 1;
        if (new_i >= 0 && !row_occup.at(new_i)){
            std::cout << "Appending the pair i,j = " << new_i << ", " << p.j << '\n';
            pq.push(Pair(new_i, p.j));
            row_occup.at(new_i) = true;
        }
        if (new_j >= 0 && !col_occup.at(new_j) && new_j >= p.i){
            std::cout << "Appending the pair i,j = " << p.i << ", " << new_j << '\n';
            pq.push(Pair(p.i, new_j));
            col_occup.at(new_j) = true;
        }
    }
    
    return vec;
}

int main(){
    auto tc_nums = TaxiCab(100);
    std::cout << "Detected taxi cab numbers are:\n";
    for (auto tc:tc_nums){
        std::cout << tc.first.cubeSum() << " = " << tc.first.i << "^3 + " << tc.first.j << "^3 = " << tc.second.i << "^3 + "<< tc.second.j << "^3\n";
    }
    return 0;
}