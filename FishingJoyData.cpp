#include "FishingJoyData.h"





void FishJoy::Flush(){

	CCUserDefault *userDefault=CCUserDefault::sharedUserDefault();
	userDefault->setBoolForkey(IS_BEGINER,getIsBeginer());
}