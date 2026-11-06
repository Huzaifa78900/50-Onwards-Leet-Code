
class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string word = "";

        for (int i = 0; i <= path.length(); i++) {

            // If we find a slash or reach the end
            if (i == path.length() || path[i] == '/') {

                // Ignore empty strings and "."
                if (word == "" || word == ".") {
                    // Do nothing
                }

                // Go to parent directory
                else if (word == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }

                // Valid directory name
                else {
                    st.push(word);
                }

                word = "";
            }
            else {
                word += path[i];
            }
        }

        // Build the final path
        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        if (result == "") {
            return "/";
        }

        return result;
    }
};
