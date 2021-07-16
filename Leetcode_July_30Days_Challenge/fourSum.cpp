//O(n^3) -> using two pointer approach(twoSum)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n= nums.size();
        if(n<4)
            return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target)
                break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target)
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target)
                    break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1] < target)
                    continue;
                int low= j+1, high= n-1;
                while(low<high)
                {
                    int sum = nums[low] + nums[high] + nums[j] + nums[i];
                    if(sum < target)
                        low++;
                    else if(sum > target)
                        high--;
                    else{
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        do{
                            low++;
                        }while(nums[low]==nums[low-1] && low<high);
                        do{
                            high--;
                        }while(nums[high]==nums[high+1] && low<high);
                    }
                }
            }
        }
        return res;
    }
};