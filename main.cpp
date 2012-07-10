#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

//	ofSetupOpenGL(1280, 960, OF_WINDOW);			// <-------- setup the GL context
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 1280, 960, OF_WINDOW);
//	ofSetupOpenGL(&window, 640, 480, OF_WINDOW);
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	
	ofRunApp(new testApp());
	
}
