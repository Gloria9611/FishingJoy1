#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"

USING_NS_CC;
class PaneLayer:
public cocos2d::CCLayer
{
public:
	PaneLayer(void);
	~PaneLayer(void);
	virtual bool init();
	CREATE_FUNC(PaneLayer)
		CC_SYNTHESIZE_READONLY(GoldCounterLayer *,_goldCounter,GoldCounter)

protected:
};