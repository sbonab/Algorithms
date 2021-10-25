#include <iostream>
#include <stack>
#include <cassert>

//using tower_t = std::stack<int>;

using std::cout;
using std::cin;
using std::max;
using std::stack;

class Tower : public stack<int>{
public: 
    Tower(){};
    Tower(int size){
        for (; size > 0; --size){
            this->push(size);
        }
    }
/*
    int pop(){
        int val = this->top();
        this->pop();
        return val;
    }
*/
    int max(){
        max_s = this->empty() ? 0 : max_s;
        return max_s;
    }

    void push(int size){
        if (this->empty())
            max_s = size;
        // this->push(size); // This was wrong, calling the push recuresively
        stack::push(size);
    }
private:
    int max_s {};

};

int getDiameter(int size){
    return 2*size - 1 > 0 ? 2*size - 1 : 0;
}

void printChar(char c, int num = 1){
    for (; num > 0; --num){
        std::cout << c;
    }
}


class Hanoi{
public:
    Hanoi(){};
    Hanoi(int num) : size(num) {
        Tower tow(num);
        tow1 = num;
    };
    
    int size {};
    Tower tow1;
    Tower tow2;
    Tower tow3;

    void print(){
        auto tow1p {tow1};
        auto tow2p {tow2};
        auto tow3p {tow3};
        int nrow {max(max(tow1p.size(), tow2p.size()), tow3p.size())};
        for( ; nrow > 0; --nrow ){   
            int s {};
            if (tow1p.size() == nrow){
                s = tow1p.top();
                tow1p.pop();
            }
            printDisk(s);

            s = 0;
            if (tow2p.size() == nrow){
                s = tow2p.top();
                tow2p.pop();
            }
            printDisk(s);

            s = 0;
            if (tow3p.size() == nrow){
                s = tow3p.top();
                tow3p.pop();
            }
            printDisk(s);

            cout << '\n';
        }
        cout << "\n\n";
    }

    void swap(int is, int id){
        assert(is > 0 && is < 4 && id > 0 && id < 4 && "Wrong tower index");

        if (is == id)
            return;
        
        
        Tower& tow_s = (is == 1 ? tow1 : is == 2 ? tow2 : tow3);
        Tower& tow_d = (id == 1 ? tow1 : id == 2 ? tow2 : tow3);

        if (tow_s.empty())
            return;

        if (!tow_d.empty())
            assert(tow_d.top() > tow_s.top() && "bigger disk cannot be placed on the smaller disk");

        tow_d.push(tow_s.top());
        tow_s.pop();
    }

    void move(int num, int is, int id){
        if (num < 1)
            return;
        if (num == 1){
            swap(is, id);
            print();
            return;
        }

        int im {is == 1 && id == 2 || is == 2 && id == 1 ? 3 : is == 2 && id == 3 || is == 3 && id == 2 ? 1 : 2};

        move(num - 1, is, im);
        swap(is, id);
        print();
        move(num - 1, im, id);
    }

    void solve(){
        move(size, 1, 2);
    }

private:
    void printDisk(int s){
        int d_max {getDiameter(size)};
        if (s > 0){
            int d {getDiameter(s)};
            printChar(' ', (d_max - d)/2);
            printChar('_', d);
            printChar(' ', (d_max - d)/2);
        }
        else{
            printChar(' ', d_max);
        }
    }
};

int main(){
    cout << "Enter the number of disks: ";
    int num{};
    cin >> num;

    Hanoi h(num);

    h.print();
    h.solve();

    return 0;
}

