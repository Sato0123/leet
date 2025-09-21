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
	int len = s.length();
	if(len == 1) return (s);

	int left  = 0;
	int right = len-1;
	int max = 1;
	string ret = s.substr(0,1);
	
	while(left < len){
		if(len - left < max) break;

		right = len-1;

		while(left < right){
		string curr = s.substr(left,right+1-left);
			int curr_len = checkPali(curr);
			if(max < curr_len){
				ret = curr;	
				max = curr_len;
			}
			right--;
		}
		left++;
	}
	return(ret);
    }

//return string length
    int checkPali(string s){
	int len = s.length();
	
	if(len == 1){
		return(1);
	}

	if( len % 2 == 0 ){
		for(int i = 0; i < len/2; i++){
			if(s[i] != s[len-1 - i]){
				return(0);
			}
		}
	}else{
		for(int i = 0; i < len/2 + 1; i++){
			if(s[i] != s[len-1 - i]){
				return(0);
			}
		}
	}
	return(len);
    }
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
