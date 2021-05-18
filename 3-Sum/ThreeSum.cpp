#include "ThreeSum.h"

ThreeSum::ThreeSum(vector<int> v): v{v}{}
ThreeSum::~ThreeSum(){}

int ThreeSum::count() const {
    int count = 0;

    for (int i = 0; i < v.size(); ++i){
        for (int j = i+1; j < v.size(); ++j){
            for (int k = j+1; k < v.size(); ++k){
                if (v[i] + v[j] + v[k] == 0){ ++count; }
            }
        }
    }

    return count;
}