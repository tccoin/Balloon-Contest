#include <iostream>

using namespace std;


// non-template function
void Swap(char & a, char & b){
    cout << "1" << endl;
}

// template function
template <typename T>
void Swap(T&, T&){
    cout << "2" << endl;
}

// explicit specialization
template <> void Swap(char & a, char & b){
    cout << "3" << endl;
}


int main(){
    int a=1, b=1;
    char c=1, d=1;
    Swap(a,b); //2
    Swap(c,d); //1
    return 0;
}
