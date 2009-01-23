#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

class FileUtils{
public:
	static bool FileExists(std::string filename);
	static void AbsorbEndline(std::ifstream& stream);
};

#endif
