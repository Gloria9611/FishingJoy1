#ifndef _GOLDCOUNTERLAYER_H
#define _GOLDCOUNTERLAYER_H
#include "cocos2d.h"
USING_NS_CC;
class GoldCounterLayer:public CCNode
{
public :static GoldCounterLayer* create(int number);
		void setNumber(int number,int ceiling=9999999);
protected:
	bool init(int number);
	int _number;
private:


};
#endif