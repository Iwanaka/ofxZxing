#include "Result.h"

namespace ofxZxing {

	Result::Result() :
		found(false) {
	}

	//--------------------------------------------------------------
	Result::Result(string text) :
		found(true), text(text){
	}

	//--------------------------------------------------------------
	bool Result::getFound() const {
		return found;
	}


	//--------------------------------------------------------------
	string Result::getText() const {
		return text;
	}

}
