class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen = needle.length();
        int k = 0;
        for (int i = 0; i < haystack.length(); i++) {
            int j = 0;
            k = i;
            while (j < nlen && k < haystack.length()) {
                if (needle[j] == haystack[k])
                {
                    j++;
                    k++;
                }
                else {
                    break;
                }
                if(j==nlen)return i;
            }
        }
        return -1;
    }
};