#ifndef _FISH_JOY_DATA_H_
#define _FISH_JOY_DATA_H_

#include "cocos2d.h"
USING_NS_CC;
class FishingJoyData:public cocos2d::CCObject{
public :
	static FishingJoyData* sharedFishJoyData();
	static FishingJoyData* getInstance();
	static void destoryInstance();
	void reset();

	//将内存中的数值保存到文件中
	void flush();
	CC_SYNTHESIZE(bool,_isBeginer,IsBeginer)
    CC_SYNTHESIZE(int,_gold,Gold)
	CC_SYNTHESIZE(bool,_isMusic,IsMusic)
	CC_SYNTHESIZE(bool,_isSound,IsSound)

	void alterGold(int golds);
	void purge();

protected:
	 FishingJoyData();
    ~FishingJoyData();
	bool init();
};
#endif