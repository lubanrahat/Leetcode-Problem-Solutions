class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(),vector<int>(matrix.size()));
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = matrix[j][i];
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(temp[i].begin(),temp[i].end());
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};