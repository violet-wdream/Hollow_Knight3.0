#ifndef SKILL_H
#define SKILL_H

#include <string>
//#include "Enemy.h"
using namespace std;
class Skill 
{
public:
	Skill();
	~Skill() {}
	string getName(int numSkill);		//得到技能名字
	string getDescription(int numSkill);		//得到技能描述
	int getNeedMP(int numSkill);		//得到技能耗蓝


protected:
	string skill_1Name;
	string skill_2Name;
	string skill_3Name;
	string skill_4Name;

	string skill_1Desc;
	string skill_2Desc;
	string skill_3Desc;
	string skill_4Desc;

	
	int skill_1Hurt;
	int skill_2Hurt;
	int skill_3Hurt;
	int skill_4Hurt;

	int skill_1NeedMp;
	int skill_2NeedMp;
	int skill_3NeedMp;
	int skill_4NeedMp;


	
};






#endif