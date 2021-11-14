vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        int si = 0, ei = numbers.size() - 1;
        
        while(si <= ei)
        {
            int sum = numbers[si] + numbers[ei];
            if(sum == target)
            {
                ans.push_back(si + 1);
                ans.push_back(ei + 1);
                break;
            }
            else if(sum > target)
                ei = ei - 1;
            else
                si = si + 1;
            
        }
        return ans;
    }