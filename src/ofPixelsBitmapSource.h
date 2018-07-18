#pragma once

#include "ofMain.h"
#include <zxing/LuminanceSource.h>

namespace zxing {

	class ofPixelsBitmapSource : public LuminanceSource {

	private:
		typedef LuminanceSource Super;

		ofPixels& image_;
		int width;
		int height;

		const unsigned char* pixel_cache;

	public:

		ofPixelsBitmapSource(ofPixels& image);
		virtual ~ofPixelsBitmapSource();

		int getWidth() const;
		int getHeight() const;

		ArrayRef<char> getRow(int y, zxing::ArrayRef<char> row) const;
		ArrayRef<char> getMatrix() const;

		bool isRotateSupported() const;
		Ref<LuminanceSource> rotateCounterClockwise();


	};

}