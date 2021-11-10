#include <iostream>
using namespace std;

double sqrt(int n)
{
    double si = 1, ei = n;
    double mid;

    while(ei -si >= 0.000001)
    {
        mid = si + (ei - si)/2;
        if(mid*mid > n)
            ei = mid ;
        else 
            si = mid ;
    }
    return ei;
}

int main()
{
    int n;
    cin >> n;

    cout << sqrt(n) << endl;
}