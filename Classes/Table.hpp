//
//  Table.hpp
//  SanGuoSha
//
//  Created by LRH on 16/1/27.
//
//  桌子

#ifndef Table_hpp
#define Table_hpp

#include "cocos2d.h"
USING_NS_CC;

class Table: public cocos2d::Layer
{
public:
    virtual bool init();
    static cocos2d::Scene* scene();
    void menuCloseCallback(Ref* pSender);
    CREATE_FUNC(Table);
private:
    
};

#endif /* Table_hpp */
