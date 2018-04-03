#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam = ofEasyCam();
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float t = ofGetElapsedTimef() * 3;
    int w = ofGetWidth();
    int h = ofGetHeight();
    int cX = w / 2;
    int cY = h / 2;
    cam.begin();
    for (int y = -15; y < 15; ++y) {
        int yPx = (((float) y) + 0.5) / 15 * h / 2;
        for (int x = -4; x < 4; ++x) {
            int xPx = (((float) x) + 0.5) / 4 * w / 2 / 10 + sin(t + y) * 18;
            ofDrawCircle(xPx, yPx, 5);
        }
    }
    cam.end();
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
