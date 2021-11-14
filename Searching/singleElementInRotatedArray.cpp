#include<vector>
int singleNonDuplicate(vector<int>& nums)
{
    int si = 0, ei = nums.size() - 1, mid;
    
    if(nums.size() != 1)
    {
    //if unique element is either at first or at last position
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[nums.size() - 2] != nums[nums.size() - 1])
            return nums[nums.size() - 1];
    }
    else
        return nums[0];
    
    while(si <= ei)
    {
        mid = si + (ei - si)/2;
        
        if(nums[mid] == nums[mid + 1] )
        {
            if(mid&1)
                ei = mid - 1;
            else
                si = mid + 1;
        }
        else if( nums[mid] == nums[mid - 1])
        {
            if((mid-1)&1)
                ei = mid - 1;
            else
                si = mid + 1;
        }    
        else 
        {
            return nums[mid];
        }  
    }
    return nums[mid];
}