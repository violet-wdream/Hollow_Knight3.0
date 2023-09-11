#include <iostream>
#include <string>
#include "Role.h"

using namespace std;


Role::Role():task(1)             // 初始属性。
{  
	//mapId = 0;
	name = "Impure_Vessel";
	health_max = 300;
	health = 300;
	magic_max = 100;
	magic = 100;
	attack = 30;
	money =5000;
}


void Role::operator=(Role player)    //深拷贝
{			
	name = player.getName();
	health_max = player.getHealth_max();
	health = player.getHealth();

	magic_max = player.getMagic_max();
	magic = player.getMagic();

	attack = player.getAttack();
	money = player.getMoney();
	bag = player.getBag();		
	task = player.getTask();
	//mapId = player.getMapId();		
	skill = player.getSkill();		
}






int Role::useSkill() 
{
		cout << endl << "请选择："<<endl;
		for (int i = 1; i < 4; i++)
		{
			cout <<i<<"." << skill.getName(i) << ":" << skill.getDescription(i) << "\n\n";
		}
		int chSkill;
		cin >> chSkill;
		if (getMagic() < skill.getNeedMP(chSkill)) 
		{
			cout << "你的灵魂不足，无法使用该技能。" << endl;
			return 0;
		}

		else 
		{
			setMagic(getMagic() - skill.getNeedMP(chSkill));
			cout << "你花费"<<skill.getNeedMP(chSkill) <<"点灵魂使用了“" << skill.getName(chSkill)<<endl<<endl;			
		}

		switch (chSkill)
		{
		case 1:
		{
				//凝聚
			if (health + 50 < health_max)
			{
				setHealth(health + 50);
			}
			else
			{
				setHealth(health_max);
			}
			cout << "回复50点血量" << endl;
			return 0;
		}
		case 2:
		{
			//冲击波
			return 2 * getAttack();
		}
		case 3:
		{
			//蓄力攻击
			return 3 * getAttack();
		}

		}
}





string Role::getName() {
	return name;
}








int Role::getHealth_max() {
	return health_max;
}

void Role::setHealth_max(int hp_m) {
	health_max = hp_m;
}

int Role::getHealth() {
	return health;
}

void Role::setHealth(int hp) {
	health = hp;
	if ( hp > getHealth_max())
		health = getHealth_max();
	if (health < 0)
		health = 0;
}

int Role::getMagic_max() {
	return magic_max;
}

void Role::setMagic_max(int mp_m) {
	magic_max = mp_m;

}

int Role::getMagic() {
	return magic;
}

void Role::setMagic(int mp) {
	magic = mp;
	if (mp > getMagic_max())
		magic = getMagic_max();
	if (mp < 0)
		magic = 0;
}

int Role::getAttack() {
	return attack;
}

void Role::setAttack(int a) {
	attack = a;

}





int Role::getMoney() 
{
	return money;
}

void Role::setMoney(int m) 
{
	money = m;
}

void Role::showRole()
{
	cout << endl;
	cout << "名称:" << name ;
	cout << "\tHP:" << health << "/" << health_max ;
	cout << "\t灵魂:" << magic << "/" << magic_max ;
	cout << "\t攻击力:" <<attack<< endl<<endl;


	cout << "武器:" << goods[weapon].getName();
	cout << "\t:" << goods[weapon].getDesc() << endl << endl;
	cout << "护符:" << goods[clothes].getName();
	cout << "\t:" << goods[clothes].getDesc() << endl << endl;
	cout << "吉欧:" << money << endl << endl;
	if (getVessel() == 0)
	{
		cout << "容器: 破损";
	}
	else
	{
		cout << "容器：完整";
	}
	
}


Bag Role::getBag() 
{
	return bag;
}


Skill Role::getSkill() 
{
	return skill;
}




void Role::setDodge(int state)
{
	dodge = state;
}
bool Role::getDodge()
{
	return dodge;
}

void Role::setVessel(int state)
{
	vessel = state;
}
bool Role::getVessel()
{
	return vessel;
}
void Role::setSki(int state)
{
	ski = state;
}
bool Role::getSki()
{
	return ski;
}






void Role::showBag() 
{
	bag.showBags();
}

int Role::getBagWhichGoodsId(int whichGoods) 
{
	return bag.getWhichGoodsId(whichGoods);

}

int Role::getBagWhichGoodsNum(int whichGoods) 
{
	return bag.getWhichGoodsNum(whichGoods);

}




void Role::addGoodsToBag(int *goodsId, int *num) 
{
	cout << endl << "得到了：" << endl;
	
	bag.showGoods(goodsId, num);
	for (int i = 0; goodsId[i] >= 0;i++)
		if (goodsId[i] == 6 || goodsId[i] == 8 || goodsId[i] == 19) 
		{
			task.setGoods(goods[goodsId[i]]);
			task.setIsTaskEnd();
		}
	if (bag.getGoodsNum() > 20) {
		cout << "背包已满，无法添加。" << endl;
	}
	else if (bag.getGoodsNum() + num[0]+num[1]+num[2]+num[3] > 20) 
	{
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << 20 - bag.getGoodsNum() << "件。" << endl;
		cout << "请选择要添加的物品：";
		for (int chioce = 0;num[chioce] == 0 || bag.getGoodsNum() >= 20;) 
		{
			cin >> chioce;
			if (num[chioce] + bag.getGoodsNum() > 20) 
			{
				bag.addGoods(goodsId[chioce], 20 - bag.getGoodsNum());
				cout << "成功添加" << 20 - bag.getGoodsNum() << "件到背包！" << endl << endl;
			}
			else 
			{
				bag.addGoods(goodsId[chioce], num[chioce]);
				cout << "成功添加" << num[chioce] << "件到背包！" << endl << endl;
			}
		}
	}
	else 
	{
		for(int i = 0; goodsId[i] >= 0;i++)
			bag.addGoods(goodsId[i], num[i]);
		cout << "全部成功添加到背包！" << endl << endl;
	}
}





void Role::addGoodsToBag(int goodsId, int num) 
{
	cout << endl << "得到了：" << endl;

	bag.showGoods(goodsId, num);
	if (bag.getGoodsNum() > 20) 
	{
		cout << "背包已满，无法添加。" << endl;
	}
	else if (bag.getGoodsNum() + num > 20) 
	{
		cout << "背包剩余空位不足，无法完全添加。" << endl;
		cout << "你仅能添加" << 20 - bag.getGoodsNum() << "件。" << endl;
		cout << "请选择要添加的物品：";
		for (int chioce = 0;num == 0 || bag.getGoodsNum() >= 20;) 
		{
			cin >> chioce;
			if (num + bag.getGoodsNum() > 20) 
			{
				bag.addGoods(goodsId, 20 - bag.getGoodsNum());
				cout << "成功添加" << 20 - bag.getGoodsNum() << "件到背包！" << endl << endl;
			}
			else 
			{
				bag.addGoods(goodsId, num);
				cout << "成功添加" << num << "件到背包！" << endl << endl;
			}
		}
	}
	else 
	{
		bag.addGoods(goodsId, num);
		cout << "全部成功添加到背包！" << endl << endl;
	}
}



bool Role::subGoodsToBag(int goodsId, int num) 
{
	return bag.reduceGoods(goodsId,num);
}

void Role::setBag(Bag bags)
{
	bag = bags;
}

void Role::savePlayerBag() 
{
	bag.saveBag();
}



void Role::newBag() {
	 Bag bags;
	 bag = bags;
}



void Role::addSaveGoodsToBag(int goodsId,int num) 
{
	bag.addGoods(goodsId, num);
}



void Role::useDrug() 
{
	if (bag.isUseDrug()) 
	{
		cout << "是否使用药品：	1.是	2.否" << endl;
		int choice;
		cin >> choice;
		if (choice == 2)
			return;
		if (choice == 1) {
			cout << "请选择要使用的药品：" << endl;
			for (int i = bag.getGoodsNum();i > 0;i--) 
			{
				for (int j = 20;j < 24; j++)
					if (getBagWhichGoodsId(i) == j)
						cout << i << "." << '\t' << goods[getBagWhichGoodsId(i)].getName() << '\t' << getBagWhichGoodsNum(i) << " 件" << endl;
			}
			cout << "0.取消" << endl;
			int choiceGoodsId, choiceGoodsNum;
			while (true) 
			{
				cin >> choiceGoodsId;
				if(choiceGoodsId < 0 || choiceGoodsId > bag.getGoodsNum())
					cout << "选择错误，请重新选择！" << endl;
				else break;
				
			}
				choiceGoodsId = getBagWhichGoodsId(choiceGoodsId);
				cout << "请选择使用多少（输入0取消）：" << endl;
				cin >> choiceGoodsNum;
				subGoodsToBag(choiceGoodsId, choiceGoodsNum);
				cout << "成功使用药品！";
				if (choiceGoodsId == 20 || choiceGoodsId == 21) 
				{
					for (int i = choiceGoodsNum;i > 0;i--)
						setHealth(goods[choiceGoodsId].getAddHP() + getHealth());
					cout << "共恢复" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "点气血。" << endl << endl;
				}
				if (choiceGoodsId == 22 || choiceGoodsId == 23) 
				{
					for (int i = choiceGoodsNum;i > 0;i--)
						setHealth(goods[choiceGoodsId].getAddMP() + getMagic());
					cout << "共恢复" << goods[choiceGoodsId].getAddMP() * choiceGoodsNum << "点内力。" << endl << endl;
				}
			if (choiceGoodsId == 0) return;
		}
		
	}
	else
	{
		cout << "没有药品" << endl;
		system("pause");
		return;
	}
}


void Role::showEquip()
{
	cout << "当前已装备:" << endl;
	cout << "武器:";
	if (weapon == -1) 
	{
		cout << "无" << endl;
	}
	else {
		cout << goods[weapon].getName() << endl;
	}
	cout << "防具:";
	if (clothes == -1) 
	{
		cout << "无" << endl;
	}
	else 
	{
		cout << goods[clothes].getName() << endl;
	}
}



void Role::wearEquip(int id)
{
	if (goods[id].getGoodsType() == 0) 
	{
		if (weapon != -1) 
		{
			removeEquip(weapon);
		}
		setAttack(getAttack() + goods[id].getAddAttack());
		weapon = id;
	}
	else if (goods[id].getGoodsType() == 1) 
	{
		if (clothes != -1) 
		{
			removeEquip(clothes);
		}
		setHealth_max(getHealth_max() + goods[id].getAddMaxHP());
		setMagic_max(getMagic_max() + goods[id].getAddMaxMP());
		clothes = id;
	}
	bag.reduceGoods(id,1);
	cout << "已装备 " << goods[id].getName() << endl;
}



void Role::removeEquip(int id)
{
	if (goods[id].getGoodsType() == 0) 
	{
		if (weapon != -1) 
		{
			cout << "当前无武器" << endl;
		}
		setAttack(getAttack() - goods[id].getAddAttack());
		weapon = -1;
	}
	else if (goods[id].getGoodsType() == 1) 
	{
		if (clothes != -1) 
		{
			cout << "当前无防具" << endl;
		}
		setHealth_max(getHealth_max() - goods[id].getAddMaxHP());
		setMagic_max(getMagic_max() - goods[id].getAddMaxMP());
		clothes = -1;
	}
	bag.addGoods(id, 1);
	cout << "已换下 " << goods[id].getName() << endl;
}

int Role::getTaskId()
{
	return task.getTaskId();
}

bool Role::getTaskIsEnd()
{
	return task.getIsEnd();
}

Task Role::getTask() 
{
	return task;
}

void Role::setTask(Task newTask)
{
	task = newTask;
}

void Role::setTaskIsEnd()
{
	task.setIsTaskEnd();
}

string Role::getTaskName()
{
	return task.getName();
}

string Role::getTaskDesc()
{
	return task.getDesc();
}

Goods Role::getTaskGoods()
{
	return task.getGoods();
}

void Role::setTaskGoods(Goods newTaskGoods){
	task.setGoods(newTaskGoods);
}

int Role::getWeapon()
{
	return weapon;
}

void Role::setWeapon(int w)
{
	weapon = w;
}

int Role::getClothes()
{
	return clothes;
}

void Role::setClothes(int c)
{
	clothes = c;
}