#include "ofApp.h"
#include <ratio>

//--------------------------------------------------------------
void ofApp::setup(){
	state = 0;
	small_font.load("arial.ttf", 50);
	big_font.load("arial.ttf", 100);
	intro_song.load("intro.mp3");
	ofSetBackgroundColor(0);
	ofSetCircleResolution(50);
	cur_color.setHsb(ofRandom(0, 192), ofRandom(156, 192), ofRandom(156, 192), 192);
	type = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	switch(state){

		// fade in title
		case 1:
			if(timer1.check(1)){
				state = 101;
				timer1.start();
			}
			break;

		// keep title on screen
		case 101:
			if(timer1.check(10)){
				state = 201;
				timer1.start();
			}
			break;

		// fade out title
		case 201:
			if(timer1.check(1)){
				state = 0;
			}
			break;

		// fade in color
		case 2:
			if(timer2.check(.5)){
				state = 102;
				timer2.start();
			}
			break;

		// keep color on screen
		case 102:
			if(timer2.check(2)){
				state = 202;
				timer2.start();
			}
			break;

		// fade out color
		case 202:
			if(timer2.check(.5)){
				if(ticker.done()){
					state = 0;
				}
				else {
					state = 2;
					cur_tick = ticker.next();
					timer2.start();
				}
			}
			break;

		default:
			break;
	}
}

float clampMap0(float x, float a, float b){
	return ofMap(x, 0, a, 0, b, true);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(auto &p : presses) p.draw();

	switch(state){

		case 1:
			ofPushStyle();
				ofSetColor(255, 255, 255, clampMap0(timer1.elapsed(), 1, 1) * 255);
				drawTitle();
			ofPopStyle();
			break;

		case 101:
			drawTitle();
			break;

		case 201:
			ofPushStyle();
				ofSetColor(255, 255, 255, 255 - clampMap0(timer1.elapsed(), 1, 1) * 255);
				drawTitle();
			ofPopStyle();
			break;

		case 2:
			ofPushStyle();
				ofSetColor(255, 255, 255, clampMap0(timer2.elapsed(), .5, 1) * 255);
				drawTick(cur_tick);
			ofPopStyle();
			break;

		case 102:
			drawTick(cur_tick);
			break;

		case 202:
			ofPushStyle();
				ofSetColor(255, 255, 255, 255 - clampMap0(timer2.elapsed(), .5, 1) * 255);
				drawTick(cur_tick);
			ofPopStyle();
			break;

		default:
			break;
	}
}

void ofApp::drawTitle(){
	ofPushMatrix();
		string title = "THE JOY OF\nABSTRACT ART";
		ofRectangle title_dim = big_font.getStringBoundingBox(title, 0, 0);
		ofTranslate(ofGetWidth() / 2 - title_dim.width / 2, ofGetHeight() / 2 - title_dim.height / 2);

		big_font.drawString(title, 0, 0);
		small_font.drawString("with Rob Boss", 0, 250);
	ofPopMatrix();
}

void ofApp::drawTick(string tick){
	ofPushMatrix();
		ofRectangle tick_dim = small_font.getStringBoundingBox(tick, 0, 0);
		ofTranslate(ofGetWidth() / 2 - tick_dim.width / 2, ofGetHeight() - 200);

		small_font.drawString(tick, 0, 0);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofColor c;
	switch(key){
		// cue intro
		case OF_KEY_F1:
			state = 1;
			timer1.start();
			intro_song.play();
			break;

		// cue color names
		case OF_KEY_F2:
			state = 2;
			timer2.start();
			ticker.start();
			cur_tick = ticker.next();
			break;

		// change shape type
		case ' ':
			type ^= 1;

		case OF_KEY_RETURN:
			c.setHsb(ofRandom(256), ofRandom(256), ofRandom(0, 64));
			ofSetBackgroundColor(c);
			break;

		default:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(state % 10 != 1){
		// add new shape
		presses.emplace_back(x, y, cur_color, type);
		// golden angle colorgen
		cur_color.setHueAngle(fmod(cur_color.getHueAngle() + 180 * (5 - sqrt(3)), 360));
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
