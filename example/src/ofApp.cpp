#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(46, 51, 70);

	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);

}

//--------------------------------------------------------------
void ofApp::update(){

	cam.update();
	
	
	if (cam.isFrameNew()) {
		
		ofxZxing::Result curResult = ofxZxing::decode(cam.getPixelsRef(), true);
		
		float curTime = ofGetElapsedTimef();
		
		if (curResult.getFound()) {
		
			result = curResult;
			lastFound = curTime;
		
		}

		else if (curTime - lastFound > 1.f) {

			result = curResult;
		
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);

	cam.draw(50, 50);

	if (result.getFound()) {
		
		ofDrawBitmapString(result.getText(), 50, 580);

	}

}