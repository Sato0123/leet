#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
        int myAtoi(string s){
            long long ret = 0;
            bool n = false;
            char digit = 0;
            bool nums = false;

            for (char x : s){
                if (((isspace(x) || ((x == '-' || x == '+'))) && (!nums))){
                    x == '-' ? n = true : n = false; 
                    (x == '-' || x == '+') ? nums = true : nums = false;
                    continue;
                }
                if (!(x >= '0' && x <= '9') || (digit > 10))
                    break;
                ret = ret * 10 + (x - '0');
                if (ret != 0)
                    digit++;
                if (ret > INT_MAX)
                    break;
                nums = true;
            }
            n == true ? ret *= -1 : 0;
            if (ret < INT_MIN || ret > INT_MAX)
                ret > 0 ? ret = INT_MAX : ret = INT_MIN;
            return (ret);
        }
};
