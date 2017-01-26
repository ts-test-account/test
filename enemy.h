//
//  enemy.h
//  rougelike
//
//  Created by 白川 岳史 on 2015/06/29.
//  Copyright (c) 2015年 白川 岳史. All rights reserved.
//

#ifndef __rougelike__enemy__
#define __rougelike__enemy__

class Enemy : public game {
public:
    //コンストラクタ・デストラクタ
    Enemy(const EnemyData& enemy, const int id, const int group_id);
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


#endif /* defined(__rougelike__enemy__) */