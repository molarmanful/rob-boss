#include "Press.h"

Press::Press(int xpos, int ypos, ofColor col, int tp){
	x = xpos;
	y = ypos;
	size = ofRandom(1, ofGetHeight() / 8);
	width = ofRandom(1, size * 4);
	height = ofRandom(1, size * 4);
	type = tp;
	color = col;

	state = 1;
	timer.start();
}

void Press::draw(){
	switch(state){

		case 1:
			if(timer.check(.2)){
				state = 0;
			}
			else {
				s = ofMap(timer.elapsed(), 0, .2, 0, size, true);
				w = ofMap(timer.elapsed(), 0, .2, 0, width, true);
				h = ofMap(timer.elapsed(), 0, .2, 0, height, true);
			}
			break;

		default:
			break;
	}

	ofPushStyle();
		ofSetColor(color, ofMap(s, 1, ofGetHeight() / 8, 255, 64, true));
		if(type == 0){
			ofDrawCircle(x, y, s);
		}
		else {
			ofDrawRectangle(x - w / 2, y - h / 2, w, h);
		}
	ofPopStyle();
}
