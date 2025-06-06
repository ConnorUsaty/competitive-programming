class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=(int)matrix.size(), m=(int)matrix[0].size();

        bool first_col=false;
        for(int i=0; i<n; ++i){
            if(matrix[i][0]==0) first_col=true;
            for(int j=1; j<m; ++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0; j<m; ++j) matrix[0][j]=0;
        }
        if(first_col){
            for(int i=0; i<n; ++i) matrix[i][0]=0;
        }
    }
};

// can mark rows / columns by putting the first idx as 0
// cannot mark with arbitray value and do 2 passes because constraints allow all possible values in int range