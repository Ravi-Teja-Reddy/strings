class Solution
{
    public:

        void remove_punctuation(string & s)
        {
            int index = 0;
            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i]>='0'&&s[i]<='9'))
                {
                    s[index++] = s[i];
                }
            }

            s.erase(index);
        }

    bool solve(string &s, int start, int end)
    {
        
       
        if (start > end)
            return true;

        if (s[start] != s[end])
            return false;

        return solve(s, start + 1, end - 1);
    }

    bool isPalindrome(string s)
    {
        int n = s.length();
        
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
            }
        }
        remove_punctuation(s);
        cout<<s.length()<<endl;
        return solve(s, 0, s.length() - 1);
    }
};