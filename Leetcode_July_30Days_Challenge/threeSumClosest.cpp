//O(n^2) -> two pointer approach

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int low= i+1, high= nums.size()-1;
            while(low<high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(abs(target-sum) < abs(diff))
                    diff = target - sum;
                if(diff == 0)
                    break;
                if(sum < target)
                    low++;
                else
                    high--;
            }
            if(diff == 0)
                break;
        }
        return target - diff;
    }
};