//O(n) time

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> count(26, 0);
        count[keysPressed[0]-'a'] = releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++)
        {
            count[keysPressed[i]-'a']= max(count[keysPressed[i]-'a'], releaseTimes[i] - releaseTimes[i-1]);
        }
        int max = INT_MIN;
        char res;
        for(int i=0;i<26;i++)
            if(count[i] >= max)
            {
                res= i+'a';
                max = count[i];
            }
        return res;
    }
};