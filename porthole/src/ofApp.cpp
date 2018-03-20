#include "ofApp.h"

int W = 1024;
int H = 768;
int R1 = 200;
int R2 = 20;
int R3 = 100;
int RESOLUTION = 500;
int FREQ = 8;

int cX = W / 2;
int cY = H / 2;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLineWidth(1000);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    float t = ofGetElapsedTimef();
    
    ofFill();
    ofSetColor(150, 150, 255);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    for (float i = 0; i < RESOLUTION; ++i) {
        float angle = 180 / PI * i / RESOLUTION;
        float waveHeight = R1 + R2 * sin(angle * FREQ);
        float x = waveHeight * cos(angle + sin(angle * FREQ) - t);
        float y = waveHeight * sin(angle + sin(angle * FREQ) - t);
        ofVertex(cX + x, cY + y);
    }
    ofEndShape();
    
    ofNoFill();
    ofSetColor(255, 150, 150);
    ofSetCircleResolution(RESOLUTION);
    ofDrawCircle(cX, cY - R1, R3);
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
