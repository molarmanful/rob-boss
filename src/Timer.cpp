#include "Timer.h"

void Timer::start(){
	time = ofGetElapsedTimef();
	start_time = time;
}

bool Timer::check(float t){
	time = ofGetElapsedTimef();
	return ofGetElapsedTimef() - start_time >= t;
}

float Timer::elapsed(){
	return ofGetElapsedTimef() - start_time;
}
