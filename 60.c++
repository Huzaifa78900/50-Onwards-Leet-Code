
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;

        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }

        nums.push_back(n);

        k--; // Convert k to zero-based indexing

        while (!nums.empty()) {
            int index = k / fact;

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            if (nums.empty()) {
                break;
            }

            k %= fact;
            fact /= nums.size();
        }

        return ans;
    }
};
