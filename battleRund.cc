//
//  battleRund.cc
//  rougelike
//
//  Created by 白川 岳史 on 2015/03/09.
//  Copyright (c) 2015年 白川 岳史. All rights reserved.
//

#include "battleRund.h"
#include <random>

int dunRand(int startnumber, int endnumber){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dice(startnumber,endnumber);

    return dice(mt);
}