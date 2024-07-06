class Solution {
public:
    int passThePillow(int n, int time) {
        int fullrounds=time/(n-1);

        int extratime=time%(n-1);
        
        if(fullrounds%2==0){
            return extratime+1;
        }else{
            return n-extratime;
        }
    }
};