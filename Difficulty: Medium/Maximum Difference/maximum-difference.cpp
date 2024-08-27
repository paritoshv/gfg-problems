//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
                stack<int>s1,s2;
        vector<int> v1(arr.size()),v2(arr.size());
        s1.push(0);
        s2.push(0);
        for(int i=0;i<arr.size();i++){
            while(!s1.empty() && s1.top()>= arr[i]){
                s1.pop();
            }
            v1[i]=s1.top();
            s1.push(arr[i]);
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!s2.empty() && s2.top()>= arr[i]){
                s2.pop();
            }
            v2[i]=s2.top();
            s2.push(arr[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,abs(v1[i] - v2[i]));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends