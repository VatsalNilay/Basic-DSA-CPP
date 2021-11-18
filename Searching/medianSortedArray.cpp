// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    // {
    //     vector<int> helper;
    //     int i = 0, j = 0;
    //     while(i < nums1.size() && j < nums2.size())
    //     {
    //         if(nums1[i] > nums2[j])
    //         {
    //             helper.push_back(nums2[j]);
    //             j++;
    //         }
    //         else if(nums1[i] < nums2[j])
    //         {
    //             helper.push_back(nums1[i]);
    //             i++;
    //         }
    //         else
    //         {
    //             helper.push_back(nums1[i]);
    //             helper.push_back(nums2[j]);
    //             i++;
    //             j++;
    //         }
    //     }
    //     while(i < nums1.size())
    //     {
    //         helper.push_back(nums1[i]);
    //         i++;
    //     }
    //     while(j < nums2.size())
    //     {
    //         helper.push_back(nums2[j]);
    //         j++;
    //     }
    //     int x = helper.size();
    //     if(x & 1)
    //         return helper[(x-1)/2];
    //     else
    //         return (helper[x/2] + helper[(x-1)/2])/2.0;
    //     return 0;
    // }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double med;
        int n1 = nums1.size(), n2 = nums2.size(); 
        if(n2 < n1) return findMedianSortedArrays(nums2,nums1);
        
        int si = 0, ei = n1 , cut1, cut2;
        int l1, l2, r1, r2;
        
        while(si <= ei)
        {
            cut1 = si + (ei - si)/2;
            cut2 = (n1 + n2 + 1)/2 - cut1;
            
            l1 = cut1 == 0 ?INT_MIN:nums1[cut1-1];
            l2 = cut2 == 0 ?INT_MIN:nums2[cut2-1];
            
            r1 = cut1 == n1 ?INT_MAX:nums1[cut1];
            r2 = cut2 == n2 ?INT_MAX:nums2[cut2];
            
            if(l1 <= r2 and l2 <= r1)
            {
                if((n1+n2)%2 == 0)
                    med = (max(l1,l2) + min(r1,r2))/2.0;
                else
                    med = max(l1,l2);
                break;
            }
            else if(l1 <= r2)
                si = cut1 + 1;
            else 
                ei = cut1 - 1;
            // else if(l1 > r2)
            //     ei = cut1 - 1;
            // else
            //     si = cut1 + 1;
        }
        return med;
    }