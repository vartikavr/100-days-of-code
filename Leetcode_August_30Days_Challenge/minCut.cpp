//O(n^2) time, DP solution

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if(n <=1 )
            return 0;
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        //isPalin[i][j] -> is substring s[i..j] a palindrome
        int minCuts[n+1]; //minCuts[i] -> minimum cuts 0..i-1
        for(int i=0;i<=n;i++)
            minCuts[i] = i-1;
        for(int j=1;j<n;j++)
        {
            for(int i=j;i>=0;i--)
            {
                if((s[i] == s[j]) && ((j-i <2) || (isPalin[i+1][j-1])))
                {
                    isPalin[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], minCuts[i] + 1);
                }
            }
        }
        return minCuts[n];
    }
};