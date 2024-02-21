#include<iostream>
using namespace std;

class reverse{
    string n;

    public:
        void in();
        void display();
        void rev();
};

void reverse :: in(){
    cout << "Enter the number : " << endl;
    cin >> n;
}

void reverse :: display(){
    cout << n << endl;
}

void reverse :: rev(){
    int i = 0, j = n.length() - 1;
    while(i < j){
        swap(n[i], n[j]);
        i++;
        j--;
    }

}
int main()
{
    reverse r;
    r.in();
    r.display();
    r.rev();
    r.display();
    return 0 ;
}