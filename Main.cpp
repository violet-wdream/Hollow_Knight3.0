#include <iostream>
#include<fstream>
#include <Windows.h>
#include <mmsystem.h>
#include "Bag.h"
#include "Enemy.h"
#include "Fight.h"
#include "Goods.h"
#include "Map.h"
#include "Npc.h"
#include "Role.h"
#include "Skill.h"
#include "Store.h"
#include"Save.h"
#include"Task.h"
#include"background.h"
#include"examinateInput.h"
#pragma comment (lib,"winmm.lib")


using namespace std;


void newGame(Role player, Map map)
{
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
	Store store;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  //设置字体颜色  /播放音乐
	background(1);


	while (true)
	{
		system("cls");
		player.showRole();   //展示任务信息 /菜单
		cout << endl << "你的位置 :" << map.getName() << endl << endl;
		map.initNpc(map.getPosition(), map.n);
		map.showNpc(map.n);                //展示npc
		cout << endl;
		map.initEnemy(map.getPosition(), map.e);          //进入地图初始化npc和敌人
		map.showEnemy(map.e);

		if (map.getPosition() != 0)
		{
			cout << "\n\n请选择： \n0.任务\t1.交谈\t2.战斗\t3.地图\n\n4.背包\t5.商店\t6.技能\n\n7.修复容器（温泉)\n\n8.保存并退出" << endl;     //menu ;
		}
		else
		{
			cout << "\n\n请选择： \n0.任务\t1.交谈\t2.战斗\t3.地图\n\n4.背包\t5.商店\t6.技能\n\n7.修复容器\n\n8.保存并退出" << endl;  //spring 
		}


		//检测输入

		//std::string choices;
		//cin >> choices;
		//int choice;
		//choice = choices[0] - '0';


		int choice;
		string choices;
		cin >> choices;
		choice = exam(choices);

		switch (choice)                                    
		{
		case 0:
		{
			Task task1(1);
			player.setTask(task1);
			cout << "任务" << player.getTaskId() << '\t' << player.getTaskName() << '\t' << player.getTaskDesc() << endl << endl;         //显示任务

			Task task2(2);
			player.setTask(task2);
			cout << "任务" << player.getTaskId() << '\t' << player.getTaskName() << '\t' << player.getTaskDesc() << endl << endl;

			Task task3(3);
			player.setTask(task3);
			cout << "任务" << player.getTaskId() << '\t' << player.getTaskName() << '\t' << player.getTaskDesc() << endl << endl;
			system("pause");
			break;
		}
		case 1:
		{
			while (true)
			{ 
				system("cls");
				cout << endl << "可对话的人物:" << endl;                                                                                   //跟npc对话然后获得道具
				map.showNpc(map.n);
				cout << "\n请输入要对话的人物(序号):  (输入3退出)" << endl;


				int npcNum = 0;
				string choices;
				cin >> choices;
				npcNum = exam(choices);

				if (npcNum == 3)
				{
					break;
				}
				if (npcNum == 0 || npcNum == 1 || npcNum == 2)
				{
					map.n[map.getPosition()].chat(map.getPosition(), npcNum, player);
					Sleep(1000);
				}
				else
				{
					cout << "输入错误" << endl;
					system("pause");
				}
			}

			break;
		}

		//---------------------------------------------------------------------------------------------------------------------------------
		case 2:                                                                                                   //战斗
		{
			cout << '\n';
			while (true)
			{
				system("cls");
				if (player.getVessel() == 0)
				{
					cout << "容器破碎，请回到温泉修复破损容器。" << endl;
					system("pause");
					break;
				}
				map.showEnemy(map.e);
				if (map.getPosition() == 0 || map.getPosition() == 1)
				{
					cout << "没有战斗目标。" << endl;
					system("pause");
					break;
				}
				cout << "请输入战斗目标序号:  (输入3退出)" << endl;

				int chFight = 0;
				string choices;
				cin >> choices;
				chFight = exam(choices);
				if (chFight == 3)
				{
					break;
				}

				if (chFight == 0 || chFight == 1 || chFight == 2)
				{
					if (map.e[chFight].getName() != " ")         //名字不是空的说明有怪
					{
						Fight fight(player, map.e[chFight]);
						system("cls");
						cout << "正在进入战斗......." << endl;
						while (fight.isFightEnd() == false)      //战斗没结束：人没死，怪没死.逃跑未判定
						{

							if (fight.fightNow() == true)           //成功逃跑
							{
								player = fight.runEndFight();              //结算战果-逃跑
								break;
							}
							if (fight.getResult() == true)           //如果战胜了：敌人血量《=0
							{
								player = fight.endFight();
								break;
							}

						}
						if (fight.getResult() == true)             
						{
							player = fight.endFight();
						}
					}

					else
					{
						cout << "没有敌人可以战斗。" << endl;
						system("pause");
					}
				}

				else
				{
					cout << "输入错误" << endl;
					system("pause");
				}
			}
			break;
		}
		//----------------------------------------------------------------------------------------------------------------------------------
		case 3:
		{
			while (true)
			{
				map.ShowMap();
				cout << "输入w a s d来移动 ，1进入地图" << endl;
				char order;
				cin >> order;
				if (order == '1')
				{

					system("cls");
					background(map.getPosition());                                                              //移动进入地图，播放图片/bgm
					break;
				}
				else
				{
					map.Move(order);
				}

			}
			break;
		}
		//----------------------------------------------------------------------------------------------------------------------------------
		case 4:
		{
			system("cls");
			player.showEquip();
			player.showBag();		//显示背包
			while (true)
			{
				system("cls");
				cout << "1.更换装备		2.取下装备	   3.使用药品     4.退出背包" << endl;
				cout << "请输入选项序号:" << endl;


				int ch;
				string choices;
				cin >> choices;
				ch = exam(choices);        //检测输入
				if (ch == 4)
				{
					break;
				}
				if (ch == 1)                          //
				{
					player.showEquip();
					player.showBag();
					cout << "请选择要换上的装备" << endl;
					int equipId;
				
					cin >> equipId;
					

					std::map<int, int>  smgg = player.getBag().getMapBags();         //检测是否有这个物品
					bool flag = 0;
					for (auto i : smgg) {
						if (i.first == equipId && i.second != 0) {
							player.wearEquip(equipId);
							player.getBag().reduceGoods(equipId, 1);
							flag = 1;
							break;
						}
					}
					if (!flag) {
						cout << "没这个装备!";
						system("pause");
					}

				}
				else if (ch == 2)                                                      
				{
					while (true)
					{
						system("cls");
						cout << "请输入要换下的装备" << endl;
						if (player.getWeapon() != -1)
						{
							cout << "1." << goods[player.getWeapon()].getName() << endl;
						}

						if (player.getClothes() != -1)
						{
							cout << "2." << goods[player.getClothes()].getName() << endl;
						}
						if (player.getWeapon() == -1 && player.getClothes() == -1)
						{
							cout << "没有装备" << endl;
							system("pause");
							break;
						}

						int chEquip;
						string choices;
						cin >> choices;
						chEquip = exam(choices);

						if (chEquip == 1)
						{
							player.removeEquip(player.getWeapon());
							player.getBag().addGoods(player.getWeapon(), 1);
						}
						else if (chEquip == 2)
						{
							player.removeEquip(player.getClothes());
							player.getBag().addGoods(player.getClothes(), 1);
						}
						else
						{
							cout << "输入错误" << endl;
							system("pause");
						}
					}
				}
				else if (ch == 3)
				{
					player.useDrug();		//是否使用药品
				}
				else
				{
					cout << "输入错误。" << endl;
					system("pause");
				}

			}

			break;
		}
		//------------------------------------------------------------------------------
		case 5:
		{
			system("cls");
			int choiceStore = 0;

			while (true)
			{
				system("cls");
				cout << "伊塞尔特：欢迎来到我的商店，想要点什么？" << endl;
				cout << "1.购买物品		2.售出物品		3.退出商店" << endl;

				string choices;
				cin >> choices;
				choiceStore = exam(choices);

				if (choiceStore == 3)
				{
					break;
				}
				if (choiceStore == 1)
				{
					store.showStores();
					player = store.storeToPlayer(player);               //买东西
				}
				if (choiceStore == 2)
				{
					player.showBag();
					player = store.playerToStore(player);       //卖东西
				}

				else
				{
					cout << "输入错误。" << endl;
					system("pause");
				}
			}
			cout << "伊塞尔特：欢迎下次光临!" << endl;
			system("pause");
			break;
		}
		//------------------------------------------------------------------------------
		case 6:
		{
			for (int i = 1; i < 4; i++)
			{
				cout << i << "." << player.getSkill().getName(i) << ":" << player.getSkill().getDescription(i) << endl;
			}
			system("pause");
			break;
		}



		//----------------------------------------------------------------------------------------------------------------------------------
		case 7:
		{
			if (map.getPosition() != 0)
			{
				cout << "请回到温泉处修复容器。" << endl;
			}
			else
			{
				cout << "容器修复成功!" << endl;
				player.setHealth(player.getHealth_max());
				player.setMagic(player.getMagic_max());
				system("pause");
			}
			system("pause");
			break;
		}
		//---------------------------------------------------------------------------------------------------------------------------------
		case 8:
		{
			Save::setToFile(player);
			exit(0);
			break;
		}
		//---------------------------------------------------------------------------------------------------------------------------------
		default:
		{
			cout << "输入错误，请重新输入: " << endl;
			system("pause");
		}


		}

	}
}





void readFile() 
{
	ifstream fileRole("SaveRole.dat", ios_base::in | ios_base::binary);
	ifstream fileBag("SaveBag.dat", ios_base::in | ios_base::binary);
	
	string name;
	bool vessel;
	int health_max, health, magic_max, magic, attack, money, weapon, clothes;
	fileRole >> name  >> health_max >> health >> magic >> magic_max >> attack >>vessel >>  money >>  weapon >> clothes;

	Role player;
	player.setHealth_max(health_max);
	player.setHealth(health);
	player.setMagic_max(magic_max);
	player.setMagic(magic);
	player.setAttack(attack);
	player.setVessel(vessel);
	player.setMoney(money);
	player.setWeapon(weapon);
	player.setClothes(clothes);




	for (int key2 = 24;!fileBag.eof();) {
			
		int key;
		int value;
		fileBag >> key >> value;
		if (key2 == key)
			break;
		player.addSaveGoodsToBag(key, value);
		key2 = key;

	}
	fileRole.close();
	fileBag.close();
	Map newMap;
	cout << "读入成功！" << endl;
	newGame(player,newMap);
	
}


//程序入口
int main()
{
	welcomePage();

	
	while (true)
	{
		int choice;
		string choices;
		cin >> choices;
		choice = exam(choices);

		switch (choice)
		{
		case 1:
		{
			Role player;
			system("cls");
			Map map;
			newGame(player, map);
			break;
		}
		case 2:
		{
			readFile();
			break;
		}
		case 3: break;
		default:
		{
			cout << "输入错误，请重新输入：" << endl;
			system("pause");
		}

		}
	}
	

	return 0;
}



