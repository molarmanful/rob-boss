#ifndef TIMER_H
#define TIMER_H

#include "ofMain.h"

class Timer {

	public:
		void start();
		bool check(float t);
		float elapsed();

		float start_time;
		float time;
};

#endif

