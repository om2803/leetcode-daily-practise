class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xoor=start^goal;
        int count=0;
        while(xoor){
            count+=xoor&1;
            xoor>>=1;
        }return count;
    }
};