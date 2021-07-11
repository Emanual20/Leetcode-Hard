class Solution {
public:
    vector<vector<string> > ans_vec;
    struct item {
        int no;
        int dis;
        vector<string> path;
    };

    bool isdis1(string s1, string s2) {
        int tot = 0;
        for (int i = 0; i < s1.length(); i++) {
            tot += (s1[i] != s2[i]);
            if (tot >= 2) return false;
        }
        return tot == 1;
    }
    bool isindic(vector<string>& wordList, string pat) {
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == pat) return true;
        }
        return false;
    }
    int indexindic(vector<string>& wordList, string pat) {
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == pat) return i;
        }
        return -1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        const int maxn = 1e3 + 10;
        bool is_used[maxn] = { 0 };

        // push beginword into wordlist, wordlist[wordlist.size()-1] is beginword
        wordList.push_back(beginWord);

        vector<vector<int>> edges;
        for (int i = 0; i < wordList.size(); i++) {
            vector<int> e;
            edges.push_back(e);
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i; j < wordList.size(); j++) {
                if (isdis1(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        if (edges[wordList.size() - 1].size() == 0 || !isindic(wordList, endWord)) {
            return ans_vec;
        }

        bool is_found = 0;
        int min_dis = 999999, org_dis = 0, endindex = indexindic(wordList, endWord);
        queue<item> q;
        vector<string> path; path.push_back(wordList[wordList.size() - 1]);
        q.push({ static_cast<int>(wordList.size() - 1), 0, path });
        is_used[wordList.size() - 1] = 1;

        vector<int> blocked;

        while (!q.empty()) {
            int now_no = q.front().no, now_dis = q.front().dis;
            
            if (now_dis > wordList.size()) return ans_vec;

            if (now_no == endindex) {
                if (!is_found) {
                    is_found = 1;
                    min_dis = now_dis;
                    ans_vec.push_back(q.front().path);
                }
                else if (now_dis == min_dis) {
                    ans_vec.push_back(q.front().path);
                }
            }
            if (org_dis < now_dis && !is_found) {
                for (int i = 0; i < blocked.size(); i++) {
                    is_used[blocked[i]] = 1;
                }
                org_dis = now_dis;
                blocked.clear();
            }

            if (now_dis < min_dis) {
                for (int i = 0; i < edges[now_no].size(); i++) {
                    if (!is_used[edges[now_no][i]]) {
                        vector<string> tmp_vec = q.front().path; tmp_vec.push_back(wordList[edges[now_no][i]]);
                        q.push({ edges[now_no][i], now_dis + 1, tmp_vec });
                        blocked.push_back(edges[now_no][i]);
                    }
                }
            }
            q.pop();
        }
        return ans_vec;
    }
};