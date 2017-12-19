#include "Counter.h"


enum{
	k_Counter_Action=0
};

Counter *Counter::create(CCArray* presenters,int digit)
{
	CCAssert(digit>=0&&digit<10,"金币数字只能为0至9之间的数字");
	Counter *counter=new Counter;
	if(counter && counter->init(presenters,digit))
	{
		counter->autorelease();
		return counter;
	}
	else
	{

		CC_SAFE_DELETE(counter);
		return NULL;
	}
}

bool Counter::init(CCArray* presenters,int digit)
{
	if(!CCNode::init())
	{
		return false;
	}

	_presenters=CCNode::create();
	CCObject *obj=NULL;
	int i=0;
	
	/*CCARRAY_FOREACH(presenters,obj)
	{
		CCNode *node=(CCNode *) obj;
		_presenters->addChild(node,0,i);
		node->setPosition(ccp(0,node->getContentSize().height*i));
		i++;
	}
	this->addChild(_presenters);
	setDigit(digit);*/

	for(int i=0;i<10;i++)
	{
		
		CCNode *node=(CCNode *)presenters->objectAtIndex(i);
		float height=node->getContentSize().height;
		_presenters->addChild(node,0,i);
		node->setPosition(ccp(0,height*i));
	}
	addChild(_presenters);
	setDigit(digit);
	return true;
}


int Counter::getDigit()
{
	return _digit;
}

void Counter::setDigit(int digit){

if(_digit!=digit){
	_digit=digit;
	animation();
}
}


void Counter::animation()
{
	_presenters->stopActionByTag(k_Counter_Action);
	CCNode *node=(CCNode *)_presenters->getChildByTag(_digit);
	CCPoint position=node->getPosition();
	CCMoveTo *moveTo=CCMoveTo::create(0.3f,ccp(0,-position.y));
	moveTo->setTag(k_Counter_Action);
	_presenters->runAction(moveTo);
}

void Counter::visit()
{
	glEnable(GL_SCISSOR_TEST);
	CCPoint position=getParent()->convertToWorldSpace(getPosition());
	CCSize size =((CCNode *)_presenters->getChildByTag(_digit))->getContentSize();
	glScissor((position.x-size.width/2)*0.4,(position.y-size.height/2)*0.4,size.width*0.4,size.height*0.4);
	CCNode::visit();
	glDisable(GL_SCISSOR_TEST);

}