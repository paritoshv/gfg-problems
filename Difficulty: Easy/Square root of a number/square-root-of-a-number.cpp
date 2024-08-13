//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int i = 1;
        long long int j = n;
        while(i<=j){
            long long int m = (j-i)/2 +i;
            if(m*m==n) return m;
            if(m*m < n){
                i=m+1;
            } else {
                j=m-1;
            }
        }
        return i-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends