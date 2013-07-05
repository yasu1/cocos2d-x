#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	//单点
	void singleCallback(CCObject* pSender);
	//多点
	void multiCallback(CCObject* pSender);
	//单点捕获例子
	void compareCallback(CCObject* pSender);
	//输入
	void inputCallback(CCObject* pSender);
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

class SingleTouch : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);

	CCSprite* Sprite;

	virtual void onEnter();
	virtual void registerWithTouchDispatcher();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	virtual void ccTouchCancelled(CCTouch* touch, CCEvent* event);

	CREATE_FUNC(SingleTouch);
};

class MultiTouch : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);

	CCSprite* Sprite;

	float distance;

	virtual void onEnter();
	virtual void registerWithTouchDispatcher();

	virtual void ccTouchesBegan(CCSet* touches, CCEvent* event);
	virtual void ccTouchesMoved(CCSet* touches, CCEvent* event);
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);
	virtual void ccTouchesCancelled(CCSet* touches, CCEvent* event);

	CREATE_FUNC(MultiTouch);
};

class TextInput : public CCLayer
{
public:
	virtual void onEnter();
	virtual void onClickTrackNode(bool bClicked);

	void menuCloseCallback(CCObject* pSender);

	virtual void registerWithTouchDispatcher();
	CCNode * m_pTrackNode;
	CCPoint  m_beginPos;
	// CCLayer
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};



#endif  // __HELLOWORLD_SCENE_H__