#include <iostream>
#include "Map.h"

using namespace std;

Map::Map()  
{
	position = 1;
	dx = 1;
	dy = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = 'Y';
}

Map::Map(int p) 
{
	position = p;
	if (p == 0) 
	{
		dx = 0;
		dy = 0;
	}
	if (p == 1) 
	{
		dx = 1;
		dy = 0;
	}
	if (p == 2) 
	{
		dx = 1;
		dy = 1;
	}
	if (p == 3) 
	{
		dx = 0;
		dy = 1;
	}
	if (p == 4) 
	{
		dx = 0;
		dy = 2;
	}
	if (p == 5) 
	{
		dx = 2;
		dy = 1;
	}
	if (p == 6) 
	{
		dx = 2;
		dy = 2;
	}
	if (p == 7) 
	{
		dx = 1;
		dy = 2;
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pos[i][j] = ' ';
		}
	}
	pos[dx][dy] = 'Y';
}


void Map::Move(char order)
{
	pos[dx][dy] = ' ';
	switch (order)
	{
	case 'w': {
		if (position == 1 || position == 3 || position == 5) {
			dy++;
			position++;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 'a': {
		if (position == 3 || position == 7) {
			dx++;
			position--;
		}
		else if (position == 0)
		{
			dx++;
			position = 1;
		}
		else if (position == 2)
		{
			dx++;
			position = 5;
		}
		else if (position == 4)
		{
			dx++;
			position = 7;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 's': {
		if (position == 2 || position == 4 || position == 6) {
			dy--;
			position--;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	case 'd': {
		if (position == 2 || position == 6) {
			dx--;
			position++;
		}
		else if (position == 1)
		{
			dx--;
			position = 0;
		}
		else if (position == 5)
		{
			dx--;
			position = 2;
		}
		else if (position == 7)
		{
			dx--;
			position = 4;
		}
		else
		{
			cout << "移动失败" << endl;
		}
		break;
	}
	default:
		break;
	}
	pos[dx][dy] = 'Y';
}

//-----------------------------------------------------------------------------------------------------------
void Map::ShowMap()
{
	system("cls");
	cout << "地图:" << endl;
	
	cout << " __________	   __________	     __________ " << endl;
	cout << "|          |	  |          |	    |          |" << endl;
	//cout<<"|          |          |          |          |"<<endl;
	cout << "| 苍白宫廷 |———| 黑卵圣殿 |———| 王后花园 |" << endl;
	cout << "|     " << pos[2][2] << "    |	  |     " << pos[1][2] << "    |	    |    " << pos[0][2] << "     |" << endl;
	//cout<<"|          |       |   |          |          |"<<endl;
	cout << "|__________|	  |__________|	    |__________|" << endl;
	cout << "      |                                   |            " << endl;
	cout << "      |                                   |            " << endl;
	cout << "      |                                   |            " << endl;
	cout << " _____|____	   __________	     _____|____ " << endl;
	cout << "|          |	  |          |	    |          |" << endl;
	//cout<<"|          |          |          |          |"<<endl;
	cout << "| 水晶山峰 |———|遗忘十字路|———|  螳螂村  |" << endl;
	cout << "|     " << pos[2][1] << "    |	  |     " << pos[1][1] << "    |	    |    " << pos[0][1] << "     |" << endl;
	//cout<<"|          |       |   |          |          |"<<endl;
	cout << "|__________|	  |__________|	    |__________|" << endl;
	cout << "                        |                             " << endl;
	cout << "                        |                             " << endl;
	cout << "                        |                             " << endl;
	cout << "           	   _____|____	     __________ " << endl;
	cout << "            	  |          |	    |          |" << endl;
	//cout<<"|          |          |          |          |"<<endl;
	cout << "                  | 德特茅斯 |———|   温泉   |" << endl;
	cout << "             	  |     " << pos[1][0] << "    |	    |    " << pos[0][0] << "     |" << endl;
	//cout<<"|          |       |   |          |          |"<<endl;
	cout << "            	  |__________|	    |__________|" << endl;

	
	cout << "您的位置: " << mapName[position] << endl;
}
//----------------------------------------------------------------------------------------------------




void Map::initNpc(int position, Npc npc[3])      //initiate the npc
{
	switch (position)
	{
		case 0:npc[0].name = "0.奎若"; npc[1].name = "1.泡温泉的小虫子"; npc[2].name = " ";//spring
			break;
		case 1:npc[0].name = "0.虫长者"; npc[1].name = "1.伟大的佐特"; npc[2].name = " "; //dirtmouth
			break;
		case 2:npc[0].name = "0.米拉"; npc[1].name = " "; npc[2].name = " ";      //crossroads
			break;
		case 3:npc[0].name = "0.奎若"; npc[1].name = " ";  npc[2].name = " ";     //mantistown
			break;
		case 4:npc[0].name = "0.白色夫人";  npc[1].name = " "; npc[2].name = " ";//queengarden
			break;
		case 5:npc[0].name = "0.奎若"; npc[1].name = "1.猎人";   npc[2].name = " ";//crystalpeak
			break;
		case 6:npc[0].name = "0.苍白之王沃姆的尸体";  npc[1].name = " "; npc[2].name = " ";//palepalace
			break;
		case 7:npc[0].name = "0.黄蜂女";  npc[1].name = " "; npc[2].name = " "; //blackeggpalace 
			break;
		default:
			break;
	}
}
void Map::showNpc(Npc npc[3])
{
	cout << "Npc:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << npc[i].name << "  ";
	}
}




//-------------------------------------------------------------------------------------------------------
void Map::initEnemy(int position, Enemy enemy[3])
{
	switch (position)
	{
	case 0:enemy[0].name = " "; enemy[1].name = " "; enemy[2].name = " ";//spring
		break;
	case 1:enemy[0].name = " "; enemy[1].name = " "; enemy[2].name = " "; //dirtmouth
		break;
	case 2:
	{	
		enemy[0].name = "龙牙哥";
		enemy[0].health = 200;
		enemy[0].health_max = 200;
		enemy[0].attack = 10;
		enemy[0].defend = 10;
		enemy[0].money = 300;
		enemy[0].goodsId[0] = 1;
		enemy[0].goodsNum[0] = 1;



		enemy[1].name = "有角躯壳"; 
		enemy[1].health = 50;
		enemy[1].health_max = 50;
		enemy[1].attack = 3;
		enemy[1].defend = 5;
		enemy[1].money = 100;
		enemy[1].goodsId[0] = 10;
		enemy[1].goodsNum[0] = 1;

		enemy[2].name = "Faker_梦境守卫Ⅰ";      //crossroads
		enemy[2].health = 500;
		enemy[2].health_max = 500;
		enemy[2].attack = 50;
		enemy[2].defend = 80;
		enemy[2].money = 1000;
		enemy[2].goodsId[0] = 4;
		enemy[2].goodsNum[0] = 1;
		break;
	}
	case 3:
	{
		enemy[0].name = "螳螂士兵";
		enemy[0].health = 200;
		enemy[0].health_max = 200;
		enemy[0].attack = 10;
		enemy[0].defend = 10;
		enemy[0].money = 100;
		enemy[0].goodsId[0] = 11;
		enemy[0].goodsNum[0] = 1;


		enemy[1].name = "螳螂盾卫";
		enemy[1].health = 250;
		enemy[0].health_max = 250;
		enemy[1].attack = 5;
		enemy[1].defend = 30;
		enemy[1].money = 100;
		enemy[1].goodsId[0] = 12;
		enemy[1].goodsNum[0] = 1;

		enemy[2].name = "Rider_梦境守卫Ⅱ";      //mantistown
		enemy[2].health = 400;
		enemy[2].health_max = 700;
		enemy[2].attack = 70;
		enemy[2].defend = 0;
		enemy[2].money = 400;
		enemy[2].goodsId[0] = 8;
		enemy[2].goodsNum[0] = 1;
		break;
	}
	case 4:
	{	
		enemy[2].name = " ";
		enemy[1].name = " ";
		

		enemy[0].name = "Surter_梦境守卫Ⅳ";      //queengarden
		enemy[0].health = 300;
		enemy[0].health_max = 700;

		enemy[0].attack = 700;
		enemy[0].defend = 20;

		enemy[0].money = 400;
		enemy[0].goodsId[0] = 9;
		enemy[2].goodsNum[0] = 1;
		break;
	}
	case 5:
	{	
		enemy[0].name = "水晶守卫";
		enemy[0].health = 100;
		enemy[0].health_max = 100;

		enemy[0].attack = 10;
		enemy[0].defend = 70;

		enemy[0].money = 100;
		enemy[0].goodsId[0] = 1;
		enemy[0].goodsNum[0] = 1;



		enemy[1].name = "水晶躯壳";
		enemy[1].health = 100;
		enemy[0].health_max = 100;

		enemy[1].attack = 5;
		enemy[1].defend = 30;

		enemy[1].money = 50;
		enemy[1].goodsId[0] = 2;
		enemy[1].goodsNum[0] = 1;


		enemy[2].name = "Lancer_梦境守卫Ⅲ";      //crystalpeak
		enemy[2].health = 200;
		enemy[2].health_max = 200;

		enemy[2].attack = 110;
		enemy[2].defend = 10;

		enemy[2].money = 2000;
		enemy[2].goodsId[0] = 7;
		enemy[2].goodsNum[0] = 1;
		break;
	}
	case 6:
	{
		enemy[0].name = "Saber_梦境守卫者Ⅴ";
		enemy[0].health = 300;
		enemy[0].health_max = 300;
		enemy[0].attack = 130;
		enemy[0].defend = 0;
		enemy[0].money = 2000;
		enemy[0].goodsId[0] = 5;
		enemy[0].goodsNum[0] = 1;

		enemy[1].name = " "; 

		enemy[2].name = " ";//palepalace
		break;
	}
	case 7:
	{
		enemy[0].name = "Hollw Knight";
		enemy[0].health = 400;
		enemy[0].health_max = 400;
		enemy[0].attack = 40;
		enemy[0].defend = 50;
		enemy[0].money = 0;
		enemy[0].goodsId[0] = 0;


		enemy[1].name = " "; 

		enemy[2].name = " "; //blackeggpalace 
		break;
	}
	default:
		break;
	}
}
void Map::showEnemy(Enemy enemy[3])
{
	cout << "Enemy:" << endl;
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i].name != " ")
		{
			cout << i << "." << enemy[i].name << "  ";
		}
	}
}




//---------------------------------------------------------------------------------------------------------





int Map::getPosition()
{
	return position;
}


int Map::getNpcGoodsId() {
	return npc.getGoodsId();
}



int Map::getNpcGoodsNum() {
	return npc.getGoodsNum();
}



string Map::getName(){
	return mapName[position];
}




