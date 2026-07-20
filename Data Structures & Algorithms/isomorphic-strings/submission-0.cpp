class Solution {
  public:
    bool isIsomorphic(string &s1, string &s2) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];

            if (mp1.count(c1)) {
                if (mp1[c1] != c2)
                    return false;
            } else {
                mp1[c1] = c2;
            }

            if (mp2.count(c2)) {
                if (mp2[c2] != c1)
                    return false;
            } else {
                mp2[c2] = c1;
            }
        }

        return true;
    }
};