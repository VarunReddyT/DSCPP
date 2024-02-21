#include<iostream>
using namespace std;

class Employee{
    private:
        int a, b, c; 
     //  ! Error :  void func(int a,int b,int c);  Private

    public: 
        int d,e;
        void func(int a,int b,int c);
};

void Employee :: func(int a, int b, int c){
    cout << a<<b<<c;
}
int main()
{
    Employee p;
    p.func(1,2,3);
    return 0 ;
}