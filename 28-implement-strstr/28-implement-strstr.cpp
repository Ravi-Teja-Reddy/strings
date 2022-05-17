class Solution
{
    public:

       	// checks if b is a substring in 'a' starting from start
        bool is_possible(string a, string b, int start, int end)
        {

            int i = start;
            int j = 0;
            while (j < b.length() && i <= end)
            {
                if (a[i++] != b[j++])
                    return false;
            }

            if (j == b.length())
                return true;
            else
                return false;
        }

    int solve(string haystack, string needle, int start, int end)
    {

        if (start > end)
            return -1;

        if (is_possible(haystack, needle, start, end))
            return start;

        return solve(haystack, needle, start + 1, end);
    }

    int strStr(string haystack, string needle)
    {

        int start = 0;

        int end = haystack.length() - 1;

        return solve(haystack, needle, start, end);
    }
};