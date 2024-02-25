class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, string> map;
        uint8_t i = 0, count = 0;
        while(i<rings.size()){
            char c = rings[i];
            int x = rings[i+1] - '0';
            if(map.find(x) == map.end()){
                map[x] = c;
            }
            else{
                map[x] += c;
            }
            i = i+2;
        }
        for(pair rod : map){
            size_t r = rod.second.find("R");
            size_t g = rod.second.find("G");
            size_t b = rod.second.find("B");
            if(r != string::npos && g != string::npos && b != string::npos)
                count ++;
        }
        return count;
    }
};