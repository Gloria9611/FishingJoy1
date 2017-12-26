#ifndef _STATICDATA_H
#define _STATICDATA_H

#include<string>
#include "cocos2d.h"
using namespace std;
//USING_NS_CC;

#define STATIC_DATA_FILENAME "static_data.plist"
#define STATIC_DATA_STRING(key) StaticData::sharedStaticData()->stringValueFromKey(key)
#define STATIC_DATA_INT(key) StaticData::sharedStaticData()->intValueFromKey(key)
#define STATIC_DATA_FlOAT(key) StaticData::sharedStaticData()->floatValueFromKey(key)
#define STATIC_DATA_BOOL(key) StaticData::sharedStaticData()->booleanFromKey(key)
#define STATIC_DATA_POINT(key) StaticData::sharedStaticData()->pointFromKey(key)
#define STATIC_DATA_RECT(key) StaticData::sharedStaticData()->rectFromKey(key)
#define STATIC_DATA_SIZE(key) StaticData::sharedStaticData()->sizeFromKey(key)


class StaticData:
	public cocos2d::CCObject {
public:

	static StaticData* sharedStaticData();
	const char* stringValueFromKey(const string& key);
	void purge();
	int intValueFromKey(string& key);
	StaticData *getInstance();
	float floatValueFromKey(string& key);
	bool booleanFromKey(string& key);
	cocos2d::CCPoint pointFromKey(const string& key);
	cocos2d::CCRect rectFromKey(const string& key);
	cocos2d::CCSize sizeFromKey(const string& key);
	//CC_SYNTHESIZE_READONLY(std::string, _staticDataPath, StaticDataPath);
protected:
	cocos2d::CCDictionary* _dictionary;
	//string _staticFileName;
	
private:
	~StaticData();
	StaticData();
	bool init();
};

#endif  //_STATICDATA_H
