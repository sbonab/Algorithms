#include <iostream>

void TaxiCab(int num){
    for (int a {1}; a <= num; ++a){
        for (int b {1}; b <= num; ++b){
            for (int c {1}; c <= num; ++c){
                for (int d {1}; d <= num; ++d){
                    if (a*a*a + b*b*b == c*c*c + d*d*d){
                        if (a != c && a != d){
                            std::cout << "a, b, c, d are " << a << ", " << b << ", " << c << ", " << d << '\n';
                        }
                    }
                }
            }
        }
    }
}

int main(){
    TaxiCab(100);

    return 0;
}