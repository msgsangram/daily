class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size(); //row
        int m=matrix[0].size(); //column
        int low=0;
        int hi=(n*m)-1;

        if(n==0) return false;
        while(low<=hi){
            int mid=(low+(hi-low)/2);
            if(matrix[mid/m][mid%m]==target) return true;

            if(matrix[mid/m][mid%m]<target){
                low=mid+1;
            }else{
                hi=mid-1;
            }

        }
        return false;
        
    }
};
