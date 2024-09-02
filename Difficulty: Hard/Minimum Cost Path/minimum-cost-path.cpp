//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,-1,1};
        while(pq.size()){
            auto temp = pq.top();
            pq.pop();
            int d = temp.first;
            for(int k=0;k<4;k++){
                int i = temp.second.first+dirX[k];
                int j = temp.second.second+dirY[k];
                if(i<n and j<n and i>=0 and j>=0 and d+grid[i][j]<dis[i][j]){
                    dis[i][j]=d+grid[i][j];
                    pq.push({d+grid[i][j],{i,j}});
                }
            }
        }
        return dis[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends