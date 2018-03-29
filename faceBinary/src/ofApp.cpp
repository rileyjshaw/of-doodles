#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("PressStart2P.ttf", 6);
    
    screenWidth = static_cast< float >(ofGetWidth());
    screenHeight = static_cast< float >(ofGetHeight());
    grabber.setPixelFormat(OF_PIXELS_GRAY);  // Linux optimization.
    grabber.setup(screenWidth, screenHeight);
    
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor(4, 4, 2, 20));
    ofDrawRectangle(0, 0, screenWidth, screenHeight);
    
    ofSetColor(ofColor(119, 178, 66));
    ofPixels camPixels = grabber.getPixels();
    camPixels.setImageType(OF_IMAGE_GRAYSCALE);
    camPixels.resize(screenWidth / 10, screenHeight / 10);
    camPixels.mirror(false, true);
    ofImage camImg = ofImage(camPixels);
    int w = camImg.getWidth();
    int h = camImg.getHeight();
    
    float xScale = screenWidth / w;
    float yScale = screenHeight / h;
    
    for (float y = 0; y < h; ++y) {
        for (float x = 0; x < w; ++x) {
            font.drawString(camImg.getColor(x, y).getLightness() < 90 ? "0" : "1", x * xScale, (y + 1) * yScale);
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
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
