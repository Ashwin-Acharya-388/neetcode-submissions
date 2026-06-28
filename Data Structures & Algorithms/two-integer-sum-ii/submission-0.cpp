class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int min=0,max=numbers.size()-1;
        vector<int>ans;
        while(min<max){
            int sum =numbers[min]+numbers[max];
            if(target==sum){
                ans.push_back(min+1);
                ans.push_back(max+1);
                break;
            }
            else if(sum<target){
                min++;
            }
            else{
                max--;
            }
        }
        return ans;
    }
};
