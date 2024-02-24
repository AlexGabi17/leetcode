class Solution {
    void map_freq(unordered_map<int, int>& map, vector<int>& nums){

        for(int n : nums){
            if(map.find(n) == map.end())
                map[n] = 1;
        
            else
                map[n] = map[n] + 1;
            
        }
    }
    int count_values(const unordered_map<int, int>& map, const vector<int>& nums){
        int counter = 0;

        for(auto e : map)
            if(std::find(nums.begin(), nums.end(), e.first) != nums.end())
                counter += e.second; 
        
        return counter;
    }
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp, mp2;
        map_freq(mp, nums1);
        map_freq(mp2, nums2);

        res.push_back(count_values(mp, nums2));
        res.push_back(count_values(mp2, nums1));

        return res;
    }
};