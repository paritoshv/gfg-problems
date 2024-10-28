//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_set<int> s;
        vector<int> ans;
        
        for(int i =0;i<arr.size();i++){
           if(s.find(arr[i])==s.end()){
               s.insert(arr[i]);
               ans.push_back(arr[i]);
           }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends