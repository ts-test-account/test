//
//  player.h
//  rougelike
//
//  Created by 白川 岳史 on 2015/06/29.
//  Copyright (c) 2015年 白川 岳史. All rights reserved.
//

#ifndef __rougelike__player__
#define __rougelike__player__


class Player : public character {
    
public:
    //コンストラクタ
    Player():status(statusdatabase[0]){}
    
    //引数付きコンストラクタ
    Player (const StatusData& statusdata){}
    
    //デストラクタ
    virtual ~Player (){
    
    //ゲッター、セッターが必要か再検討

    //戦闘処理用関数
    void attack(ChrRef target);
    void attacked(int n);
    void choicePersonalAction();
    void choiceTarget();
    void viewUseableSkill();

};

#endif /* defined(__rougelike__player__) */

