//
//  LobbyScene.hpp
//  SanGuoSha
//
//  Created by LRH on 16/1/27.
//
//  多人对战

#ifndef LobbyScene_hpp
#define LobbyScene_hpp

//#include "AsioClient.h"
#include <cocos2d.h>
#include <cocos-ext.h>
#include <boost/smart_ptr.hpp>
#include "Macros.h"
//#include "SgsClient.h"

using namespace cocos2d;
//using namespace sgs::net;
using namespace cocos2d::extension;

namespace sgs {
    namespace scene {
        //用户资料
        class LobbyBoardUser :public cocos2d::Node {
        public:
            LobbyBoardUser();
            ~LobbyBoardUser();
            virtual bool init();
            CREATE_FUNC(LobbyBoardUser);
        };
        //用户面板
        class LobbyBoardInfo :public cocos2d::Node {
        public:
            LobbyBoardInfo();
            ~LobbyBoardInfo();
            virtual bool init();
            CREATE_FUNC(LobbyBoardInfo);
            void createTouchDownAction(CCObject* pSender, CCControlEvent event) ;
            void backTouchDownAction(CCObject* pSender, CCControlEvent event);
        };
        //房间表格单元
        class LobbyTableCell :public cocos2d::extension::TableViewCell {
        public:
            LobbyTableCell(const Size& size);
            ~LobbyTableCell();
            bool init();
            static LobbyTableCell * create(const Size& size);
            void select();
            void unselect();
            bool isSelect();
            void setRoomName(const string& name);
            CC_SYNTHESIZE_PASS_BY_REF_FOR_BOOL(selectable_, Selectable);
            CC_SYNTHESIZE_PASS_BY_REF(string, ip_ , Ip);
        private:
            Size cellSize_;
            //是否被选中
            bool selected_;
            Sprite* selectBg_;
            Sprite* unselectBg_;
            CCLabelTTF * lable_;
        };
        
        //大厅
        class Lobby : public cocos2d::Layer, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
        {
        public:
            Lobby();
            ~Lobby();
            virtual bool init();
            static cocos2d::Scene* scene();
            CREATE_FUNC(Lobby);
            virtual void onEnter ();
            virtual void onExit ();
            
            void addRoom(const string& name, const string& ip);
            //认证通过回调
            void authSuccessCallback();
            //搜索回调函数，不能直接调用UIThread接口
            //void seacherCallback(const sgs::net::IpAndNameStruct&);
            
            //ScrolView
            virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
            virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {};
            //from CCTableViewDelegate
            virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
            //CCTableViewDataSource
            virtual cocos2d::Size cellSizeForTable(cocos2d::extension::TableView *table);
            virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, unsigned int idx);
            virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
            
        private:
            //table尺寸
            Size cellSize_;
            //最大房间数
            int maxCount_;
            //房间搜索器
            //boost::shared_ptr<UdpSearcher> seacherPtr_;
            cocos2d::extension::TableView* tableView_;
            std::vector<LobbyTableCell *> cellVector_;
            //boost::shared_ptr<sgs::client::SgsClient> client_;
        };
        
    }
}

#endif /* LobbyScene_hpp */
