#ifndef example16_1_GameObjStar_h
#define example16_1_GameObjStar_h
#include "cocos2d.h"
using namespace cocos2d;

class GameObjStar : public CCNode
{
public:
    GameObjStar(void);
    CREATE_FUNC(GameObjStar);
    short state;
    virtual ~GameObjStar(void);
    virtual void onEnter();
    virtual void onExit();
    bool _visable;
    void set_visable(bool var);
    bool get_visable();
};

#endif
