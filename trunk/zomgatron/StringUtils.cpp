#include "StringUtils.h"

string* StringUtils::SplitString(string toSplit, char splitter, int* num){
	int words = 0;
	int chars = 0;
	string::const_iterator it = toSplit.begin();
	while(it != toSplit.end()){
		if(*it == splitter){
			if(chars > 0)
				++words;
			chars = 0;
		}else{
			++chars;
		}
		++it;
	}
	if(chars > 0)
		++words;

	string* results = new string[words];
	for(int i = 0; i < words; i++){
		results[i] = "";
	}
	chars = 0;
	int current = 0;
	it = toSplit.begin();
	while(it != toSplit.end()){
		if(*it == splitter){
			if(chars > 0){
				++current;
			}
			chars = 0;
		}else{
			++chars;
			results[current] += *it;
		}
		++it;
	}

	if(num)
		*num = words;
	return results;
}
bool StringUtils::CaselessCompare(string one, string two){
	string::const_iterator it1=one.begin();
	string::const_iterator it2=two.begin();

	//stop when either string's end has been reached
	while ( (it1!=one.end()) && (it2!=two.end()) ) 
	{ 
		if(toupper(*it1) != toupper(*it2)) //letters differ?
			return false;
		//proceed to the next character in each string
		++it1;
		++it2;
	}
	size_t size1=one.size(), size2=two.size();// cache lengths
    return size1 == size2;
}

string StringUtils::FilenameOnly(string path){
	short startIndex = path.rfind("/");
	short sec = path.rfind("\\");

	if(startIndex == path.npos)
		startIndex = -1; // will go to 0
	if(sec == path.npos)
		sec = -1;

	if(sec > startIndex)
		startIndex = sec;

	++startIndex;

	int endIndex = path.rfind(".");
	return path.substr(startIndex, endIndex-startIndex);
}