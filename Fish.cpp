#include "Fish.h"

Fish::Fish(void)
{
}

Fish::~Fish(void)
{
}

float Fish::getPercent()
{
	float percent=0.1;
	switch(_type)
	{
	case 0:
		percent=1.0;
		break;
case 1:
		percent=0.9;
		break;
case 2:
		percent=0.8;
		break;
case 3:
		percent=0.7;
		break;
case 4:
		percent=0.6;
		break;
case 5:
		percent=0.5;
		break;
case 6:
		percent=0.4;
		break;
	default:
		break;


	}
}
Fish* Fish::create(FishType type/* = k_Fish_Type_SmallFish */)
{
	Fish* fish = new Fish;
	if (fish && fish->init(type))
	{
		fish->autorelease();
		return fish;
	}
	else
	{
		CC_SAFE_DELETE(fish);
		return NULL;
	}
}

bool Fish::init(FishType type /* = k_Fish_Type_SmallFish */)
{
	do 
	{
		if (!CCNode::init())
		{
			return false;
		}
		if (type < k_Fish_Type_SmallFish || type >= k_Fish_Type_Count)
		{
			type = k_Fish_Type_SmallFish;
		}
		setType(type);
		//_type = type
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", _type + 1);
		CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
		CC_BREAK_IF(!animation);
		CCAnimate* animate = CCAnimate::create(animation);
		_fishSprite = CCSprite::create();
		addChild(_fishSprite);
		_fishSprite->runAction(CCRepeatForever::create(animate));
		return true;
	} while (0);
	return false;
}

int Fish::getScore(void)
{
	return 0;
}

int Fish::getSpeed(void)
{
	return 200;
}

CCRect Fish::getCollisionArea()
{

		CCSize size = _fishSprite->getContentSize();
	CCPoint pos = getParent()->convertToWorldSpace(getPosition());
	return CCRect(pos.x - size.width / 2, pos.y - size.height/2, size.width, size.height);
}

void Fish::beCaught(){
	//添加NULL
	stopActionByTag(k_Action_MoveTo);
	CCCallFunc* callFunc = CCCallFunc::create(this,callfunc_selector(Fish::beCaught_CallFunc));
	CCSequence* sequence = CCSequence::create(CCDelayTime::create(1.0f),callFunc,NULL);
	//CCBlink* blink = CCBlink::create(1.0f, 8);
	CCSpawn* spawn = CCSpawn::create(sequence,/* blink,*/ NULL);
	_fishSprite->runAction(spawn);
}

void Fish::beCaught_CallFunc()
{
	if(isRunning())
	{
		getParent()->removeChild(this/*,false*/);
	}
}

void Fish::moveTo(CCPoint destination){
	CCPoint point =getParent()->convertToWorldSpace(this->getPosition());
	float duration=ccpDistance(destination,point)/getSpeed();
	CCMoveTo *moveTo=CCMoveTo::create(duration,destination);
	CCCallFunc *callFunc=CCCallFunc::create(this,callfunc_selector(Fish::moveEnd));
	CCSequence *sequence=CCSequence::create(moveTo,callFunc,NULL);
	sequence->setTag(k_Action_MoveTo);
	this->runAction(sequence);


}

void Fish::moveEnd(){
	if(isRunning()){
		getParent()->removeChild(this,true);
	}

}

/*void Fish::reset(){
	setRotation(0);
}*/


CCSize Fish::getSize(){
	return _fishSprite->displayFrame()->getRect().size;

}