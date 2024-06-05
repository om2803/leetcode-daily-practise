class Solution {
public:
    vector<int> fn(const string& word){
        vector<int> cnt(26,0);
        for(char c: word){
            cnt[c-'a']++;
        }
        return cnt;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26,100);
        for(auto it:words){
            vector<int> cnt=fn(it);

            for(int i=0;i<26;i++){
                v[i]=min(v[i],cnt[i]);
            }
        }
        vector<string> res;
        for(int i=0;i<26;i++){
            for(int j=1;j<=v[i];j++){
                res.push_back(string(1,'a'+i));
            }
        }return res;
    }
};