#include<iostream>
using namespace std;
int main() {
    //pointer to int is created, and pointing to some garbage address
    int *p=0;
    cout<<*p<<endl;
    return 0;
}