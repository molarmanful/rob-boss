#ifndef PRESS_H
#define PRESS_H

#include "ofMain.h"
#include "Timer.h"

class Press {
	public:
		Press(int xpos, int ypos, ofColor col, int tp);
		void draw();

		int x;
		int y;
		int type;
		int size;
		int width;
		int height;
		ofColor color;

		int state;
		Timer timer;
		int s;
		int w;
		int h;
};

#endif
