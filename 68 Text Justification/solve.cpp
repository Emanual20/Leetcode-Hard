class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int now_length = 0, now_tot = 0;
        for(int i = 0; i < words.size(); i++){
            now_length += words[i].length() + (now_tot == 0 ? 0 : 1);
            now_tot += 1;

            if(now_length > maxWidth){
                now_tot -= 1;
                now_length -= words[i].length() + (now_tot == 0 ? 0 : 1);
                string s = "";

                if(now_tot == 1){
                    s += words[i-1];
                    for(int j = 0; j < (maxWidth - words[i-1].length()); j++){
                        s += ' ';
                    }
                    ans.push_back(s);
                }
                else{
                    int res = (maxWidth - now_length) + (now_tot - 1);
                    for(int j = i - now_tot; j < i; j++){
                        s += words[j];
                        int round = res/(now_tot-1) + ((j-i+now_tot)<(res%(now_tot-1))?1:0);
                        cout<<now_length<<" "<<round<<endl;
                        if(j != i - 1){
                            for(int k = 0; k < round; k++){
                                s += ' ';
                            }
                        }
                    }
                    ans.push_back(s);
                }

                now_length = 0;
                now_length = words[i].length();
                now_tot = 1;
            }
        }

        int i = words.size();
        string s = "";
        if(now_tot == 1){
            s += words[i-1];
            for(int j = 0; j < (maxWidth - words[i-1].length()); j++){
                s += ' ';
            }
            ans.push_back(s);
        }
        else{
            int res = (maxWidth - now_length) + (now_tot - 1);
            for(int j = i - now_tot; j < i; j++){
                s += words[j];
                if(j != i-1){
                    s += ' ';
                }
            }
            int round = maxWidth - s.length();
            for(int j = 0; j < round; j++){
                s += ' ';
            }

            ans.push_back(s);
        }

        return ans;
    }
};