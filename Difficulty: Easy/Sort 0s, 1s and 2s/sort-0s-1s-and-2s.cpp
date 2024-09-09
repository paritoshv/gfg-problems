//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int zeros=0,ones=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) zeros++;
            else if(arr[i]==1)ones++;
        }
        for(int i=0;i<arr.size();i++){
            if(zeros){
                arr[i]=0;
                zeros--;
            }
            else if(ones){
                arr[i]=1;
                ones--;
            }
            else arr[i]=2;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends