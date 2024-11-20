//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
                int n=nums.size(), can1, can2, counter1 = 0, counter2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==can1)counter1++;
            else if(nums[i]==can2)counter2++;
            else if(counter1==0){
                can1=nums[i];
                counter1++;
            }
            else if(counter2==0){
                can2=nums[i];
                counter2++;
            }
            else{
                counter1--;
                counter2--;
            }
        }
        int vote1=0,vote2=0;
        for(auto x:nums){
            if(x==can1)vote1++;
            if(x==can2)vote2++;
        }
        vector<int> ans;
        if(vote1>n/3)ans.push_back(can1);
        if(vote2>n/3)ans.push_back(can2);
        if(ans.size()==2 && ans[0]>ans[1])swap(ans[0],ans[1]);
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
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends