class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();

        int len=0;
        string res="";

        stack<int> st;
        for(char ch:s){
            if(ch=='('){
                st.push(res.length());
            }else if(ch==')'){
                len=st.top();
                st.pop();
                reverse(res.begin()+len, res.end());
            }else{
                res.push_back(ch);
            }
            
        }
        return res;


    }
};