//O(n) time, O(n) space

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxLeft[nums.size()], minRight[nums.size()], n= nums.size();
        maxLeft[0]= nums[0];
        for(int i=1;i<n;i++)
        {
            maxLeft[i] = max(maxLeft[i-1], nums[i]);
        }
        minRight[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--){
            minRight[i]= min(nums[i], minRight[i+1]);
        }
        for(int i=0;i<n-1;i++)
            if(maxLeft[i] <= minRight[i+1]){
                return i+1;
            }
        return -1;
    }
};