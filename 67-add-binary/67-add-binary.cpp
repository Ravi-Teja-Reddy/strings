class Solution {
public:
    
    
    string solve(string a, string b,string& ans, int carry)
    {
        if(a.length()==0 && b.length()==0)
        {
            if(carry)
            {
                ans+='1';
                return ans;
            }
            else
            {
                return ans;
            }
        }
        
        else if(a.length()==0)
        {
            if(b[0]=='1' && carry)
            {
                ans+='0';
            return solve(a,b.substr(1),ans,1);
            }
            if(b[0]=='0' && carry)
            {
                ans+='1';
                return solve(a,b.substr(1),ans,0);
            }
            
            if(b[0]=='0')
            {
                ans+='0';
                cout<<"a "<<ans<<endl;
                 return solve(a,b.substr(1),ans,0);
            }
            if(b[0]=='1')
            {
                ans+='1';
                 return solve(a,b.substr(1),ans,0);
            }
        }
        
        else if(b.length()==0)
        {
            if(a[0]=='1' && carry)
            {
                ans+='0';
            return solve(a.substr(1),b,ans,1);
            }
            if(a[0]=='0' && carry)
            {
                ans+='1';
                return solve(a.substr(1),b,ans,0);
            }
            
            if(a[0]=='0')
            {
                ans+='0';
                 return solve(a.substr(1),b,ans,0);
            }
            if(a[0]=='1')
            {
                ans+='1';
                 return solve(a.substr(1),b,ans,0);
            }
        }
        
        int sum=((a[0]-'0')+(b[0]-'0')+carry)%2;
        carry=((a[0]-'0')+(b[0]-'0')+carry)/2;
        ans+=(char)(sum+'0');
        
        string output=solve(a.substr(1),b.substr(1),ans,carry);
        
        return ans;
    }
    
    string addBinary(string a, string b) {
        
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
         ans=solve(a,b,ans,0);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};