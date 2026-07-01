class Solution {
public:
    priority_queue<int>maxHeap;
    int res;
    int lastStoneWeight(vector<int>& stones) {
        for(int num : stones){
            maxHeap.push(num);
        }
    while(maxHeap.size()!=1){
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();
        if(x==y && maxHeap.size()==0){
            return 0;
        }
        if(x<y){
            y=y-x;
            maxHeap.push(y);
        }
        if(x>y){
            x=x-y;
            maxHeap.push(x);
        }
    }
    res = maxHeap.top();
    return res;
    }
    
};
