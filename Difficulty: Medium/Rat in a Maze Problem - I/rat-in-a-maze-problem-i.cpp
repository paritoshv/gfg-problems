//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    bool canVisit(int x, int y, vector<vector<int>> &mat, vector<vector<int>> visited, int n){
        if((x>=0 && x<n) && (y>=0 && y <n) && mat[x][y] == 1 && visited[x][y]!=1){
        return true;
        }
      return false;
    }

    void solve(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &visited, int n, vector<string> &ans,string path){
    
        if(x==n-1 && y==n-1){
        ans.push_back(path);    
        return;
        }
        visited[x][y]=1;
    
        if(canVisit(x+1,y,mat,visited,n)){
        solve(x+1,y, mat, visited, n, ans,path+"D");
    
        }
        if(canVisit(x-1,y,mat,visited,n)){
       
        solve(x-1,y, mat, visited, n, ans,path+"U");
     
        }
        if(canVisit(x,y+1,mat,visited,n)){
       
        solve(x,y+1, mat, visited, n, ans,path+"R");
       
        }
        if(canVisit(x,y-1,mat,visited,n)){
        solve(x,y-1, mat, visited, n, ans,path+"L");
       
        }
        
        visited[x][y]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;
        if(mat[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path ="";
        solve(0, 0, mat, visited, n, ans, path);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends