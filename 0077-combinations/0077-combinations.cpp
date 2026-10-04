
class Solution {
public:

    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int n, int k) {

        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        int need = k - current.size();

        for (int i = start; i <= n - need + 1; i++) {

            current.push_back(i);

            backtrack(i + 1, n, k);

            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        long long total = 1;

        int x = k;

        if (x > n - x) {
            x = n - x;
        }

        for (int i = 1; i <= x; i++) {
            total = total * (n - x + i) / i;
        }

        result.reserve(total);
        current.reserve(k);

        backtrack(1, n, k);

        return result;
    }
};