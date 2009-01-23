#include "FileUtils.h"
using namespace std;

bool FileUtils::FileExists(std::string filename){
	ifstream ifs(filename.c_str(), ios::in);
	ifs.close();
	if(ifs.fail()){
		ifs.clear(ios::failbit);
		return false;
	}
	return true;
}
void FileUtils::AbsorbEndline(ifstream& stream){
	// absorb endline
	char dump;
	do{
		dump = stream.peek();
		if(dump == '\n' || dump == '\r')
			stream.read(&dump, 1);
		else
			break;
	}while(true);
}
