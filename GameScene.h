#pragma once
#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"
#include "MenuLayer.h"
#include "CannonLayer.h"
#include "TouchLayer.h"
#include "Fish.h"
#include "PaneLayer.h"
#include "FishingJoyData.h"
#include "GoldCounterLayer.h"
#include "PersonalAudioEngine.h"
USING_NS_CC;

class GameScene :
	public CCScene
{
public:
	GameScene(void);
	CREATE_FUNC(GameScene)
	virtual bool init();
	virtual ~GameScene();
	void cannonAimAt(CCPoint target);
	void cannonShootTo(CCPoint target);
	void alterGold(int delta);
	void onEnter();
protected:
	BackgroundLayer* _backgroundLayer;
	FishLayer* _fishLayer;
	MenuLayer* _menuLayer;
	CannonLayer* _cannonLayer;
	TouchLayer* _touchLayer;
	PaneLayer *_paneLayer;
	void preloadResources(void);
	bool checkOutCollisionBetweenFishesAndBullet(Bullet *_bullet);
	void checkOutCollisionBetweenFishesAndFishingNet(Bullet *_bullet);
	void checkOutCollision();
	virtual void update(float delta);
	void fishWillBeCaught(Fish* _fish);
	//void alterGold(int delta);
};

