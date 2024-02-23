class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;
        uint16_t count = 0;
        for(char c : allowed){
            set.insert(c);
        }

        for(string word : words){
            bool consistent = true;
            for(char c : word){
                if(set.find(c) == set.end()){
                    consistent = false;
                    break;
                }
            }
            if(consistent) count ++;
        }

        return count;

    }
};