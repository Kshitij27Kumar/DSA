class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
    while (i < chars.size()) {
        char c = chars[i];
        int len = 0;
        while (i < chars.size() && chars[i] == c) {
            ++i;
            ++len;
        }
        chars[j++] = c;
        if (len > 1) {
            string s = to_string(len);
            for (int k = 0; k < s.size(); ++k) {
                chars[j++] = s[k];
            }
        }
    }
    return j;
    }
};
