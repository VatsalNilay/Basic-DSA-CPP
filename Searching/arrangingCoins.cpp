int mySqrt(double x) 
    {
        double si = 1, ei = x/2; //ei = x will make your code runtime 3ms, otherwise 0ms
        double mid;
        if(x == 0 || x == 1)
            return x;

        while(ei - si >= 0.000001)
        {
            mid = si + (ei - si)/2;

            if(mid*mid > x)
                ei = mid;
            else
                si = mid;
        }
        return ei;
    }
    
    int arrangeCoins(int n) 
    {
        if(n == 1) return 1;
        // int i = 1, ans = 0;
        // while(n - i >= 0)    
        // {
        //     n = n - i;
        //     i++;
        //     ans++;
        // }
        double val = 0;
        for(int i = 0; i < 8; i++)
            val += n;
        int ans = mySqrt(1 + val) - 1;
        
        return ans/2;
    }