#include<iostream>
using namespace std;
int examinateInput(int range1, int range2, int num)
{
	while (num<range1 || num>range2)
	{
		cout << "�����������������: " << endl;
		cin >> num;
	}
	return num;
}
int exam(string choices)
{
	int choice;
	if (choices.size() > 1)return -1;      //���������λ������һ���Ƿ�ֵ
	choice = choices[0] - '0';
	return choice;
}
