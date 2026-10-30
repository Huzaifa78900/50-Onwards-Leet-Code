
class Solution {
public:
    bool isNumber(string s) {

        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.length(); i++) {

            char c = s[i];

            if (isdigit(c)) {
                digit = true;
                digitAfterE = true;
            }

            else if (c == '+' || c == '-') {

                // Sign is allowed only at start or after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }

            }

            else if (c == '.') {

                // Dot cannot appear after exponent or twice
                if (dot || exp) {
                    return false;
                }

                dot = true;
            }

            else if (c == 'e' || c == 'E') {

                // Exponent needs a number before it
                // Only one exponent is allowed
                if (exp || !digit) {
                    return false;
                }

                exp = true;
                digitAfterE = false;
            }

            else {
                return false;
            }
        }

        return digit && digitAfterE;
    }
};
