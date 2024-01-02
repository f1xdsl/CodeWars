//Given a signed 32 - bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.
//
//Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).
//
//Example 1:
//
//Input: x = 123
//Output : 321
//Example 2 :
//
//    Input : x = -123
//    Output : -321
//    Example 3 :
//
//    Input : x = 120
//    Output : 21
//
//
//    Constraints :
//
//    -231 <= x <= 231 - 1
//

#include <string>
#include <limits>
class Solution {
public:

    static int reverse(int x) {
        int res = 0;
        std::string s{ std::to_string(x) };
        std::string rev_s = s;
        std::string maxi{ std::to_string(INT32_MAX) };
        std::string mini{ std::to_string(INT32_MIN) };
        if (x < 0) {
            rev_s.erase(0, 1);
            std::reverse(rev_s.begin(), rev_s.end());
            rev_s = "-" + rev_s;
            if (rev_s < mini || rev_s.length() < mini.length()) res = stoi(rev_s);
        }
        else {
            std::reverse(s.begin(), s.end());
            if (s < maxi || s.length() < maxi.length()) {
                res = stoi(s);
            }
        }
        return res;
    }
};
