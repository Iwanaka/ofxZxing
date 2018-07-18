#include "ofxZxing.h"

#include "ofPixelsBitmapSource.h"

#include <zxing/qrcode/QRCodeReader.h>
#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/common/HybridBinarizer.h>
#include <zxing/Exception.h>

namespace ofxZxing {

	using namespace std;
	using namespace zxing;
	using namespace zxing::qrcode;
	

	Result decode(ofPixels& pixels, bool adaptive = true) {


		try {

			Ref<ofPixelsBitmapSource> source(new ofPixelsBitmapSource(pixels));

			Ref<Binarizer> binarizer(NULL);
			
			if (adaptive) {
				binarizer = new HybridBinarizer(source);
			}
			else {
				binarizer = new GlobalHistogramBinarizer(source);
			}


			Ref<BinaryBitmap> image(new BinaryBitmap(binarizer));

			QRCodeReader reader;
			DecodeHints hints;
			
			hints.addFormat(BarcodeFormat::QR_CODE);
			hints.setTryHarder(true);
			

			Ref<zxing::Result> result(reader.decode(image, hints));

			string text = result->getText()->getText();

			return Result(text);
		
		}
		catch (zxing::Exception& e) {
			//cerr << "Error: " << e.what() << endl;
			return Result();
		}


	}

}