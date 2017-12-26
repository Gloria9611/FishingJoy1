#pragma once
#include "cocos2d.h"
#include "StaticData.h"
#include "Fish.h"
USING_NS_CC;

#define FISH_MAX_COUNT 50

class FishLayer :
	public CCLayer
{
public:
	FishLayer();
	CREATE_FUNC(FishLayer)
	virtual bool init();
	virtual ~FishLayer(void);
	CC_SYNTHESIZE_READONLY(CCArray*,_fishes,Fishes)
	CCArray* getFishes()
	{
		return _fishes;
	}
protected:
	//CCArray* _fishes;
	void addFish(float delta);
	void resetFish(Fish* fish);
};
