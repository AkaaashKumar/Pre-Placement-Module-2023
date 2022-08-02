class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        size_t res_len = max(num1.size(), num2.size());
        int carry = 0;
        for (size_t i = 0; i < res_len; ++i) {
            int digit_sum = 0;
            if (i < num1.size()) {
                digit_sum += num1[i] - '0';
            }
            if (i < num2.size()) {
                digit_sum += num2[i] - '0';
            }
            digit_sum += carry;
            carry = digit_sum / 10;
            digit_sum %= 10;
            res.push_back(digit_sum + '0');
        }
        if (carry) {
            res.push_back(carry + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
