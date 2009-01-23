#ifndef __TRANSPORTATIONOBJECT_H__
#define __TRANSPORTATIONOBJECT_H__

#define COMPILEDTOEXT ".ctof"
#define UNCOMPILEDTOEXT ".rtof"
#define TOS_DIR "Data/TransportationObjects/"
#define UNCOMPILEDTOS_DIR "Data/TransportationObjects/Raw/"

#include "DrawnObject.h"
#include "Location.h"
#include <string>

class TransportationObject: public DrawnObject{
protected:
	std::string destination;
	std::string destinationAnchor;
	std::string desc;
	std::string name;
public:
	TransportationObject(void* mesh, void* material, void* texture, int numPieces);

	void activate() override { Location::ChangeLocation(GetDestination(), destinationAnchor); }
	std::string activationText() override { return desc; }

	Location* GetDestination() { return Location::GetLocation(destination); }
	std::string GetAnchor() { return destinationAnchor; }
	std::string GetDesc() { return desc; }
	std::string GetName() { return name; }

	static TransportationObject* FromFile(std::string filename);
	static void CompileTransportationObject(std::string uncompiledfilename);
	static std::vector<TransportationObject*> allTransportationObjects;
	static TransportationObject* GetTransportationObject(std::string name);
};

#endif
