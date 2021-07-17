//O(n)

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int numOf1s = 0;
        for(int i=0;i<arr.size();i++)
            if(arr[i]==1)
                numOf1s++;
        if(numOf1s == 0) 
            return {0, 2};
        if(numOf1s % 3 != 0)
            return {-1, -1};
        int part1s = numOf1s/3;
        int indexPart1 =-1, indexPart2 =-1, indexPart3= -1;
        numOf1s=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                numOf1s++;
                if(numOf1s == 1)
                    indexPart1 = i;
                else if(numOf1s == part1s + 1)
                    indexPart2 = i;
                else if(numOf1s == 2*part1s +1)
                    indexPart3 = i; 
            }  
        }
        while(indexPart3 <arr.size()){
            if(arr[indexPart1]== arr[indexPart2] && arr[indexPart2]== arr[indexPart3])
            {
                indexPart1++;
                indexPart2++;
                indexPart3++;
            }
            else
                return {-1, -1};
        }
        return {indexPart1-1 ,indexPart2};
    }
};