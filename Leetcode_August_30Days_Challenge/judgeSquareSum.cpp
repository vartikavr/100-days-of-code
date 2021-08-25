//Two pointer approach
//O(sqrt(c)) time, O(1) space

class Solution {
public:
    bool judgeSquareSum(int c) {
        long int low=0, high= sqrt(c);
        while(low<=high)
        {
            if(low*low + high*high == c)
                return true;
            else if(low*low + high*high < c)
                low++;
            else
                high--;
        }
        return false;
    }
};