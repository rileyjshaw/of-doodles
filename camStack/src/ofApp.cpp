#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Cache these since we're not resizing.
    int screenWidth = ofGetScreenWidth();
    int screenHeight = ofGetScreenHeight();
    
    // Find the max camera resolution within the screen
    // dimensions...
    grabber.initGrabber(screenWidth, screenHeight);
    
    // ...it probably isn't a supported size, so let's
    // check which resolution we actually got.
    int camWidth = grabber.getWidth();
    int camHeight = grabber.getHeight();
    
    screenGridWidth = screenWidth / GRID_X;
    screenGridHeight = screenHeight / GRID_Y;
    camGridWidth = camWidth / GRID_X;
    camGridHeight = camHeight / GRID_Y;
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    int frame = ofGetFrameNum() % FRAME_DELAY;
    grabber.update();
    ofPixels px = grabber.getPixels();
    px.mirror(false, true);

    switch (MODE) {
        case 0:  // SEQUENTIAL.
            for (int y = GRID_Y - 1; y >= 0; --y) {
                for (int x = GRID_X - 1; x >= 0; --x) {
                    int idx = x + y * GRID_X;
                    history[frame][idx] = idx ? history[frame][idx - 1] : ofImage(px);
                }
            }
            break;
            
        case 1:  // REVERSE SEQUENTIAL.
            for (int y = 0; y < GRID_Y; ++y) {
                for (int x = 0; x < GRID_X; ++x) {
                    int idx = x + y * GRID_X;
                    if (idx == GRID_X * GRID_Y - 1) history[frame][idx] = ofImage(px);
                    else history[frame][idx] = history[frame][idx + 1];
                }
            }
            break;
            
        case 2:  // DIAGONAL.
            for (int y = GRID_Y - 1; y >= 0; --y) {
                for (int x = GRID_X - 1; x >= 0; --x) {
                    history[frame][x + y * GRID_X] = history[frame][max(x - 1, 0) + max(y - 1, 0) * GRID_X];
                }
            }
            history[frame][0] = ofImage(px);
            break;
            
        case 3:  // BUBBLE.
            int cXMax = GRID_X / 2;
            int cYMax = GRID_Y / 2;
            int cXMin = cXMax - 1 + GRID_X % 2;
            int cYMin = cYMax - 1 + GRID_Y % 2;
            
            for (int y = 0; y <= cYMin; ++y) {
                for (int x = 0; x <= cXMin; ++x) {
                    if (x == cXMin and y == cYMin) history[frame][x + y * GRID_X] = ofImage(px);
                    else history[frame][x + y * GRID_X] = history[frame][min(x + 1, cXMin) + min(y + 1, cYMin) * GRID_X];
                }
            }
            
            for (int y = 0; y <= cYMin; ++y) {
                for (int x = GRID_X - 1; x > cXMin; --x) {
                    if (x == cXMax and y == cYMin) history[frame][x + y * GRID_X] = ofImage(px);
                    else history[frame][x + y * GRID_X] = history[frame][max(x - 1, cXMax) + min(y + 1, cYMin) * GRID_X];
                }
            }

            for (int y = GRID_Y - 1; y > cYMin; --y) {
                for (int x = 0; x <= cXMin; ++x) {
                    if (x == cXMin and y == cYMax) history[frame][x + y * GRID_X] = ofImage(px);
                    else history[frame][x + y * GRID_X] = history[frame][min(x + 1, cXMin) + max(y - 1, cYMax) * GRID_X];
                }
            }

            for (int y = GRID_Y - 1; y > cYMin; --y) {
                for (int x = GRID_X - 1; x > cXMin; --x) {
                    if (x == cXMax and y == cYMax) history[frame][x + y * GRID_X] = ofImage(px);
                    else history[frame][x + y * GRID_X] = history[frame][max(x - 1, cXMax) + max(y - 1, cYMax) * GRID_X];
                }
            }
            
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int frame = ofGetFrameNum() % FRAME_DELAY;
    
    for (int y = 0; y < GRID_Y; ++y) {
        for (int x = 0; x < GRID_X; ++x) {
            ofImage img = history[frame][x + y * GRID_X];
            if (!img.isAllocated()) continue;
            
            ofImage crop;
            crop.cropFrom(img, x * camGridWidth, y * camGridHeight, camGridWidth, camGridHeight);
            crop.draw(x * screenGridWidth, y * screenGridHeight, screenGridWidth, screenGridHeight);
        }
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
