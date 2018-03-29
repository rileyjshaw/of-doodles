#include "ofApp.h"

#define SPEED 1
#define RESET_FRAME 60
#define FIRST_FRAME 40

void ofApp::clearPixels(ofPixels &px) {
    px.clear();
    px.allocate(camWidth, camHeight, OF_PIXELS_RGBA);
    ofColor transparent = ofColor(255, 255, 255);
    transparent.a = 0;
    for (int y = 0; y < camHeight; ++y) {
        for (int x = 0; x < camWidth; ++x) {
            px.setColor(x, y, transparent);
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    screenWidth = ofGetWidth();
    screenHeight = ofGetHeight();
    grabber.setPixelFormat(OF_PIXELS_RGBA);
    grabber.setup(screenWidth / 2, screenHeight / 2);
    screenWidth = camWidth = grabber.getWidth();
    screenHeight = camHeight = grabber.getHeight();
    
    ofSetWindowShape(screenWidth, screenHeight);

    clearPixels(ping);
    clearPixels(pong);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int frameNum = ofGetFrameNum();
    if (frameNum < FIRST_FRAME) return;
    
    ofPixels camPixels = grabber.getPixels();
    camPixels.mirror(false, true);
    ofImage(camPixels).draw(0, 0, screenWidth, screenHeight);
    
    ofPixels oldPixels;
    ofPixels newPixels;
    if (frameNum % 2 == 0) {
        oldPixels = ping;
        newPixels = pong;
    } else {
        oldPixels = pong;
        newPixels = ping;
    }

    // TODO(riley): Keep old dust?
    if ((frameNum - FIRST_FRAME) == 0 || rego) {
        clearPixels(oldPixels);
        ping = oldPixels = ofPixels(camPixels);
        rego = false;
    }
    
    clearPixels(newPixels);
    for (int y = camHeight - 1; y >= 0; --y) {
        for (int x = 0; x < camWidth; ++x) {
            if (y + SPEED >= camHeight) {
                continue;
            }
            
            ofColor oldColor = oldPixels.getColor(x, y);
            if (oldColor.a == 0) continue;
            
            int oldBrightness = oldColor.getBrightness();
            int drop = 0;
            int shift = 0;
            while (
                   y + drop < camHeight and
                   drop < SPEED and
                   abs(camPixels.getColor(x, y + drop + 1).getBrightness() - oldBrightness) > 10 and
                   newPixels.getColor(x, y + drop + 1).a == 0) {
                ++drop;
            }
            if (drop == 0) {
                if (ofRandom(20) > 19) shift = (rand() % 2) * 2 - 1;
                if (x + shift == ofClamp(x + shift, 0, camWidth - 1) and newPixels.getColor(x + shift, y).a != 0) shift = 0;
            }
            if (x + shift == ofClamp(x + shift, 0, camWidth - 1) and y + drop == ofClamp(y + drop, 0, camWidth - 1)) {
                newPixels.setColor(x + shift, y + drop, oldColor);
            }
        }
    }
    
    for (int y = 0; y < camHeight; ++y) {
        for (int x = 0; x < camWidth; ++x) {
            if (ofRandom(10) > 9 and newPixels.getColor(x, y).a == 0) {
                newPixels.setColor(x, y, camPixels.getColor(x, y));
            }
        }
    }
    
    if (frameNum % 2 == 0) {
        pong = newPixels;
    } else {
        ping = newPixels;
    }
    
    ofImage(newPixels).draw(0, 0, screenWidth, screenHeight);
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
    rego = true;
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

