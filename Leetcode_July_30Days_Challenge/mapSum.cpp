//O(1) for insert, O(n*p) for sum 
//where n -> no of elements in map, p-> length of input string

class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int res =0 ;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->first.find(prefix) == 0)
                res+= it->second;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */