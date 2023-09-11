#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include"Skill.h"
using namespace std;

class Enemy 
{
friend class Map;
public:
	Enemy() {}
	~Enemy(){}
	string getName();
	int getHealth_max();
	void setHealth_max(int hp_m);

	int getHealth();
	void setHealth(int hp);

	int getAttack();
	void setAttack(int a);

	int getDefend();
	void setDefend(int d);

	int* getGoodsId();		//掉落物品
	int* getGoodsNum();		//掉落物品数量

	int getMoney();			//增加金钱
	int useSkill();	//怪物使用技能，返回伤害数值
	void showEnemy();
	




private:
	string name = " ";
	Skill skill;
	int health_max;
	int health;
	int attack;
	int defend;
	int goodsId[4] = {0}; //打死怪物会掉落的物品
	int goodsNum[4] = {0};//打死怪物会掉落的物品数量
	int money;  //打死怪物增加的金钱
};



#endif