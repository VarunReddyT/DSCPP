#include <iostream>
#include <stdlib.h>
using namespace std;
int a[10], n;
int linear(int, int);
int main()
{
    int i, res, key;
    cout << "enter how many elements u want to insert in an array=\n";
    cin >> n;
    cout << "enter the" << n << "elements=\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "the given elements=\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    cout << "enter the element to be search=\n";
    cin >> key;
    res = linear(key, 0);
    if (res < n)
    {
        cout << "\nelement" << key << "found at position" << res + 1;
    }
    else
    {
        cout << "\nelement" << key << "not found";
    }
    return 0;
}
int linear(int key, int loc)
{
    if (a[loc] == key)
    {
        return loc;
    }
    else
    {
        loc++;
        if (loc < n)
        {
            return linear(key, loc);
        }
        return loc;
    }
}