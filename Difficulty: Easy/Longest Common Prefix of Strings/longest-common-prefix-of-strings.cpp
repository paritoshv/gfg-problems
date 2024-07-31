//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string prefix = "";
        size_t minlength = arr[0].length();
        for(int j =0; j < arr.size();j++){
            minlength = min(arr[j].length(), minlength);    
        }
        for(size_t i =0;i<minlength;i++){
            char k = arr[0][i];
            for(int j =0; j < arr.size();j++){
                if(arr[j][i]!=k){
                    return prefix=="" ? "-1" :  prefix;
                }
            }
            prefix+=k;
        }
        return prefix=="" ? "-1" :  prefix;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends