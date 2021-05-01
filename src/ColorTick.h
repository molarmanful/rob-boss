#ifndef COLORTICK_H
#define COLORTICK_H

#include "ofMain.h"

class ColorTick {

	public:
		void start();
		string next();
		bool done();

		int i;
		vector<string> msgs;
};

#endif

