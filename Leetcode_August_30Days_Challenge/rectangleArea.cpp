class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int res=0;
     set<int> sx, sy;
    for (auto v : rectangles) sx.insert(v[0]), sy.insert(v[1]), sx.insert(v[2]), sy.insert(v[3]);
    vector<int> x(begin(sx), end(sx)), y(begin(sy), end(sy));
    vector<vector<int>> m(x.size(), vector<int>(y.size(), 0));

    for (auto v : rectangles) {
        for (auto i = lower_bound(begin(x), end(x), v[0]); *i != v[2]; ++i)
        for (auto j = lower_bound(begin(y), end(y), v[1]); *j != v[3]; ++j)
            if (m[i - begin(x)][j - begin(y)]++ == 0) 
            res = (res + ((long long)*next(i) - *i) * (*next(j) - *j)) % 1000000007;
        }
        return res;   
    }
};