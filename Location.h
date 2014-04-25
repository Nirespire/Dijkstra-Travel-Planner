#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

#include "Route.h"
class Route;

using namespace std;

class Location{
public:
		string country;
		string capital;
		float lat;
		float lon;

		vector<Route*> routes;

		bool exists;
		Location* previous;
		float lengthFromStart;

		Location();
		~Location();
		Location(string count, string cap);
		Location(string count, string cap, float lt, float lg);

		float getWeight(Location* start, Location* end);

		int operator== (const Location &rhs) const;
		int operator< (const Location &rhs) const;
		int operator> (const Location &rhs) const;

		bool operator()(Location& l1, Location& l2);
};

Location::Location(){
	country = "";
	capital = "";
	lat = 0;
	lon = 0;

	// Used as a highest value possible for comparison purposes
	lengthFromStart = 999999;

	exists = true;

	previous = NULL;
}

Location::~Location(){};

Location::Location(string count, string cap){
	country = count;
	capital = cap;
	lat = 0;
	lon = 0;

	lengthFromStart = 999999;

	exists = true;

	previous = NULL;
}

Location::Location(string count, string cap, float lt, float lg){
	country = count;
	capital = cap;
	lat = lt;
	lon = lg;

	lengthFromStart = 999999;

	exists = true;

	previous = NULL;
}

int Location::operator== (const Location &rhs) const{
	
	if(this -> capital.compare(rhs.capital) == 0){
		return 0;
	}
	return 1;
}

int Location::operator< (const Location &rhs) const{
	if(this -> lengthFromStart < rhs.lengthFromStart){
		return 1;
	}
}

int Location::operator> (const Location &rhs) const{
	if(this -> lengthFromStart > rhs.lengthFromStart){
		return 1;
	}
}

class compareLocation{
public:
	bool operator()(const Location* l1, const Location* l2) const{
		bool output = false;
		if(l1->lengthFromStart > l2->lengthFromStart){
			output = true;
		}
		return output;
	}
};

#endif
