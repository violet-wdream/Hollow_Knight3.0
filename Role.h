#ifndef ROLE_H
#define ROLE_H

#include <string>
#include "Skill.h"
#include "Bag.h"
#include"Goods.h"
#include"Task.h"
using namespace std;

class Role {
public:
	Role();
	~Role() {}

	void operator =(Role player);

	string getName();
	int getHealth_max();
	void setHealth_max(int hp_m);

	int getHealth();
	void setHealth(int hp);

	int getMagic_max();
	void setMagic_max(int mp_m);

	int getMagic();
	void setMagic(int mp);

	int getAttack();
	void setAttack(int a);

	
	int getMoney();
	void setMoney(int m);

	//int getMapId();
	//void setMapId(int NewMapId);


	Skill getSkill();
	void addSaveGoodsToBag(int goodId,int num);

	Bag getBag();
	void showBag();
	int getBagWhichGoodsId(int whichGoods);			//得到背包里第whichGoods件物品
	int getBagWhichGoodsNum(int whichGoods);
	//显示背包
	void addGoodsToBag(int *goodsId, int* num);//加入背包,重载应对两种情况
	void addGoodsToBag(int goodsId, int num);

	bool subGoodsToBag(int goodsId, int num);	//减少背包里的物品

	void setBag(Bag bags);

	void savePlayerBag();		//用来单独保存背包
	void newBag();

	void showRole();//人物属性 当前装备


	void setDodge(int state);
	bool getDodge();
	void setSki(int state);
	bool getSki();
	void setVessel(int state);
	bool getVessel();

	int useSkill();		//使用技能,返回技能的攻击力加成
	void useDrug();			//使用药品

	int getWeapon();
	void setWeapon(int w);
	int getClothes();
	void setClothes(int c);

	void showEquip();//展示当前装备
	void wearEquip(int id);//穿上装备
	void removeEquip(int id);//脱下装备



	int getTaskId();
	bool getTaskIsEnd();
	void setTask(Task newTask);
	void setTaskIsEnd();
	Task getTask();
	string getTaskName();
	string getTaskDesc();
	Goods getTaskGoods();
	void setTaskGoods(Goods newTaskGoods);

private:
	string name;
	int health_max;
	int health;
	int magic_max;
	int magic;
	int attack = 30;
	bool dodge=0;
	bool ski = 0;
	bool vessel=1;
	int money=0;
	Bag bag;			//背包
	//int bag[20];
	//int mapId;			//记录玩家当前所在地

	Skill skill;		//他所拥有的技能


	int skillLevel;		//升级带来的技能升级点数

	int weapon = -1;//当前武器id  默认-1为无
	int clothes = -1; //当前防具id
	Task task;
				  //物品实例化
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

};
#endif