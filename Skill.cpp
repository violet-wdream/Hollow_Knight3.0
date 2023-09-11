#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill()              //默认构造给本体角色，敌人的技能修改setSkill()。
{
	skill_1Name = "凝聚";
	skill_2Name = "冲击波";
	skill_3Name = "蓄力攻击";
	skill_4Name = " ";

	skill_1Desc = "消耗20灵魂恢复50血量";
	skill_2Desc = "消耗40灵魂对敌人造成2倍攻击伤害";
	skill_3Desc = "消耗80灵魂对敌人造成3倍攻击伤害";
	skill_4Desc = " ";




	skill_1NeedMp = 20;
	skill_2NeedMp = 40;
	skill_3NeedMp = 80;
	skill_4NeedMp = 0;

	



}




string Skill::getName(int numSkill) 
{
	
	if(numSkill == 1)
		return skill_1Name;
	if (numSkill == 2)
		return skill_2Name;
	if (numSkill == 3)
		return skill_3Name;
	if (numSkill == 4)
		return skill_4Name;
}


string Skill::getDescription(int numSkill) {
	
	if (numSkill == 1)
		return skill_1Desc;
	if (numSkill == 2)
		return skill_2Desc;
	if (numSkill == 3)
		return skill_3Desc;
	if (numSkill == 4)
		return skill_4Desc;
}



int Skill::getNeedMP(int numSkill) {
	
	if (numSkill == 1)
		return skill_1NeedMp;
	if (numSkill == 2)
		return skill_2NeedMp;
	if (numSkill == 3)
		return skill_3NeedMp;
	if (numSkill == 4)
		return skill_4NeedMp;
}















