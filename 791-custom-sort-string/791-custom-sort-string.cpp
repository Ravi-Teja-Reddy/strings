class Solution
{
    public:
        string customSortString(string order, string s)
        {

            string out = "";

            unordered_set<char> set;
            unordered_map<char, int> map;
            int n1 = order.length();
            int n2 = s.length();
            for (int i = 0; i < n1; i++)
                set.insert(order[i]);

            for (int i = 0; i < n2; i++)
            {
                if (map.find(s[i]) == map.end())
                    map[s[i]] = 1;
                else
                    map[s[i]] += 1;
            }

            for (int i = 0; i < n1; i++)
            {
                if (map.find(order[i]) != map.end())
                {
                    for (int j = 0; j < map[order[i]]; j++)
                        out += order[i];
                }
            }

            for (int i = 0; i < n2; i++)
            {
                if (set.find(s[i]) == set.end())
                    out += s[i];
            }

            return out;
        }
};