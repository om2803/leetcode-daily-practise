class Solution {
public:
    int numSteps(string s) {
        int c=0, count=0;
        for(int i=s.length()-1;i>0;i--){
            if(s[i]-'0'+c==1){
                count+=2;
                c=1;
            }else{
                count++;
            }
        }return c+count;
    }
};