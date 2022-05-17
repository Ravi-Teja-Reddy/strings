class Solution
{
    public:
        bool isValid(string s)
        {

            stack<char> stk;
            int i = 0;
            while (s[i] != '\0')
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                {
                    stk.push(s[i]);
                    i++;
                }
                else
                {
                    if (s[i] == ')')
                    {
                        if (!stk.empty() && stk.top() != '(')
                        {

                            return false;
                        }

                        if (stk.empty())
                            return false;

                        stk.pop();
                    }
                    else if (s[i] == '}')
                    {
                        if (!stk.empty() && stk.top() != '{')
                        {

                            return false;
                        }

                        if (stk.empty())
                            return false;

                        stk.pop();
                    }
                    else
                    {
                        if (!stk.empty() && stk.top() != '[')
                        {

                            return false;
                        }

                        if (stk.empty())
                            return false;

                        stk.pop();
                    }

                    i++;
                }
            }

            if (stk.empty())
                return true;
            else
                return false;
        }
};