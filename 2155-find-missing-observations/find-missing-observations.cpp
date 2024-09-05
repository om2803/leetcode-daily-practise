class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
        int remsum=mean*(n+rolls.size())-sum;

        if(remsum>6*n or remsum<n){
            return{};
        }
        int dismean=remsum/n;
        int mod=remsum%n;
        vector<int> rem_ele(n, dismean);
        for(int i=0;i<mod;i++){
            rem_ele[i]++;
        }
        return rem_ele;
    }
};