#pragma once

#include "ofMain.h"
#include "ofxZxing.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxZxing::Result result;
		ofVideoGrabber cam;
		float lastFound;

};
