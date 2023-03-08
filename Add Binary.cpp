class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int carry = 0, i = m - 1, j = n - 1;
        string result = "";
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        return result;
    }
};
