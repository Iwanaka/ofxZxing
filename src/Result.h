#pragma once


#include "ofMain.h"

namespace ofxZxing {

	class Result {
	public:
		Result();
		Result(string text);

		bool getFound() const;
		string getText() const;

	protected:
		bool found;
		string text;
	};

}