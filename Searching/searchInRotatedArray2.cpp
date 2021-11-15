#include<vector>
bool search(vector<int>& nums, int target)
    {
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] == target)
        //         return true;
        // }
        // return false;
        
        
        int si = 0, ei = nums.size() - 1, mid;
        
        while(si <= ei)
        {
            if(nums[si] == target || nums[ei] == target)
                return true;
            else if(target > nums[si])
            {
                while(si < ei and nums[si] == nums[si+1]) si++;
                
                si++;
            }
            else if(target < nums[ei])
            {
                while(si < ei and nums[ei - 1] == nums[ei])ei--;
                ei--;
            }
            else
                break;
        }
        return false;
    }
