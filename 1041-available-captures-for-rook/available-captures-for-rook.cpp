class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_i, rook_j;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[i][j] == 'R'){
                    rook_i = i;
                    rook_j = j;
                    break;
                }
            }
        }
        cout<<rook_i<<" "<<rook_j;
        int temp_i = rook_i, temp_j = rook_j, count = 0;
        // atacking north
        temp_i = temp_i - 1;
        while(temp_i >= 0){
            if(board[temp_i][temp_j] == 'p'){
                count ++;
                break;
            }
            else if(board[temp_i][temp_j] == 'B'){
                break;
            }
            temp_i --;
        }

        // attacking south

        temp_i = rook_i, temp_j = rook_j;
        temp_i = temp_i + 1;
        while(temp_i < board.size()){
            if(board[temp_i][temp_j] == 'p'){
                count ++;
                break;
            }
            else if(board[temp_i][temp_j] == 'B'){
                break;
            }
            temp_i ++;
        }

        // attacking west

        temp_i = rook_i, temp_j = rook_j;
        temp_j --;
        while(temp_j >= 0){
            if(board[temp_i][temp_j] == 'p'){
                count ++;
                break;
            }
            else if(board[temp_i][temp_j] == 'B'){
                break;
            }
            temp_j --;
        }

        // attacking east

        temp_i = rook_i, temp_j = rook_j;
        temp_j ++;
        while(temp_j < board.size()){
            if(board[temp_i][temp_j] == 'p'){
                count ++;
                break;
            }
            else if(board[temp_i][temp_j] == 'B'){
                break;
            }
            temp_j ++;
        }
        
        return count;

    }
};