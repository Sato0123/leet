#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	vector<char> *vec = new vector<char>();
	int right = 0;	
	int left  = 0;	
	int max   = 0;	

	if(s == "") return (0);

	while(s[right] != 0){
		//search duplication in a vector
		for(char x : *vec){
			if( s[right] == x ){
				while(s[left] != s[right]){
					vec->erase(vec->begin());
					left++;
				}
				vec->erase(vec->begin());
				left++;
				break;
			}
		}

		//push char in a vector
		vec->push_back(s[right]);

		// update max
		if( max < (right - left + 1) ) max = (right - left + 1);

		right++;
	}
	
	return(max);
    }
};

int main(){
//test data
	string a = "abcbacbb";
	string b = "bbbbb";
	string c = "pwwkew";
	string d = "fbojelwjgercer";

	string aa = "";
	string bb = "abcdefghijklmnopqrstuvwxyz";
	string cc = "aaaaaac";

//call target code
	Solution *sol = new Solution();
	int x = sol->lengthOfLongestSubstring(a);
	int y = sol->lengthOfLongestSubstring(b);
	int z = sol->lengthOfLongestSubstring(c);
	int o = sol->lengthOfLongestSubstring(d);

	int xx= sol->lengthOfLongestSubstring(aa);
	int yy= sol->lengthOfLongestSubstring(bb);
	int zz= sol->lengthOfLongestSubstring(cc);

//debug code
	printf("     %-10s -> ((%d))\n",a.c_str(),x);
	printf("     %-10s -> ((%d))\n",b.c_str(),y);
	printf("     %-10s -> ((%d))\n",c.c_str(),z);
	printf("     %-10s -> ((%d))\n",d.c_str(),o);

	printf("     %-10s -> ((%d))\n",aa.c_str(),xx);
	printf("     %-10s -> ((%d))\n",bb.c_str(),yy);
	printf("     %-10s -> ((%d))\n",cc.c_str(),zz);
}
