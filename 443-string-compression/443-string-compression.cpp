class Solution {
public:
    int compress(vector<char>& chars) {
        
        
        int i=0,count=1;
        string output="";
        int j;
        
        int n=chars.size();
        
        while(i<n)
        {
            j=i+1;
            
            while(j<n)
            {
                if(chars[i]==chars[j])
                    count++;
                else
                    break;
                
                j++;
            }
            
            if(count>1)
            {
                output+=chars[i];
                output+=to_string(count);
                count=1;
            }
            else
            {
                output+=chars[i];
            }
            
            i=j;
        }
        
        chars.clear();
        
        n=output.length();
        
        for(int i=0;i<n;i++)
            chars.push_back(output[i]);
        
        return n;
    }
};