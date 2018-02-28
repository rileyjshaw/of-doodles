#include "ofApp.h"

int imgSize = 60;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    font.load("Helvetica", 48);
    img.load("./plane.png");
    // or plane, skull, shrug.
    // plane needs a + PI / 4 on its rotation.
    
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
        worms[i].x = worms[i].x + cos(worms[i].a) * 10;
        worms[i].y = worms[i].y + sin(worms[i].a) * 10;
        worms[i].a = worms[i].a + fmod(worms[i].va, 2 * PI);
        worms[i].va = fmax(fmin(worms[i].va + ofRandom(-PI / 30, PI / 30), PI / 10), -PI / 10);
        
        if (worms[i].x < 0 || worms[i].x > ofGetWidth() || worms[i].y < 0 || worms[i].y > ofGetHeight()) {
            worms[i].x = worms[i].xPrev = ofRandomWidth();
            worms[i].y = worms[i].yPrev = ofRandomHeight();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < nWorms; ++i) {
        ofPushMatrix();
            ofTranslate(worms[i].x + imgSize / 2, worms[i].y + imgSize / 2, 0);
        
            ofRotate((worms[i].a) * 180 / PI, 0, 0, 1);
            ofPushMatrix();
                img.draw(-imgSize / 2, -imgSize / 2, imgSize, imgSize);
            ofPopMatrix();
        ofPopMatrix();
    }
    
//    font.drawString("STOP WASTING TIME LOL", 100, 400);
    
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
