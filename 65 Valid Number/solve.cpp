class Solution {
public:
    int type(char c){
        if(c == '+' || c == '-'){
            return 0;
        }
        else if(c == '.'){
            return 1;
        }
        else if(c >= '0' && c <= '9'){
            return 2;
        }
        else if(c == 'e' || c == 'E'){
            return 3;
        }
        else return 4;
    }
    bool isNumber(string s) {
        // +/- ; . ; 0-9 ; e/E; else
        int move[8][5] = {
            0, 1, 2, 7, 7,
            7, 7, 4, 7, 7,
            7, 3, 2, 5, 7, 
            7, 7, 3, 5, 7, 
            7, 7, 4, 5, 7,
            5, 7, 6, 7, 7,
            7, 7, 6, 7, 7,
            7, 7, 7, 7, 7
        };
        int accept[] = {2, 3, 4, 6};
        int now = 0;
        for(int i = 0; i < s.length(); i++){
            now = move[now][type(s[i])];
        }
        for(int i = 0; i < 4; i++){
            if(now == accept[i]) return 1;
        }
        return 0;
    }
};