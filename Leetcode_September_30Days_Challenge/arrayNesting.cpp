//O(n) time, O(n) space

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        vector<bool> visited(nums.size(), false);
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                int start = nums[i], count=0;
                do{
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }while(start!=nums[i]);
                res = max(res, count);
            }
        }
        return res;
    }
};