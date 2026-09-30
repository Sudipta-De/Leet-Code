class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        k--;

        string ans = "";

        while (!nums.empty()) {
            int index = k / fact;

            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            k %= fact;

            if (!nums.empty()) {
                fact /= nums.size();
            }
        }

        return ans;
    }
};