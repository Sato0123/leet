#include <stdio.h>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	if (s == "")
		return (0);	
	map<char,int> charmap;
	int max   = 0;	
	int cnt   = 0;	
	int ind   = 0;

	while(s[ind] != 0){
		if(!charmap.count(s[ind])){
			charmap[s[ind]] = ind;
		}else{
			ind = charmap[s[ind]] + 1;
			charmap.clear();
			cnt = 0;
			continue;
		}
		cnt++;
		ind++;
		if(cnt > max) max = cnt;
	}
        return (max);
    }
};

int main(){
//test data
	string a = "abcabcbb";
	string b = "bbbbb";
	string c = "pwwkew";

	string aa = "";
	string bb = "abcdefghijklmnopqrstuvwxyz";
	string cc = "aaaaaac";

//call target code
	Solution *sol = new Solution();
	int x = sol->lengthOfLongestSubstring(a);
	int y = sol->lengthOfLongestSubstring(b);
	int z = sol->lengthOfLongestSubstring(c);

	int xx= sol->lengthOfLongestSubstring(aa);
	int yy= sol->lengthOfLongestSubstring(bb);
	int zz= sol->lengthOfLongestSubstring(cc);

//debug code
	printf("     %-10s -> ((%d))\n",a.c_str(),x);
	printf("     %-10s -> ((%d))\n",b.c_str(),y);
	printf("     %-10s -> ((%d))\n",c.c_str(),z);

	printf("     %-10s -> ((%d))\n",aa.c_str(),xx);
	printf("     %-10s -> ((%d))\n",bb.c_str(),yy);
	printf("     %-10s -> ((%d))\n",cc.c_str(),zz);
}
