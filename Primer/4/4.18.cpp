#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Program to print all element of a vector til the first negative element
    vector<int> v { 5, 10, 23, 45, -6, -7};
    
    auto beg = v.begin();
    cout << (*beg)++ << endl;
    while(beg != v.end() && *beg >= 0)
    {
        cout << *++beg << " " << endl << flush;
        //cout << ++*beg ; //This will lead to infinite loop since *beg will access the first value and ++ will keep on incrementing that value.
    }

    return 0;
}
