#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenWidth = static_cast< float >(ofGetWidth());
    screenHeight = static_cast< float >(ofGetHeight());
//    grabber.setPixelFormat(OF_PIXELS_GRAY);  // Linux optimization.
    grabber.setup(screenWidth / 10, screenHeight / 10);
    camWidth = grabber.getWidth();
    camHeight = grabber.getHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPixels camPixels = grabber.getPixels();
//    camPixels.setImageType(OF_IMAGE_GRAYSCALE);
    camPixels.resize(camWidth / 2, camHeight / 2);
    camPixels.mirror(false, true);
    
    int fullW = camPixels.getWidth();
    int fullH = camPixels.getHeight();
    int sliceW = fullW / 2;
    int sliceH = fullH / 2;
    
    vector<ofImage> slices;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            ofPixels slice = ofPixels(camPixels);
            slice.crop(x * fullW / 4, y * fullH / 4, sliceW, sliceH);
            slices.push_back(ofImage(slice));
        }
    }
    
    for (int y = 0; y < screenHeight; y += sliceH) {
        for (int x = 0; x < screenWidth; x += sliceW) {
            slices[(x + y) % 9].draw(x, y);
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
