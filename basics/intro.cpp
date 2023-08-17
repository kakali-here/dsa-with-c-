#include <iostream>
using namespace std;
int main(){
int num = 5;
cout<<num<<endl;
cout<< "adress of num is" <<&num<<endl;
int *ptr = &num;
cout<<"value is :" <<*ptr<<endl;
cout<<"ptr is:"<<ptr<<endl;
cout<<"*&num is:"<<*&num<<endl;
return 0;
}