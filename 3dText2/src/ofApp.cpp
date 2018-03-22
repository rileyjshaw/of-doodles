#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    splitAxis = 0;
    padding = 10;
    isOrtho = true;
    
    cam.enableOrtho();
    cam.rotate(ofQuaternion(-0.118498, 0.271082, 0.0492605, 0.953964));
    font.load("AnonymousPro-Bold.ttf", 200, true, true, true);
    
    topBuffer.allocate(w, h, GL_RGBA);
    topBuffer.begin();
    ofClear(255, 255, 255, 0);
    topBuffer.end();
    
    bottomBuffer.allocate(w, h, GL_RGBA);
    bottomBuffer.begin();
    ofClear(255, 255, 255, 0);
    bottomBuffer.end();
    
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    topBuffer.begin();
    ofRectangle topBounds = font.getStringBoundingBox("HOPE", 0, 0);
    ofSetColor(255, 255, 255, 255);
    font.drawString("HOPE", (w - topBounds.getWidth()) / 2, (h + topBounds.getHeight()) / 2);
    topBuffer.end();
    
    bottomBuffer.begin();
    ofRectangle bottomBounds = font.getStringBoundingBox("LOVE", 0, 0);
    ofSetColor(255, 255, 255, 255);
    font.drawString("LOVE", (w - bottomBounds.getWidth()) / 2, (h + bottomBounds.getHeight()) / 2);
    bottomBuffer.end();
    
    int yOffsetTop = splitAxis + padding;
    int yOffsetBottom = h / 2 - splitAxis + padding;
    cam.begin();
    ofPushMatrix();

    for (int z = -100; z <= 100; ++z) {
        ofTranslate(0, 0, float(z) / 100);
        topBuffer.getTexture().drawSubsection(-w / 2, yOffsetTop, w, h / 2, 0, -yOffsetTop);
        bottomBuffer.getTexture().drawSubsection(-w / 2, -yOffsetBottom, w, h / 2, 0, yOffsetBottom);
    }
    
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            splitAxis += 10;
            break;
        case OF_KEY_DOWN:
            splitAxis -= 10;
            break;
        case OF_KEY_LEFT:
            padding += 5;
            break;
        case OF_KEY_RIGHT:
            padding = max(padding - 5, 0);
            break;
        case 'o':
            isOrtho = !isOrtho;
            if (isOrtho) cam.enableOrtho();
            else cam.disableOrtho();
            break;
            
    }
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
