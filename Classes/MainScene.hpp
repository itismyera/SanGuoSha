//
//  MainScene.hpp
//  SanGuoSha
//
//  Created by LRH on 16/1/27.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"
#include <cocos-ext.h>

USING_NS_CC;
USING_NS_CC_EXT;
using namespace CocosDenshion;

class MainLayer:public cocos2d::Layer
{
public:
    virtual bool init();
    static cocos2d::Scene* scene();
    void menuCloseCallback(Ref* pSender);
    CREATE_FUNC(MainLayer);
    
    //显示输入名字的对话框
    //void showInputNameDialog();
    //void inputName(const string & name);
    void initMenu();
    //void clientCallback(const sgs::net::IpAndNameStruct&);
    //void modifyString(string name);
    //void startServer();
    //void startClient();
private:
    //boost::shared_ptr<sgs::net::AsioServer> server_;
    //sgs::net::AsioClient asioClient = new sgs::net::AsioClient(NULL);
    //CursorTextField* m_pCursorTextField;
    cocos2d::Menu* pMenu;
};

#endif /* MainScene_hpp */
