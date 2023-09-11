#include<iostream>
using namespace std;
int examinateInput(int range1, int range2, int num)
{
	while (num<range1 || num>range2)
	{
		cout << "输入错误，请重新输入: " << endl;
		cin >> num;
	}
	return num;
}
int exam(string choices)
{
	int choice;
	if (choices.size() > 1)return -1;      //如果超过两位数返回一个非法值
	choice = choices[0] - '0';
	return choice;
}
