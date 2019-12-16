#include <iostream>

using namespace std;
int main(){
    cout << sizeof(int) << endl; //4
    // signed and unsigned
    unsigned u1 = 10, u2 = 42;
    cout << u2-u1 << endl; //32
    cout << u1-u2 << endl; //2^32-32=4294967296-32
    int i1=10, i2=42, i3=-11;
    cout << i2-i1 << endl; //32
    cout << i1-i2 << endl; //-32
    cout << i1-u1 << endl; //0
    cout << u1-i1 << endl; //0
    // try scientific notation
    cout << 1E3 << endl;
    return 0;
}
