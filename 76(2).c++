
class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);

        // Store the frequency of characters in t
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int required = t.length();
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            // Include the current character
            if (freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;

            // When all required characters are found
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the left character
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
