//O(n*k(logk)) time
//where n is the number of given strings, k is the length of longest string 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for(int i=0;i<n;i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        map<string, vector<string>>::iterator it;
        for(it=m.begin();it!=m.end();it++)
            res.push_back(it->second);
        return res;
    }
};