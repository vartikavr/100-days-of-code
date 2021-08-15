//O(len(s) + len(t)) time

class Solution {
public:
    
    // ***USING ONE HASHMAP***
    
    string minWindow(string s, string t)
    {
        int start=0, end=0;
        vector<int> freq(128, 0);
        for(int i=0;i<t.length();i++)
            freq[t[i]]++;
        int remaining = t.size(), minSize = INT_MAX, minIndex=-1;
        while(end<s.length())
        {
            if(freq[s[end]] > 0)
                remaining--;
            freq[s[end]]--;
            /* reduce the freq of that char regardless of its presence in t
            if the char is not in t, it will result in negative frequency. 
            later as we move the start pointer to the left, we will increase 
            the freq of this char. So we will essentially cancel out all the 
            subtractions we do on the char */ 
            
            end++;
            
            while(remaining == 0)
            {
                if(end-start < minSize)
                {
                    minSize = end-start;
                    minIndex= start;
                }
                freq[s[start]]++;
                /* if the char existed in t already, then freq would be greater than 0. 
                Otherwise it will be 0 or less than 0, as we reduced the frequency of the 
                char earlier regardless of it being in t or not */
                
                if(freq[s[start]] > 0) 
                    remaining++;
                start++;
            }
        }
        if(minSize == INT_MAX)
            return "";
        return s.substr(minIndex, minSize);
    }
    
    // ***USING TWO HASHMAPS***
    
    // bool isMatch(map<char, int> &mapT, map<char, int> &mapS)
    // {
    //     for(auto it=mapT.begin();it!=mapT.end();it++)
    //     {
    //         if(mapS[it->first] < it->second)
    //             return false;
    //     }
    //     return true;
    // }
    // string minWindow(string s, string t) {
    //     int start=0, end=0;
    //     map<char, int> mapT, mapS;
    //     for(int i=0;i<t.size();i++)
    //         mapT[t[i]]++;
    //     int minSize=INT_MAX, minIndex=-1;
    //     while(end<s.length())
    //     {
    //         mapS[s[end]]++;
    //         end++;
    //         while(isMatch(mapT, mapS))
    //         {
    //             if(end-start < minSize)
    //             {
    //                 minSize = end-start;
    //                 minIndex = start; 
    //             }
    //             mapS[s[start]]--;
    //             start++;
    //         }
    //     }
    //     if(minSize == INT_MAX)
    //         return "";
    //     return s.substr(minIndex, minSize);
    // }
};