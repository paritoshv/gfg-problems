//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        unordered_map<int, int> mp;
        
        for(int i =0 ; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        vector <int> ans;
        for(auto i : mp){
            if(i.second > (nums.size()/3)){
                ans.push_back(i.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        if(ans.size() == 0) ans.push_back(-1); 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends