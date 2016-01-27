//
//  Table.cpp
//  SanGuoSha
//
//  Created by LRH on 16/1/27.
//
//

#include "Table.hpp"

Scene* Table::scene()
{
    Scene * scene = NULL;
    do
    {
        scene = Scene::create();
        CC_BREAK_IF(! scene);
        
        Table *layer = Table::create();
        CC_BREAK_IF(! layer);
        
        scene->addChild(layer);
    } while (0);
   
    return scene;
}

bool Table::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(! Layer::init());
        
        Size size = Director::getInstance()->getWinSize();
        
        Sprite* bgImg = Sprite::create("image/table/bg.png");
        CC_BREAK_IF(! bgImg);
        
        bgImg->setPosition(Vec2(size.width/2, size.height/2));
        
        this->addChild(bgImg, 0);
        
        Sprite* equ = Sprite::create("image/table/equ.png");
        CC_BREAK_IF(! equ);
       
        equ->setPosition(Vec2(0, 0));
        equ->setAnchorPoint(Vec2(0,0));
        this->addChild(equ, 0);
        
        Sprite* user = Sprite::create("image/table/user.png");
        CC_BREAK_IF(! user);
       
        user->setPosition(Vec2(size.width-user->getTextureRect().size.width, 0));
        user->setAnchorPoint(Vec2(0,0));
        this->addChild(user, 0);
        
        Sprite* roles = Sprite::create("image/table/roles.png");
        CC_BREAK_IF(! roles);
        
        roles->setPosition(Vec2(0, size.height-roles->getTextureRect().size.height));
        roles->setAnchorPoint(Vec2(0,0));
        
        this->addChild(roles, 0);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void Table::menuCloseCallback(Ref* pSender)
{
    
}
