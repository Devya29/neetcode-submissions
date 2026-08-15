class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> tracker;

        for (int x : nums) {
            tracker[x]++;

            if (tracker[x] > nums.size() / 2)
                return x;
        }

        return -1;
    }
};