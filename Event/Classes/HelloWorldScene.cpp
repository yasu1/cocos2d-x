#include "HelloWorldScene.h"
#include "AnotherLayer.h"

using namespace cocos2d;

static CCRect getRect(CCNode * pNode)
{
	CCRect rc;
	rc.origin = pNode->getPosition();
	rc.size = pNode->getContentSize();
	rc.origin.x -= rc.size.width / 2;
	rc.origin.y -= rc.size.height / 2;
	return rc;
}

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

		CCLabelTTF* label2 = CCLabelTTF::create("single", "Arial", 24);
		CCMenuItemLabel* item1 = CCMenuItemLabel::create(label2, this, menu_selector(HelloWorld::singleCallback));

		CCLabelTTF* label3 = CCLabelTTF::create("multiply", "Arial", 24);
		CCMenuItemLabel* item2 = CCMenuItemLabel::create(label3, this, menu_selector(HelloWorld::multiCallback));

		CCLabelTTF* label = CCLabelTTF::create("catch", "Arial", 24);
		CCMenuItemLabel* item3 = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::compareCallback));

		CCLabelTTF* label1 = CCLabelTTF::create("input", "Arial", 24);
		CCMenuItemLabel* item4 = CCMenuItemLabel::create(label1, this, menu_selector(HelloWorld::inputCallback));

		CCMenu* menu = CCMenu::create( item1, item2, item3, item4,  NULL);
		menu->alignItemsVertically();



		menu->setPosition(ccp(150+CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2));
		this->addChild(menu);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::singleCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = SingleTouch::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}

void HelloWorld::multiCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = MultiTouch::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}

void HelloWorld::compareCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = SingleTouch::create();
	layer->setPosition(0,100);
	layer->setScale(0.5);
	scene->addChild(layer);

	CCLayer* layer1 = SingleTouch1::create();
	scene->addChild(layer1);
	layer1->setPosition(200,100);
	layer1->setScale(0.5);
	CCDirector::sharedDirector()->replaceScene(scene);
}
void HelloWorld::inputCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = new TextInput;
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}


//SingleTouch

CCScene* SingleTouch::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SingleTouch *layer = SingleTouch::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool SingleTouch::init()
{
	bool bRet = false;
	do 
	{

		CC_BREAK_IF(! CCLayer::init());

		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(SingleTouch::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		// Place the menu item bottom-right conner.
		pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

		// Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu, 1);

		// 2. Add a label shows "Hello World".

		// Create a label and initialize with string "Hello World".
		CCLabelTTF* pLabel = CCLabelTTF::create("SingleTouch", "Arial", 24);
		CC_BREAK_IF(! pLabel);

		// Get window size and place the label upper. 
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pLabel->setPosition(ccp(size.width / 2, size.height - 50));

		// Add the label to HelloWorld layer as a child layer.
		this->addChild(pLabel, 1);

		// 3. Add add a splash screen, show the cocos2d splash image.
		CCSprite* pSprite = CCSprite::create("HelloWorld.png");
		CC_BREAK_IF(! pSprite);

		Sprite = pSprite;
		// Place the sprite on the center of the screen
		pSprite->setPosition(ccp(size.width/2, size.height/2));

		// Add the sprite to HelloWorld layer as a child layer.
		this->addChild(pSprite, 0);


		bRet = true;
	} while (0);

	return bRet;
}

void SingleTouch::menuCloseCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = HelloWorld::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}

void SingleTouch::onEnter()
{
	CCLayer::onEnter();
	setTouchEnabled(true);
}

void SingleTouch::registerWithTouchDispatcher()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

bool SingleTouch::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCLog("SingleTouchBegan");
	return true;
}

void SingleTouch::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	CCLog("SingleTouchMoved");
	Sprite->setPosition(touch->getLocation());
}

void SingleTouch::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCLog("SingleTouchEnded");
}

void SingleTouch::ccTouchCancelled(CCTouch* touch, CCEvent* event)
{
	CCLog("SingleTouchCancelled");
}

//MultiTouch

CCScene* MultiTouch::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		MultiTouch *layer = MultiTouch::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool MultiTouch::init()
{
	bool bRet = false;
	do 
	{

		CC_BREAK_IF(! CCLayer::init());

		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(MultiTouch::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		// Place the menu item bottom-right conner.
		pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

		// Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu, 1);

		// 2. Add a label shows "Hello World".

		// Create a label and initialize with string "Hello World".
		CCLabelTTF* pLabel = CCLabelTTF::create("MultiTouch", "Arial", 24);
		CC_BREAK_IF(! pLabel);

		// Get window size and place the label upper. 
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pLabel->setPosition(ccp(size.width / 2, size.height - 50));

		// Add the label to HelloWorld layer as a child layer.
		this->addChild(pLabel, 1);

		// 3. Add add a splash screen, show the cocos2d splash image.
		CCSprite* pSprite = CCSprite::create("HelloWorld.png");
		CC_BREAK_IF(! pSprite);

		Sprite =CCSprite::create("grossinis_sister1.png");  
		Sprite->setPosition(ccp(size.width/2, size.height/2) );  
		// Place the sprite on the center of the screen
		pSprite->setPosition(ccp(size.width/2, size.height/2));

		// Add the sprite to HelloWorld layer as a child layer.
		this->addChild(pSprite, 0);

		this->addChild(Sprite,0);

		bRet = true;
	} while (0);

	return bRet;
}

void MultiTouch::menuCloseCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = HelloWorld::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}

void MultiTouch::onEnter()
{
	CCLayer::onEnter();
	setTouchEnabled(true);
}

void MultiTouch::registerWithTouchDispatcher()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addStandardDelegate(this, 0);
}

void MultiTouch::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCLog("MultiTouchBegan");

	if(touches->count() >= 2)
	{
		CCSetIterator iter = touches->begin();
		CCPoint point1 = ((CCTouch*)(*iter))->getLocationInView();
		point1 = CCDirector::sharedDirector()->convertToGL(point1);
		iter ++;
		CCPoint point2 = ((CCTouch*)(*iter))->getLocationInView();
		point2 = CCDirector::sharedDirector()->convertToGL(point2);

		distance = sqrt((point1.x - point2.x)*(point1.x - point2.x)+(point1.y - point2.y)*(point1.y - point2.y));

	}
}

void MultiTouch::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	if(touches->count() == 1)
	{
		CCSetIterator iter1 = touches->begin();
		Sprite->setPosition(((CCTouch*)(*iter1))->getLocation());
	}
	else if(touches->count() >= 2)
	{
		//Sprite
		CCSetIterator iter = touches->begin();
		CCPoint point1 = ((CCTouch*)(*iter))->getLocationInView();
		point1 = CCDirector::sharedDirector()->convertToGL(point1);
		iter ++;
		CCPoint point2 = ((CCTouch*)(*iter))->getLocationInView();
		point2 = CCDirector::sharedDirector()->convertToGL(point2);

		float distance1 = sqrt((point1.x - point2.x)*(point1.x - point2.x)+(point1.y - point2.y)*(point1.y - point2.y));

		float scale = distance1/distance;
		distance = distance1;

		if(scale > 1.0)
		{
			CCFiniteTimeAction *action =CCScaleTo::create(1.2f,3);  
			Sprite->runAction(action);  
		}
		else
		{
			CCFiniteTimeAction *action =CCScaleTo::create(1.2f,1);  
			Sprite->runAction(action);  
		}
	}
}

void MultiTouch::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	CCLog("MultiTouchEnded");
}

void MultiTouch::ccTouchesCancelled(CCSet* touches, CCEvent* event)
{
	CCLog("MultiTouchCancelled");
}
//TextInput

bool TextInput::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLog("aaa");
	m_beginPos = pTouch->getLocation();
	return true;
}


void TextInput::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)
{
	if (! m_pTrackNode)
	{
		return;
	}

	CCPoint endPos = pTouch->getLocation();    

	float delta = 5.0f;
	if (::abs(endPos.x - m_beginPos.x) > delta
		|| ::abs(endPos.y - m_beginPos.y) > delta)
	{
		// not click
		m_beginPos.x = m_beginPos.y = -1;
		return;
	}

	// decide the trackNode is clicked.
	CCRect rect;
	CCPoint point = convertTouchToNodeSpaceAR(pTouch);

	rect = getRect(m_pTrackNode);

	this->onClickTrackNode(rect.containsPoint(point));
	CCLOG("----------------------------------");
}

void TextInput::onEnter()
{
	CCLayer::onEnter();
	
	setTouchEnabled(true);

	CCSize s = CCDirector::sharedDirector()->getWinSize();

	CCTextFieldTTF * pTextField = CCTextFieldTTF::textFieldWithPlaceHolder("<click here for input>","Arial",24);
	addChild(pTextField);
	pTextField->setPosition(ccp(s.width / 2, s.height / 2));

	m_pTrackNode = pTextField;

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(TextInput::menuCloseCallback));

	// Place the menu item bottom-right conner.
	pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

	// Create a menu with the "close" menu item, it's an auto release object.
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu);
}

void TextInput::registerWithTouchDispatcher()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

void TextInput::onClickTrackNode(bool bClicked)
{
	CCTextFieldTTF * pTextField = (CCTextFieldTTF*)m_pTrackNode;
	if (bClicked)
	{
		// TextFieldTTFTest be clicked
		CCLOG("TextFieldTTFDefaultTest:CCTextFieldTTF attachWithIME");
		pTextField->attachWithIME();
	}
	else
	{
		// TextFieldTTFTest not be clicked
		CCLOG("TextFieldTTFDefaultTest:CCTextFieldTTF detachWithIME");
		pTextField->detachWithIME();
	}
}

void TextInput::menuCloseCallback(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* layer = HelloWorld::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(scene);
}
