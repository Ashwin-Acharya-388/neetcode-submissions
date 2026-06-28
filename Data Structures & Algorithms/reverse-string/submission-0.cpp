class Solution {
public:
    void reverseString(vector<char>& s) {
        int beg=0,end=s.size()-1;
        char temp;
        while(beg<=end){
            temp=s[beg];
            s[beg]=s[end];
            s[end]=temp;
            beg++;
            end--;
        }
    }
};