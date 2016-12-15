#ifndef __Rougelike__characterParameter__
#define __Rougelike__characterParameter__

//キャラクターデータの構造体
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

//パラメータデータベース　このデータをどこに置くべきか検討する
static const ActionData actiondatabase[] = {
    {0,"noname", 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1,"warrior", 40, 3, 30, 10, 15, 15, 5, 1, 0},
    {2,"hunter", 30, 10, 20, 5, 18, 20, 10, 3, 0},
    {3,"priest", 10, 50, 5, 3, 10, 15, 20, 1,  0},
    {4,"sorcerer", 15, 50, 5, 3, 10, 15, 20, 7, 0},
    {5,"monk", 50, 10, 20, 8, 20, 25, 5, 1, 0}
};

static const Action actions[] = {
	{0,"単純攻撃",0,0,100,0,0,10"の攻撃"},
	{1,"ファイア",1,1,50,1,1,30"を唱えた"},
	{2,"アイス",2,1,75,2,2,50"を唱えた"}
};

#endif /* defined(__rougelike__status__) */
