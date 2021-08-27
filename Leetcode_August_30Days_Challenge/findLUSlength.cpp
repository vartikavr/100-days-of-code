//O(n*(m^2)) time, where m = size of given vector

class Solution {
public:
    bool ifSubsq(string a, string b)
    {
        if(a.length() > b.length())
            return false;
        int i=0, j=0;
        for(;i<b.length();i++)
        {
            if(j<a.size() && a[j]==b[i])
                j++;
        }
        if(j==a.length())
            return true;
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        if(strs.size() == 0)
            return -1;
        int res=-1;
        for(int i=0;i<strs.size();i++)
        {
            int j=0;
            for(;j<strs.size();j++)
            {
                if(i==j)
                    continue;
                if(ifSubsq(strs[i], strs[j])) //strs[i] is a subsequence of strs[j]
                    break;
            }
            if(j==strs.size()) //strs[i] is not a subsequence of any string
                res= max(res, static_cast<int>(strs[i].length()));
        }
        return res;
    }
};