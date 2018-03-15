#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor fade = ofColor(0, 20);
    ofSetColor(fade);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    float t = ofGetElapsedTimef();
    ofSetColor(255);
    for (int y = 1; y <= 12; ++y) {
        for (int x = 1; x <= 12; ++x) {
            int i = x - 1 + (y - 1) * 12;
            int x0 = x * 80;
            int y0 = y * 80;
            
            ofPoint pt;
            pt.x = x0 + 15 + ofMap(sin(t * x / 2), -1, 1, 0, 50);
            pt.y = y0 + 15 + ofMap(cos(t * y / 2), -1, 1, 0, 50);
            
            ofDrawCircle(pt, 4);
            
//            line[i].addVertex(pt);
//            if (line[i].size() > 10) {
//                vector<ofPoint> vertices = line[i].getVertices();
//                vertices.erase(vertices.begin());
//            }
//
//            line[i].draw();
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
