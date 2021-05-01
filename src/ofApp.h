#pragma once

#include "ofMain.h"
#include "Timer.h"
#include "ColorTick.h"
#include "Press.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void drawTitle();
		void drawTick(string tick);

		int state;

		Timer timer1;
		Timer timer2;

		ColorTick ticker;
		string cur_tick;

		ofTrueTypeFont small_font;
		ofTrueTypeFont big_font;

		ofSoundPlayer intro_song;

		vector<Press> presses;
		ofColor cur_color;
		int type;
};
