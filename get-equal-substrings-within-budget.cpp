class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0, ans = 0;
        int n = s.size();
        for(int i=0,j=-1;i<s.size();) {
            do {
                j++;
                cost += abs(s[j]-t[j]);
            } while(j < n && cost <= maxCost);
            ans = max(ans,j-i);
            if(j == n) break;
            while(i <= j && cost > maxCost) {
                cost -= abs(s[i]-t[i]);
                i++;
            }
        }
        return ans;
    }
};
