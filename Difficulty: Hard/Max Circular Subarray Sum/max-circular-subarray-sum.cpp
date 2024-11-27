//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
                int n = arr.size(),mn=INT_MAX,mx=INT_MIN,sum1=0,sum2=0,total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
            sum2=min(arr[i],sum2+arr[i]);
            mn=min(mn,sum2);
            sum1=max(arr[i],sum1+arr[i]);
            mx=max(mx,sum1);
        }
        return max(mx,total-mn);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends