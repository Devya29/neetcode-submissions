class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        int minLength = INT_MAX;

        // Find minimum length
        for (int i = 0; i < strs.size(); i++) {
            minLength = min(minLength, (int)strs[i].length());
        }

        string ans = "";

        // Compare character by character
        for (int i = 0; i < minLength; i++) {

            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {

                if (ch != strs[j][i])
                    return ans;
            }

            ans += ch;
        }

        return ans;
    }
};