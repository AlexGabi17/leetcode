class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<char, string> mp;
        char ch = 'a';
        for(auto m : morse){
            mp[ch] = m;
            ch ++;
        }
        uint8_t count = 0;
        unordered_set<string> set;
        for(string word : words){
            string transformation = "";
            for(char c : word){
                transformation += mp[c];
            }
            if(set.find(transformation) == set.end()){
                count ++;
                set.insert(transformation);
            }
        }
        return count;
    }
};