double root(int n)
{
    double si = 0, ei = n, mid;
    
    while(ei - si >= 0.000001)
    {
        mid = si + (ei - si)/2;
        if(mid * mid > n)
            ei = mid;
        else
            si = mid;
    }
    return ei;
}
bool isPerfectSquare(int num) 
{
    if(num == 0)
        return true;
    double ans = root(num);
    int k = ans;
    // cout << ans << " " << 
    return k*k == num;
    
    
}

/* //Not my answer but the better one in terms of complexities  
bool isPerfectSquare(int num) 
{
    if (num == 1) return true;
    int s = 1, e = num / 2;

    while(s <= e) 
    {
        double mid = s + ((e - s)/2);
        double srt = num / mid;
        if (srt == mid) 
            return true;
        else if (mid > srt) 
            e = mid - 1;
        else 
            s = mid + 1;    
    }
    return false;
}
*/