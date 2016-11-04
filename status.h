//
//  status.h
//  rougelike
//
//  Created by 白川 岳史 on 2015/08/11.
//  Copyright (c) 2015年 白川 岳史. All rights reserved.
//

#ifndef __rougelike__status__
#define __rougelike__status__

#include <stdio.h>

//キャラクターデータの構造体
struct StatusData {     
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

class Status {

private:
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
}
#endif /* defined(__rougelike__status__) */

