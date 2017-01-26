//
//  player.cc
//  rougelike
//
//  Created by 白川 岳史 on 2017/01/26.
//  Copyright (c) 2015年 白川 岳史. All rights reserved.
//

#include "player.h"

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

