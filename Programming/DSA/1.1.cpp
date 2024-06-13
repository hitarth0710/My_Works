#include <iostream>
using namespace std;

int main()
{
    int n, ele, pos, i, pos1;
    cout << "Enter the Size of array :" << endl;
    cin >> n;
    int *p = new int[n];
    cout << "Enter the Elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "The Elements Entered are" << endl;
    for (i = 0; i < n; i++)
    {
        cout << p[i] << '\t';
    }
    cout << endl;
    cout << "Enter the Element you want to insert : ";
    cin >> ele;
    cout << "On which Position you want to enter :";
    cin >> pos;
    if (pos > n)
        cout << "Greater than the size of array";
    else
    {

        for (i = n - 1; i >= pos - 1; i--)
        {
            p[i + 1] = p[i];
        }
        p[pos - 1] = ele;
    }
    cout << "After Insertion" << endl;
    for (i = 0; i < n; i++)
    {
        cout << p[i] << '\t';
    }
    cout << endl;
    cout << "Enter the postion you want to delete from :";
    cin >> pos1;
    if (pos1 > n)
        cout << "Greater than the size of array";
    else
    {
        for (i = pos1 - 1; i < n - 1; i++)
        {
            p[i] = p[i + 1];
        }
    }
    cout << "After Deletion" << endl;
    for (i = 0; i < n - 1; i++)
    {
        cout << p[i] << '\t';
    }
    cout << endl;

    return 0;
}
