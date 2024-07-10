#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while((cin >> n) && n)
    {
        string moves;
        cin >> moves;

        string directions = "NLSO";
        int di = 0;

        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i] == 'D') di = (di + 1) % 4;
            else
            {
                di = (di - 1) % 4;
                if (di < 0) di = 3;
            }
        }

        cout << directions[di] << endl;
    }
}