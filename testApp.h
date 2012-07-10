#ifndef _TEST_APP
#define _TEST_APP


#define OF_ADDON_USING_OFXOPENCV

#include "ofMain.h"

#define _USE_LIVE_VIDEO		// uncomment this to use a live camera

#include "ofxCvHaarFinder.h"

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

        #ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber 		vidGrabber;
		#else
		  ofVideoPlayer 		vidPlayer;
		#endif
        
        ofxCvColorImage			colorImg;
        ofxCvColorImage			colorImg2;
        
        ofxCvGrayscaleImage 	grayImage;
		ofxCvGrayscaleImage		grayImage2;
		
		ofxCvHaarFinder			haarFinder;
		
		int						threshold;
		bool					bLearnBakground;
    
        int                     faceNum;

};

#endif
