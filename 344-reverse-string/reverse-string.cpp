class Solution {
public:
    void reverseString(vector<char>& s) {
        int se=0, e=s.size()-1;
        while(se<=e){
            swap(s[se],s[e]);
            se++;
            e--;
        }
    }
};