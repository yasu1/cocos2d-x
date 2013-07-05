#include "cocos2d.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

class SingleTouch1:public cocos2d::CCLayer
{
public:
	virtual bool init(); 
	static cocos2d::CCScene* scene();

	void menuCloseCallback(CCObject* pSender);

	CCSprite* Sprite;

	virtual void onEnter();
	virtual void registerWithTouchDispatcher();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	CREATE_FUNC(SingleTouch1);

};