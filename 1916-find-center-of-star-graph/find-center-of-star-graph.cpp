class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v=edges[0];
        vector<int> vec=edges[1];
        return (v[0]==vec[0] or v[0]==vec[1])? v[0]:v[1];
    }
};