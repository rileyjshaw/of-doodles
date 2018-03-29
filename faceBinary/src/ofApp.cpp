#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("PressStart2P.ttf", 6);
    
    screenWidth = static_cast< float >(ofGetWidth());
    screenHeight = static_cast< float >(ofGetHeight());
    grabber.setPixelFormat(OF_PIXELS_GRAY);  // Linux optimization.
    grabber.setup(screenWidth / 10, screenHeight / 10);
    
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

    int w = camPixels.getWidth();
    int h = camPixels.getHeight();
    float xScale = screenWidth / w;
    float yScale = screenHeight / h;
    
    int avgBrightness = 0;
    int brightnesses[w * h];
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int i = x + y * w;
            int brightness = camPixels.getColor(x, y).getBrightness();
            brightnesses[i] = brightness;
            avgBrightness += brightness;
        }
    }
    avgBrightness /= w * h;
    
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            font.drawString(brightnesses[x + y * w] < avgBrightness ? "0" : "1", x * xScale, (y + 1) * yScale);
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
