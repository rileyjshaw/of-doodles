#include "ofApp.h"

int nRows = 6;
int nCols = 23;
int squareSize = 35;
int squarePad = 7;
float baseOffset = squarePad * 1.5;
float topPad = (335 - squareSize * nRows - squarePad * (nRows - 1)) / 2;

//--------------------------------------------------------------
void ofApp::setup(){
    // Based on http://digitalartmuseum.org/gallery/image/8864.html
    seed = 0;
    
    ofColor bg;
    bg.r = 194;
    bg.g = 196;
    bg.b = 165;
    ofBackground(bg);
    
    // Debug: shows the possible range of outputs.
//    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Create a static image that doesn't animate.
    ofSeedRandom(seed);
    
    ofColor crimson;
    crimson.r = 153;
    crimson.g = 47;
    crimson.b = 84;
    crimson.a = 255 / 2;
    
    ofColor black(0);
    black.a = 255 * 7 / 10;
    
    for (int y = 0; y < nRows; ++y) {
        for (int x = 0; x < nCols; ++x) {
            for (int color = 0; color < 2; ++color) {  // lol..
                ofSetColor(color ? black : crimson);
                
                int redraws = pow(1 + (nCols - x) / 5 - color, 2);
                for (int i = 0; i < redraws; ++i) {
                    int x0 = x * (squareSize + squarePad);
                    int y0 = topPad + y * (squareSize + squarePad);
                    float offset = baseOffset * (pow(i + 1, 0.24));
                    
                    ofPoint a(x0 + ofRandom(-offset, offset), y0 + ofRandom(-offset, offset));
                    ofPoint b(x0 + squareSize + ofRandom(-offset, offset), y0 + ofRandom(-offset, offset));
                    ofPoint c(x0 + squareSize + ofRandom(-offset, offset), y0 + squareSize + ofRandom(-offset, offset));
                    ofPoint d(x0 + ofRandom(-offset, offset), y0 + squareSize + ofRandom(-offset, offset));
                    
                    ofDrawLine(a, b);
                    ofDrawLine(b, c);
                    ofDrawLine(c, d);
                    ofDrawLine(d, a);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    seed += 1000;
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
