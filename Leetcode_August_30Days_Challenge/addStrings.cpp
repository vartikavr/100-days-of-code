//O(n) time, where n>m 
//n -> size of string 1, m -> size of string 2

class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.length();
        int size2 = num2.length();
        int i=size1-1, j=size2-1, carry=0;
        string res;
        while(i>=0 || j>=0)
        {
            int p = 0;
            if(i>=0)
                p = num1[i]-'0';
            int q = 0;
            if(j>=0)
                q = num2[j]-'0';
            int sum = (p+q+carry)%10;
            carry = (p+q+carry)/10;
            res+= sum+'0';
            i--;
            j--;
        }
        if(carry)
            res+= carry+'0';
        reverse(res.begin(), res.end());
        return res;
    }
};