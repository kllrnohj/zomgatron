#include "TransportationObject.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "StringUtils.h"
#include "FileUtils.h"
#include "EncryptionUtils.h"
using namespace std;

TransportationObject::TransportationObject(void* mesh, void* material, void* texture, int numPieces): DrawnObject(mesh, material, texture, numPieces){
	TransportationObject::allTransportationObjects.push_back(this);
}

void WriteBufEncrypted(ofstream& ofile, string toWrite){
	short len, elen;
	len = toWrite.length();
	char* buf = new char[len+1];
	ZeroMemory(buf, len+1);
	memcpy(buf, toWrite.c_str(), len);
	elen = EncryptionUtils::GetEncryptDecryptShort(len);
	EncryptionUtils::EncryptBuf(buf, len);
	ofile << elen << buf << endl;
	delete [] buf;
}
void ReadBufEncrypted(ifstream& ifile, string& result){
	short len;
	ifile >> len;
	EncryptionUtils::EncryptDecryptShort(len);
	char* buf = new char[len+1];
	ZeroMemory(buf, len+1);
	ifile.read(buf, len);
	EncryptionUtils::DecryptBuf(buf, len);
	result = string(buf);
	delete [] buf;
}

TransportationObject* TransportationObject::FromFile(std::string filename){
	ifstream ifile(filename.c_str(), ios::in|ios::binary);
	string meshname;
	string destinationName;
	string destinationAnchor;
	string desc;
	ReadBufEncrypted(ifile, meshname);
	FileUtils::AbsorbEndline(ifile);
	ReadBufEncrypted(ifile, desc);
	FileUtils::AbsorbEndline(ifile);
	ReadBufEncrypted(ifile, destinationName);
	FileUtils::AbsorbEndline(ifile);
	ReadBufEncrypted(ifile, destinationAnchor);
	ifile.close();

	void* mesh;
	void* material;
	void* texture;
	int numMaterials;
	mesh = EngineStatics::Engine->LoadMeshFromFile(meshname.c_str(), &material, &texture, &numMaterials);

	TransportationObject* to = new TransportationObject(mesh, material, texture, numMaterials);
	to->desc = desc;
	to->destination = destinationName;
	to->destinationAnchor = destinationAnchor;
	to->name = StringUtils::FilenameOnly(filename);

	return to;
}

void TransportationObject::CompileTransportationObject(std::string uncompiledfilename){
	string meshname;
	string destinationName;
	string destinationAnchor;
	string desc;
	ifstream ifile(uncompiledfilename.c_str(), ios::in);
	getline(ifile, meshname);
	getline(ifile, desc);
	getline(ifile, destinationName);
	getline(ifile, destinationAnchor);
	string filename = "Data/X/";
	filename += meshname;
	filename += "/";
	filename += meshname;
	filename += ".x";
	meshname = filename;
	ifile.close();
	string fname = StringUtils::FilenameOnly(uncompiledfilename);
	string cfname = TOS_DIR;
	cfname += fname;
	cfname += COMPILEDTOEXT;
	ofstream ofile(cfname.c_str(), ios::out|ios::binary);
	WriteBufEncrypted(ofile, meshname);
	WriteBufEncrypted(ofile, desc);
	WriteBufEncrypted(ofile, destinationName);
	WriteBufEncrypted(ofile, destinationAnchor);
	ofile.close();
}

std::vector<TransportationObject*> TransportationObject::allTransportationObjects;

TransportationObject* TransportationObject::GetTransportationObject(std::string name){
	if(name == "NULL")
		return NULL;
	for(int x = 0; x < TransportationObject::allTransportationObjects.size(); x++){
		if(allTransportationObjects.at(x)->GetName() == name)
			return allTransportationObjects.at(x);
	}

	// got here means they requested one that's not in memory, I guess we should load it...
	string newFilename(TOS_DIR);
	newFilename += name;
	newFilename += COMPILEDTOEXT;
	if(FileUtils::FileExists(newFilename)){
		// it exists, load it
		return TransportationObject::FromFile(newFilename);
	}else{
		string newFilename2(UNCOMPILEDTOS_DIR);
		newFilename2 += name;
		newFilename2 += UNCOMPILEDTOEXT;
		if(FileUtils::FileExists(newFilename2)){
			CompileTransportationObject(newFilename2);
			return TransportationObject::FromFile(newFilename);
		}
	}

	// got here means the file didn't exist, so that conversation simply doesn't exist
	return NULL;
}
