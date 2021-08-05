//O(n*n) time

class Solution {
public:
    int dp[501][501];
    int calc(int l, int r, vector <int> &piles) {
        if(l == r-1) 
            return max(piles[l], piles[r]);
        if(dp[l][r] != -1) 
            return dp[l][r];
        int ifleft = piles[l] + max(calc(l+2, r, piles), calc(l+1, r-1, piles));
        int ifright = piles[r] + max(calc(l+1, r-1, piles), calc(l, r-2, piles));
        return dp[l][r] = max(ifleft, ifright);
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        int alex = calc(l, r, piles);
        int sum = 0;
        for(int i=0;i<piles.size();i++) 
            sum += piles[i];
        return alex > (sum - alex);
    }
};