class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins(timePoints.size());
        for(int i=0;i<timePoints.size();i++){
            string time=timePoints[i];
            int h=stoi(time.substr(0,2));
            int m=stoi(time.substr(3));
            mins[i]=h*60+m;
        }
        sort(mins.begin(), mins.end());
        int ans=INT_MAX;
        for(int i=0;i<mins.size()-1;i++){
            ans=min(ans, mins[i+1]-mins[i]);
        }
        return min(ans, 24*60-mins[mins.size()-1]+mins[0]);
    }
};