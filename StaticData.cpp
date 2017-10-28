#include "StaticData.h"

static StaticData* g_sharedStaticData = NULL;

StaticData* StaticData::sharedStaticData() 
{
	if (g_sharedStaticData == NULL) {
		g_sharedStaticData = new StaticData();
		g_sharedStaticData->init();
	}
	return g_sharedStaticData;
}

void StaticData::purge() 
{
	CC_SAFE_RELEASE_NULL(g_sharedStaticData);
}

int StaticData::intValueFromKey(string key) 
{
	return _dictionary->valueForKey(key)->intValue();
}

const char* StaticData::stringValueFromKey(string key) 
{
	return _dictionary->valueForKey(key)->getCString();
}

float StaticData::floatValueFromKey(string key) 
{
	return _dictionary->valueForKey(key)->floatValue();
}


bool StaticData::booleanFromKey(string key)
{
	return _dictionary->valueForKey(key)->boolValue();
}


CCPoint StaticData::pointFromKey(string key) 
{
	return CCPointFromString(_dictionary->valueForKey(key)->getCString());
}


CCRect StaticData::rectFromKey(string key) 
{
	return CCRectFromString(_dictionary->valueForKey(key)->getCString());
}

CCSize StaticData::sizeFromKey(string key) 
{
	return CCSizeFromString(_dictionary->valueForKey(key)->getCString());
}

bool StaticData::init() 
{

	_dictionary = CCDictionary::createWithContentsOfFile(_staticFileName.c_str());
	_dictionary->retain();

	return true;
}

StaticData::~StaticData() 
{
	CC_SAFE_RELEASE_NULL(_dictionary);
}

StaticData::StaticData()
{
	_staticFileName = STATIC_DATA_FILENAME;
}

