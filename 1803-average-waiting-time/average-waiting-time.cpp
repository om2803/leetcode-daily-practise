class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double avgtime=0;

        int currtime=0;

        for(auto it:customers){
            int arrivaltime=it[0];
            int cooktime=it[1];

            if(arrivaltime> currtime){
                currtime=arrivaltime;
            }
            int waitTime=currtime+cooktime-arrivaltime;
            avgtime +=waitTime;

            currtime+=cooktime;

        }
        return avgtime/n;
    }
};