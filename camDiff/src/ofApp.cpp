#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Cache these since we're not resizing.
    screenWidth = ofGetScreenWidth();
    screenHeight = ofGetScreenHeight();
    
    // Find the max camera resolution within the screen
    // dimensions...
    grabber.initGrabber(screenWidth, screenHeight);
    
    // ...it probably isn't a supported size, so let's
    // check which resolution we actually got.
    int camWidth = grabber.getWidth();
    int camHeight = grabber.getHeight();
    
    // The trick is to compare a small version of the
    // current frame with a small version of the last
    // one so we don't need to compare pixel-by-pixel.
    // We make our comparison images 20x smaller here:
    gridWidth = camWidth / 20;
    gridHeight = camHeight / 20;
    
    // Hopefully these are the same, if the screen and
    // camera have the same aspect ratio. But we store
    // them separately just in case.
    gridSpacingX = screenWidth / gridWidth;
    gridSpacingY = screenHeight / gridHeight;
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    // Draw the raw camera input to the screen.
    ofPixels px = grabber.getPixels();
    px.mirror(false, true);
    ofImage frame = ofImage(px);
    frame.draw(0, 0, screenWidth, screenHeight);
    
    // Shrink our camera image to the comparison grid size.
    frame.setImageType(OF_IMAGE_GRAYSCALE);
    frame.resize(gridWidth, gridHeight);

    // Wherever a pixel in the new grid is different enough
    // from a pixel in the old grid, we highlight the region
    // with a random color.
    if (lastFrame.isAllocated()) {
        for (int y = 0; y < gridHeight; ++y) {
            for (int x = 0; x < gridWidth; ++x) {
                int a = frame.getColor(x, y).getBrightness();
                int b = lastFrame.getColor(x, y).getBrightness();
                if (abs(a - b) > 10) {
                    int xPx = x * gridSpacingX;
                    int yPx = y * gridSpacingY;
                    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), 100);
                    ofDrawRectangle(xPx, yPx, gridSpacingX, gridSpacingY);
                }
            }
        }
    }
    lastFrame = frame;
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
