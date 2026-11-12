class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";

        int need[128] = {0};
        int have[128] = {0};

        // Store the frequency of each character required from t
        for (char c : t)
            need[c]++;

        int left = 0;
        int required = t.length();
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            have[c]++;

            // This character satisfies one required character
            if (need[c] > 0 && have[c] <= need[c])
                required--;

            // Current window contains everything required
            while (required == 0) {
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove leftmost character
                char leftChar = s[left];
                have[leftChar]--;

                // Removing this makes the window invalid
                if (need[leftChar] > 0 &&
                    have[leftChar] < need[leftChar])
                    required++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};