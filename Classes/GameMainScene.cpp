//
//  GameMainScene.cpp
//  example12-1
//
//  Created by shuoquan man on 12-10-21.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "GameMainScene.h"
#include "GameMenuScene.h"
#include "GameObjMap.h"
#include "GameConst.h"
#include "GameObjHero.h"
#include "GameObjStar.h"
using namespace cocos2d;

Scene* GameMain::scene()
{
    Scene *scene = Scene::create();
    
    GameMain *layer = GameMain::create();
    
    scene->addChild(layer);
    
    return scene;
}
bool GameMain::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    //地图
    Size size = Director::sharedDirector()->getWinSize();    
    map = new GameObjMap();
    map->setAnchorPoint(ccp(0,1));
    map->setPosition(ccp(0,size.height));
    addChild(map,0);

    ////玩家
    //hero = new GameObjHero();
    //hero->setScale(0.5);
    //hero->setPosition(ccp(100,160));
    //addChild(hero,1);

    gamemark = new GameMark();
    addChild(gamemark,4);

	gamemark = new GameMark();
	addChild(gamemark, 4);

    gameover = Sprite::create("gameover.png");
    gameover->setAnchorPoint(Vec2(0.5,0.5));
    gameover->setPosition(Vec2(0,0));
    gameover->setPosition(Vec2(size.width/2,size.height/2 + 70));
    gameover->setVisible(false);
    gameover->setScale(0.5);
    addChild(gameover,5);

    MenuItemImage *pCloseItem = MenuItemImage::create("back.png","back.png",CC_CALLBACK_1(GameMain::menuBackCallback,this));
    pCloseItem->setPosition( ccp(size.width/2,size.height/2 - 50) );
    pCloseItem->setScale(0.5);
    Menu* pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition( Vec2::ZERO );
    this->addChild(pMenu,5,25);
    pMenu->setVisible(false);
    pMenu->setEnabled(false);
    isover = false;


    scheduleUpdate();
    return true;
}
void GameMain::setover(){
    Menu* pMenu = (Menu *)this->getChildByTag(25);
    pMenu->setVisible(true);
    pMenu->setEnabled(true);
    gameover->setVisible(true);
    gameover->setScale(0);
    pMenu->setScale(0);
    pMenu->runAction(ScaleTo::create(0.5,1));
    gameover->runAction(ScaleTo::create(0.5,0.5));
    isover = true;
}
void GameMain::isherodrop(){
	Vec2 p1 = (map->getChildByTag(0))->getPosition();
	Vec2 p2 = (map->getChildByTag(1))->getPosition();
	int temp;
	if (p1.x <= 100 && (p1.x + 480) >= 100) 
    {
		temp = (100 - p1.x) / 64;
		if (bg1shu[temp] == -1) 
        {
			//hero->setState(2);
		}
	}
	else 
    {
		temp = (100 - p2.x) / 64;
		if (bg2shu[temp] == -1)
        {
		//	hero->setState(2);
		}
	}
}
bool GameMain::isCollion(Vec2 p1,Vec2 p2,int w1,int h1,int w2,int h2){
    if(abs(p1.x - p2.x) < w1 + w2 && abs(p1.y - p2.y) < h1 + h2){
        return true;
    }
    return false;
};
void GameMain::update(float time){
    if(hero->state == 0)
       isherodrop();
    Vec2 p1 = (map->getChildByTag(0))->getPosition();
    Vec2 p2 = (map->getChildByTag(1))->getPosition();
    for(int i = 0;i < 5;i ++){
        if(p1.x <= 100 && (p1.x + 480) >= 100){
            GameObjStar *obj = (GameObjStar *)(map->stars1)->objectAtIndex(i);
            if(obj->get_visable() && isCollion(Vec2(100,hero->getPosition().y + 62.5),Vec2(p1.x + 86 + 96 * i,280),40,35,18.25,17.75)){
                obj->set_visable(false);
                gamemark->addnumber(200);
            }
        }else{
            GameObjStar *obj = (GameObjStar *)(map->stars2)->objectAtIndex(i);
            if(obj->get_visable() && isCollion(Vec2(100,hero->getPosition().y + 62.5),Vec2(p2.x + 86 + 96 * i,280),40,35,18.25,17.75)){
                obj->set_visable(false);
                gamemark->addnumber(200);
            }
        }
    }
}
void GameMain::menuBackCallback(Ref* pSender){
    CCDirector::sharedDirector()->setDepthTest(true);
    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5,GameMenu::scene(), true));
}
//void GameMain::onEnterTransitionDidFinish()
//{
//    CCLayer::onEnterTransitionDidFinish();
//    CCDirector::sharedDirector()->setDepthTest(false);
//}
//
//void GameMain::onExitTransitionDidStart()
//{
//    CCLayer::onExitTransitionDidStart();
//}
//void GameMain::onExit(){
//    CCLayer::onExit();
//}
//void GameMain::onEnter(){
//    CCLayer::onEnter();
//}
