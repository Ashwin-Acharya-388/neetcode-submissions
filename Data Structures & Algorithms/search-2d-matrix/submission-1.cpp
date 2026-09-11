class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int beg=0, end = m-1,res=-1;
        while(beg<=end){
            int mid = (beg+end)/2;
            if(target<=matrix[mid][n-1] && target>=matrix[mid][0]){
                res=mid;
                break;
            }
            else if(matrix[mid][n-1]<target){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(res==-1){return false;}
        beg=0;
        end=n-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(matrix[res][mid]==target){
                return true;
            }
            else if(matrix[res][mid]<target){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};
