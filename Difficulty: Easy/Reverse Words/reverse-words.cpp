//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string temp = "";
        stack<string> st;
        int i =0;
        while(i<str.length()){
            if(str[i]=='.'){
                st.push(temp);
                temp = "";
            } else {
                temp+=str[i];
            }
            i++;
        }
        
        st.push(temp);
        str ="";
        while(!st.empty()){
            string k = st.top();
            st.pop();
            
            str+= k;
            if(!st.empty()){
               str+="."; 
            }
        }
        return str;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends