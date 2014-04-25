#ifndef ROUTE_H
#define ROUTE_H

#include <string>

#include "Location.h"
using namespace std;

class Location;

const float MULTI = 3;

class Route{
public:
		Location* origin;
		Location* destination;

		string originS;
		string destinationS;

		string transport;
		float time;
		float cost;
		string note;

		Route();
		~Route();
		Route(Location* org, Location* dest);
		Route(Location* org, Location* dest, string trans, float tim, float cst, string notee);

		bool doesConnect(Location* start, Location* end);
};

Route::Route(){
	origin = NULL;
	destination = NULL;
	transport = "";
	time = 0;
	cost = 0;
	note = "";
};

Route::~Route(){

};

Route::Route(Location* org, Location* dest){
	origin = org;
	destination = dest;
	transport = "";
	time = 0;
	cost = 0;
	note = "";
};

Route::Route(Location* org, Location* dest, string trans, float tim, float cst, string notee){
	origin = org;
	destination = dest;
	transport = trans;
	time = tim;
	cost = cst;
	note = notee;

	if(trans.compare("plane") == 0){
		cost =  cst * MULTI;
	}
};


bool Route::doesConnect(Location* start, Location* end){
	if(start == origin && end == destination){
			return true;
	}

	else{
		return false;
	}
};


#endif
