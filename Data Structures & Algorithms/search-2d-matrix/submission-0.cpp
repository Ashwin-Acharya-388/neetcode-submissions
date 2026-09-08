class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int top=0,bot=m-1,row=-1;
        while(top<=bot){
            int mid=(top+bot)/2;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                row=mid;
                break;
            }
            else if(matrix[mid][0]>target){
                bot=mid-1;
            }
            else{
                top=mid+1;
            }
        }
        if(row==-1){return false;}
        int end=n-1,beg=0;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};
