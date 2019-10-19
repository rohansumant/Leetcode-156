class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(int i=0,j;i<s.size();i=j) {
            j = i;
            while(j < s.size() && s[j] == s[i]) j++;
            int cnt = j-i;
            if(!st.empty() && st.back().first == s[i]) {
                cnt += st.back().second;
                st.pop_back();
            }
            cnt %= k;
            if(cnt) {
                st.push_back({s[i],cnt});
            }
        }
        string ss;
        for(auto pr : st) {
            ss += string(pr.second,pr.first);
        }
        return ss;
    }
};
