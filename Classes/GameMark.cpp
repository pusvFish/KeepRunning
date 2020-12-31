
#include "GameMark.h"
GameMark::GameMark(void)
{
}

GameMark::~GameMark(void)
{
}
void GameMark::onExit()
{
	CCNode::onExit();
}
void GameMark::onEnter()
{
    Node::onEnter();
    Size size = Director::sharedDirector()->getWinSize(); 
    this->setContentSize(size);
   // bits = CCArray::create(5);
	bits=CCArray::create();
	Sprite *title= Sprite::create("score.png");
    title->setPosition(Vec2(size.width/2 + 120,size.height - 15));
    title->setScale(0.5);
    addChild(title);

    for(int i = 0;i < 5;i ++){
        Sprite * shu = Sprite::create("shu.png");
        ui = shu->getTexture();
        shu->setScale(0.5);
        shu->setTextureRect(CCRectMake(234,0,26,31));
        shu->setPosition(Vec2(size.width - 15 - i * 15,size.height - 15));
        bits->addObject(shu);
        addChild(shu);
    }
    bits->retain();
    mark = 0;
}
void GameMark::addnumber(int var){
    //按位设置数字
    mark += var;
    int temp = mark % 10;
    if(temp > 0){
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
    }else{
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = (mark % 100) / 10;
    if(temp > 0){
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  
 
    }else{
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = (mark % 1000) / 100;
    if(temp > 0){
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
 
    }else{
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake(234,0,26,31));
    }
    temp = (mark % 10000) / 1000;
    if(temp > 0){
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
 
    }else{
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake(234,0,26,31)); 
    }
    temp = mark / 10000;
    if(temp > 0){
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  
 
    }else{
        ((Sprite *)bits->objectAtIndex(0))->setTexture(ui);
        ((Sprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake(234,0,26,31));
    }
}