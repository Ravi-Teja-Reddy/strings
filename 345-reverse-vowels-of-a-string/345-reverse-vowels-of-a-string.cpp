#include <bits/stdc++.h>

class Solution
{
    public:

        string solve(string &s, int start, int last, unordered_set<char> &set)
        {
            if (start >= last)
                return s;

            while (start < last && set.find(s[start]) == set.end())
                start++;

            while (start < last && set.find(s[last]) == set.end())
                last--;

            swap(s[start], s[last]);

            return solve(s, start + 1, last - 1, set);
        }

    string reverseVowels(string s)
    {
        unordered_set<char> set;
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        set.insert('A');
        set.insert('E');
        set.insert('I');
        set.insert('O');
        set.insert('U');

        return solve(s, 0, s.length() - 1, set);
    }
};