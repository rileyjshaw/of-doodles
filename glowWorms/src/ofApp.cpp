#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    for (int i = 0; i < nWorms; ++i) {
        worms[i].a = ofRandom(PI * 2);
        worms[i].x = ofRandomWidth();
        worms[i].y = ofRandomHeight();
        worms[i].va = ofRandom(-PI / 8, PI / 8);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < nWorms; ++i) {
        worms[i].xPrev = worms[i].x;
        worms[i].yPrev = worms[i].y;
        worms[i].x = worms[i].x + cos(worms[i].a) * 3;
        worms[i].y = worms[i].y + sin(worms[i].a) * 3;
        worms[i].a = worms[i].a + fmod(worms[i].va, 2 * PI);
        worms[i].va = worms[i].va + ofRandom(-PI / 30, PI / 30);
        // TODO(riley): Add some max tings.
        
        if (worms[i].x < 0 || worms[i].x > ofGetWidth() || worms[i].y < 0 || worms[i].y > ofGetHeight()) {
            worms[i].x = worms[i].xPrev = ofRandomWidth();
            worms[i].y = worms[i].yPrev = ofRandomHeight();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < nWorms; ++i) {
        Worm worm = worms[i];
        ofSetColor(0);
        ofSetLineWidth(16);
        ofDrawLine(worm.xPrev, worm.yPrev, worm.x, worm.y);
//        ofDrawCircle(worms[i].x, worms[i].y, 16);
        ofSetColor(255);
        ofSetLineWidth(8);
        ofDrawLine(worm.xPrev, worm.yPrev, worm.x, worm.y);
//        ofDrawCircle(worms[i].x, worms[i].y, 10);
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
