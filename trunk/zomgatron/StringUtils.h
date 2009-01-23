#ifndef __STRINGUTILS_H__
#define __STRINGUTILS_H__

#include <string>

using namespace std;

class StringUtils{
public:
	static string* SplitString(string toSplit, char splitter, int* num);
	static bool CaselessCompare(string one, string two);
	static string FilenameOnly(string path);
};

#endif
