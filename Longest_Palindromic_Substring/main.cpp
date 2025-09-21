#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
	if(s.empty()) return ("");
	
	int max   = -1;
	int last  = s.size();
	int start = 0;
	int end   = 0;
	
	if(last == 0) return (s);

	for(int c = 0; c < last; c++){
		// center odd case
		int right = c;
		int left  = c;
		while(left >= 0 && right <= last){
			if(s[right] != s[left])break;
			right++;
			left--;
		}
		right--;
		left++;
		if(right - left > max){
			max   = right - left;
			start = left  ;
			end   = right ;
		}
		// center even case
		right = c+1;
		left  = c;
		while(left >= 0 && right <= last){
			if(s[right] != s[left])break;
			right++;
			left--;
		}
		right--;
		left++;
		if(right - left > max){
			max   = right - left;
			start = left  ;
			end   = right ;
		}
	}
	return (s.substr(start,end - start + 1));
    };
};

int main(){
//init
	Solution *sol = new Solution();
	//map<pair<input,output>,expected>
	map<pair<string,string>,string> *ans_map = new map<pair<string,string>,string>;

//input test data
	//cases of leetcode
	 //genearl
	 ans_map->insert({{"babad",sol->longestPalindrome("babad")},"bab"}); 
	 ans_map->insert({{"cbbd",sol->longestPalindrome("cbbd")},"bb"}); 

	//cases of what I thought
	 //genearl
	  ans_map->insert({{"abcdefghijklmnopqrstuvwxyzz",sol->longestPalindrome("abcdefghijklmnopqrstuvwxyzz")},"zz"}); 
	  ans_map->insert({{"aaaaaac",sol->longestPalindrome("aaaaaac")},"aaaaaa"}); 
	  ans_map->insert({{"kj1v1",sol->longestPalindrome("kj1v1")},"1v1"}); 
	 //boundary
	  // -> no case
	 //error
	  ans_map->insert({{"--++--",sol->longestPalindrome("--++--")},""}); 
	 //edge
	  ans_map->insert({{"",sol->longestPalindrome("")},""}); 
	  ans_map->insert({{"a",sol->longestPalindrome("a")},"a"}); 
	  ans_map->insert({{"ac",sol->longestPalindrome("ac")},"a"}); 
	  ans_map->insert({{"aa",sol->longestPalindrome("aa")},"aa"}); 
	  ans_map->insert({{"dtgrtoxuybwyfskikukcqlvprfipgaygawcqnfhpxoifwgpnzjfdnhpgmsoqzlpsaxmeswlhzdxoxobxysgmpkhcylvqlzenzhzhnakctrliyyngrquiuvhpcrnccapuuwrrdufwwungaevzkvwbkcietiqsxpvaaowrteqgkvovcoqumgrlsxvouaqzwaylehybqchsgpzbkfugujrostopwhtgrnrggocprnxwsecmvofawkkpjvcchtxixjtrnngrzqpiwywmnbdnjwqpmnifdiwzpmabosrmzhgdwgcgidmubywsnshcgcrawjvfiuxzyzxsbpfhzpfkjqcpfyynlpshzqectcnltfimkukopjzzmlfkwlgbzftsddnxrjootpdhjehaafudkkffmcnimnfzzjjlggzvqozcumjyazcapzzxyiwxlcwpzvdsyqcfnguoidiiekwcjdvbxjvgwgcjcmjwbizhhcgirebhsplioytrgjqwrpwdciaeizxssedsylptffwhnedriqozvfcnsmxmdxdtflwjvrvmyausnzlrgcchmyrgvazjqmvttabnhffoe",sol->longestPalindrome("dtgrtoxuybwyfskikukcqlvprfipgaygawcqnfhpxoifwgpnzjfdnhpgmsoqzlpsaxmeswlhzdxoxobxysgmpkhcylvqlzenzhzhnakctrliyyngrquiuvhpcrnccapuuwrrdufwwungaevzkvwbkcietiqsxpvaaowrteqgkvovcoqumgrlsxvouaqzwaylehybqchsgpzbkfugujrostopwhtgrnrggocprnxwsecmvofawkkpjvcchtxixjtrnngrzqpiwywmnbdnjwqpmnifdiwzpmabosrmzhgdwgcgidmubywsnshcgcrawjvfiuxzyzxsbpfhzpfkjqcpfyynlpshzqectcnltfimkukopjzzmlfkwlgbzftsddnxrjootpdhjehaafudkkffmcnimnfzzjjlggzvqozcumjyazcapzzxyiwxlcwpzvdsyqcfnguoidiiekwcjdvbxjvgwgcjcmjwbizhhcgirebhsplioytrgjqwrpwdciaeizxssedsylptffwhnedriqozvfcnsmxmdxdtflwjvrvmyausnzlrgcchmyrgvazjqmvttabnhffoe")},"?"}); 
	 //stress
	  // -> no case

//print result
	printf("RESULT... INPUT           -> ((OUTPUT)) \n");
	for(const auto &pair : *ans_map){
		string input    =  pair.first.first;
		string output   =  pair.first.second;
		string expected =  pair.second;
		if(output == expected)
			printf("   OK ... %-15s -> ((%s)) \n",input.c_str(),output.c_str());
		else if(output != expected && expected == "?")
			printf("   ?? ... %-15s -> ((%s)) \n",input.c_str(),output.c_str());
		else
			printf("   NG ... %-15s -> ((%s)) \n",input.c_str(),output.c_str());
	}
}
