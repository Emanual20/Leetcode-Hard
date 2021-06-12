class Solution {
public:
    int is_finish = 0;

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

    bool check(vector<vector<char>>& board, int x, int y, char ch){
        for(int i=0;i<9;i++){
            if(board[i][y] == ch) return false;
        }
        for(int i=0;i<9;i++){
            if(board[x][i] == ch) return false;
        }
        int x_base = x - x % 3, y_base = y - y % 3;
        for(int i = x_base; i < x_base + 3 ; i++){
            for(int j = y_base ; j < y_base + 3; j++){
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<char>>& board, int now, int goal, int pos){
        if(now == goal) {
            is_finish = 1;
            return;
        }
        int x = pos / 9, y = pos % 9;
        if(!is_needfill(board[x][y])){
            return dfs(board, now, goal, pos+1);
        }

        for(int i=1;i<=9;i++){
            if(check(board, x, y, '0' + i)){
                board[x][y] = '0' + i;
                dfs(board, now + 1, goal, pos + 1);
                if(is_finish) return;
                board[x][y] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        int round = calc_space(board);
        dfs(board, 0, round, 0);
    }
};