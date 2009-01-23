#include "Location.h"
#include "StringUtils.h"
#include "EncryptionUtils.h"
#include "FileUtils.h"
#include "TransportationObject.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Location* Location::currentLocation;

string GetOneString(string set){
	return set.substr(1, set.length()-2);
}

Vector4 GetFourNumbers(string set, char split = ','){
	string real = set.substr(1, set.length()-2); // get the values only
	int num;
	string* pieces = StringUtils::SplitString(real, split, &num);
	if(num != 4){
		delete [] pieces;
		throw "Tried to get 4 numbers from something wrong!";
	}
	Vector4 result;
	result.x = (float)atof(pieces[0].c_str());
	result.y = (float)atof(pieces[1].c_str());
	result.z = (float)atof(pieces[2].c_str());
	result.w = (float)atof(pieces[3].c_str());

	delete [] pieces;

	return result;
}

Vector3 GetThreeNumbers(string set, char split = ','){
	string real = set.substr(1, set.length()-2); // get the values only
	int num;
	string* pieces = StringUtils::SplitString(real, split, &num);
	if(num != 3){
		delete [] pieces;
		throw "Tried to get 3 numbers from something wrong!";
	}
	Vector3 result;
	result.x = (float)atof(pieces[0].c_str());
	result.y = (float)atof(pieces[1].c_str());
	result.z = (float)atof(pieces[2].c_str());

	delete [] pieces;

	return result;
}

Vector2 GetTwoNumbers(string set, char split = ','){
	string real = set.substr(1, set.length()-2); // get the values only
	int num;
	string* pieces = StringUtils::SplitString(real, split, &num);
	if(num != 2){
		delete [] pieces;
		throw "Tried to get 2 numbers from something wrong!";
	}
	Vector2 result;
	result.x = (float)atof(pieces[0].c_str());
	result.y = (float)atof(pieces[1].c_str());

	delete [] pieces;

	return result;
}

Point2 GetTwoInts(string set, char split = ','){
	string real = set.substr(1, set.length()-2); // get the values only
	int num;
	string* pieces = StringUtils::SplitString(real, split, &num);
	if(num != 2){
		delete [] pieces;
		throw "Tried to get 2 ints from something wrong!";
	}
	Point2 result;
	result.a = atoi(pieces[0].c_str());
	result.b = atoi(pieces[1].c_str());

	delete [] pieces;

	return result;
}

Point3 GetThreeInts(string set, char split = ','){
	string real = set.substr(1, set.length()-2); // get the values only
	int num;
	string* pieces = StringUtils::SplitString(real, split, &num);
	if(num != 3){
		delete [] pieces;
		throw "Tried to get 3 ints from something wrong!";
	}
	Point3 result;
	result.a = atoi(pieces[0].c_str());
	result.b = atoi(pieces[1].c_str());
	result.c = atoi(pieces[2].c_str());

	delete [] pieces;

	return result;
}

FOURINTS GetFourInts(string set, char split = ','){
	string real = set.substr(1, set.length()-2); // get the values only
	int num;
	string* pieces = StringUtils::SplitString(real, split, &num);
	if(num != 4){
		delete [] pieces;
		throw "Tried to get 4 ints from something wrong!";
	}
	FOURINTS result;
	result.a = atoi(pieces[0].c_str());
	result.b = atoi(pieces[1].c_str());
	result.c = atoi(pieces[2].c_str());
	result.d = atoi(pieces[3].c_str());

	delete [] pieces;

	return result;
}

void AddPlaneFromULine(string line, LocationPieces* pieces){
	int num;
	string* splits = StringUtils::SplitString(line, ';', &num);
	// position, direction, sizexz, cutsandslices, color
	// all required... so...
	if(num != 5){
		delete [] splits;
		throw "Tried to compile invalid Plane!";
	}
	Vector3 position = GetThreeNumbers(splits[0]);
	Vector3 direction = GetThreeNumbers(splits[1]);
	Vector2 sizes = GetTwoNumbers(splits[2]);
	Point2 cutsandslices = GetTwoInts(splits[3]);
	FOURINTS color = GetFourInts(splits[4]);

	VBufObject* plane = new VBufObject(sizes.x, sizes.y, cutsandslices.a, cutsandslices.b, D3DCOLOR_ARGB(color.d, color.a, color.b, color.c));
	plane->SetPosition(position);
	plane->LookAt(position + direction);

	pieces->vertexObjects.push_back(plane);

	delete [] splits;
}
void AddCharacterFromULine(string line, LocationPieces* pieces){
	int num;
	string* splits = StringUtils::SplitString(line, ';', &num);
	// name position direction
	if(num != 3){
		delete [] splits;
		throw "Character from line found invalid line!";
	}
	string name = GetOneString(splits[0]);
	Character* result = Character::GetCharacter(name);
	result->SetPosition(GetThreeNumbers(splits[1]));
	result->LookAt(result->GetPosition() + GetThreeNumbers(splits[2]));

	pieces->worldObjects.push_back(result);

	delete [] splits;
}
void AddLightFromULine(string line, LocationPieces* pieces){
	int num;
	string* splits = StringUtils::SplitString(line, ';', &num);

	string name = GetOneString(splits[0]);
	LIGHTTYPE type;
	//check name vs how many it needs
	if(StringUtils::CaselessCompare(name, "point")){
		type = LTPOINT;
		if(num != 5){
			delete [] splits;
			throw "Light from line found invalid line!";
		}
	}else if(StringUtils::CaselessCompare(name, "spot")){
		type = LTSPOT;
		if(num != 6){
			delete [] splits;
			throw "Light from line found invalid line!";
		}
	}else if(StringUtils::CaselessCompare(name, "directional")){
		type = LTDIRECTIONAL;
		if(num != 5){
			delete [] splits;
			throw "Light from line found invalid line!";
		}
	}else{
		delete [] splits;
		throw "Light from line found invalid line! (Invalid light type)";
	}

	Vector4 d = GetFourNumbers(splits[1]);
	Vector4 s = GetFourNumbers(splits[2]);
	int r = (int)(d.x * 255.0f);
	int g = (int)(d.y * 255.0f);
	int b = (int)(d.z * 255.0f);
	int a = (int)(d.w * 255.0f);
	DWORD diffuse = COLORARGB(a,r,g,b);
	DWORD specular = COLORARGB(((int)(s.w*255)), ((int)(s.x*255)), ((int)(s.y*255)), ((int)(s.z*255)));
	Vector4 rangea0a1a2 = GetFourNumbers(splits[3]);
	Vector3 position, direction;
	if(type == LTPOINT){
		position = GetThreeNumbers(splits[4]);

		Light* l = new Light(type, diffuse, specular, rangea0a1a2.x, rangea0a1a2.y, rangea0a1a2.z, rangea0a1a2.w);
		l->SetPosition(position);
		pieces->lightObjects.push_back(l);
	}else if(type == LTDIRECTIONAL){
		direction = GetThreeNumbers(splits[4]);

		Light* l = new Light(type, diffuse, specular, rangea0a1a2.x, rangea0a1a2.y, rangea0a1a2.z, rangea0a1a2.w);
		l->SetPosition(Vector3(0, 0, 0));
		l->LookAt(direction);
		pieces->lightObjects.push_back(l);
	}else{
		position = GetThreeNumbers(splits[4]);
		direction = GetThreeNumbers(splits[5]);

		Light* l = new Light(type, diffuse, specular, rangea0a1a2.x, rangea0a1a2.y, rangea0a1a2.z, rangea0a1a2.w);

		l->SetPosition(position);
		l->LookAt(position + direction);
		pieces->lightObjects.push_back(l);
	}

	delete [] splits;
}

void AddAnchorFromULine(string line, LocationPieces* pieces){
	int num;
	string* splits = StringUtils::SplitString(line, ';', &num);
	if(num != 3){
		delete [] splits;
		throw "Received invalid anchor ULine.";
	}
	Anchor* a = new Anchor();
	a->anchorName = GetOneString(splits[0]);
	a->position = GetThreeNumbers(splits[1]);
	a->direction = GetThreeNumbers(splits[2]);

	pieces->anchors.push_back(a);

	delete [] splits;
}

void AddTOFromULine(string line, LocationPieces* pieces){
	int num;
	string* splits = StringUtils::SplitString(line, ';', &num);
	if(num != 3){
		delete [] splits;
		throw "Received broken Transportation object line.";
	}
	TransportationObject* to = TransportationObject::GetTransportationObject(GetOneString(splits[0]));
	if(!to)
		throw "Could not find Transportation object.";
	Vector3 pos, dir;
	pos = GetThreeNumbers(splits[1]);
	dir = GetThreeNumbers(splits[2]);
	to->SetPosition(pos);
	to->LookAt(pos + dir);
	pieces->worldObjects.push_back(to);
}

void FindAndDoOperation(string line, LocationPieces* pieces){
	if(line.length() > 0 && line[0] == '#')
		return;
	int num;
	string* splits = StringUtils::SplitString(line, ':', &num);
	if(num != 2){
		delete [] splits;
		throw "Find and Do Operation found invalid line!";
	}
	if(StringUtils::CaselessCompare(splits[0], "plane")){
		AddPlaneFromULine(splits[1], pieces);
	}else if(StringUtils::CaselessCompare(splits[0], "character")){
		AddCharacterFromULine(splits[1], pieces);
	}else if(StringUtils::CaselessCompare(splits[0], "light")){
		AddLightFromULine(splits[1], pieces);
	}else if(StringUtils::CaselessCompare(splits[0], "anchor")){
		AddAnchorFromULine(splits[1], pieces);
	}else if(StringUtils::CaselessCompare(splits[0], "TransportationObject")){
		AddTOFromULine(splits[1], pieces);
	}else{
		throw "Invalid line for find and do!";
	}

	delete [] splits;
}

Location::Location(){
	allLocations.push_back(this);
}

std::vector<Location*> Location::allLocations;
void Location::CompileLocation(std::string uncompiledfilename){
	ifstream ifile(uncompiledfilename.c_str(), ios::in);
	LocationPieces pieces;
	getline(ifile, pieces.name);
	getline(ifile, pieces.desc);
	string startPos;
	getline(ifile, startPos);
	int num;
	string* startPoses = StringUtils::SplitString(startPos, ':', &num);
	if(num != 2){
		delete [] startPoses;
		throw "Start poses was an invalid line!";
	}
	string* startPosDir = StringUtils::SplitString(startPoses[1], ';', NULL);
	pieces.startPosition = GetThreeNumbers(startPosDir[0]);
	pieces.startDirection = GetThreeNumbers(startPosDir[1]);
	delete [] startPoses;
	string temp;
	while(!ifile.eof()){
		getline(ifile, temp);
		FindAndDoOperation(temp, &pieces);
	}

	ifile.close();

	// well now I have everything out of the uncompiled version.... now to build a compiled version :(
	string filenameonly = StringUtils::FilenameOnly(uncompiledfilename);
	string path = LOCATIONS_DIR;
	path += filenameonly;
	path += COMPILEDLOCATIONEXT;
	ofstream ofile(path.c_str(), ios::out|ios::binary);


	short len = pieces.name.length();
	char* buf = new char[len + 1];
	ZeroMemory(buf, len + 1);
	memcpy(buf, pieces.name.c_str(), len);
	EncryptionUtils::EncryptBuf(buf, len);
	short elen = len;
	EncryptionUtils::EncryptDecryptShort(elen);

	ofile << elen << buf << endl;

	delete [] buf;

	len = pieces.desc.length();
	buf = new char[len + 1];
	ZeroMemory(buf, len + 1);
	memcpy(buf, pieces.desc.c_str(), len);
	EncryptionUtils::EncryptBuf(buf, len);
	elen = len;
	EncryptionUtils::EncryptDecryptShort(elen);

	ofile << elen << buf << endl;

	delete [] buf;

	ofile << EncryptionUtils::GetEncryptedFloat(pieces.startPosition.x) << " " << EncryptionUtils::GetEncryptedFloat(pieces.startPosition.y) << " " << EncryptionUtils::GetEncryptedFloat(pieces.startPosition.z) << endl;
	ofile << EncryptionUtils::GetEncryptedFloat(pieces.startDirection.x) << " " << EncryptionUtils::GetEncryptedFloat(pieces.startDirection.y) << " " << EncryptionUtils::GetEncryptedFloat(pieces.startDirection.z) << endl;

	for(unsigned int x = 0; x < pieces.anchors.size(); x++){
		ofile << EncryptionUtils::GetEncryptDecryptShort(ANCHOR) << " ";
		short len, elen;
		len = pieces.anchors.at(x)->anchorName.length();
		char* abuf = new char[len+1];
		ZeroMemory(abuf, len+1);
		memcpy(abuf, pieces.anchors.at(x)->anchorName.c_str(), len);
		elen = len;
		EncryptionUtils::EncryptBuf(abuf, len);
		EncryptionUtils::EncryptDecryptShort(elen);
		ofile << elen << abuf << " ";
		delete [] abuf;
		// write position then direction
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.anchors.at(x)->position.x) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.anchors.at(x)->position.y) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.anchors.at(x)->position.z) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.anchors.at(x)->direction.x) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.anchors.at(x)->direction.y) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.anchors.at(x)->direction.z) << endl;

		delete pieces.anchors.at(x);
	}
	for(unsigned int x = 0; x < pieces.lightObjects.size(); x++){
		ofile << EncryptionUtils::GetEncryptDecryptShort(LIGHT) << " "; // write type
		ofile << EncryptionUtils::GetEncryptDecryptUL(pieces.lightObjects.at(x)->GetType()) << " ";
		ofile << EncryptionUtils::GetEncryptDecryptUL(pieces.lightObjects.at(x)->GetDiffuse()) << " ";
		ofile << EncryptionUtils::GetEncryptDecryptUL(pieces.lightObjects.at(x)->GetSpecular()) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetRange()) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetAtten0()) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetAtten1()) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetAtten2()) << " ";
		if(pieces.lightObjects.at(x)->GetType() == LTPOINT){
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetPosition().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetPosition().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetPosition().z) << endl;
		}else if(pieces.lightObjects.at(x)->GetType() == LTDIRECTIONAL){
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetForward().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetForward().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetForward().z) << endl;
		}else if(pieces.lightObjects.at(x)->GetType() == LTSPOT){
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetPosition().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetPosition().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetPosition().z) << " ";

			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetForward().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetForward().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.lightObjects.at(x)->GetForward().z) << endl;
		}else{
			throw "Got unrecognized light in uncompiled file";
		}

		delete pieces.lightObjects.at(x);
	}
	for(unsigned int x = 0; x < pieces.vertexObjects.size(); x++){
		ofile << EncryptionUtils::GetEncryptDecryptShort(PLANE) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetPosition().x) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetPosition().y) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetPosition().z) << " ";

		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetForward().x) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetForward().y) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetForward().z) << " ";

		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetWidth()) << " ";
		ofile << EncryptionUtils::GetEncryptedFloat(pieces.vertexObjects.at(x)->GetDepth()) << " ";

		ofile << EncryptionUtils::GetEncryptDecryptUI(pieces.vertexObjects.at(x)->GetRows()) << " ";
		ofile << EncryptionUtils::GetEncryptDecryptUI(pieces.vertexObjects.at(x)->GetColumns()) << " ";

		ofile << EncryptionUtils::GetEncryptDecryptUL(pieces.vertexObjects.at(x)->GetColor()) << endl;

		delete pieces.vertexObjects.at(x);
	}
	for(unsigned int x = 0; x < pieces.worldObjects.size(); x++){
		if(pieces.worldObjects.at(x)->isCharacter()){
			ofile << EncryptionUtils::GetEncryptDecryptShort(CHARACTER) << " ";

			short clen, eclen;
			string name = ((Character*)pieces.worldObjects.at(x))->getID();
			clen = name.length();
			eclen = EncryptionUtils::GetEncryptDecryptShort(clen);
			char* buf = new char[clen+1];
			ZeroMemory(buf, clen+1);
			memcpy(buf, name.c_str(), clen);
			EncryptionUtils::EncryptBuf(buf, clen);
			ofile << eclen << buf << endl;
			delete [] buf;

			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetPosition().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetPosition().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetPosition().z) << " ";

			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetForward().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetForward().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetForward().z) << endl;

			// since there is a manager for these we don't delete them, unlike the lights and VBufObjects.
		}else{
			// we assume it's a transportation object...
			ofile << EncryptionUtils::GetEncryptDecryptShort(TRANSPORTATIONOBJECT) << " ";

			short clen, eclen;
			string name = ((TransportationObject*)pieces.worldObjects.at(x))->GetName();
			clen = name.length();
			eclen = EncryptionUtils::GetEncryptDecryptShort(clen);
			char* buf = new char[clen+1];
			ZeroMemory(buf, clen+1);
			memcpy(buf, name.c_str(), clen);
			EncryptionUtils::EncryptBuf(buf, clen);
			ofile << eclen << buf << endl;
			delete [] buf;

			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetPosition().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetPosition().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetPosition().z) << " ";

			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetForward().x) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetForward().y) << " ";
			ofile << EncryptionUtils::GetEncryptedFloat(pieces.worldObjects.at(x)->GetForward().z) << endl;

			// since there is a manager for these we don't delete them, unlike the lights and VBufObjects.
		}
	}

	ofile.close();
}
Location* Location::FromFile(std::string compiledfilename){
	Location* result = new Location();
	ifstream ifile(compiledfilename.c_str(), ios::in|ios::binary);

	short elen;
	ifile >> elen;
	short len = EncryptionUtils::GetEncryptDecryptShort(elen);
	char* buf = new char[len+1];
	ZeroMemory(buf, len+1);
	ifile.read(buf, len);
	EncryptionUtils::DecryptBuf(buf, len);
	result->name = string(buf);
	delete [] buf;
	FileUtils::AbsorbEndline(ifile);

	ifile >> elen;
	len = EncryptionUtils::GetEncryptDecryptShort(elen);
	buf = new char[len+1];
	ZeroMemory(buf, len+1);
	ifile.read(buf, len);
	EncryptionUtils::DecryptBuf(buf, len);
	result->desc = string(buf);
	delete [] buf;
	FileUtils::AbsorbEndline(ifile);

	int itempa, itempb, itempc, itempd;
	ifile >> itempa >> itempb >> itempc;
	result->startPosition.x = EncryptionUtils::GetDecryptedFloat(itempa);
	result->startPosition.y = EncryptionUtils::GetDecryptedFloat(itempb);
	result->startPosition.z = EncryptionUtils::GetDecryptedFloat(itempc);
	FileUtils::AbsorbEndline(ifile);
	ifile >> itempa >> itempb >> itempc;
	result->startDirection.x = EncryptionUtils::GetDecryptedFloat(itempa);
	result->startDirection.y = EncryptionUtils::GetDecryptedFloat(itempb);
	result->startDirection.z = EncryptionUtils::GetDecryptedFloat(itempc);
	FileUtils::AbsorbEndline(ifile);

	string temp;
	while(!ifile.eof()){
		OBJECT_TYPE type;
		short stemp;
		ifile >> stemp;
		type = (OBJECT_TYPE)EncryptionUtils::GetEncryptDecryptShort(stemp);

		if(type == LIGHT){
			LIGHTTYPE ltype;
			DWORD dtemp;
			ifile >> dtemp;
			ltype = (LIGHTTYPE)EncryptionUtils::GetEncryptDecryptUL(dtemp);
			DWORD ldiffuse, lspecular;
			float range, atten0, atten1, atten2;
			//ifile >> itempa >> itempb >> itempc >> itempd;
			ifile >> ldiffuse >> lspecular;
			ldiffuse = EncryptionUtils::GetEncryptDecryptUL(ldiffuse);
			lspecular = EncryptionUtils::GetEncryptDecryptUL(lspecular);
			/*ldiffuse.r = EncryptionUtils::GetDecryptedFloat(itempa);
			ldiffuse.g = EncryptionUtils::GetDecryptedFloat(itempb);
			ldiffuse.b = EncryptionUtils::GetDecryptedFloat(itempc);
			ldiffuse.a = EncryptionUtils::GetDecryptedFloat(itempd);*/
			//FileUtils::AbsorbEndline(ifile);
			//ifile >> itempa >> itempb >> itempc >> itempd;
			/*lspecular.r = EncryptionUtils::GetDecryptedFloat(itempa);
			lspecular.g = EncryptionUtils::GetDecryptedFloat(itempb);
			lspecular.b = EncryptionUtils::GetDecryptedFloat(itempc);
			lspecular.a = EncryptionUtils::GetDecryptedFloat(itempd);*/
			//FileUtils::AbsorbEndline(ifile);
			ifile >> itempa >> itempb >> itempc >> itempd;
			range = EncryptionUtils::GetDecryptedFloat(itempa);
			atten0 = EncryptionUtils::GetDecryptedFloat(itempb);
			atten1 = EncryptionUtils::GetDecryptedFloat(itempc);
			atten2 = EncryptionUtils::GetDecryptedFloat(itempd);
			//FileUtils::AbsorbEndline(ifile);
			// pos/dir
			if(ltype == LTSPOT){
				Vector3 pos, dir;
				ifile >> itempa >> itempb >> itempc;
				pos.x = EncryptionUtils::GetDecryptedFloat(itempa);
				pos.y = EncryptionUtils::GetDecryptedFloat(itempb);
				pos.z = EncryptionUtils::GetDecryptedFloat(itempc);
				ifile >> itempa >> itempb >> itempc;
				dir.x = EncryptionUtils::GetDecryptedFloat(itempa);
				dir.y = EncryptionUtils::GetDecryptedFloat(itempb);
				dir.z = EncryptionUtils::GetDecryptedFloat(itempc);

				Light* newLight = new Light(ltype, ldiffuse, lspecular, range, atten0, atten1, atten2);
				newLight->SetPosition(pos);
				newLight->LookAt(pos + dir);

				result->lightObjects.push_back(newLight);
			}else if(ltype == LTDIRECTIONAL){
				Vector3 dir;
				ifile >> itempa >> itempb >> itempc;
				dir.x = EncryptionUtils::GetDecryptedFloat(itempa);
				dir.y = EncryptionUtils::GetDecryptedFloat(itempb);
				dir.z = EncryptionUtils::GetDecryptedFloat(itempc);

				Light* newLight = new Light(ltype, ldiffuse, lspecular, range, atten0, atten1, atten2);
				Vector3 pos(0, 0, 0);
				newLight->SetPosition(pos);
				newLight->LookAt(pos + dir);

				result->lightObjects.push_back(newLight);
			}else if(ltype == LTPOINT){
				Vector3 pos;
				ifile >> itempa >> itempb >> itempc;
				pos.x = EncryptionUtils::GetDecryptedFloat(itempa);
				pos.y = EncryptionUtils::GetDecryptedFloat(itempb);
				pos.z = EncryptionUtils::GetDecryptedFloat(itempc);

				Light* newLight = new Light(ltype, ldiffuse, lspecular, range, atten0, atten1, atten2);
				newLight->SetPosition(pos);

				result->lightObjects.push_back(newLight);
			}else{
				throw "Got unrecognized light type in compiled location";
			}
		}else if(type == TRANSPORTATIONOBJECT){
			string name;
			short namelen;
			ifile >> namelen;
			EncryptionUtils::EncryptDecryptShort(namelen);
			char* buf = new char[namelen + 1];
			ZeroMemory(buf, namelen+1);
			ifile.read(buf, namelen);
			EncryptionUtils::DecryptBuf(buf, namelen);
			name = string(buf);
			delete [] buf;
			Vector3 pos, dir;

			ifile >> itempa >> itempb >> itempc;
			pos.x = EncryptionUtils::GetDecryptedFloat(itempa);
			pos.y = EncryptionUtils::GetDecryptedFloat(itempb);
			pos.z = EncryptionUtils::GetDecryptedFloat(itempc);
			ifile >> itempa >> itempb >> itempc;
			dir.x = EncryptionUtils::GetDecryptedFloat(itempa);
			dir.y = EncryptionUtils::GetDecryptedFloat(itempb);
			dir.z = EncryptionUtils::GetDecryptedFloat(itempc);

			TransportationObject* newTO = TransportationObject::GetTransportationObject(name);
			newTO->SetPosition(pos);
			newTO->LookAt(pos + dir);

			result->worldObjects.push_back(newTO);
		}else if(type == CHARACTER){
			// currently this won't work if the name has spaces, etc, but they shouldn't methinks.
			string name;
			short namelen;
			ifile >> namelen;
			EncryptionUtils::EncryptDecryptShort(namelen);
			char* buf = new char[namelen + 1];
			ZeroMemory(buf, namelen+1);
			ifile.read(buf, namelen);
			EncryptionUtils::DecryptBuf(buf, namelen);
			name = string(buf);
			delete [] buf;
			Vector3 pos, dir;

			ifile >> itempa >> itempb >> itempc;
			pos.x = EncryptionUtils::GetDecryptedFloat(itempa);
			pos.y = EncryptionUtils::GetDecryptedFloat(itempb);
			pos.z = EncryptionUtils::GetDecryptedFloat(itempc);
			ifile >> itempa >> itempb >> itempc;
			dir.x = EncryptionUtils::GetDecryptedFloat(itempa);
			dir.y = EncryptionUtils::GetDecryptedFloat(itempb);
			dir.z = EncryptionUtils::GetDecryptedFloat(itempc);

			Character* newCharacter = Character::GetCharacter(name);
			newCharacter->SetPosition(pos);
			newCharacter->LookAt(pos + dir);

			result->worldObjects.push_back(newCharacter);
		}else if(type == PLANE){
			Vector3 pos, dir;

			ifile >> itempa >> itempb >> itempc;
			pos.x = EncryptionUtils::GetDecryptedFloat(itempa);
			pos.y = EncryptionUtils::GetDecryptedFloat(itempb);
			pos.z = EncryptionUtils::GetDecryptedFloat(itempc);
			ifile >> itempa >> itempb >> itempc;
			dir.x = EncryptionUtils::GetDecryptedFloat(itempa);
			dir.y = EncryptionUtils::GetDecryptedFloat(itempb);
			dir.z = EncryptionUtils::GetDecryptedFloat(itempc);

			float sizex, sizez;

			ifile >> itempa >> itempb;
			sizex = EncryptionUtils::GetDecryptedFloat(itempa);
			sizez = EncryptionUtils::GetDecryptedFloat(itempb);

			unsigned int rows, columns;
			ifile >> rows >> columns;
			rows = EncryptionUtils::GetEncryptDecryptUI(rows);
			columns = EncryptionUtils::GetEncryptDecryptUI(columns);
			DWORD color;
			ifile >> color;
			color = EncryptionUtils::GetEncryptDecryptUL(color);

			VBufObject* newPlane = new VBufObject(sizex, sizez, rows, columns, color);
			newPlane->SetPosition(pos);
			newPlane->LookAt(pos + dir);

			result->vertexObjects.push_back(newPlane);
		}else if(type == ANCHOR){
			Vector3 pos, dir;
			string name;
			short len;
			ifile >> len;
			EncryptionUtils::EncryptDecryptShort(len);
			char* abuf = new char[len+1];
			ZeroMemory(abuf, len+1);
			ifile.read(abuf, len);
			EncryptionUtils::DecryptBuf(abuf, len);
			name = string(abuf);

			ifile >> itempa >> itempb >> itempc;
			pos.x = EncryptionUtils::GetDecryptedFloat(itempa);
			pos.y = EncryptionUtils::GetDecryptedFloat(itempb);
			pos.z = EncryptionUtils::GetDecryptedFloat(itempc);
			ifile >> itempa >> itempb >> itempc;
			dir.x = EncryptionUtils::GetDecryptedFloat(itempa);
			dir.y = EncryptionUtils::GetDecryptedFloat(itempb);
			dir.z = EncryptionUtils::GetDecryptedFloat(itempc);

			Anchor* a = new Anchor();
			a->anchorName = name;
			a->position = pos;
			a->direction = dir;

			result->anchors.push_back(a);
		}else{
			throw "Got unrecognized type in compiled location";
		}
		FileUtils::AbsorbEndline(ifile);
	}

	ifile.close();

	return result;
}
Location* Location::GetLocation(std::string name){
	if(name == "NULL")
		return NULL;
	for(unsigned int x = 0; x < Location::allLocations.size(); x++){
		if(*allLocations.at(x)->GetName() == name)
			return allLocations.at(x);
	}

	// got here means they requested one that's not in memory, I guess we should load it...
	string newFilename(LOCATIONS_DIR);
	newFilename += name;
	newFilename += COMPILEDLOCATIONEXT;
	if(FileUtils::FileExists(newFilename)){
		// it exists, load it
		return Location::FromFile(newFilename);
	}else{
		string newFilename2(UNCOMPILEDLOCATIONS_DIR);
		newFilename2 += name;
		newFilename2 += UNCOMPILEDLOCATIONEXT;
		if(FileUtils::FileExists(newFilename2)){
			CompileLocation(newFilename2);
			return Location::FromFile(newFilename);
		}
	}

	// got here means the file didn't exist, so that conversation simply doesn't exist
	return NULL;
}

void Location::ChangeLocation(string name, string anchorName){
	ChangeLocation(Location::GetLocation(name), anchorName);
}

void Location::ChangeLocation(Location* newLocation, string anchorName){
	currentLocation = newLocation;
	EngineStatics::Engine->SetWorldObjects(newLocation->worldObjects);
	EngineStatics::Engine->SetVertexObjects(newLocation->vertexObjects);
	vector<Light*>* oldLights = EngineStatics::Engine->GetLightObjects();
	EngineStatics::Engine->SetLightObjects(newLocation->lightObjects);

	// initialize lighting
	for(unsigned int x = 0; x < oldLights->size(); x++){
		oldLights->at(x)->SetEnabled(false);
	}
	for(unsigned int x = 0; x < newLocation->lightObjects.size(); x++){
		newLocation->lightObjects.at(x)->GenerateStruct();
		newLocation->lightObjects.at(x)->SetEnabled(true);
	}

	if(anchorName == "NULL"){
		EngineStatics::Engine->GetPlayer()->SetPosition(newLocation->startPosition);
		EngineStatics::Engine->GetPlayer()->LookAt(newLocation->startPosition + newLocation->startDirection);
	}else{
		bool foundIt = false;
		for(unsigned int x = 0; x < newLocation->anchors.size(); x++){
			if(newLocation->anchors.at(x)->anchorName == anchorName){
				foundIt = true;
				EngineStatics::Engine->GetPlayer()->SetPosition(newLocation->anchors.at(x)->position);
				EngineStatics::Engine->GetPlayer()->LookAt(newLocation->anchors.at(x)->position + newLocation->anchors.at(x)->direction);
			}
		}
		if(!foundIt)
			throw "Tried to change location on invalid anchor!";
	}
}