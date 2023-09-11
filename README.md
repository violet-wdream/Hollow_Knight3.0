# MUD-game--
A simple MUD game, It has a Chinese name - 侠客行(chivalrous line)

这是我在暑假C++课程设计中和两位组员设计的一个简单的MUD游戏
----------------------------------------------------
声明:<br>
    1.由我和两位同学共同开发，在这里感谢张同学和孟同学。<br>
    2.游戏名是抄袭的，如有侵权请联系我。<br>
    
    
环境：'C++'、'vs2015'<br>


重要文件和内容说明：<br>
    1.Bag.cpp和Bag.h是定义人物背包文件，采用容器关联容器map进行储存，每次访问都用容器的迭代器iterator。<br>
    2.Enemy.cpp和Enemy.h是定义怪物属性文件，设计的怪物拥有基本属性外还自带消灭后会掉落的金钱、装备、经验等。'怪物名是抄袭LOL的野区怪物名'<br>
    3.Fight.h和Fight.cpp是定义人怪战斗文件，采用回合制的攻击方式，设计了基本攻击和技能攻击（下面会介绍这个），包括物理攻击和魔法攻击，还添加了逃跑机制，逃跑成功率随机哦,里面还有很多判定，包括防御力抵挡攻击，人物死亡，怪物死亡，战斗过程使用背包内药品等<br>
    4.Goods.cpp和Goods.h是定义物品的文件，我们为物品（包括武器、护甲、药品等）设计了唯一ID和基本属性与描述。人物可以通过击败怪物或交谈得到，装备上能提升相应的属性，例如装备武器提升攻击力，装备护甲提升防御力等。'物品的名字和描述也是抄袭的（滑稽）'<br>
    5.Main.cpp是游戏入口文件，也是游戏主运行文件，里面会输出游戏的基本信息和其他的信息，还有游戏开始时的读取上一次保存的游戏功能（下面还会说明），此文件包括了所有定义的文件，通过创建调用实现游戏的进行。<br>
    6.Map.cpp和Map.h是定义地图文件，里面实现了包括地图绘制，人物移动，地点存在的NPC和怪物等信息。<br>
    7.Npc.cpp和Npc.h是定义NPC人物的文件，我们设计了六个非游戏玩家，设置在地图上的特殊地点出现，能够跟玩家对话，并提供任务配合任务机制驱动玩家，赠与金钱物品装备等。'名字好像都是抄袭的，你知道的我们最烦去设计这种东西了'<br>
    8.Read.cpp和Save.cpp等都是定义游戏的保存和读取的文件，当玩家在游戏里触发保存游戏功能时会生成SaveBag.dat、SaveRole.dat、SaveSkill.dat、SaveTask.dat文件用来分别保存人物当前背包内容、人物当前属性值、人物当前拥有的技能内容、人物当前的任务内容。<br>
    9.Role.cpp和Role.h是用来定义人物的文件，我们设计的人物拥有生命值、类型魔法值、攻击力、......等属性外，还添加了技能机制，背包机制，任务机制，恢复机制等较多内容，有点复杂，所有我重载了=号方便每次在游戏运行时的人物更新。<br>
    10.Skill.cpp和Skill.h定义了人物技能的文件，我们设计了每个人物四个技能（实际上现在每个人物有不一样的技能，用的却是相同的技能名字，你知道的我最烦设计这种了T_T），能够通过技能加点来升级技能，技能能在战斗中使用，提供给人物攻击力加成，并且还会耗蓝，它们各自有不同的属性。<br>
    11.Store.cpp和Store.h定义了商店的文件，我们设计了能显示上面定义的物品，人物能够随时访问，并提供购买和售出功能，需要配合人物背包与金钱等。<br>
    12.Task.cpp和Task.h定义了任务机制文件，我们设计了三个简单的人物，玩家需通过在地图上的移动与NPC对话触发和完成。（当然了剧情很俗套，没错，就是英雄救美）<br>


<br>