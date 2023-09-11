#include <iostream>
#include "Enemy.h"

using namespace std;


string Enemy::getName()
{
	return name;
}

int Enemy::getHealth_max() 
{
	return health;
}

void Enemy::setHealth_max(int hp_m) 
{
	health_max = hp_m;

}

int Enemy::getHealth() 
{
	return health;
}

void Enemy::setHealth(int hp) 
{
	health = hp;

}




int Enemy::getAttack() 
{
	return attack;
}

void Enemy::setAttack(int a) 
{
	attack = a;

}

int Enemy::getDefend() 
{
	return defend;
}

void Enemy::setDefend(int d) 
{
	defend = d;
}

int* Enemy::getGoodsId()
{
	return goodsId;
}

int* Enemy::getGoodsNum() 
{
	return goodsNum;
}


int Enemy::getMoney()
{
	return money;
}

//
int Enemy::useSkill()           //在map中初始化enemy的技能。
{
	int hurtSkill=0;
	srand((unsigned)time(NULL));
	int ranSkill=rand()%3;
	cout << getName() << "发动技能:";
	switch (ranSkill)
	{
	case 0:
	{
		cout << "回复,回复自身1/10生命值" << endl;
		health += health_max / 10;
		if (getHealth() >= getHealth_max() )
		{
			health = health_max;
		}
		break;
	}
	case 1:
	{
		hurtSkill = attack;
		cout << "吸血，在一回合内获得50%的物理吸血" << endl;
		health += attack/2;
		if (getHealth() >= getHealth_max())
		{
			health = health_max;
		}
		break;
	}
	case 2:
	{
		hurtSkill = 2 * attack;
		cout << "狂暴，攻击翻倍同时自身收到伤害" << endl;
		health -= 3*attack;
		if (health <= 0)
		{
			health = 1;
		}
		break;
	}

	}
	
	return hurtSkill;
}
 



void Enemy::showEnemy() {
	cout <<endl<< "当前怪物属性:" <<'\t';
	cout << "名称:" << name << '\t'<<endl;
	cout << "生命值:" << health << "/" << health_max << '\t';
	cout << "攻击:" << attack << '\t';
	cout << "防御:" << defend << endl;
}



