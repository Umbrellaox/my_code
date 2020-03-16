// longest_common_subsequence.cpp : find the longest common subsequence of two strings.
// Date : 3/16/2020
// Author : Myi

#include <iostream>
#include <string>

using namespace std;

/**
 * find the longest common subsequence of two strings
 */
string longest_common_subsequence(const string& a, const string& b)
{
	//递归基
	if (a == "" || b == "")
	{
		return "";
	}

	//递归基
	if ((a.size() <= 1 && b.size() <= 1) && a[a.size() - 1] != b[b.size() - 1])
	{
		return "";
	}


	//如果最后一个字母都相同, 则减而治之
	if (a[a.size() - 1] == b[b.size() - 1])
	{
		return a[a.size() -1 ] + longest_common_subsequence(a.substr(0, a.size() - 1), b.substr(0, b.size() - 1));
	}
	else // 如果最后一个字母都不同, 则继续递归
	{
		return longest_common_subsequence(a.substr(0, a.size() - 1), b).size() > 
			longest_common_subsequence(a, b.substr(0, b.size() - 1)).size() ? 
			longest_common_subsequence(a.substr(0, a.size() - 1), b) : 
			longest_common_subsequence(a, b.substr(0, b.size() - 1));
	}
}

int main()
{

	string temp = longest_common_subsequence("didactical", "advantage");
	
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		cout << temp[i];
	}
	cout << endl;
}
