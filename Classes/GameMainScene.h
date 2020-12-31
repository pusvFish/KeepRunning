#ifndef example16_1_GameMainScene_h
#define example16_1_GameMainScene_h
#include "cocos2d.h"
#include "GameObjHero.h"
#include "GameObjMap.h"
#include "GameMark.h"
using namespace cocos2d;
class GameMain : public cocos2d::Layer
{
public:
    
   // GameObjHero* hero;
    
    virtual bool init();
    bool isover;
  
    void isherodrop();
    void setover();
    GameObjMap * map;
    GameMark *gamemark;
    CCSprite *gameover;
    static cocos2d::CCScene* scene();
    
    void menuBackCallback(Ref* pSender);
    
    CREATE_FUNC(GameMain);
    
    //void update(float time);
    
    /*void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();*/
    
    bool isCollion(Vec2 p1,Vec2 p2,int w1,int h1,int w2,int h2);
};


#endif
