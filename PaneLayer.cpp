#include "PaneLayer.h"

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

return true;
}

