struct my_comparator{
    bool operator()(const int& a, const  int& b){
        return a<b;
    }
};
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end(), my_comparator());
        vector<int> prefix, res;
        int prev = 0;
        for(auto e : nums){
            int val = e + prev;
            prefix.push_back(val);
            prev = val;
        }
        int i, j, mid;
        for(auto q : queries){
            i=0;
            j=prefix.size()-1;
            while(i<=j){
                mid = i + (j-i)/2;
                if(prefix[mid] <= q){
                    i = mid + 1;
                }
                else{
                    j = mid - 1;
                }
            }
            res.push_back(i);
            

        }
        return res;
    }
};