#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 0; i < 100; i++)
    {
        cout << i << ", ";
        if(i > 10)
        {
            cout << "STOP THE COUNT!!\n";
            break;
        }
    }
}