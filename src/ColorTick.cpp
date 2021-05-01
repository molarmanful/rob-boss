#include "ColorTick.h"

void ColorTick::start(){
	i = 0;
	msgs = {
		"TITANIUM WHITE",
		"(WE THINK?)",
		"(WE DON'T ACTUALLY KNOW)",
		"(WASN'T IN THE JOB DESCRIPTION)"
	};
}

string ColorTick::next(){
	return msgs[i++];
}

bool ColorTick::done(){
	return i >= msgs.size();
}
