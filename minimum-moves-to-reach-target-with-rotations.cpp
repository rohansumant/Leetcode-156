const int INF = 1e9;
class Solution {
public:
    vector<vector<int>> a;
    int dp[105][105][4];
    int r,c;
    
    inline bool open(int x,int y) {
        return (x < r) && (y < c) && !a[x][y];
    }
    
    int go(int x,int y,int pos) {
        if(!pos && x == r-1 && y == c-2) return 0;
        if(x < r && y < c && dp[x][y][pos] != -1) return dp[x][y][pos];
        int ans = INF;
        if(!pos) {
            // after all translation movements reset the flag that doesn't allow turning
            if(open(x,y+2)) ans = min(ans,1+go(x,y+1,(2|pos)^2)); // sideways
            if(open(x+1,y) && open(x+1,y+1)) {
                ans = min(ans,1+go(x+1,y,(2|pos)^2)); // below
                if(pos < 2) { // turn if allowed
                    ans = min(ans,1+go(x,y,3^pos));
                }
            }
        } else {
            if(open(x,y+1) && open(x+1,y+1)) {
                ans = min(ans,1+go(x,y+1,(2|pos)^2));
                if(pos < 2) {
                    ans = min(ans,1+go(x,y,3^pos));
                }
            }
            if(open(x+2,y)) ans = min(ans,1+go(x+1,y,(2|pos)^2)); // below
        }
        dp[x][y][pos] = ans;
        return ans;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        a = grid;
        r = a.size(); c = a[0].size();
        for(int i=0;i<105;i++) for(int j=0;j<105;j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
            dp[i][j][2] = dp[i][j][3] = -1;
        }
        int ans = go(0,0,0);
        return ans >= INF ? -1 : ans;
    }
};
