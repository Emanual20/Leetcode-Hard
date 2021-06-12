class Solution {
public:
    bool is_needfill(char x){
        return x == '.';
    }

    int calc_space(vector<vector<char>>& board){
        int ret = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(is_needfill(board[i][j])) ret++;
            }
        }
        return ret;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int round = calc_space(board);
        while(round){

            int f = 1;

            for(int i=0;i<board.size();i++){
                if(!f) break;
                for(int j=0;j<board[i].size();j++){
                    if(!f) break;
                    
                    if(!is_needfill(board[i][j])){
                        continue;
                    }

                    int flag[10]={0}, tot=0;

                    for(int k=0;k<9;k++){
                        if(!is_needfill(board[i][k]) && !flag[board[i][k] - '0']) {
                            flag[board[i][k] - '0'] = 1;
                            tot++;
                        }
                    }

                    for(int k=0;k<9;k++){
                        if(!is_needfill(board[k][j]) && !flag[board[k][j] - '0']) {
                            flag[board[k][j] - '0'] = 1;
                            tot++;
                        }                        
                    }

                    int x_base = i - i % 3;
                    int y_base = j - j % 3;
                    for(int a = x_base; a < x_base + 3; a++){
                        for(int b = y_base; b < y_base + 3; b++){
                            if(!is_needfill(board[a][b]) && !flag[board[a][b] - '0']){
                                flag[board[a][b] - '0'] = 1;
                                tot++;
                            }
                        }
                    }

                    if(tot == 8){
                        for(int k = 1; k <= 9; k++){
                            if(!flag[k]){
                                board[i][j] = k + '0';
                            }
                        }
                        f = 0;
                    }

                }
            }

            round-=1;
        }
    }
};