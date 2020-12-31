//
//  GameObjMap.h
//  example12-1
//
//  Created by shuoquan man on 12-10-21.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef example16_1_GameObjMap_h
#define example16_1_GameObjMap_h
#include "GameObjStar.h"
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;
class GameObjMap : public CCNode
{
public:
    GameObjMap(void);
    short state;
    virtual ~GameObjMap(void);
    virtual void onEnter();
    virtual void onExit();
    void bg1change();
    void bg2change();
   // cocos2d::CCArray * stars1;
    //cocos2d::CCArray * stars2;
    vector<GameObjStar*>  stars1;
    vector<GameObjStar*>  stars2;
};


#endif
