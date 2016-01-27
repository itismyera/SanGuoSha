//
//  MainScene.cpp
//  SanGuoSha
//
//  Created by LRH on 16/1/27.
//
//

#include "MainScene.hpp"
#include "Table.hpp"


Scene* MainLayer::scene()
{
    Scene* scene = NULL;
    do{
        //scene = new MQScene();
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        
        MainLayer* layer = MainLayer::create();
        CC_BREAK_IF(!layer);
        
        scene->addChild(layer);
        
    }while(0);
    
    return scene;
}

bool MainLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        //std::string version = "Version " + Config::getInstance()->getProperty(CONFIG_KEY_VERSION);
        std::string version = "Version 1.0";
        Label* pLabel = Label::createWithTTF(version.c_str(), "fonts/arial.ttf", 24);
        CC_BREAK_IF(! pLabel);
        Size size = Director::getInstance()->getWinSize();
        pLabel->setPosition(Vec2(size.width -150, 0));
        pLabel->setAnchorPoint(Vec2(0,0));
        //pLabel->setColor();
        this->addChild(pLabel, 1, 99);
        
        Sprite* pSprite = Sprite::create("system_mainbg.jpg");
        CC_BREAK_IF(! pSprite);
        
        pSprite->setPosition(Vec2(size.width/2, size.height/2));
        this->addChild(pSprite, 0);
        
        SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/system/springOfTheEastLogin.mp3",true);
        initMenu();
        //bool hasName = Config::getInstance()->containProperty(CONFIG_KEY_NAME);
        bool hasName = true;
        //是否有名字
        if(!hasName) {
            pMenu->setVisible(false);
            //showInputNameDialog();
        }
        
        bRet = true;
    }while(0);
    return bRet;
}

void MainLayer::initMenu()
{
    do
    {
        //单机游戏
        //3.0两种写法
        MenuItemImage *pSingleGameItem = MenuItemImage::create(
                "button_singleNormal.png",
                "button_singleSelected.png",
                std::bind(&MainLayer::menuCloseCallback,this,std::placeholders::_1));
        /*
        MenuItemImage *pSingleGameItem = MenuItemImage::create(
                "button_singleNormal.png",
                "button_singleSelected.png",
                CC_CALLBACK_1(MainLayer::menuCloseCallback, this));
        */
        CC_BREAK_IF(! pSingleGameItem);
        pSingleGameItem->setTag(MENU_SINGLE_GAME_TAG);
        pSingleGameItem->setAnchorPoint(Vec2(0.5,0.5));
        //多人游戏
        MenuItemImage *pMultiGameItem = MenuItemImage::create(
                "button_multiNormal.png",
                "button_multiSelected.png",
                std::bind(&MainLayer::menuCloseCallback,this,std::placeholders::_1));
        CC_BREAK_IF(! pMultiGameItem);
        pMultiGameItem->setTag(MENU_MULTI_GAME_TAG);
        
        //关于我们
        MenuItemImage *pAboutUsItem = MenuItemImage::create(
                "button_aboutNormal.png",
                "button_aboutSelected.png",
                std::bind(&MainLayer::menuCloseCallback,this,std::placeholders::_1));
        CC_BREAK_IF(! pAboutUsItem);
        pAboutUsItem->setTag(MENU_ABOUT_GAME_TAG);
        //退出游戏
        MenuItemImage *pExitGameItem = MenuItemImage::create(
                "button_exitNormal.png",
                "button_exitSelected.png",
                std::bind(&MainLayer::menuCloseCallback,this,std::placeholders::_1));
        pExitGameItem->setTag(MENU_EXIT_GAME_TAG);
        CC_BREAK_IF(! pExitGameItem);
        
        pMenu = Menu::create(pSingleGameItem, pMultiGameItem,pAboutUsItem ,pExitGameItem, NULL);
        pMenu->setPosition(Vec2(Director::getInstance()->getWinSize().width/2, Director::getInstance()->getWinSize().height/2));
        pMenu->alignItemsVerticallyWithPadding(50);
        CC_BREAK_IF(! pMenu);
        
        this->addChild(pMenu);
    }
    while(0);
}

void MainLayer::menuCloseCallback(Ref* pSender)
{
    Node * node = (Node *)pSender;
    
    switch(node->getTag()) {
        case MENU_SINGLE_GAME_TAG:
            SimpleAudioEngine::getInstance()->playEffect("audio/system/choose-item.mp3");
            //startServer();
            CCLOG("single clicked");
            Director::getInstance()->pushScene(Table::scene());
            break;
        case MENU_MULTI_GAME_TAG:
            SimpleAudioEngine::getInstance()->playEffect("audio/system/choose-item.mp3");
            //startClient();
            CCLOG("multi clicked");
            //Director::getInstance()->pushScene(sgs::scene::Lobby::scene());            
            break;
        case MENU_ABOUT_GAME_TAG:
            SimpleAudioEngine::getInstance()->playEffect("audio/system/choose-item.mp3");
            CCLOG("about clicked");
            //Director::getInstance()->pushScene(AboutUs::scene());
            break;
        case MENU_EXIT_GAME_TAG:
            Director::getInstance()->end();
            break;
    }
}


