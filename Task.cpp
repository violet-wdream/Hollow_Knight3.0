
#include"Task.h"

Task::Task(int id):goods(24)
{
	isEnd = false;
	if (id == 1) 
	{
		taskId = 1;
		name = "�ξ��ػ���:";
		desc = "Ѱ��Faker��Saber��Lancer��Rider��Surter�������Ǵ�ܡ�";
	}
	else if (id == 2) {
		taskId = 2;
		name = "����֮��:";
		desc = "Ѱ�Ҳ԰�֮���Ͱ�ɫ�ʺ󣬻�ȡ����֮����Ƭ��";
	}
	else if (id == 3) {
		taskId = 3;
		name = "��������:";
		desc = "ǰ��������ȡ���ն���ʿ��Ϊ������������ӡ����";
	}
}



int Task::getTaskId() {
	return taskId;
}

string Task::getName() {
	return name;
}

string Task::getDesc() {
	return desc;
}

Goods Task::getGoods() {
	return goods;
}

void Task::setGoods(Goods newGoods){
	goods = newGoods;
}

bool Task::getIsEnd() {
	return isEnd;
}

void Task::setIsTaskEnd() {
	isEnd = true;
}