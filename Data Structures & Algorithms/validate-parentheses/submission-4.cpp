class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        char ch;
        for(int i=0;i<s.size();i++){
            ch=s[i];
            if(ch=='('||ch=='['||ch=='{'){
                st.push(ch);
            }
          else  if(!st.empty()&&ch==')' && st.top()=='('){
                
                st.pop();
            }
          else  if(!st.empty()&&ch==']' && st.top()=='['){
                st.pop();
            } 
         else  if(!st.empty()&&ch=='}' && st.top()=='{'){
                st.pop();
            }
         else{
            return false;
         }
        }
        return st.empty();
    }
};
