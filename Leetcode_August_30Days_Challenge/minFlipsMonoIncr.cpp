//O(n) time, O(n) space
//prefix sum solution

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n= s.length();
        vector<int> prefixOnes(s.length()+1, 0);
        //prefixOnes[i] stores number of 1s from s[0]..s[i-1]
        for(int i=0;i<n;i++)
            prefixOnes[i+1] = prefixOnes[i] + (s[i]-'0');
        int res = INT_MAX;
        for(int cut=0;cut<=n;cut++)
            res = min(res, prefixOnes[cut] + (n-cut-(prefixOnes[n]-prefixOnes[cut])));
                          //^                //^
                          //|                //|
                          //|                //number of 0s to change to 1s on right side of cut index
                          //|
                          //number of 1s to change to 0s on left side of cut index
        return res;
    }
};