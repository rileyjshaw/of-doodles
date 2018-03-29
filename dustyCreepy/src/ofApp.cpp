#include "ofApp.h"

#define SPEED 10
#define RESET_FRAME 50
//
//void clearPixels(ofPixels px){
//    int numPixels = px.size() / px.getNumChannels();
//    for (int i = 0; i < numPixels; ++i) {
//
//    }
//}

//--------------------------------------------------------------
void ofApp::setup(){
    screenWidth = ofGetWidth();
    screenHeight = ofGetHeight();
    grabber.setPixelFormat(OF_PIXELS_RGBA);
    grabber.setup(screenWidth / 2, screenHeight / 2);
    camWidth = grabber.getWidth();
    camHeight = grabber.getHeight();

    ping.allocate(camWidth, camHeight, OF_PIXELS_RGBA);
    pong.allocate(camWidth, camHeight, OF_PIXELS_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int frameNum = ofGetFrameNum();
    if (frameNum < RESET_FRAME) return;
    
    ofPixels camPixels = grabber.getPixels();
    camPixels.mirror(false, true);
    ofImage(camPixels).draw(0, 0);
    
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
    if (frameNum % RESET_FRAME == 0) {
        ping = oldPixels = ofPixels(camPixels);
    }

    newPixels.clear();
    newPixels.allocate(camWidth, camHeight, OF_PIXELS_RGBA);
    for (int y = 0; y < camHeight - SPEED; ++y) {
        for (int x = 0; x < camWidth; ++x) {
            ofColor oldColor = oldPixels.getColor(x, y);

            // Dark pixels fall away.
//            if (oldColor.getBrightness() < 127) {
                newPixels.setColor(x, y + SPEED, oldColor);
//            } else {
//                int drop = 0;
//                while (drop < SPEED and camPixels.getColor(x, y + drop + 1).getBrightness() > 127) {
//                    ++drop;
//                }
//                newPixels.setColor(x, y + drop, oldColor);
//            }
        }
    }
    
    ofImage(newPixels).draw(0, 0, camWidth, camHeight);
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

