#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
        int reverse(int x){
            long long ret = 0;
            long long tmp = x < 0 ? -1 * static_cast<long long>(x) : x;
            long long tmp2 = x < 0 ? -1 * static_cast<long long>(x) : x;
            int digits = 0;

            while (tmp > 9){
                tmp /= 10;
                digits++;
            }

            for (int i = digits; tmp2 > 0;i--)
            {
                ret += tmp2 % 10 * pow(10,i); 
                if (ret > INT_MAX || ret < INT_MIN)
                    return (0);
                tmp2 /= 10;
            }
            
            if (x < 0)
                return (-1 * ret);
            else
                return (ret);
        }
};