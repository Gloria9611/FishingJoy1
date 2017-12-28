#ifndef PERSONALAUDIOENGINE_H
#define PERSONALAUDIOENGINE_H
#include "SimpleAudioEngine.h"
//#include "cocos2d.h"
//using namespace cocos2d;


typedef enum{
	kEffectSwichCannon=0,
	kEffectShoot,
		kEffectFishNet,
		kEffectCoins
}EffectType;

class PersonalAudioEngine:public CocosDenshion::SimpleAudioEngine
{
public :
	static PersonalAudioEngine *getInstance();
	static void destoryIntance();
	void playBackgroundMusic(int type);
	void playEffect(EffectType type);
	//PersonalAudioEngine* sharedEngine();
protected:
	bool init();
	PersonalAudioEngine();
	~PersonalAudioEngine();
	PersonalAudioEngine(const PersonalAudioEngine& engine);
private:


};
#endif