//#include "GameAboutScene.h"
//#include "GameMenuScene.h"
//
//
//
//Scene* GameAbout::scene()
//{
//    Scene *scene = Scene::create();
//    
//    GameAbout *layer = GameAbout::create();
//    
//    scene->addChild(layer);
//    
//    return scene;
//}
//bool GameAbout::init()
//{
//    if ( !Layer::init() )
//    {
//        return false;
//    }
//    
//    Size size = Director::sharedDirector()->getWinSize();    
//    
//    Sprite* bg = Sprite::create("back_1.png");
//    bg->setScale(0.6f);
//    bg->setPosition( Vec2(size.width/2, size.height/2) );
//    this->addChild(bg, 0,0);
//
//    Sprite *kuang = CCSprite::create("tb.png");
//    kuang->setScale(0.5);
//    kuang->setRotation(90);
//    kuang->setPosition(Vec2(size.width/2, size.height/2));
//    this->addChild(kuang,2,2);
//
//    char inf[256];
//    sprintf(inf,"name:loli run\n\n program:shuoquan man\n\n art design:zuyi li\n\n company:hz books\n\n    powered by cocos2D-x");
//   // CCLabelTTF *myjineng = CCLabelTTF::create(inf,CCSizeMake(400,400),kCCTextAlignmentLeft, "Marker Felt", 20);
//	CCLabelTTF *myjineng=CCLabelTTF::create(inf,"Marker Felt",20,CCSizeMake(400,400),kCCTextAlignmentLeft);
//    myjineng->setAnchorPoint(ccp(0,1));
//    myjineng->setColor(ccc3(0,0,0));
//    myjineng->setPosition(ccp(100,260));
//    this->addChild(myjineng);
//
//    //关于标签
//    Sprite*abouttitle = Sprite::create("about.png");
//    abouttitle->setScale(0.5);
//    abouttitle->setPosition(ccp(size.width/2, size.height - 20));
//    this->addChild(abouttitle,3,3);
//
//    //返回
//    MenuItemImage *back = MenuItemImage::create("backA.png", "backB.png",CC_CALLBACK_1(GameAbout::menuBackCallback,this));
//    back->setScale(0.5);
//    back->setPosition(ccp(size.width - 20,size.height - 20));
//    back->setEnabled(false);
//    Menu* mainmenu = Menu::create(back,NULL);
//    mainmenu->setPosition(Vec2(0,0));
//    this->addChild(mainmenu,3,4);
//    return true;
//}
//void GameAbout::menuBackCallback(Ref* pSender){
//    CCDirector::sharedDirector()->setDepthTest(true);
//    CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5,GameMenu::scene(), true));
//}
////void GameAbout::onEnterTransitionDidFinish()
////{
////    CCLayer::onEnterTransitionDidFinish();
////    CCDirector::sharedDirector()->setDepthTest(false);
////}
//
////void GameAbout::onExitTransitionDidStart()
////{
////    CCLayer::onExitTransitionDidStart();
////}
////void GameAbout::onExit(){
////    CCLayer::onExit();
////}
////void GameAbout::onEnter(){
////    CCLayer::onEnter();
////	CCNode* mainmenu = this->getChildByTag(4);
////    CCArray* temp = mainmenu->getChildren();
////    ((CCMenuItemImage *)temp->objectAtIndex(0))->setEnabled(true);
////}