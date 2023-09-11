#ifndef SAVE_CPP
#define SAVE_CPP
#include"Save.h"
#include<fstream>
#include<iostream>
using namespace std;


void Save::setToFile(Role player) 
{
	ofstream fileRole("SaveRole.dat", ios_base::binary);
	ofstream fileBag("SaveBag.dat", ios_base::binary);
	
	fileRole << player.getName() << ' '
		<< player.getHealth_max() << ' '
		<< player.getHealth() << ' '
		<< player.getMagic() << ' '
		<< player.getMagic_max() << ' '
		<< player.getAttack() << ' '
		<<player.getVessel()<<' '
		<< player.getMoney() << ' '
		<< player.getWeapon() << ' '
		<< player.getClothes();
	for (const auto &i : player.getBag().getMapBags()) 
	{
		fileBag << i.first<<' ' << i.second<< ' ';
	}
	cout << "±£´æ³É¹¦£¡" << endl;
	system("pause");
	fileRole.close();
	fileBag.close();
}

#endif


