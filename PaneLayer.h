#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;
class PaneLayer:
public cocos2d::CCLayer,public ScheduleCounterDelegate
{
public:
	PaneLayer(void);
	~PaneLayer(void);
	virtual bool init();
	CREATE_FUNC(PaneLayer)
		CC_SYNTHESIZE_READONLY(GoldCounterLayer *,_goldCounter,GoldCounter)

protected:
	virtual void scheduleTimeUp();
	virtual void setScheduleNumber(int number);
	CCLabelAtlas *_scheduleLabel;
};