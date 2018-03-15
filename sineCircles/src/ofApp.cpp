#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    img.load("./emoji.png");
    offsetAmount = 0;
    editToggle = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    ofColor fader = ofColor(0, 10);
    ofSetColor(fader);
    ofDrawRectangle(0, 0, w, h);
    
    float cX = w / 2;
    float cY = h / 2;
    float t = ofGetElapsedTimef();
    float tSin = sin(t);
    float r = ofMap(tSin, -1, 1, 20, 100);
    
    ofSetColor(255);
    for (int j = 0; j < 20; j += 2) {
        for (int i = 0; i < 12; ++i) {
            float freq = i / 12.0;
            float phase = t / 4 + j * offsetAmount;
            ofDrawCircle(cX + j * r * cos(freq * TWO_PI + phase), cY + j * r * sin(freq * TWO_PI + phase), r * j / 10);
        }
    }
    
//    img.draw(cX - 30, cY - 30, 60, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        editToggle = !editToggle;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if (!editToggle) return;
    
    ofBackground(0);
    offsetAmount = x / 10;
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
