//============================================================================
// Name			: 004_MedianOfTwoSortedArray.cpp
// Author		: @SCUT-Mida
// Version		: 1.0
// Create Date	: 2015-11-28 17:38
// Descripton	: LeetCode the 4st Problem;
//				  https://leetcode.com/problems/median-of-two-sorted-arrays/
// Complexity	: 
//============================================================================
#include <vector>
#include <algorithm>		//sort()函数包括的头文件
#include <iostream>
using namespace std;
#include "conio.h"         //kbhit()函数的头文件

//Solution1：Accepted了，运行时间52ms！！但时间复杂度是：O(n+m) + log(n+m)！！
class Solution1 {			//合并两个数组，直接通过下标返回中位数
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> C;
		int m = nums1.size(), n = nums2.size();
		vector<int> A = nums1, B = nums2;
		int pa = 0, pb = 0;    // point of A & B

		while (pa < m || pb < n) {
			if (pa == m) {
				C.push_back(B[pb++]);
				continue;
			}
			if (pb == n) {
				C.push_back(A[pa++]);
				continue;
			}
			if (A[pa] > B[pb])
				C.push_back(B[pb++]);
			else
				C.push_back(A[pa++]);
		}
		if ((n + m) & 1)
			return C[(n + m) / 2];
		else
			return (C[(n + m) / 2 - 1] + C[(n + m) / 2]) / 2.0;

	}
};

//Solution2：Accepted了！！运行时间44ms！！时间复杂度：O(log(m + n))！！
class Solution2 {            //网上大牛的，还没看懂！！！！
private:
	double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
		if (m < n) {
			swap(n, m);
			swap(A, B);
		}
		if (n == 0)
			return A[k - 1];
		if (k == 1)
			return min(A[0], B[0]);

		int pb = min(k / 2, n), pa = k - pb;
		if (A[pa - 1] > B[pb - 1])
			return findKthSortedArrays(A, m, B + pb, n - pb, k - pb);
		else if (A[pa - 1] < B[pb - 1])
			return findKthSortedArrays(A + pa, m - pa, B, n, k - pa);
		else
			return A[pa - 1];
	}

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if ((n + m) & 1)
			return findKthSortedArrays(&nums1[0], m, &nums2[0], n, (n + m) / 2 + 1);
		else
			return (findKthSortedArrays(&nums1[0], m, &nums2[0], n, (n + m) / 2 + 1) +
			findKthSortedArrays(&nums1[0], m, &nums2[0], n, (n + m) / 2)) / 2.0;
	}
};



int main() {

	Solution2 s;
	vector<int> nums1{ 0, 1, 2, 3, 4, 5, 6, 8 };
	vector<int> nums2{ 2, 3, 7,10,12 };
	double ret = s.findMedianSortedArrays(nums1, nums2);
	cout << ret << endl;

	while (!_kbhit());			//方便调试看数据
	return 0;
}
