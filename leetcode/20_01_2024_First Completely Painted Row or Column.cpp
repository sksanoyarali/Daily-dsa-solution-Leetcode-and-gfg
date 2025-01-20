// First Completely Painted Row or Column
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,pair<int,int>> elementrc;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                elementrc[mat[i][j]]={i,j};
            }
        }
        vector<int> rowcount(n,0);
        vector<int> colcount(m,0);
        for(int i=0;i<m*n;i++){
            int ele=arr[i];
            auto it=elementrc[ele];
            int row=it.first;
            int col=it.second;
            rowcount[row]++;
            colcount[col]++;
            if(rowcount[row]==m || colcount[col]==n){
                return i;
            }
        }
        return -1;
    }
};