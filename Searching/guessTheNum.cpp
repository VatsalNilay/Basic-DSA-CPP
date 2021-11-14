//guess is predefined function which returns -1 if the guess is lower, 1 if guess is higher, 0 otherwise

/*DONT RUN THIS CODE ANYWHERE ELSE OTHER THAN LEETCODE IDE. THEY HAVE CREATED A SPECIAL FUNCTION int guess(int num)
  WHICH I HAVE NOT.
*/

#include<iostream>
using namespace std;

int guessNumber(int n) 
{
    int si = 1, ei = n, mid;
    while (si <= ei) 
    {
        mid = si + (ei - si) / 2;
        
        if (guess(mid) < 0) 
            ei = mid - 1;
        else if(guess(mid) > 0)
            si = mid + 1;
        else if(guess(mid) == 0)
            return mid;
    }
    return mid;
}

int main()
{
    int n;
    cin >> n;

    cout << guessNumber(n) << endl;
}