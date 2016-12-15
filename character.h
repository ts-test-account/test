//
//  character.h
//  rougelike
//
//  Created by 白川 岳史 on 2015/06/29.
//  Copyright (c) 2015年 白川 岳史. All rights reserved.
//

#ifndef __rougelike__character__
#define __rougelike__character__

#include <stdio.h>
#include <characterParameter.h>

class character {
    
protected:
    StatusData status;
    
public:
    //コンストラクタ・デストラクタ
    character():status(statusdatabase[0]){}
    
    //引数付きコンストラクタ
    character (const StatusData& statusdata) :status(statusdata){}
    
    //デストラクタ
    virtual ~character (){}
    
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

#endif /* defined(__rougelike__character__) */

