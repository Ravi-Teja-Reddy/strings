class Solution {
public:
    int compress(vector<char>& chars) {
        
        
        int i=0,count=1;
        int index=0;
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
                chars[index++]=chars[i];
                string s=to_string(count);
                
                for(int k=0;k<s.length();k++)
                    chars[index++]=s[k];
                
                count=1;
            }
            else
            {
                chars[index++]=chars[i];
            }
            
            i=j;
        }
        
       
        
        return index;
    }
};