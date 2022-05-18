class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>stk;
        
        int n=s.length();
        
        int start=0;
        
        string ans="";
        while(start<n ){
            
           if(s[start]!=' ' && ans=="")
           {
               
               ans+=s[start];
               start++;
           }
            else if(s[start]!=' ' && ans!="")
            {
                ans+=s[start];
                start++;
            }
            
           else if(s[start]==' ' && ans!="")
            {
                stk.push(ans);
                ans="";
               start++;
            }
            
            else
                start++;
        }
       
        if(ans!="")
        stk.push(ans);
        string out="";
        
        while(!stk.empty())
        {
            out+=stk.top();
            out+=" ";
            stk.pop();
        }
        
        if(out!=" ")
            out.pop_back();
        
        return out;
        
        
    }
};