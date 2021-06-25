class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        int count = 0;  
        for(char c : t)
        {
            need[c]++;
        }
        count = t.length();
        int l=0, r=0, start=0, size = INT_MAX;
        while(r<s.length())
        {
            char c = s[r];
            if(need[c]>0)
                count--;
            need[c]--;
            if(count==0)
            {
                while(l<r && need[s[l]]<0)
                {
                    need[s[l++]]++;
                }
                if(r-l+1 < size)
                {
                    size = r-l+1;
                    start = l;
                }
                need[s[l]]++;
                l++;
                count++;
            }
            r++;
        }
        return size==INT_MAX ? "" : s.substr(start, size);
    }
};