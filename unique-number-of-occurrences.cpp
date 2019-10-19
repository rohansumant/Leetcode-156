class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i:arr) mp[i]++;
        vector<int> a;
        for(auto pr:mp) a.push_back(pr.second);
        sort(a.begin(),a.end());
        bool ok = true;
        for(int i=1;i<a.size();i++) if(a[i] == a[i-1]) {
            ok = false;
        }
        return ok;
    }
};
