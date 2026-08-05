class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        int x=numbers[i],y=numbers[j];
        int sum = x+y;
        while(sum!=target && i<j){
            if(sum<target){x=numbers[++i];}
            if(sum>target){y=numbers[--j];}
            sum = x+y;
        }
        return {i+1,j+1};
    }
};
