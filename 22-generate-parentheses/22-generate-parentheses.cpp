class Solution
{
    public:

        vector<string> res;

    void solve(int open, int close, string output)
    {

        if (open < 0 || close < 0)
            return;

        if (open ==0 && close == 0)
        {
            res.push_back(output);
            return;
        }

        if (close == open)
        {
             solve(open - 1, close, output + '(');
        }
        
        else{
        solve(open - 1, close, output + '(');
        solve(open, close - 1, output + ')');
        }
    }

    vector<string> generateParenthesis(int n)
    {

        int open = n, close = n;

        string output = "";

        solve(open, close, output);

        return res;
    }
};