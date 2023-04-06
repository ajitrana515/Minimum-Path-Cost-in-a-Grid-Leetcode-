// in this question we apply dynammic programming approach with the help of top bottom memorization approach in this question we created the f recursive
function which find the minimum value from all the possible path.

class Solution {
public:
int f(int i,int j,int n,int m,vector<vector<int>>& g,vector<vector<int>>& movecost,vector<vector<int>>& dp){
    if(i==n-1){
        return g[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int move=0;move<m;move++){
     ans=min(ans,g[i][j]+movecost[g[i][j]][move]+f(i+1,move,n,m,g,movecost,dp));
    }
    return dp[i][j]=ans;
}
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,f(0,i,n,m,grid,moveCost,dp));

        }
        return mini;
    }
};
