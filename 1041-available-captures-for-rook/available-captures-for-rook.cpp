class Solution {
    int countPawns(vector<vector<char>>& board, int temp_i, int temp_j, int step_i, int step_j){
        temp_i = temp_i + step_i;
        temp_j = temp_j + step_j;
        int count = 0;
        while(temp_i >= 0 && temp_i < board.size() && temp_j >=0 && temp_j < board.size()){
            if(board[temp_i][temp_j] == 'p'){
                count ++;
                break;
            }
            else if(board[temp_i][temp_j] == 'B'){
                break;
            }
            temp_i = temp_i + step_i;
            temp_j = temp_j + step_j;
        }
        return count;
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_i, rook_j, count = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[i][j] == 'R'){
                    rook_i = i;
                    rook_j = j;
                    break;
                }
            }
        }
        
        // atacking north
        count += countPawns(board, rook_i, rook_j, -1, 0);

        // attacking south
        count += countPawns(board, rook_i, rook_j, 1, 0);

        // attacking west
        count += countPawns(board, rook_i, rook_j, 0, -1);

        // attacking east
        count += countPawns(board, rook_i, rook_j, 0, 1);

        return count;

    }
};