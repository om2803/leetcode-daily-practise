class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        int ans=0;
        int maxval=0;
        for(int it: nums){
            if(it>maxval){
                count=0;
                maxval=it;
                ans=0;
            }
            if(it==maxval){
                count++;
            }else{
                count=0;
            }
            ans=max(ans,count);
        }return ans;
    }
};