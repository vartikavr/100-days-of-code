//O((2^n)*n) time
//reference video -> https://www.youtube.com/watch?v=RIn3gOkbhQE

class Solution {
public:
    void recurFunc(vector<int> &nums,vector<int> &sub, vector<vector<int>> &res, int start)
    {
        res.push_back(sub);
        for(int i=start;i<nums.size();i++)
        {
            if(start == i || nums[i] != nums[i-1])
            {
                sub.push_back(nums[i]);
                recurFunc(nums, sub, res, i+1);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        recurFunc(nums, sub, res, 0);
        return res;
    }
};