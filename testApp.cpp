#include "testApp.h"

#define MOVIE_INPUT_WSIZE   320
#define MOVIE_INPUT_HSIZE   240

#define MOVIE_INPUT_WSIZE_640   640
#define MOVIE_INPUT_HSIZE_480   480


//--------------------------------------------------------------
void testApp::setup(){

	vidGrabber.initGrabber(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
        
    colorImg.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    colorImg2.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
	
 	grayImage.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
	grayImage2.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
	
	//lets load in our face xml file
    haarFinder.setup("haarcascade_frontalface_alt2.xml");
    
    faceNum = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    bool bNewFrame = false;
	
	#ifdef _USE_LIVE_VIDEO
       vidGrabber.grabFrame();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.idleMovie();
        bNewFrame = vidPlayer.isFrameNew();
	#endif
	
	if (bNewFrame){
		
		#ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(vidGrabber.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
            colorImg2.setFromPixels(colorImg.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
	    #else
            colorImg.setFromPixels(vidPlayer.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
            colorImg2.setFromPixels(vidGrabber.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);			
        #endif
		
        grayImage = colorImg;
		grayImage2	= colorImg2;
		
		haarFinder.findHaarObjects(grayImage, 10, 10);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    int numFace = haarFinder.blobs.size();
    
    float	x[numFace], y[numFace], w[numFace], h[numFace], cx[numFace], cy[numFace]; 

	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetColor(0xffffff);
    
	// Face
    colorImg2.draw(0, 0, MOVIE_INPUT_WSIZE_640, MOVIE_INPUT_HSIZE_480);
    colorImg2.draw(MOVIE_INPUT_WSIZE_640, 0, MOVIE_INPUT_WSIZE_640, MOVIE_INPUT_HSIZE_480);
    
    
    //******************************
	// Face
    //******************************                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    for(int i = 0; i < numFace; i++){
        x[i] = haarFinder.blobs[i].boundingRect.x;
        y[i] = haarFinder.blobs[i].boundingRect.y;
        w[i] = haarFinder.blobs[i].boundingRect.width;
        h[i] = haarFinder.blobs[i].boundingRect.height;
            
        if( 0 == i ){
            glTranslatef(x[0], y[0], 0);
            ofSetColor(0xFFFFFF);
            ofRect(x[i]+MOVIE_INPUT_WSIZE_640, y[i], 2*w[i], 2*h[i]);
        }
         else if( 1 == i ){
             // 最初(1つ目)に検出した顔を切り抜き
             colorImg2.setROI(x[0], y[0], w[0], h[0]);
             glTranslatef(x[1], y[1], 0);
             // 次に(2つ目)に検出した顔にはりつけ
             colorImg2.drawROI(x[1]+MOVIE_INPUT_WSIZE_640-155, y[1]-35, 2*w[1], 2*h[1]);
        }
        else {
            break;
        }
    }
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
		case 's':
			vidGrabber.videoSettings();
		break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}	

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}
