//============================================================================
// Name			: 002_AddTwoNumbers.cpp
// Author		: @SCUT-Mida
// Version		: 1.0
// Create Date	: 2015-11-28 17:04
// Descripton	: LeetCode the 2nd Problem;https://leetcode.com/problems/add-two-numbers/
// Complexity	: 
//============================================================================
#include <vector>
#include <algorithm>		//sort()函数包括的头文件
#include <iostream>
using namespace std;
#include "conio.h"         //kbhit()函数的头文件

/* Definition for singly-linked list.*/
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

//Solution：问题是解决了，也可以提交了！！但运行时间40ms！太久了！！
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ret = new ListNode(0);
		ListNode *cur = ret;
		int sum = 0;
		while (1) {
			if (l1 != NULL) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				sum += l2->val;
				l2 = l2->next;
			}
			cur->val = sum % 10;
			sum /= 10;
			if (l1 != NULL || l2 != NULL || sum)
				cur = (cur->next = new ListNode(0));
			else
				break;
		}
		return ret;
	}
};



int main() {
	//Solution1 s;
	Solution s;
	ListNode *l1 = new ListNode(0), *l2 = new ListNode(0);
	ListNode *pl1, *pl2;
	int l1_length, l2_length;
	int temp;
	cin >> l1_length >> l2_length;
	pl1 = l1;
	while (l1_length--)
	{
		cin >> temp;
		pl1->val = temp;
		pl1 = (pl1->next = new ListNode(0));
	}

	pl2 = l2;
	while (l2_length--)
	{
		cin >> temp;
		pl2->val = temp;
		pl2 = (pl2->next = new ListNode(0));
	}
	
	ListNode *ret = s.addTwoNumbers(l1, l2);
	while (ret->next != NULL)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;

	while (!_kbhit());			//方便调试看数据
	return 0;
}
