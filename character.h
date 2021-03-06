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

class character;
typedef std::shared_ptr<game> ChrRef;

class character {
    
protected:
    StatusData status;
    
public:
    //コンストラクタ
    character():status(statusdatabase[0]){}
    
    //引数付きコンストラクタ
    character (const StatusData& statusdata) :status(statusdata){}
    
    //デストラクタ
    virtual ~character (){
    
    //ここにゲッター、セッターが必要か再検討

    //純粋仮想関数
    virtual void attack(ChrRef target) = 0;
    virtual void attacked(int n) = 0; //子クラスの関数が引数を持つ場合、純粋仮想関数にも同じ引数を持たせる必要がある？
    virtual void choicePersonalAction() = 0;
    virtual void choiceTarget() = 0;
    virtual void viewUseableSkill() = 0; //enemyクラスには不要な実装なのでこの形が正しいかどうか後で検証
};

#endif /* defined(__rougelike__character__) */

