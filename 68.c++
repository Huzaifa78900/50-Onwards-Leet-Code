
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {

            int j = i;
            int letters = 0;

            // Step 1: Find maximum words that fit in this line
            while (j < n &&
                   letters + words[j].length() + (j - i) <= maxWidth) {

                letters += words[j].length();
                j++;
            }

            int count = j - i;
            int spaces = maxWidth - letters;

            string line = "";

            // Step 2: Last line or single word
            if (j == n || count == 1) {

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1) {
                        line += " ";
                    }
                }

                // Add remaining spaces at the end
                line += string(maxWidth - line.length(), ' ');
            }

            // Step 3: Fully justify the line
            else {

                int gaps = count - 1;

                int spacePerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1) {

                        int totalSpaces = spacePerGap;

                        // Left gaps get extra spaces
                        if (k - i < extraSpaces) {
                            totalSpaces++;
                        }

                        line += string(totalSpaces, ' ');
                    }
                }
            }

            ans.push_back(line);

            // Move to the next line
            i = j;
        }

        return ans;
    }
};
