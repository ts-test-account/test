#ifndef __Rougelike__acitonParameter__
#define __Rougelike__acitonParameter__

//技データの構造体
struct Action {
    int id;
    std::string name;
    int type;
    int element;
    int hitprob;
    int target;
    int addstatus;
    int addstatusprob;
    std::string message;
};

static const Action actions[] = 
	{0,"単純攻撃",0,0,100,0,0,10"の攻撃"},
	{1,"ファイア",1,1,50,1,1,30"を唱えた"},
	{2,"アイス",2,1,75,2,2,50"を唱えた"}
};

#endif /* defined(__rougelike__status__) */