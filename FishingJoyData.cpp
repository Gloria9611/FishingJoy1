//#include "cocos2d.h"
#include "FishingJoyData.h"
#include "StaticData.h"
USING_NS_CC;

#define IS_BEGINER "isBeginer"
#define MUSIC "music"
#define SOUND "sound"
#define GOLD "gold"
FishingJoyData::FishingJoyData(/*void*/)
{
    
}
FishingJoyData::~FishingJoyData(/*void*/)
{
    /*this->flush();maybe not*/
}
static FishingJoyData* _sharedFishJoyData=NULL;


void FishingJoyData::purge(){
	CC_SAFE_RELEASE_NULL (_sharedFishJoyData);
}





FishingJoyData* FishingJoyData::getInstance()
{
	if(_sharedFishJoyData==NULL)
	{
		_sharedFishJoyData=new FishingJoyData;
		_sharedFishJoyData->init();
	}
	return _sharedFishJoyData;
}


void FishingJoyData::destoryInstance()
{
	CC_SAFE_DELETE(_sharedFishJoyData);
}

bool FishingJoyData::init()
{
	//���ж��Ƿ��һ����
	_isBeginer=CCUserDefault::sharedUserDefault()->getBoolForKey(IS_BEGINER,true);
	if(_isBeginer){
		//��ǰXML�ļ�Ϊ�ա�������û�����ݵģ����ó�ʼ�����ݲ����浽XML�ļ���
	reset();
	flush();
	
	}

	else{
		CCUserDefault *userDefault=CCUserDefault::sharedUserDefault();
		//setIsBeginer(userDefault->getBoolForKey(IS_BEGINER));
		setIsMusic(userDefault->getBoolForKey(MUSIC));
		setIsSound(userDefault->getBoolForKey(SOUND));
		setGold(userDefault->getIntegerForKey(GOLD));
	
	}

	return true;
}

void FishingJoyData::reset()
{
	this->setIsMusic(true);
	this->setIsSound(true);
	this->setGold(200);
	this->setIsBeginer(false);
}


void FishingJoyData::flush(){

	CCUserDefault *userDefault=CCUserDefault::sharedUserDefault();
	//userDefault->setBoolForkey(IS_BEGINER,getIsBeginer());
	CCUserDefault::sharedUserDefault()->setBoolForKey(IS_BEGINER,getIsBeginer());
	userDefault->setIntegerForKey(GOLD,getGold());
	userDefault->setBoolForKey(MUSIC,getIsMusic());
	userDefault->setBoolForKey(SOUND,getIsSound());
	userDefault->flush();
}

void FishingJoyData::alterGold(int golds)
{

	int num=getGold();
	num+=golds;
	setGold(num);
	flush();
}