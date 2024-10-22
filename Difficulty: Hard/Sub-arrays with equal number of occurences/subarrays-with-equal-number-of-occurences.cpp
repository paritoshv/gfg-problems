//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        int n=arr.size();
        

        int countX[n], countY[n];
        
        map<int, int> m; // To store counts of same diffs
        
        // Count occurrences of x and y
        for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
        if (i != 0)
        countX[i] = countX[i - 1] + 1;
        else
        countX[i] = 1;
        } else {
        if (i != 0)
        countX[i] = countX[i - 1];
        else
        countX[i] = 0;
        }
        if (arr[i] == y) {
        if (i != 0)
        countY[i] = countY[i - 1] + 1;
        else
        countY[i] = 1;
        } else {
        if (i != 0)
        countY[i] = countY[i - 1];
        else
        countY[i] = 0;
        }
        
        // Increment count of current
        m[countX[i] - countY[i]]++;
        }
        
        // Traverse map and commute result. 
        int result = m[0];
        for (auto it = m.begin(); it != m.end(); it++) 
        result = result + ((it->second) * ((it->second) - 1)) / 2;
        
        return (result);
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
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends