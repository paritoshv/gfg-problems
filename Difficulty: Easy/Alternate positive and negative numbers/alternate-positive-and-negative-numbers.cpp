//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int sign = 1;
        // if(arr[0]<0) sign =-1;
        
        queue <int> nq;
        queue <int> pq;
        
        for(int i =0;i<arr.size();i++){
            if(arr[i]<0){
                nq.push(arr[i]);
            } else {
                pq.push(arr[i]);
            }
        }
        int j =0;
        while(j<arr.size() && !pq.empty() && !nq.empty()){
            int t = sign < 0 ? nq.front() : pq.front();
            sign < 0 ? nq.pop() : pq.pop();
            arr[j]= t;
            j++;
            sign = sign*-1;
        }
        while(j<arr.size() &&!pq.empty()){
            int t = pq.front();
            pq.pop();
            arr[j]= t;
            j++;
        }
        while(j<arr.size() &&!nq.empty()){
            int t = nq.front();
            nq.pop();
            arr[j]= t;
            j++;
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends