class Solution
{
    public:
        int minSteps(string s, string t)
        {

            unordered_map<char, int> map1;
            unordered_map<char, int> map2;

            int n = s.length();

            for (int i = 0; i < n; i++)
            {
                if (map1.find(s[i]) != map1.end())
                    map1[s[i]] += 1;
                else
                    map1[s[i]] = 1;
            }

            for (int i = 0; i < n; i++)
            {
                if (map2.find(t[i]) != map2.end())
                    map2[t[i]] += 1;
                else
                    map2[t[i]] = 1;
            }

            int count1 = 0, count2 = 0;

            int count = 0;

            for (int i = 0; i < n; i++)
            {
                if (map1.find(t[i]) != map1.end())
                    count1 = map1[t[i]];
                else
                    count1 = 0;
                if (map2.find(t[i]) != map2.end())
                    count2 = map2[t[i]];
                else
                    count2 = 0;

                if (count2 > count1)
                {
                    count += (count2 - count1);

                    map2[t[i]] = 0;
                }
            }

            return count;
        }
};