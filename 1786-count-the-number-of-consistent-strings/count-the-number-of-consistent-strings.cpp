class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(int i=0;i<allowed.length();i++){
            st.insert(allowed[i]);
        }
        int count=0;

        for(string it:words){
            bool ok=true;
            for(int i=0;i<it.length();i++){
                char ch=it[i];

                if(st.find(ch)==st.end()){
                    ok=false;
                    break;
                }
            }
            if(ok){
                count++;
            }
        }return count;
    }
};