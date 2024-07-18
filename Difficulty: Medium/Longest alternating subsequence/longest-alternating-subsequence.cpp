//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        if(arr.size()<2){
            return arr.size();
        }
        int l=1;
        int g=1;
        for(int i=1;i<arr.size();i++){

            if(arr[i]>arr[i-1]){
                l=1+g;
            }
            else if(arr[i]<arr[i-1]){
                g=1+l;
            }
        }
        return max(l,g);
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends