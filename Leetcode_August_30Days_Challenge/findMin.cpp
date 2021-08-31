//Binary search, O(logN)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, n=nums.size(), high=n-1;
        if(n==1)
            return nums[0];
        if(nums[high] > nums[low])
            return nums[low];
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid+1] < nums[mid])
                return nums[mid+1];
            if(nums[mid] < nums[mid-1])
                return nums[mid];
            if(nums[0] < nums[mid])
                low = mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};