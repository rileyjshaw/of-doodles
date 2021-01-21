#include "ofApp.h"

int W = 1024;
int H = 768;
int R1 = 200;
int R2 = 20;
int R3 = 100;
int RESOLUTION = 1000;
int N_WAVES = 12;
float SPEED = 0.3;

int cX = W / 2;
int cY = H / 2;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLineWidth(20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(135, 206, 235);
    
    float t = ofGetElapsedTimef();
    
    // BUILD THIS WITH CARDBOARD! Motor in the center of the
    // waves, frame it, add a button, arduino in dead sleep,
    // and a battery. Nice.
    //
    // Also add:
    //   • a bird or two sticking out above certain waves.
    //   • message in a bottle.
    //   • plane?
    //   • stationary LED "outside of the boat" to simulate sunlight?
    //   • or fade it in and out for day / night?
    //   • etc etc...
    //
    ofFill();
    ofSetColor(64, 164, 223);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    for (float i = 0; i < RESOLUTION; ++i) {
        float angle = 180 / PI * i / RESOLUTION;
        
        // We push the radius up and down based on the point in a
        // sine wave with frequency N_WAVES. To turn it into a
        // buzzsaw, we also push the angle forwards and back so max
        // height occurs at max forward angle extension.
        float cyclePoint = sin(angle * N_WAVES);
        float waveHeight = R1 + R2 * cyclePoint;
        
        float x = waveHeight * cos(angle + cyclePoint / 10 + t * SPEED);
        float y = waveHeight * sin(angle + cyclePoint / 10 + t * SPEED);
        ofVertex(cX + x, cY + y);
    }
    ofEndShape();
    
    ofNoFill();
    ofSetColor(205, 127, 50);
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
