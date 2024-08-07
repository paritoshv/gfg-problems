//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i =0;
        int i1 =0;
        int i2 =0;
        int ans =0;
        while(i!=k && i1<arr1.size() && i2<arr2.size()){
            
            if(arr1[i1]<=arr2[i2]){
                ans=arr1[i1];
                i1++;
            } else{
                ans=arr2[i2];
                i2++;
            }
            i++;
        }
        
        while(i!=k && i1<arr1.size()){
            ans=arr1[i1];
            i1++;
            i++;
        }
        while(i!=k && i2<arr2.size()){
            ans=arr2[i2];
            i2++;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends