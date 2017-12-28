#include "PaneLayer.h"
#include "GameScene.h"
#include "ScheduleCountDown.h"

PaneLayer::PaneLayer(void){

}

PaneLayer::~PaneLayer(void)
{
}

bool PaneLayer::init()
{
if(!CCLayer::init()){
	return false;
}


_goldCounter=GoldCounterLayer::create(0);
addChild(_goldCounter);
_goldCounter->setPosition(ccp(600,17));

int maxTime=10;
ScheduleCountDown *countDown=ScheduleCountDown::create(this,maxTime,false);
addChild(countDown,0,99);
_scheduleLabel=CCLabelAtlas::create(/*"10","baoshiyu_shuzi_02-ipadhd.png",50,54,'0'*/CCString::createWithFormat("%d",maxTime)->getCString(),"baoshiyu_shuzi_02-ipadhd.png",50,54,'0');

//CCLabelAtlas *label=CCLabelAtlas::create("10","baoshiyu_shuzi_02-ipadhd.png",50,54,'0');
addChild(_scheduleLabel);
_scheduleLabel->setPosition(ccp(100,1200));
return true;
}


 void PaneLayer::scheduleTimeUp(){
	((GameScene *)getParent())->alterGold(200);
	ScheduleCountDown *countDown=(ScheduleCountDown *)getChildByTag(99);
	if(countDown->getLoop()==false)
	{
		_scheduleLabel->setVisible(false);
	}
}
 void PaneLayer::setScheduleNumber(int number){
	// CCLabelAtlas* label=(CCLabelAtlas *)getChildByTag(99);
	 _scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
	}
