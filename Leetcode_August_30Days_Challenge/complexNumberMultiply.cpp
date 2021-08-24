//O(1) time, O(1) space

class Solution {
public:
    pair<int,int> extract(string str)
    {
        int i=0, realPart, imgPart;
        while(i<str.length() && str[i]!='+')
            i++;
        realPart = stoi(str.substr(0, i));
        imgPart = stoi(str.substr(i+1, str.length()-(i+1)-1));
        return {realPart, imgPart};
    }
    string complexNumberMultiply(string num1, string num2) {
        if(num1=="")
            return num2;
        if(num2=="")
            return num1;
        pair<int, int> p1= extract(num1);
        pair<int, int> p2= extract(num2);
        int realNo, imgNo;
        realNo = p1.first*p2.first - p1.second*p2.second;
        imgNo = p1.first*p2.second + p1.second*p2.first;
        string res = to_string(realNo) + "+" + to_string(imgNo) + "i";
        return res;
    }
};