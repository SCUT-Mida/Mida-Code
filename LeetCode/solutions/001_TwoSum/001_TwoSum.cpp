//============================================================================
// Name			: 001_TwoSum.cpp
// Author		: @SCUT-Mida
// Version		: 1.0
// Create Date	: 2015-11-28 16:37
// Descripton	: LeetCode the 1st Problem;https://leetcode.com/problems/two-sum/
// Complexity	: Solution1==>O(n^2);Solution1==>...;
//============================================================================
#include <vector>
#include <algorithm>		//sort()函数包括的头文件
#include <iostream>
using namespace std;
#include "conio.h"         //kbhit()函数的头文件

//Solution1：问题是解决了，但是不给我提交！！说我Time Limit Exceeded ！！！
class Solution1 {			//简单的暴力枚举循环
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int sz = numbers.size();
		vector<int> index;
		for (int i = 0; i < sz; i++)
		for (int j = i + 1; j < sz; j++)
		if (numbers[i] + numbers[j] == target) {
			index.push_back(i + 1);
			index.push_back(j + 1);
			return index;
		}
	}
};

//Solution2：问题是解决了，也可以提交了！！运行时间12ms！！！
class Solution2 {         //先排序，然后双向迭代器夹逼
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int sz = numbers.size();
		int sum;
		vector<int> sorted(numbers);
		sort(sorted.begin(), sorted.end());

		auto beg = sorted.begin(), end = sorted.end() - 1;
		vector<int> index;
		while (beg != end)
		{
			sum = *beg + *end;
			if (sum < target)
				beg++;
			else if (sum > target)
				end--;
			else
			for (int i = 0; i < sz; i++)
			{
				if (numbers[i] == *beg)
					index.push_back(i + 1);
				else if (numbers[i] == *end)
					index.push_back(i + 1);
				if (index.size() == 2)
					return index;
			}
		}
	}
};



int main() {
	//Solution1 s;
	Solution2 s;
	vector<int> in;
	int n, t;
	cin >> n;
	while (n--) {
		cin >> t;
		in.push_back(t);
	}
	cin >> t;
	in = s.twoSum(in, t);
	cout << in[0] << ' ' << in[1] << endl;

	while (!_kbhit());			//方便调试看数据
	return 0;
}
