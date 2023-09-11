#ifndef MAP_H
#define MAP_H

#include <string>
#include "Enemy.h"
#include"Role.h"
#include "Npc.h"

using namespace std;

class Map
{
public:
	Map();//初始位置为地图0
	Map(int pos); //由参数pos为所在位置

	~Map() {}
	void ShowMap();			//显示大地图

	void Move(char order);

	void initNpc(int position,Npc npc[3]);
	void showNpc(Npc npc[3]);
	void initEnemy(int position, Enemy enemy[3]);
	void showEnemy(Enemy enemy[3]);


	int getPosition();


	int getNpcGoodsId();
	int getNpcGoodsNum();
	string getName();
	Npc n[3];
	Enemy e[3];




private:
	string name;
	int position; //当前位置
	string mapName[10] = { "温泉","德特茅斯","遗忘十字路","螳螂村","王后花园","水晶山峰","苍白宫廷","黑卵圣殿" };
	int mapNum;
	char pos[6][6];
	int dx;
	int dy;
	Npc npc;
};

#endif