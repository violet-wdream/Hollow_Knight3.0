
#include"Npc.h"
#include<iostream>
using namespace std;

string Npc::getName() 
{
	return name;
}

int Npc::getGoodsNum()
{
	return goodNum;
}

int Npc::getGoodsId() {
	return goodId;
}

int Npc::getMoney() {
	return money;
}




void Npc::chat(int position, int num, Role player) {
	switch (position) {
	case 0: {
		if (num == 0) 
		{
			cout << "奎若：" << endl;
			cout << "我一直以来都感觉这里在吸引着我。我听了那么多漫游者和恐怖之物的故事。\n\n我再也抵挡不了这种诱惑。一定要亲眼看看。\n" << endl;
			cout << "我来得正是时候！这个死寂的世界又涌现出了生命。\n" << endl;
			cout << "为了拯救圣巢，教师自愿成为了封印，但她还给自己下了一道额外的保护。\n\n虽然我记不起来到底是怎么回事了，但我也参与了这场壮举。\n" << endl;
			system("pause");
			cout << "\n\n……但是雨似乎永不停歇，我想在离开这个王国之前看看它的源头。一定无比壮丽！\n" << endl;
			cout << "光凭一根旧骨钉可没法在这片废墟中生存下去。不过没关系！只要四处转转就能想到办法。\n\n以前也有很多虫子来过这里，他们的装备比你我都精良，但大部分下场惨烈。\n他们一定不会介意其他探险家拿走他们的武器。这其实是一桩善举啊，死者不该跟这种东西埋在一起。" << endl;
			system("pause");
		}
		if (num == 1)
		{
			cout << "……你好\n";
			system("pause");
		}
		else cout << "没有这个人物" << endl;
		break;
	}
	case 1: {
		if (num == 0) {
			cout << "虫长者：" << endl;
			cout << "德特茅斯的四周都是悬崖峭壁， 要到这来的话，绝大多数旅行者都要走上一段曲折迂回的道路，那绝对是一段艰辛的路途，但在王国的鼎盛时期要到这里就容易得多了。\n" << endl;
			cout << "在悬崖上有一个很容易通过的老旧的通行处。\n\n不过与它连接的桥梁很早以前就崩塌了，但即使大桥没断， 也有一扇大门挡在入口处。" << endl;
			cout << "在我们的城镇下面曾经有一个伟大的王国。\n\n它已经变成废墟很久了，但它依旧吸引着虫子们到那深处去。" << endl;
			cout << "财富、荣耀、启迪，那深处的黑暗似乎包含有无数的可能性。\n\n我相信你也在下面寻求着你的梦想。" << endl;
			system("pause");
			cout << "\n\n不过你要小心，那下面充满了恶心的气息。生物会被剥夺原有的记忆，变得疯狂。" << endl;
			cout << "也许梦想并不是那么好的东西……" << endl<<endl;
			player.addGoodsToBag(20, 1);
			system("pause");
			
		}
		else if (num == 1) {
			cout << "伟大的佐特：" << endl;
			cout << "戒律四：忘记过去。 过去充满痛苦，回想过去只能让你满心悲凉。想想别的东西，比如未来和美食。\n" << endl;
			cout << "戒律八：独自旅行。 你不能依赖别的虫子，没人永远忠诚。所以没人能永远和你同行。\n" << endl;
			system("pause");
			cout << "\n\n戒律五十：不要沉溺于谜题。 生活有时候让人疑惑。晦涩的谜题。如果不能马上发现一件事物的内涵，那就不要浪费时间去探究。继续前进即可。\n" << endl;
			cout << "戒律五十五： 不要做梦。 梦想是危险的东西，是不属于你的古怪念头。它们会侵蚀你的思想。但你一对抗这些念头，你的身体就会受伤！所以最好跟我一样根本不做梦。\n" << endl;
			player.addGoodsToBag(20, 1);
			system("pause");
		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	case 2: {
		if (num == 0) {
			cout << "米拉：" << endl;
			cout << "说说你为什么要来这地方？想要发财的话看看周围就行了！\n\n矿石里还有满满的财宝！能让大家都当上富翁。拿把镐头和我一起挖就行了！哈哈！" << endl;
			cout << "欢迎你跟我一起干，这里的财宝够我们两个人用的！\n\n要是你不喜欢挖……挖……挖东西，那也可以坐下和我一起唱歌！哈哈哈！" << endl;
			system("pause");
			cout << "\n\n工作很辛苦，但我不介意。\n\n我在这里可以不眠不休地工作。太有意思了！" << endl;
			cout << "就要找到了……继续唱歌吧，水晶！继续唱歌，好让我找到你！" << endl;
			player.addGoodsToBag(21, 1);
			system("pause");
		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	case 3: {
		if (num == 0) {
			cout << "奎若：" << endl;
			cout << "又见面了！想必你已经见过村子里的部落了，对吧？\n\n坦白说……他们不太相信陌生者。" << endl;
			cout << "不过他们并不野蛮。空气里的瘟疫蒙蔽了弱者的心智……但他们抵抗住了疾病。\n\n他们依然身怀睿智和荣耀，当然也保存着致命的传统。" << endl;
			system("pause");
			cout << "\n\n……想想看，这么个小家伙却背负着王国的命运。" << endl<<endl;
			player.addGoodsToBag(1, 1);
			system("pause");
		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	case 4: {
		if (num == 0) {
			cout << "白色夫人：" << endl;
			cout << "哦！有虫子来了。它走过漫漫长路才找到我。\n\n它是需要我的帮助吗？还是偶然来到了这和自己有关的地方？" << endl;
			cout << "没错，没错，我在等你。\n\n不，也许这么说不妥当。我在等待你这样的生物。" << endl;
			cout << "我有个礼物，一直想送给你这样的。只有一半，找到另一半之后你就会得到强大的力量。\n\n你未来的道路上一定会需要这样强大的力量。" << endl;
			system("pause");
			cout << "\n\n我恳求你，取代容器。我们对它的力量判断失误。灌输给它的一个念头让它有了污点。\n\n但你没有这种缺陷，你可以将那东西封印在身体里。 我要警告你。容器本身可能已经变得脆弱，但它体内的东西赋予了极大力量。\n" << endl;
			cout << "做好准备，但不要磨蹭。容器一旦过早被打破，瘟疫就会带着被封印多年的狂怒和力量喷涌而出。" << endl;
			system("pause");
			player.addGoodsToBag(16, 1);
			system("pause");
	
		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	case 5: {
		if (num == 0) {
			cout << "奎若：" << endl;
			cout << "看到下面的矿工还不能摆脱无尽的苦工，这会让你悲伤吗？\n" << endl;
			cout << "即使已经死去，强烈的使命感依然在驱动他们的躯壳。\n" << endl;
			system("pause");
			cout << "\n\n据说水晶矿里蕴含着某种能量，没有城市中市民驾驭的灵魂那么强大，而且温和得多。" << endl<<endl;
			player.addGoodsToBag(2, 1);
			system("pause");
		}
		else if (num == 1) {
			cout << "猎人日志的躯壳矿工条目：“被水晶山峰上珍贵水晶所吸引的虫子的遗骸。它的爪镐现在成为了凶猛的武器。”\n" << endl;
			system("pause");
			cout << "\n\n猎人日志的亮背虫条目：“身体巨大而且防守周密，但缓慢又温顺。圣巢的虫子们以前会强迫这些生物运送它们的推车和机器。”\n" << endl;
			cout << "猎人日志的结晶躯壳条目：“死于水晶间的虫子的遗骸。被奇怪的力量复活，生长在山峰上的晶体中有一种奇怪的力量。它们在黑暗中闪闪发光，注意听的话，你还会发现它们在唱歌。轻柔的歌声……\n" << endl;
			system("pause");

		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	case 6: {
		if (num == 0) {
			cout << "\n\n……沃姆之魂。根之灵魂。虚空之心……\n" << endl;
			system("pause");
			player.addGoodsToBag(15, 1);
			system("pause");

		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	case 7: {
		if (num == 0) {
			cout << "黄蜂女  ：" << endl;
			cout << "你的表现令我印象深刻，小鬼。你肩负着这全世界的命运，但仍然这么坚强。\n" << endl;
			cout << "光是打破守梦者的封印就已经是不可能的任务，而能接受自己空虚的内在，更是让你超凡出众。\n" << endl;
			cout << "圣巢的鬼魂啊，你拥有选择结局的力量。你是要代替我们生来就受诅咒的兄弟，还是要超越它？\n" << endl;
			system("pause");

			cout << "\n\n……我见过这个敏捷的小生物。我以为它是猎物，于是扑了过去，但它在一瞬间就用飞刀刺伤了我，随后绝尘而去。它也是……猎人吗？\n" << endl;
			cout << "……它能完成那不可能的使命吗？它该这么做吗？\n" << endl;
			player.addGoodsToBag(6, 1);
			system("pause");
		}
		else cout << "没有这个人物！" << endl;
		break;
	}
	default:cout << "error!" << endl << endl; break;
	};
}

