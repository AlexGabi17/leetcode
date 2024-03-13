class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        vector<int> freq_row(mat.size(), 0);
        vector<int> freq_col(mat[0].size(), 0);
        int count = 0;

        for(int i=0; i < mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    freq_row[i] ++;
                    freq_col[j] ++;
                }
                
            }
        }
        for(int i=0; i<mat.size(); i++){
            cout<<freq_row[i]<<"->";
            if(freq_row[i] == 1){
                for(int j=0; j<mat[0].size(); j++){
                    // cout<<freq_col[j]<<" ";
                    if(freq_col[j] == 1 && mat[i][j] == 1){
                        count ++;
                    }
                }
            }
            // cout<<'\n';
        }



        /*
      1 0 1 1 3 1 0 1
   1 [0,0,0,0,0,1,0,0]
   2 [0,0,0,0,1,0,0,1]
   1 [0,0,0,0,1,0,0,0]
   2 [1,0,0,0,1,0,0,0]
   2 [0,0,1,1,0,0,0,0]
        */


        return count;
    }
};