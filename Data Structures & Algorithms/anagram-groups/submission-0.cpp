class Solution {
public:
    bool anagram(string s, string t)
    {
        if(s.size() != t.size()) return false;

        int hash[26] = {0};

        for(int i = 0; i < s.size(); i++)
            hash[s[i] - 'a']++;

        for(int i = 0; i < t.size(); i++)
        {
            if(hash[t[i] - 'a'] == 0)
                return false;

            hash[t[i] - 'a']--;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        vector<bool> visited(strs.size(), false);

        for(int i = 0; i < strs.size(); i++)
        {
            if(visited[i]) continue;

            vector<string> temp;      // <-- sirf ye naya group
            temp.push_back(strs[i]);
            visited[i] = true;

            for(int j = i + 1; j < strs.size(); j++)
            {
                if(!visited[j] && anagram(strs[i], strs[j]))
                {
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            res.push_back(temp);       // <-- poora group ek saath add
        }

        return res;
    }
};