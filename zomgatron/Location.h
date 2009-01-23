#ifndef __LOCATION_H__
#define __LOCATION_H__

#define COMPILEDLOCATIONEXT ".clf"
#define UNCOMPILEDLOCATIONEXT ".rlf"
#define LOCATIONS_DIR "Data/Locations/"
#define UNCOMPILEDLOCATIONS_DIR "Data/Locations/Raw/"

#include <vector>
#include <string>
using namespace std;

#include "VBufObject.h"
#include "DrawnObject.h"
#include "Character.h"

enum OBJECT_TYPE{
	PLANE = 0x0001,
	CHARACTER = 0x0002,
	LIGHT = 0x0004,
	ANCHOR = 0x0008,
	TRANSPORTATIONOBJECT = 0x0010,
};

struct THREEINTS{
	int a, b, c;
};
struct FOURINTS{
	int a, b, c, d;
};

struct Anchor{
	std::string anchorName;
	Vector3 position, direction;
};

struct LocationPieces{
	Vector3 startPosition, startDirection;
	vector<VBufObject*> vertexObjects;
	vector<DrawnObject*> worldObjects;
	vector<Light*> lightObjects;
	vector<Anchor*> anchors;
	string name;
	string desc;
};

class Location{
private:
	static Location* currentLocation;
protected:
	Vector3 startPosition, startDirection;
	vector<VBufObject*> vertexObjects;
	vector<DrawnObject*> worldObjects;
	vector<Light*> lightObjects;
	
	vector<Anchor*> anchors;
	string name;
	string desc;
public:
	Location();

	vector<VBufObject*>* GetVertexObjects() { return &vertexObjects; }
	vector<DrawnObject*>* GetWorldObjects() { return &worldObjects; }
	vector<Light*>* GetLightObjects() { return &lightObjects; }

	string* GetName() { return &name; }
	string* GetDesc() { return &desc; }
	Vector3 GetStartPosition() { return startPosition; }

	static void CompileLocation(std::string uncompiledfilename);
	static Location* FromFile(std::string compiledfilename);
	static std::vector<Location*> allLocations;
	static Location* GetLocation(std::string name);
	static Location* GetCurrentLocation() { return currentLocation; }
	static void ChangeLocation(string name, string anchorName = "NULL");
	static void ChangeLocation(Location* newLocation, string anchorName = "NULL");
};

#endif
