#include "ofApp.h"

#define MOVIE_INPUT_WSIZE   320
#define MOVIE_INPUT_HSIZE   240

#define MOVIE_INPUT_WSIZE_640   640
#define MOVIE_INPUT_HSIZE_480   480

//--------------------------------------------------------------
void ofApp::setup(){
    windowWidth = ofGetWidth();
    windowHeight = ofGetHeight();
    // 検分器は重いので検出する画像は小さくする
    cam.initGrabber(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    colorImg.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    roiImg.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    grayImage.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    // 検分器の読み込み
    haarFinder.setup("haarcascade_frontalface_alt2.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    // カメラ入力の更新
    cam.update();
    
    // 取り込んだフレームを画像としてキャプチャ
    colorImg.setFromPixels(cam.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    roiImg.setFromPixels(colorImg.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    // カラーのイメージをグレースケールに変換
    grayImage = colorImg;

    // 検分器にグレースケールを読み込ませる
    haarFinder.findHaarObjects(grayImage, 10, 10);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xffffff);
    colorImg.draw(0, 0, MOVIE_INPUT_WSIZE_640, MOVIE_INPUT_HSIZE_480);
    
    //******************************
    // Face
    //******************************
    // 検出した顔の数
    int numFace = haarFinder.blobs.size();
    float x[numFace], y[numFace], w[numFace], h[numFace];

    for(int i = 0; i < numFace; i++){
        x[i] = haarFinder.blobs[i].boundingRect.x;
        y[i] = haarFinder.blobs[i].boundingRect.y;
        w[i] = haarFinder.blobs[i].boundingRect.width;
        h[i] = haarFinder.blobs[i].boundingRect.height;
        
        if( 0 == i ){
            // 最初(1つ目)に検出した顔を切り抜き
            roiImg.setROI(x[i], y[i], w[i], h[i]);
        }
        else if( 1 == i ){
            glTranslatef(x[i], y[i], 0);
            // 次に(2つ目)に検出した顔にはりつけ
            roiImg.drawROI(x[i], y[i], 2*w[i], 2*h[i]);
        }
        else {
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}