//============================================================================
// Name			: 003_LongestSubstring.cpp
// Author		: @SCUT-Mida
// Version		: 1.0
// Create Date	: 2015-11-28 17:32
// Descripton	: LeetCode the 3nd Problem;
//				  https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Complexity	: 
//============================================================================
#include <vector>
#include <algorithm>		//sort()函数包括的头文件
#include <iostream>
using namespace std;
#include "conio.h"         //kbhit()函数的头文件

//Solution：Accepted了！！运行时间28ms！
class Solution {           //Programming By @Mida         
public:
	int lengthOfLongestSubstring(string s) {
		if (!s.empty()){
			auto beg = s.begin(), end = s.end();
			auto next = beg + 1;
			if (next == end)
				return 1;
			int sublength = 1;
			while (next != end){
				if (*beg == *next){
					sublength = ((sublength > 1) ? sublength : 1);
					beg++; next++;
				}
				else{
					next++;
					if (next == end){
						sublength = ((next - beg) > sublength ? (next - beg) : sublength);
						break;
					}
					for (int i = 0; i < (next - beg); i++)
					if (*(beg + i) == *next){
						sublength = ((next - beg) > sublength ? (next - beg) : sublength);
						beg = beg + i + 1;
						if (beg == next)
							next++;
						break;
					}
				}
			}
			return sublength;
		}
		else
			return 0;
	}
};


int main() {
	
	Solution s;
	string str = "abcabcbb";
	int ret = s.lengthOfLongestSubstring(str);
	cout << ret << endl;

	while (!_kbhit());			//方便调试看数据
	return 0;
}
