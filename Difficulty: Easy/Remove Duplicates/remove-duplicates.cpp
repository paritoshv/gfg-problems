//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string removeDups(string str) {
        int arr[26]={0};
        int j=0;

        for(int i=0;i<str.size();i++){
            if(arr[str[i]-'a']==0){
                str[j++]=str[i];
            }
            arr[str[i]-'a']=1;
        }
        return str.substr(0,j);


    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends