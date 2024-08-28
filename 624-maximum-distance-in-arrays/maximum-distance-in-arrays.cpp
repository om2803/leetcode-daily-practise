class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int gmin=arrays[0][0];
        int gmax=arrays[0].back();
        int dist=0;

        for(int i=1;i<arrays.size();i++){
            int lmin=arrays[i][0];
            int lmax=arrays[i].back();

            dist=max(dist, max(lmax-gmin, gmax-lmin));

            gmin=min(gmin, lmin);
            gmax=max(gmax, lmax);
        }return dist;
    }
};