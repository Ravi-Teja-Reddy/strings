class Solution {
public:
    string solve(string num1, string num2, string& ans, int carry)
    {
        
        if(num1=="" && num2=="")
        {
            if(carry)
            {
                ans+=(char)carry+'0';
               
                return ans;
            }
            else
                return ans;
        }
        
        
        else if(num1=="")
        {
            if(carry)
            {
                int digit=((num2[0]-'0')+carry)%10;
                 carry=((num2[0]-'0')+carry)/10;
                
                ans+=(char)digit+'0';
                return solve(num1,num2.substr(1),ans,carry);
            }
            else
            {
                int digit=((num2[0]-'0'))%10;
                
                ans+=(char)digit+'0';
                return solve(num1,num2.substr(1),ans,carry);
            }
        }
        
        else if(num2=="")
        {
            if(carry)
            {
                int digit=((num1[0]-'0')+carry)%10;
                carry=((num1[0]-'0')+carry)/10;
                
                ans+=(char)digit+'0';
                return solve(num1.substr(1),num2,ans,carry);
            }
            else
            {
                int digit=((num1[0]-'0'))%10;
                
                ans+=(char)digit+'0';
                return solve(num1.substr(1),num2,ans,carry);
            }
        }
        
        
        int digit=((num2[0]-'0')+(num1[0]-'0')+carry)%10;
         carry=((num2[0]-'0')+(num1[0]-'0')+carry)/10;
        
        ans+=(char)digit+'0';
        
        return solve(num1.substr(1),num2.substr(1),ans,carry);
        
        
    }
    string addStrings(string num1, string num2) {
        
        
        reverse(num1.begin(),num1.end());
        
        reverse(num2.begin(),num2.end());
        
        string res="";
        
        res=solve(num1,num2,res,0);
        
        reverse(res.begin(),res.end());
        return res;
    }
};