//O(n), assuming rand() takes O(1) 
//Fisher-Yates shuffle algorithm

class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    void swap(int *a, int *b){
        int temp = *a;
        *a= *b;
        *b= temp;
    }
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(original);
        for(int i=res.size()-1; i>0;i--){
            int j= rand()%(i+1);
            swap(&res[i], &res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */