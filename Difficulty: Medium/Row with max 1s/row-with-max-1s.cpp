//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n =arr.size();
        int ans =-1;
        int ansReturn =-1;
        for(int i =0; i<n; i++){
            int k = arr[i].size();
            int j=0;
            bool foundOne =0;
            while(j<arr[i].size() && foundOne==0){
                if(arr[i][j]==1){
                    foundOne=1;
                }
                j++;
            }
            j--;
            // cout << j;
            if(foundOne==1){
                if(k-j > ans){
                    ansReturn = i;
                }
                ans = max(k-j,ans);
            }
        }
        return ansReturn;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends