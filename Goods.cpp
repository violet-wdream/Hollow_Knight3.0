#include "Goods.h"

Goods::Goods(int id)
{
	switch (id)
	{
	case 0: {
		goodsId = id;
		name = "粗钝的骨钉";
		desc = "未经打磨强化的普通骨钉。+10攻击";
		goodsType = 0;
		addAttack = 10;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case 1: {
		goodsId = id;
		name = "锐利的骨钉";                                        //knight
		desc = "经过锻造师打磨冶炼，锋利度增加。+20攻击";
		goodsType = 0;
		addAttack = 20;
		priceBuy = 200;
		priceSell = 100;
		break;
	}
	case 2: {
		goodsId = id;
		name = "阐释者";                                            //kirito
		desc = "据史料记载，这把武器是一位黑衣剑客的佩剑，散发出银白的光芒，剑语是： 吾阐释你的梦。+30攻击";
		goodsType = 0;
		addAttack = 30;
		priceBuy = 600;
		priceSell = 200;
		break;
	}
	case 3: {
		goodsId = id;
		name = "逐暗者";                                            //kirito
		desc = "与阐释者相生的另一把名剑，同为那位黑衣剑客的配件，剑身仿佛蕴藏者星空。+30攻击";
		goodsType = 0;
		addAttack = 30;
		priceBuy = 600;
		priceSell = 200;
		break;
	}
	case 4: {
		goodsId = id;
		name = "冰凛蔷薇";                                         //ugo
		desc = "健身华丽，由圣巢水晶制成，散发着冰冷之气，剑镡为蔷薇形状，得名冰凛蔷薇，初见者无不惊叹： 我超， 冰！ +50攻击";
		goodsType = 0;
		addAttack = 50;
		priceBuy = 1000;
		priceSell = 500;
		break;
	}
	case 5: {
		goodsId = id;
		name = "契约胜利之剑";                                   //saber 
		desc = "传说中不列颠国王亚瑟王从湖之仙女那得到被称为“王者之剑”的圣剑Excalibur，打倒saber掉落。+150攻击";
		goodsType = 0;
		addAttack = 250;
		priceBuy = 9999;
		priceSell = 9999;
		break;
	}
	case 6: {
		goodsId = id;
		name = "天地乖离开辟之星";                                 //archer 吉尔伽美什
		desc = "吉尔伽美什的宝具，通体由黄金铸成，散发着耀眼的光明，具有对城能力。+120攻击";
		goodsType = 0;
		addAttack = 120;
		priceBuy = 1296;
		priceSell = 600;
		break;
	}
	case 7: {
		goodsId = id;
		name = "穿刺死棘之枪";                               //lancer
		desc = "逆转因果的魔枪。倒转因果，以必中心脏为前题的“果”决定挥舞长枪攻击的“因”。因为结果已经注定了，一般的防御与回避不论怎么做都毫无意义。这个效果属于一种诅咒（干涉命运），打倒lancer掉落。+80攻击";
		goodsType = 0;
		addAttack = 180;
		priceBuy = 9999;
		priceSell = 9999;
		break;
	}
	case 8: {
		goodsId = id;                                            //rider
		name = "无铭·短剑";
		desc = "美杜莎（Rider）所使用的武器。外貌与其说是短剑，不如说是刺向对方的“钉”。这个武器被连接与长锁链，也能以锁链绑缚拘束刺到的对象，打倒rider掉落。+90攻击";
		goodsType = 0;
		addAttack = 190;
		priceBuy = 9999;
		priceSell = 9999;
		break;
	}
	case 9: {
		goodsId = id;
		name = "熔火巨剑";                                //surter
		desc = "由火神Surter使用肜火之力打造而成，具有强大的力量，打倒surter掉落。+100攻击";
		goodsType = 0;
		addAttack = 200;
		priceBuy = 9999;
		priceSell = 9999;
		break;
	}
	case 10: {
		goodsId = id;
		name = "普通护符";
		desc = "普通的一枚护符，提供少量属性加成。+10生命上限";
		goodsType = 1;
		addAttack = 0;
		addMaxHP = 10;
		addMaxMP = 0;
		priceBuy = 200;
		priceSell = 70;
		break;
	}
	case 11: {                                              //恩奇都
		goodsId = id;
		name = "骄傲之证";
		desc = "精良的护符，可以为使用者提供攻击力加成，打倒龙牙哥掉落。+20攻击";
		goodsType = 1;
		addAttack = 20;
		addMaxHP = 0;
		addMaxMP = 0;
		priceBuy = 300;
		priceSell = 90;
		break;
	}
	case 12: {
		goodsId = id;
		name = "清泉流响";
		desc = "蕴含水元素之力，为使用者提供大量生命值加成。+100生命上限";
		goodsType = 1;
		addAttack = 0;
		addMaxHP = 100;
		addMaxMP = 0;
		priceBuy = 500;
		priceSell = 200;
		break;
	}
	case 13: {
		goodsId = id;
		name = "冰霜之心";
		desc = "外表看来宛如透明水晶,实际上却是用千年不化的天山寒冰制成,非常珍贵,为使用者提供灵魂加成。+70灵魂上限";
		goodsType = 1;
		addAttack = 0;

		addMaxHP = 0;
		addMaxMP = 70;
		priceBuy = 700;
		priceSell = 300;
		break;
	}
	case 14: {
		goodsId = id;
		name = "冀以锁系神明";
		desc = "恩齐都的宝具，由神之刚制成，具有束缚神明的力量，为使用者提供攻击力和灵魂加成。+50攻击 +50灵魂上限";
		goodsType = 1;
		addAttack = 50;
		addMaxHP = 0;
		addMaxMP = 50;
		priceBuy = 1000;
		priceSell = 400;
		break;
	}
	case 15: {
		goodsId = id;
		name = "国王之魂碎片（白）";
		desc = "黑卵圣殿的钥匙——国王之魂的碎片之一，通过苍白之王获取。";
		goodsType = 1;
		addAttack = 0;

		addMaxHP = 0;
		addMaxMP = 0;
		priceBuy = 999999;
		priceSell = 0;
		break;
	}
	case 16: {
		goodsId = id;
		name = "国王之魂碎片（黑）";
		desc = "黑卵圣殿的钥匙——国王之魂的碎片之一，通过白色皇后获取。";
		goodsType = 1;
		addAttack = 0;

		addMaxHP = 0;
		addMaxMP = 0;
		priceBuy = 999999;
		priceSell = 0;
		break;
	}
	case 17: {
		goodsId = id;
		name = "国王之魂";
		desc = "由黑白碎片合成，是黑卵圣殿的钥匙。";
		goodsType = 1;
		addAttack = 0;

		addMaxHP = 0;
		addMaxMP = 0;
		priceBuy = 999999;
		priceSell = 0;
		break;
	}
	case 18: {
		goodsId = id;
		name = "名刀司马";
		desc = "传说为梦之泪伤所用过的护符，可以在危险时刻救你一命，只要你唱起这首歌《Tu vivi nell'aria》+50攻击";
		goodsType = 1;
		addAttack = 50;

		addMaxHP = 0;
		addMaxMP = 0;
		priceBuy = 1000;
		priceSell = 400;
		break;
	}
	case 19: {
		goodsId = id;
		name = "妖刀村正（断）";
		desc = "妖刀村正的断剑，已经破败不堪，但其附带的妖邪之气仍未散去，可做护符，在关键时候恢复至满状态。+100灵魂上限";
		goodsType = 1;
		addAttack = 0;

		addMaxHP = 0;
		addMaxMP = 100;
		priceBuy = 1145;
		priceSell = 514;
		break;
	}
	case 20: {
		goodsId = id;
		name = "六味地黄丸";
		desc = "常见的疗伤药,补充50点血量";
		goodsType = 2;
		addHP = 50;
		addMP = 0;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case 21: {
		goodsId = id;
		name = "灵魂瓶";
		desc = "捕捉了少量灵魂，使用后可以恢复40点灵魂";
		goodsType = 2;
		addHP = 0;
		addMP = 40;
		priceBuy = 100;
		priceSell = 50;
		break;
	}
	case 22: {
		goodsId = id;
		name = "王守义十三香";
		desc = "非常的新鲜，非常的美味，香啊，很香啊，使用后可以将生命和灵魂上限提高100点";
		goodsType = 2;
		addMaxHP = 100;
		addMaxMP = 100;
		priceBuy = 1000;
		priceSell = 500;
		break;
	}
	case 23: {
		goodsId = id;
		name = "韩信小饮料";
		desc = "传说为国服韩信偷塔时所用的饮料，能够提升攻击力，你们觉得怎么样？+50攻击 ";
		goodsType = 2;
		addAttack = 50;
		priceBuy = 1000;
		priceSell = 500;
		break;
	}
	default:
		break;
	}
}

Goods::~Goods()
{
}



string Goods::getName(){
	return string(name);
}

int Goods::getGoodsId()
{
	return goodsId;
}

string Goods::getDesc()
{
	return string(desc);
}



int Goods::getGoodsType()
{
	return goodsType;
}

int Goods::getAddAttack()
{
	return addAttack;
}

int Goods::getAddDefend()
{
	return addDefend;
}

int Goods::getAddHP()
{
	return addHP;
}

int Goods::getAddMaxHP()
{
	return addMaxHP;
}

int Goods::getAddMP()
{
	return addMP;
}

int Goods::getAddMaxMP()
{
	return addMaxMP;
}

int Goods::getPriceSell()
{
	return priceSell;
}

int Goods::getPriceBuy()
{
	return priceBuy;
}

void Goods::showGoods()
{
	cout << name << endl;
	cout << desc << endl;
	if (goodsType == 0) //武器
	{
		cout << "攻击力:" << addAttack << endl;
	}
	if (goodsType == 1) //防具/护符
	{
		cout << "增加血量:" << addMaxHP << endl;
		cout << "增加灵魂:" << addMaxMP << endl;
	}
	if (goodsType == 2) //药品
	{
		cout << "回复血量:" << addHP << endl;
		cout << "增加血量上限:" << addMaxHP << endl;
		cout << "回复灵魂:" << addMP << endl;
		cout << "增加灵魂上限:" << addMaxMP << endl;
	}
}
