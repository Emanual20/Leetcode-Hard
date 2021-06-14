class Solution {
public:
#define isoffvalid(x,y,n) (((x) >= 0 && (x) < n)&&((y) >= 0 && (y) < n))
    vector<vector<string>> ans;
    Solution() {
        ;
    }
    bool check(vector<string>& board, int x, int y, int n) {
        for (int i = 0; i < n; i++) {
            if (board[x][i] != '.') {
                return false;
            }
            if (board[i][y] != '.') {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            int off = i - y;
            int off_x = x - off;
            int off_y = i;
            if (isoffvalid(off_x, off_y, n) && board[off_x][off_y] != '.') {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            int off = i - y;
            int off_x = x + off;
            int off_y = i;
            if (isoffvalid(off_x, off_y, n) && board[off_x][off_y] != '.') {
                return false;
            }
        }

        return true;
    }
    void solve(vector<string>& board, int now, int goal, int pos, int n) {
        if (goal == now) {
            vector<string>* tmp = new vector<string>(board);
            ans.push_back(*tmp);
        }
        if (pos >= n * n) return;
        int off_x = pos / n, off_y = pos % n;
        for (int i = off_y; i < n; i++) {
            if (check(board, off_x, i, n)) {
                board[off_x][i] = 'Q';
                int pos_next = (off_x + 1) * n;
                solve(board, now + 1, goal, pos_next, n);
                board[off_x][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string x = "";
            for (int j = 0; j < n; j++) {
                x += '.';
            }
            board.push_back(x);
        }
        solve(board, 0, n, 0, n);
        return ans;
    }
};