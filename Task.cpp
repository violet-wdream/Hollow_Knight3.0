
#include"Task.h"

Task::Task(int id):goods(24)
{
	isEnd = false;
	if (id == 1) 
	{
		taskId = 1;
		name = "梦境守护者:";
		desc = "寻找Faker，Saber，Lancer，Rider，Surter并将他们打败。";
	}
	else if (id == 2) {
		taskId = 2;
		name = "国王之魂:";
		desc = "寻找苍白之王和白色皇后，获取国王之魂碎片。";
	}
	else if (id == 3) {
		taskId = 3;
		name = "纯粹容器:";
		desc = "前往黑卵神殿，取代空洞骑士成为纯粹容器，封印辐光";
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