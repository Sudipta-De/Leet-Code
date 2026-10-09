
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> path;

        backtrack(s, 0, path, ans);
        return ans;
    }

private:
    void backtrack(string& s, int index,
                   vector<string>& path,
                   vector<string>& ans) {

        if (path.size() == 4) {
            if (index == s.size()) {
                string ip = path[0] + "." + path[1] + "." +
                            path[2] + "." + path[3];
                ans.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (part.size() > 1 && part[0] == '0')
                break;

            // Segment value must not exceed 255
            if (stoi(part) > 255)
                break;

            path.push_back(part);

            backtrack(s, index + len, path, ans);

            path.pop_back();
        }
    }
};