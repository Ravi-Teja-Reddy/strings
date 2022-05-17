class Solution
{
    public:
        string keys[10] = { "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz" };

    vector<string> solve(string digits)
    {
        if (digits == "")
        {
            vector<string> res;
            res.push_back("");
            return res;
        }

        int digit = digits[0] - '0';

        vector<string> small_output = solve(digits.substr(1));

        vector<string> output;

        string first = keys[digit];

        for (int i = 0; i < first.length(); i++)
        {
            for (int j = 0; j < small_output.size(); j++)
            {
                output.push_back(first[i] + small_output[j]);
            }
        }

        return output;
    }

    vector<string> letterCombinations(string digits)
    {

        if (digits.length() == 0)
        {
            vector<string> out;
            return out;
        }

        return solve(digits);
    }
};