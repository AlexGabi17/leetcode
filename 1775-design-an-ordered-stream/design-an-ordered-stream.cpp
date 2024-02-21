class OrderedStream {
    unordered_map<int, string> mp;
    int size, index = 1;
public:
    OrderedStream(int n) {
        this->size = n;
    }
    
    vector<string> insert(int idKey, string value) {
        mp[idKey] = value;
        vector<string> res;
        if(mp.find(index) == mp.end()) return res;

        for(int i=index; i<=size; i++){
            if(mp.find(i) != mp.end())
                res.push_back(mp[i]);
            else
                break;
        }
        index += res.size();
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */