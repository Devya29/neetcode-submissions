class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;

        int write = 0, read = 1, count = 1;
        char current = chars[0];

        while (read < chars.size()) {
            if (chars[read] == current) {
                count++;
                read++;
            } else {
                chars[write++] = current;

                if (count > 1) {
                    int start = write;
                    while (count) {
                        chars[write++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(chars.begin() + start, chars.begin() + write);
                }

                current = chars[read];
                count = 1;
                read++;
            }
        }

        // Last group
        chars[write++] = current;

        if (count > 1) {
            int start = write;
            while (count) {
                chars[write++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin() + start, chars.begin() + write);
        }

        return write;
    }
};