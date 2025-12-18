#include <bits/stdc++.h>

using namespace std;

class Solution {
    public :
        string convert(string s, int numRows){
            vector<string> ret(numRows);
            int zig = numRows - 2; 
            if (numRows <= 1)
                zig = 0; 
            int section = numRows + zig;
            int len = s.length();
            int i = 0;

            for(;i < len / section; i++){
                for (int j = 0;j < section;j++){
                    if (j == 0)
                       ret[0].push_back(s.at(i * section)); 
                    //section前半部
                    else if (j < section / 2)
                       ret[j].push_back(s.at(i * section + j)); 
                    //section後半部
                    else if(j > section / 2)
                       ret[section - j].push_back(s.at(i * section + j)); 
                    else
                       ret[numRows - 1].push_back(s.at(i * section + j));
                }
            }

            for (int j = 0;i * section + j < len;j++){
                if (j == 0)
                   ret[0].push_back(s.at(i * section)); 
                else if (j < section / 2)
                   ret[j].push_back(s.at(i * section + j)); 
                else if(j > section / 2)
                   ret[section - j].push_back(s.at(i * section + j)); 
                else
                   ret[numRows - 1].push_back(s.at(i * section + j));
            }

            string result;
            for(int i = 0; i < size(ret);i++){
               result += ret[i]; 
            }
            return result;
        }
};