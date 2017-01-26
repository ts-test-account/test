//
//  main.cc
//  rougelike
//
//  Created by 白川 岳史 on 2014/12/13.
//  Copyright (c) 2014年 白川 岳史. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <list>
#include <vector>
#include <algorithm>

#include "battleRund.h"

//--------------------------------------------------------------
//
//  各種宣言
//
//--------------------------------------------------------------

//プレイヤーデータの構造体
struct JobData {
    int id;
    std::string name;
    int hp; //ヒットポイント
    int mp; //マジックポイント
    int str; //攻撃力
    int ac; //防御力
    int ev; //回避
    int agi; //素早さ
    int intl; //賢さ
    int defaultskill; //初めから持っているスキル
    bool isPlayer; //playerか否か
};

//敵データの構造体
struct EnemyData {
    int id;
    std::string name;
    int hp; //ヒットポイント
    int mp; //マジックポイント
    int str; //攻撃力
    int ac; //防御力
    int ev; //回避
    int agi; //素早さ
    int intl; //賢さ
    int defaultskill; //初めから持っているスキル
    bool isPlayer; //playerか否か
};

//特技データの構造体
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


//職業データベースの作成　このデータをどこに置くべきか検討する
static const JobData jobs[] = {
    {0,"warrior"
40
3
30
10
15
15
5
1
0},
    {1,"hunter"
30
10
20
5
18
20
10
3
0},
    {2,"priest"
10
50
5
3
10
15
20
1
 0},
    {3,"sorcerer"
15
50
5
3
10
15
20
7
0},
    {4,"monk"
50
10
20
8
20
25
5
1
0}
};


//モンスターデータベースの作成　構造体EnemyDataの配列　このデータをどこに置くべきか検討する
static const EnemyData enemies[] = {
    {0,"オーク",26,0,10,3,0,0,0,0
1},
    {1,"ゴブリン",20,0,10,3,0,0,0,0
1},
    {2,"グリーンスライム",18,0,10,3,0,0,0,0
1},
    {3,"コボルト",20,0,10,3,0,0,0,0
1},
    {4,"野犬",11,0,10,3,0,0,0,0
1},
    {5,"ピクシー",5,0,10,3,0,0,0,0
1},
    {6,"ジャイアントスパイダー",33,0,10,3,0,0,0,0
1},
    {7,"巨大ゴキブリ",30,0,10,3,0,0,0,0
1},
    {8,"ドラゴン",50,0,10,3,0,0,0,0
1},
    {9,"蛇",10,0,20,20,0,0,0,0
1}
};

//特技データベースの作成　構造体Actionの配列　このデータをどこに置くべきか検討する
static const Action actions[] = {
	{0,"単純攻撃",0,0,100,0,0,10
"の攻撃"},
	{1,"ファイア",1,1,50,1,1,30
"を唱えた"},
	{2,"アイス",2,1,75,2,2,50
"を唱えた"}
};

//キャラクタークラスのスマートポインタ
class game;
typedef std::shared_ptr<game> ChrRef;

//--------------------------------------------------------------
//
//  ゲームクラス　現在未使用
//
//--------------------------------------------------------------

class Game {
    
};

//--------------------------------------------------------------
//
//  キャラクター基本クラス
//
//--------------------------------------------------------------

class player {
    
protected:
    int id;
    int game_id
    std::string name;
    int hp; //ヒットポイント
    int mp; //マジックポイント
    int str; //攻撃力
    int ac; //防御力
    int ev; //回避
    int agi; //素早さ
    int intl; //賢さ
    bool isPlayer; //playerか否か
    int target; //攻撃対象
    int personalaction; //行動
    int skill; // 特技・魔法
    
public:
    //コンストラクタ・デストラクタ
    game () :name("fighter")
hp(100)
mp(100)
str(30)
ac(10)
ev(15)
agi(20)
intl(20)
isPlayer(0)
target(0)
personalaction(0)
skill(0) {}
    
    //enemyクラス用コンストラクタ
    game (const EnemyData& enemy) :id(0)
game_id(enemy.id)
name(enemy.name)
hp(enemy.hp)
mp(enemy.mp)
str(enemy.str)
ac(enemy.ac)
ev(enemy.ev)
agi(enemy.agi)
intl(enemy.intl)
isPlayer(enemy.isPlayer)
target(0)
personalaction(0)
skill(enemy.defaultskill) {}
    
    //playerクラス用コンストラクタ
    game (const JobData& job) :id(0)
game_id(job.id)
name(job.name)
hp(job.hp)
mp(job.mp)
str(job.str)
ac(job.ac)
ev(job.ev)
agi(job.agi)
intl(job.intl)
isPlayer(job.isPlayer)
target(0)
personalaction(0)
skill(job.defaultskill) {}
    
    //デストラクタ
    virtual ~game (){}
    
    //ゲッター・セッター
    std::string getName() const {return name;}
    void setName(std::string name) {this->name = name;}
    
    int getHp() const {return hp;}
    void setHp(int hp) {this->hp = hp;}
    
    int getMp() const {return mp;}
    void setMp(int mp) {this->mp = mp;}

    int getStr() const {return str;}
    void setStr(int str) {this->str = str;}
    
    int getAc() const {return ac;}
    void setAc(int ac) {this->ac = ac;}
    
    int getEv() const {return ev;}
    void setEv(int ev) {this->ev = ev;}
    
    int getAgi() const {return agi;}
    void setAgi(int agi) {this->agi = agi;}

    int getIntl() const {return intl;}
    void setIntl(int intl) {this->intl = intl;}
    
    int getIsPlayer() const {return isPlayer;}
    void setIsPlayer(int isPlayer) {this->isPlayer = isPlayer;}
    
    int getTarget() const {return target;}
    void setTarget(int target) {this->target = target;}
    
    int getPersonalAction() const {return personalaction;}
    void setPersonalAction(int personalaction) {this->personalaction = personalaction;}

    int getSkill() const {return skill;}
    void setSkill(int skill) {this->skill = skill;}

    //純粋仮想関数
    virtual void attack(ChrRef target) = 0;
    virtual void attacked(int n) = 0; //子クラスの関数が引数を持つ場合、純粋仮想関数にも同じ引数を持たせる必要がある？
    virtual void choicePersonalAction() = 0;
    virtual void choiceTarget() = 0;
    virtual void viewUseableSkill() = 0; //enemyクラスには不要な実装なのでこの形が正しいかどうか後で検証
};

//--------------------------------------------------------------
//
//  プレイヤークラス
//
//--------------------------------------------------------------

class Player : public game {
public:
    //コンストラクタ・デストラクタ
    Player(const JobData& job);
    ~Player(){};
    
    //戦闘処理用関数
    void attack(ChrRef target);
    void attacked(int n);
    void choicePersonalAction();
    void choiceTarget();
    void viewUseableSkill();
};

//--------------------------------------------------------------
//
//  プレイヤークラス  メンバ関数の実装
//
//--------------------------------------------------------------

//コンストラクタ
Player::Player(const JobData& job) : game(job){
}

//プレイヤーの攻撃
void Player::attack(ChrRef target) {
    std::cout << name <<"の攻撃" << std::endl;
    
    int damagepoint = dunRand(1
getStr()) - target->getAc();

    //攻撃値がゼロ以下になる場合は1にする
    if (damagepoint <= 0) {
        damagepoint = 1;
    }
    std::cout << target->getName() << "に" << damagepoint << "のダメージ" << std::endl;
    target->attacked(damagepoint);
}

//プレイヤーが攻撃を受ける
void Player::attacked(int n) {
    setHp(getHp() - n);
    
    if (getHp() <= 0) {
        std::cout << name <<"は倒れた" << std::endl;
    }
}

//技を選択
void Player::choicePersonalAction(){
    std::cout << this->name << "の技を選択して下さい" << std::endl;
    std::cin >> this->personalaction;
}

//ターゲットを選択
void Player::choiceTarget(){
    std::cout << this->name << "のターゲットを選択して下さい" << std::endl;
    std::cin >> this->target;
}

//使用可能な技を表示する
void Player::viewUseableSkill(){
    //全ビットをスキャン
    int tokugiindex = 0;
    for (int i = 1; i != 0; i <<= 1){
        if ((skill & i) != 0) {
            std::cout << actions[tokugiindex].id << ":" << actions[tokugiindex].name << std::endl;
        }
        tokugiindex++;
    }

}


//--------------------------------------------------------------
//
//  敵クラス
//
//--------------------------------------------------------------

class Enemy : public game {
public:
    //コンストラクタ・デストラクタ
    Enemy(const EnemyData& enemy
const int id
const int group_id);
    ~Enemy(){};
    
    //戦闘処理用変数
    void attack(ChrRef target);
    void attacked(int n);
    void choicePersonalAction();
    void choiceTarget();
    void viewUseableSkill();

protected:
    int idnumber;
    int groupidnumber;
};

//--------------------------------------------------------------
//
//  敵クラス  関数の実装
//
//--------------------------------------------------------------

//コンストラクタ
Enemy::Enemy(const EnemyData& enemy
const int id
const int group_id) : game(enemy)
idnumber(id)
groupidnumber(group_id){
}

//敵の攻撃
void Enemy::attack(ChrRef target) {
    std::cout << name << "の攻撃" << std::endl;
    int damagepoint = dunRand(1
getStr()) - target->getAc();
    
    //攻撃値がゼロ以下になる場合は1にする
    if (damagepoint <= 0) {
        damagepoint = 1;
    }
    
    std::cout << target->getName() << "に" << damagepoint << "のダメージ" << std::endl;
    target->attacked(damagepoint);
}

void Enemy::attacked(int n) {
    setHp(getHp() - n);
    
    if (getHp() > 0) {
        std::cout << getName() << "のHPは" << getHp() << std::endl;
    }
    else {
        std::cout << getName() << "を倒した" << std::endl;
    }
}

void Enemy::choicePersonalAction(){
    this->personalaction = dunRand(0
2);//ここの数字は後でコンパイラに計算させるように変更する
}

void Enemy::choiceTarget(){
    this->target = dunRand(0
2);//ここの数字は後でコンパイラに計算させるように変更する
}

void Enemy::viewUseableSkill(){
    
}


//--------------------------------------------------------------
//
//  バトルクラス
//
//--------------------------------------------------------------

class Battle {
private:
//    Player* player;  //純粋仮想関数が基底クラスにある場合はポインタじゃないと実体化できない？
    
    //プレイヤーのカウンタ
    int playercounter = 0;
    //生存プレイヤー、敵のカウンタ
    size_t alivecounterplayer = 0;
    size_t alivecounterenemy = 0;
    
    //各戦闘のキャラクター格納用リスト
    std::vector<ChrRef> chr_vector; //ここをEnemyクラスの参照のリストにしていたのがエラーの原因だった。後で理由を追求
    
public:
    //コンストラクタ・デストラクタ
    Battle(){};
    ~Battle(){};
    
    //vectorにキャラクターのポインタを格納する関数
    void addList(const EnemyData& c
const int id
const int group_id);
    void addListPlayer(const JobData& c);
    
    //戦闘用のメインの関数
    void match();
};

//--------------------------------------------------------------
//
//  バトルクラス  メンバ関数の実装
//
//--------------------------------------------------------------
void Battle::addList(const EnemyData& c
const int id
const int group_id){
    ChrRef enemy(new Enemy(c
id
group_id));
    chr_vector.push_back(enemy);
}

void Battle::addListPlayer(const JobData& c){
    ChrRef player(new Player(c));
    chr_vector.push_back(player);
}

void Battle::match() {
    //各数値を一時的に格納する変数
    int action;
    
    //職業を選択して、その職業で初期化されたプレイヤークラスのポインタをvectorに格納
    std::cout << "職業を３つ選択して下さい" << std::endl;
    for (int i = 0; i < 3; i++) {
        int playerchoice;
        std::cin >> playerchoice;
        addListPlayer(jobs[playerchoice]);
        playercounter++;
    }
    
    //戦闘のループ
    for (int i = 0; i < 2; i++) {//ここで戦闘回数をハードコーディングしている。再検討の必要有り。
        
        int enemy_counter = 0;
        int kind_of_enemy = 0;
        int number_of_kind_of_enemy = dunRand(1
4);

        //種類数は最低1最大4
        for (int i = 0; i < number_of_kind_of_enemy; i++) {
            //敵の種類の決定
            kind_of_enemy = dunRand(0
9);
            //同種の個体数は最低1最大3
            for (int j = 0; j < dunRand(1
3); j++) {
                addList(enemies[kind_of_enemy]
enemy_counter
i);
                enemy_counter++;
                if (enemy_counter >= 7) return;
            }
        }
        std::cout << "test" << std::endl;


        //戦闘内のターンのループ
        while (1) {
            std::cout << "ターン開始" << std::endl;
            
            //ライフがゼロでは無いキャラクターを全て表示する
            for(std::vector<ChrRef>::iterator itr = chr_vector.begin(); itr != chr_vector.end(); ++itr){
                if ((*itr)->getHp() > 0) {
                    std::cout << itr - chr_vector.begin() << "：" << (*itr)->getName() << std::endl;
                }
            }
            std::cout << "たたかう：1　　逃げる：0" << std::endl;
            std::cin >> action;

            //全体の行動を分岐
            switch (action) {
                //たたかうを選択した場合
                case 1:
                {
                    //各キャラクターが使用する技およびターゲットの設定
                    for(std::vector<ChrRef>::iterator itr = chr_vector.begin(); itr != chr_vector.end(); ++itr){
                        if ((*itr)->getHp() > 0) {
                            //各キャラクターが選択できる技の表示
                            (*itr)->viewUseableSkill();
                            //行動の選択
                            (*itr)->choicePersonalAction();
                            //ターゲットの選択
                            (*itr)->choiceTarget();
                        }

                    }

                    //攻撃処理
                    for(std::vector<ChrRef>::iterator itr = chr_vector.begin(); itr != chr_vector.end(); ++itr){

                        //自身が生存しているか確認、攻撃対象が生存しているか確認、両方とも問題が無ければ攻撃実行
                        if ((*itr)->getHp() > 0) {
                            //攻撃対象が生存しているか確認　生存していれば攻撃を実行
                            if (((chr_vector[(*itr)->getTarget()]->getHp()) > 0) && ((*itr)->getTarget() >=0) && ((*itr)->getTarget() <=6)) {//さらに整数であることもチェックする必要がある。再検討。
                                (*itr)->attack(chr_vector[(*itr)->getTarget()]);
                            } else {
                                std::cout << (*itr)->getName() << "の攻撃は失敗した" << std::endl;
                            }
                        }

                        //各キャラクターの攻撃後に敵とプレイヤーの生存数を確認する
                        alivecounterplayer = std::count_if(chr_vector.begin()
chr_vector.end()
[](ChrRef counttarget){return (counttarget->getHp() > 0 && counttarget->getIsPlayer() == 0);});
                        alivecounterenemy = std::count_if(chr_vector.begin()
chr_vector.end()
[](ChrRef counttarget){return (counttarget->getHp() > 0 && counttarget->getIsPlayer() != 0);});
                        
                        //いずれかのメンバーがゼロであれば攻撃処理のループを抜ける
                        if (alivecounterplayer == 0 || alivecounterenemy == 0) {
                            break;
                        }
                        
                    }
                    std::cout << "ターン終了" << std::endl;
                    break;
                    
                }break;

                //逃げるを選択した場合
                case 0:
                {
                    std::cout << "何もしなかった" << std::endl;
                }break;
    
                default:
                {

                }
            }

    
            //戦闘終了後処理
            if (alivecounterplayer == 0 || alivecounterenemy == 0) {
                //新しい戦闘に移る前に全敵キャラクターのオブジェクトをベクターから取り除く
                //関数オブジェクトとしてのラムダ式を作成
                auto game_remove = std::remove_if(chr_vector.begin()
chr_vector.end()
[](ChrRef removetarget){return removetarget->getIsPlayer() != 0;});
                //ラムダ式を呼び出す
                chr_vector.erase(game_remove
chr_vector.end());
                //whileから抜ける
                break;
            }

        }
        //forを抜ける
        if (alivecounterplayer == 0) {
            std::cout << "GAME OVER" << std::endl;
            break;
        }
    }
    //クリア時の処理
    if (alivecounterplayer > 0) {
        std::cout << "GAME CLEAR" << std::endl;
    }
}



//--------------------------------------------------------------
//
//  メイン関数
//
//--------------------------------------------------------------

int main(int argc
char *argv[]) {
    std::cout << "動作テスト" << std::endl;
    
    Battle battle;
    battle.match();
    
    return 0;
}

