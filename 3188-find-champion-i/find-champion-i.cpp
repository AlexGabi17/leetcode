class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        unordered_map<int, int> freq;
        for(auto row: grid){
            int i=0;
            for(int elem: row){
                if(freq.find(elem) == freq.end()){
                    if(elem == 0){
                        freq[i] = 1;
                    }
                }
                else{
                    if(elem == 0){
                        freq[i] = freq[i] + 1;
                    }
                }
                i ++;
            }
        }
        int max_value = INT_MIN, max_index;
        for(auto elem: freq){
            if(elem.second > max_value){
                max_value = elem.second;
                max_index = elem.first;
            }
        }
        return max_index;
    }
};