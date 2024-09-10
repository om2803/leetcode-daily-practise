class Solution {
public:
    int getLucky(string s, int k) {
        string ans="";

        for(char ch:s){
            ans+=to_string(ch-'a'+1);
        }
        while(k-- >0){
            int sum=0;
            for(char digi:ans){
                sum+=digi-'0';
            }
            ans=to_string(sum);
        }
        return stoi(ans);
    }
};