#include "ofApp.h"

// TODO(riley): Where does all of this go in an ideal world?
// TODO(riley): Read https://google.github.io/styleguide/cppguide.html#Header_Files
int WIDTH = 150;
int HEIGHT = 150;
int SPACING_PX = 5;
int HAIR_LENGTH_PX = 20;
int DIMENSIONALITY = 2;
int WIDTH_PX = WIDTH * SPACING_PX;
int HEIGHT_PX = HEIGHT * SPACING_PX;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(WIDTH_PX, HEIGHT_PX);
    ofBackground(ofColor::white);
    ofSetColor(0, 0, 0, 255 / 2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for (float x = 0; x <= WIDTH; ++x) {
        for (float y = 0; y <= HEIGHT; ++y) {
            // Change the noise2D output range to [0, 360deg].
            float angle = ofNoise(x / 100, y / 100, ofGetElapsedTimef() / 2) * 2 * PI;
            
            // Using the same gridOffset value for both x and y components shifts
            // the origin diagonally, which creates cool patchy bits full of
            // parallel lines.
            float gridOffset = ofRandom(-2.5, 2.5);
            
            float xPx = (x + 0.5 + gridOffset) * SPACING_PX - WIDTH * 2.5;
            float yPx = (y + 0.5 + gridOffset) * SPACING_PX - HEIGHT * 2.5;
            float zPx = ofRandom(-100, 100);
            float xOffset = cos(angle) * HAIR_LENGTH_PX;
            float yOffset = sin(angle) * HAIR_LENGTH_PX;
            
            ofDrawLine(xPx, yPx, zPx, xPx + xOffset, yPx + yOffset, zPx);
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
    HAIR_LENGTH_PX = x / 10;
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
