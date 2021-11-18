//     int findMin(vector<int>& nums) 
//     {
//         int si = 0, ei = nums.size() - 1, mid;
//         int pivot = 0;
//         while(si <= ei)
//         {
//             mid = si + (ei - si)/2;  
//             if(mid > si && nums[mid] < nums[mid -1])
//             {
//                 // cout << "HI" << endl;
//                 pivot = mid;
//                 break;
//             }
//             else if(mid < ei && nums[mid] > nums[mid + 1])
//             {
//                 pivot = mid + 1;
//                 break;
//             }
//             if(nums[mid] < nums[ei])
//                 ei = mid - 1;
//             else
//                 si = mid + 1;
//         }    
//         return nums[pivot] ;
//     }
int findMin(vector<int>& nums) 
{
    int l = 0, r = nums.size() - 1;
    int middle = 0;
    while (l < r) {
        middle = (l + r) / 2;
        cout << l << middle << r  << endl;    
        if (nums[middle] > nums[nums.size() - 1]) 
        {
            l = middle +1;
        } else if (nums[middle] < nums[nums.size() - 1]) {
            r = middle -1;
        }
    }
    int pivot = (r + l) / 2;
    if(pivot == nums.size()-1) return nums[pivot];
    if (nums[pivot] > nums[pivot + 1]) return nums[pivot+1];
    if (nums[pivot] < nums[pivot + 1]) return nums[pivot];   
    return 0;
}