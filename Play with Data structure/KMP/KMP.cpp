//============================================================================
// Name        : KMP.cpp
// Author      : @SCUT-Mida
// Version     : 1.0
// Create Date : 2015-11-23 16:56
// Descripton  : 使用标准C++的方式来实现KMP模式匹配算法
//				 参照《大话数据结构》P141。	  
//	Thought    : next数组的作用就是记录模式字符串T，在匹配中不相等
//				 时，该回溯到重新开始匹配的字符下标
//	Complexity : getNextval()[O(m)]+kmpSearch()[O(n)]，即O(m+n)
//============================================================================

#include "iostream"
using namespace std;
#include "conio.h"         //kbhit()函数的头文件

class KMP{
public:
		/*若Pat的长度为m，此函数的复杂度为O(m)*/
		void getNext(string Pat,int* next){								//字符串与数组下标从0开始！
			next[0] = -1;
			int PreIndex = -1, PostIndex = 0;							//PreIndex表示前缀下标，Postfix表示后缀下标
			while (PostIndex < (int)Pat.size()){
				if (-1 == PreIndex || Pat[PostIndex] == Pat[PreIndex]){		//代表与第一个字符都不匹配
					next[++PostIndex] = ++PreIndex;
				}else{
					PreIndex = next[PreIndex];
				}
			}
		}

		/*若Pat的长度为m，此函数的复杂度为O(m)*/
		void getNextval(string Pat, int* nextval){                        //字符串与数组下标从0开始！
			nextval[0] = -1;
			int PreIndex = -1, PostIndex = 0;							//PreIndex表示前缀下标，Postfix表示后缀下标
			while (PostIndex < (int)Pat.size()){
				if (-1 == PreIndex || Pat[PostIndex] == Pat[PreIndex]){		//代表与第一个字符都不匹配
					/*此处是修改版的nextval与next的区别*/
					if (Pat[++PostIndex] != Pat[++PreIndex])				//当前字符与前缀字符不同
						nextval[PostIndex] = PreIndex;
					else												//相等，将前缀记录的下标值付给当前字符的nextval值
						nextval[PostIndex] = nextval[PreIndex];
				}
				else{
					PreIndex = nextval[PreIndex];
				}
			}
		}

		/*若Src的长度为n，此函数的复杂度为O(n)*/ 
		int kmpSearch(string Src, string Pat, int* nextval, int pos)        
		{
			int Src_i = pos, Pat_j = 0;
			while (Src_i < (int)Src.size() && Pat_j < (int)Pat.size()){   //(int)Src.size()前面的(int)一定要加，不然当Pat_j为-1的时候就会跳出while循环
				if (Pat_j == -1 || Src[Src_i] == Pat[Pat_j]){
					++Src_i;
					++Pat_j;
				}
				else{
					Pat_j = nextval[Pat_j];
				}
			}
			if (Pat_j >= (int)Pat.size())
			{
				return Src_i - Pat.size();
			}
			else
				return -1;           //-1代表没有匹配上
		}
};

void main()
{
	string Src = "aabcabcebafabcabceabcaefabcacdabcab";
	string Pat = "abcab";
	KMP kmp;

	int* next = new int[Pat.size()];
	kmp.getNext(Pat, next);
	for (int i = 0; i < Pat.size(); i++)
	{
		cout << next[i]<<" ";
	}
	cout << endl;

	int* nextval = new int[Pat.size()];
	kmp.getNextval(Pat, nextval);
	for (int i = 0; i < Pat.size(); i++)
	{
		cout << nextval[i] << " ";
	}
	cout << endl;

	int pos = kmp.kmpSearch(Src, Pat, nextval, 0);
	cout << pos << endl;
	while (!kbhit());			//方便调试看数据

}
