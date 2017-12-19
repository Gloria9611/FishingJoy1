#include "GoldCounterLayer.h"
#include "Counter.h"
#include "StaticData.h"
#define NUM_COUNTER 7
GoldCounterLayer *GoldCounterLayer::create(int number)
{
	GoldCounterLayer *gold=new GoldCounterLayer;
	if(gold && gold->init(number)){
		gold->autorelease();
		return gold;

	}
	else
	{
		CC_SAFE_DELETE(gold);
		return NULL;

	}
}



bool GoldCounterLayer::init(int number)
{
	if(!CCNode::init()){

		return false;
	}
	for(int i=0;i<NUM_COUNTER;i++)
	{
		CCArray *array=CCArray::createWithCapacity(10);
		CCTexture2D *texture=CCTextureCache::sharedTextureCache()->addImage("ui_text_01-ipadhd.png");
		CCSize textureSize=texture->getContentSize();
		for(int j=0;j<10;j++){
			CCSprite *sprite=CCSprite::createWithTexture(texture,CCRect(textureSize.width/10*j,0,textureSize.width/10,textureSize.height));
			array->addObject(sprite);
		}
		CCSize digitSize;
		Counter *counter=Counter::create(array);
		addChild(counter,0,i);
		counter->setPosition(ccp(digitSize.width/10*i,0));

	}
	setNumber(number);
	return true;
}


void GoldCounterLayer::setNumber(int number,int ceiling){

	if(number>ceiling){
		number=ceiling;
	}

	if(number<0){
		number=0;
	}

	for(int i=NUM_COUNTER-1;i>=0;i--){
		Counter *counter=(Counter *)getChildByTag(i);
		counter->setDigit(number%10);
		number/=10;
	}
}