#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AnotherLayer.h"

USING_NS_CC;

CCScene* SingleTouch1::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SingleTouch1 *layer = SingleTouch1::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SingleTouch1::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(! CCLayer::init());

		// Get window size and place the label upper. 
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite* sprite = CCSprite::create("HelloWorld.png");

		Sprite = sprite;
		sprite->setPosition(ccp(size.width / 2, size.height - 50));
		this->addChild(sprite);


		bRet = true;
	} while (0);

	return bRet;
}

bool SingleTouch1::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("SingleTouch1Began");
	return true;
}
void SingleTouch1::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("SingleTouch1Moved");
	Sprite->setPosition(pTouch->getLocation());
}
void SingleTouch1::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("SingleTouch1Ended");
}
void SingleTouch1::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("SingleTouch1Cancelled");
}

void SingleTouch1::menuCloseCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = HelloWorld::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}

void SingleTouch1::onEnter()
{
	CCLayer::onEnter();
	setTouchEnabled(true);
}

void SingleTouch1::registerWithTouchDispatcher()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}