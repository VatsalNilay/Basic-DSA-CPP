//https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include<iostream>
using namespace std;
char ceiling_letters(char letters[], int n, char x)
{
    if(x > letters[n-1])
        return letters[0];

    int si = 0, ei = n - 1;
    int mid;

    while(si <= ei)
    {
        mid = si + (ei - si)/2;

        // if(letters[mid] == x)
        //     return letters[mid];
        if(letters[mid] > x)
            ei = mid - 1;
        else
            si = mid + 1;
    }
    return letters[si % n];
}
int main()
{
    int size;
    cin >> size;
    char *letters = new char[size];
    for (int i = 0; i < size; i++)
        cin >> letters[i];
    
    char target;
    cin >> target;

    cout << ceiling_letters(letters, size, target) << endl;

}