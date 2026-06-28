class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n=nums.size();
      vector<int>ans(n);
      for(int i=0;i<n;i++){
        ans[i]=nums[i];
      }
      sort(ans.begin(),ans.end());
      int i=0,j=n-1;
      int val1, val2;
      while(i<j){
        int answ=ans[i]+ans[j];
        if(answ==target){
            val1 = ans[i];
            val2 = ans[j];
            break;
        }
        else if(answ<target){
            i++;
        }
        else{
            j--;
        }
      }
      vector<int> result;
      for(int k=0; k<n; k++){
        if(nums[k] == val1 || nums[k] == val2) result.push_back(k);
      }
      return result;
    }
};