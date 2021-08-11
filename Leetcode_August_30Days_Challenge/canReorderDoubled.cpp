//O(n + klogk) time, where k is the number of unique numbers

class Solution {
public:
    static bool myCmp(int &a, int &b)
    {
        return abs(a) < abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;  
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        vector<int> temp;
        for(auto it=m.begin();it!=m.end();it++)
            temp.push_back(it->first);
        sort(temp.begin(), temp.end(), myCmp);
        for(int i=0;i<temp.size();i++)
        {
            if(m[temp[i]] > m[2*temp[i]])
                return false;
            m[2*temp[i]]-= m[temp[i]];
        }
        return true;
    }
};