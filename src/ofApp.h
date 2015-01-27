#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCvHaarFinder.h"

class ofApp : public ofBaseApp{
    private:
        int windowWidth;
        int windowHeight;
	
    public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // ライブカメラを使用する際には、カメラ入力を準備
        ofVideoGrabber          cam;
    
        // オリジナルのカラー映像
        ofxCvColorImage			colorImg;     // 切り抜いた画像を表示先
        ofxCvColorImage			roiImg;       // 顔の画像切り抜き元
    
        // グレースケールに変換後
        ofxCvGrayscaleImage 	grayImage;
    
        ofxCvHaarFinder			haarFinder;
};