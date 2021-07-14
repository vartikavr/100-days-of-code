//O(N), where M < N
//N -> length of str, M -> length of order

class Solution {
public:
    string customSortString(string order, string str) {
        string res="";
        int count[256]={0};
        for(int i=0;i<str.length();i++)
            count[str[i]]++;
        for(int i=0;i<order.length();i++){
            while(count[order[i]]>0){
                count[order[i]]--;
                res+= order[i];
            }
        }
        for(int i=0;i<str.length();i++){
            while(count[str[i]]>0)
            {
                res+= str[i];
                count[str[i]]--;
            }
        }
        return res;
    }
};