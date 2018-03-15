#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Based on http://digitalartmuseum.org/gallery/image/8864.html
    seed = 0;
    nRows = 6;
    nCols = 23;
    squareSize = 35;
    squarePad = 7;
    baseOffsetMagnitude = squarePad * 1.5;
    topPad = (335 - squareSize * nRows - squarePad * (nRows - 1)) / 2;
    isTweaking = false;
    originOffsetPower = 0.32;
    pointOffsetPower = 0.4;
    
    ofColor bg;
    bg.r = 194;
    bg.g = 196;
    bg.b = 165;
    ofBackground(bg);
    
    // Debug: shows the possible range of outputs.
//     ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

ofPoint ofApp::generateOffset(float maxAmplitude){
    float angle = ofRandom(TWO_PI);
    return ofRandom(maxAmplitude) * ofPoint(cos(angle), sin(angle));
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Create a static image that doesn't animate.
    ofSeedRandom(seed);
    
    ofColor crimson;
    crimson.r = 153;
    crimson.g = 47;
    crimson.b = 84;
    crimson.a = 255 / 5;
    
    ofColor black(0);
    black.a = 255 * 2.1 / 5;
    
    ofSetLineWidth(2);
    
    for (int y = 0; y < nRows; ++y) {
        for (int x = 0; x < nCols; ++x) {
            for (int color = 0; color < 2; ++color) {  // lol..
                ofSetColor(color ? black : crimson);
                
                int redraws = pow(1 + (nCols - x) / 5 - color, 2.2);
                for (int i = 0; i < redraws; ++i) {
                    float maxOriginOffsetMagnitude = (pow(i + 2, originOffsetPower));
                    int x0 = x * (squareSize + squarePad);
                    int y0 = topPad + y * (squareSize + squarePad);
                    ofPoint p0 = ofPoint(x0, y0) + generateOffset(maxOriginOffsetMagnitude);
                    
                    float maxPointOffsetMagnitude = baseOffsetMagnitude * (pow(i + 2, pointOffsetPower));
                    
                    ofPoint a = p0 + generateOffset(maxPointOffsetMagnitude);
                    ofPoint b = p0 + ofPoint(squareSize, 0) + generateOffset(maxPointOffsetMagnitude);
                    ofPoint c = p0 + ofPoint(squareSize, squareSize) + generateOffset(maxPointOffsetMagnitude);
                    ofPoint d = p0 + ofPoint(0, squareSize) + generateOffset(maxPointOffsetMagnitude);
                    
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
    if (key == ' ') {
        isTweaking = !isTweaking;
        
        if (!isTweaking) {
            cout << originOffsetPower << ", " << pointOffsetPower << endl;
        }
    } else seed += 1000;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if (isTweaking) {
        originOffsetPower = x / 300.0;
        pointOffsetPower = y / 400.0;
    }
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
