#include "Fight.h"
#include <iostream>
#include<fstream>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")


using namespace std;

void outputTxt1(string txt)
{
	string line;
	ifstream myfile(txt);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << "    " << line << endl;
			Sleep(100);
		}
		myfile.close();
	}
	else cout << "error,fail to output the file";
}

int examinateInput1(int range1, int range2, int num)
{
	while (num<range1 || num>range2)
	{
		cout << "输入错误，请重新输入: " << endl;
		cin >> num;
	}
	return num;
}

Fight::Fight(Role p, Enemy e) :player(p), enemy(e) 
{
	round = 1;
}



//每回合战斗
bool Fight::fightNow()                             //true 打完了-win/lose ，false没结束。
{
	if (player.getVessel() == 0||player.getHealth()==0)
	{
		cout << "当前容器处于破损状态，请回到温泉处修复。" << endl;
		return true;
	}
	if (enemy.getHealth()<=0)
	{
		result = true;
		return true;
	}
	showFight();
	cout << "请选择：1.普攻  2.闪避   3 .技能   4. 药品  5.逃跑(75%概率成功) " << endl;
	string str;
	while (true)
	{
		cin >> str;
		int tmp=str[0]-'0';
		if (tmp <1||tmp>5)
		{
			break;
		}
		cout << "输入错误。请重新输入：" << endl;
	}
	int choices = 0;
	choices = str[0] - '0';

	switch (choices)
	{
		case 1:
		{
			cout << "你使用了普通攻击。\n" << endl;
			hurtPlayer = player.getAttack() - enemy.getDefend();
			if (hurtPlayer <= 0)
			{
				cout << "未能击穿敌人护甲，没有造成伤害！\n" << endl;
				hurtPlayer = 0;
			}
			player.setMagic(player.getMagic() + hurtPlayer);
			enemyFight();	
			cout << "你成功对" << enemy.getName() << "造成了" << hurtPlayer << "点的伤害。\n" << endl;
			cout << "获得" << hurtPlayer << "点灵魂"<<endl;
			enemy.setHealth(enemy.getHealth() - hurtPlayer);

				
			break;
		}

		case 2:
		{
			player.setDodge(1);                 //闪避
			cout << "你发动闪避。\n" << endl;
			enemyFight();
			break;
		}
		case 3:
		{
			cout << "你使用技能\n" << endl;
			hurtPlayer = player.useSkill();
			player.setSki(1);
			enemyFight();  //怪物攻击
			cout <<"你成功对" <<enemy.getName()<< "造成了" << hurtPlayer << "的技能伤害。\n" << endl;
			enemy.setHealth(enemy.getHealth() - hurtPlayer);
			
			break;
		}
		case 4:
		{
			recoverHpOrMp();
			enemyFight();  //怪物攻击
			break;
		}
		case 5:
		{
			srand((unsigned)time(NULL));
			if (rand() % 100 <= 25)        //75%
			{			
				cout << "逃跑失败!\n" << endl;
				enemyFight();  
			}
			else 
			{
				cout << "逃跑成功!\n" << endl;
				system("pause");
				return true;	//跳转至战斗逃跑结束，没有获得增益 =>isfightend =true ; 跳出while;
			}
			break;
		}
	}
	
	system("pause");
	system("cls");
	round++;		//回合数加一
	return false;				//战斗未逃跑,未战胜
}




//显示战斗的状态
void Fight::showFight() 
{
	player.showRole();
	cout << endl;
	enemy.showEnemy();
	cout << endl << "第" << round << "回合" << endl;
}






//怪物的随机战斗
void Fight::enemyFight() 
{
	
	srand((unsigned)time(NULL));
	int randNum = rand() % 100;       //random rate


	if (randNum<= 30 )                    //敌人普攻 30%
	{
		cout << enemy.getName() << "发动普攻\n "<<endl;
		if (player.getDodge() == 0)      //玩家不闪避
		{
			hurtEnemy = enemy.getAttack();
		}
		else                              //玩家闪避
		{
			cout << "你成功闪避\n" << endl;
			hurtEnemy = 0;
		}

		player.setHealth(player.getHealth() - hurtEnemy);
	}
	else if(randNum<=75&&randNum>30)             //敌人技能 45%
	{

		hurtEnemy = enemy.useSkill();                    


		srand((unsigned)time(NULL));
		int ran= rand() % 100 <= 75;
		if (player.getDodge() == 1 && ran<=75)
		{
			cout << "你成功闪避！\n" << endl;
			hurtEnemy = 0;
		}
		else if(player.getDodge()==1&&ran>75)
		{
			cout << "你闪避失败。\n" << endl;
		}
		player.setHealth(player.getHealth() - hurtEnemy); //使用技能并造成伤害
	}

	else if(randNum>75&&randNum<100)                                      //敌人闪避 25%
	{
		hurtEnemy = 0;
		cout << enemy.getName() << "发动闪避\n" << endl;;
		if (player.getSki() == 1)
		{
			cout << enemy.getName() << "闪避失败!\n" << endl;
		}
		else 
		{
			cout << enemy.getName() << "闪避成功!\n" << endl;
			hurtPlayer = 0;
		}

	}
	cout << enemy.getName() << "对你造成了" << hurtEnemy << "点伤害\n" << endl;
	player.setDodge(0);
	player.setSki(0);          //set the dodge / ski =0
}






//判断战斗的结束
bool Fight::isFightEnd() 
{
	if (player.getHealth() <= 0)                  //玩家阵亡
	{
		player.setHealth(0);
		player.setVessel(0);
		cout << "容器破碎，请回到温泉修复破损容器。" << endl;
		return true;
	}
	else if (enemy.getHealth() <= 0)                 //敌人阵亡
	{
		cout << "敌人已被击败"<<endl;
		result = true;
		return true;
	}
	else if (fightNow() == true)
	{
		return true;
	}
	return false;
}







//正常结束结束战斗，获得增益
Role & Fight::endFight() 
{  //结束战斗
	cout << enemy.getName()<< "死亡，战斗胜利" << endl;
	Sleep(1000);
	system("pause");
	if (enemy.getName() == "Hollw Knight"&&enemy.getHealth()<=0)
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\t……消灭…………光辉将被释放……\n\n\t\t\t\t\t\t\t\t\t……这个容器，损毁……失败了……\n\n\t\t\t\t\t\t\t\t\t……黎明……将会到来……\n\n\t\t\t\t\t\t\t\t\t……那篡位者，没有思想……只有力量……\n\n\t\t\t\t\t\t\t\t\t……消灭篡位者……我们的光会让它窒息……\n";
		PlaySound(TEXT("end.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		Sleep(2000);
		system("pause");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		outputTxt1("end.txt");
		string newGameMenu = "\t\t\t\t\t\t\t\t\t不论什么代价都在所不惜。\n\n\t\t\t\t\t\t\t\t\t没有可以思考的心智。\n\n\t\t\t\t\t\t\t\t\t没有可以屈从的意志。\n\n\t\t\t\t\t\t\t\t\t没有为苦难哭泣的声音。\n\n\t\t\t\t\t\t\t\t\t生于神与虚空之手。\n\n\t\t\t\t\t\t\t\t\t你必封印在众人梦中散布瘟疫的障目之光。\n\n\t\t\t\t\t\t\t\t\t你是容器。\n\n\t\t\t\t\t\t\t\t\t你是空洞骑士……\n";
		for (unsigned i = 0; i < newGameMenu.length(); i++) 
		{
			Sleep(50);
			cout << newGameMenu[i];
		}
		cout << "\n\n\t\t\t\t\t\t\t\t\tProducers: WDream   ZyL   ZhR" << endl;
		system("pause");
		exit(0);
	}
	addMoney(enemy.getMoney());
	player.addGoodsToBag(enemy.getGoodsId()[0], enemy.getGoodsNum()[0]);
	system("pause");
	return player;
}


//选择逃跑，没有增益
Role &Fight::runEndFight() 
{
	return player;
}

void Fight::addMoney(int addMoney) { //增加吉欧
	cout << "你获得了" << addMoney << "吉欧。" << endl;
	player.setMoney(player.getMoney() + addMoney);
}
/*
void Fight::addFightEndGoods(int* addGoodsId,int* num) 
{  //增加物品
	player.addGoodsToBag(addGoodsId,num);		//addGoodsToBag函数来判断是否能放入
}
*/









//药品
void Fight::recoverHpOrMp() 
{ //消耗物品回复生命值
	if (player.getBag().getGoodsNum() <= 0)
		cout << "没有药品可用！" << endl;
	else {
		cout << "请选择要使用的药品（0取消）：" << endl;
		for (int i = player.getBag().getGoodsNum();i > 0;i--) {
			for (int j = 20;j < 24; j++)
				if (player.getBagWhichGoodsId(i) == j)
					cout << i << "." << '\t' << goods[player.getBagWhichGoodsId(i)].getName() << '\t' << player.getBagWhichGoodsNum(i) << " 件" << endl;
		}

		int choiceGoodsId, choiceGoodsNum;
		cin >> choiceGoodsId;
		if (choiceGoodsId > 0) {
			choiceGoodsId = player.getBagWhichGoodsId(choiceGoodsId);
			cout << "请选择使用多少：" << endl;
			cin >> choiceGoodsNum;
			player.subGoodsToBag(choiceGoodsId, choiceGoodsNum);
			cout << "成功使用药品！";
			if (choiceGoodsId == 20 || choiceGoodsId == 21) {
				for (int i = choiceGoodsNum;i > 0;i--)
					player.setHealth(goods[choiceGoodsId].getAddHP() + player.getHealth());
				cout << "共恢复" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "点气血。" << endl << endl;
			}
			if (choiceGoodsId == 22 || choiceGoodsId == 23) {
				for (int i = choiceGoodsNum;i > 0;i--)
					player.setHealth(goods[choiceGoodsId].getAddMP() + player.getMagic());
				cout << "共恢复" << goods[choiceGoodsId].getAddMP() * choiceGoodsNum << "点内力。" << endl << endl;
			}
		}
	}
}

bool Fight::getResult()
{
	return result;
}