#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("RammettoOne-Regular.ttf", 200, true, true, true);
    
    float xOffset = (ofGetWidth() - font.stringWidth("string")) / 2;
    float yOffset = (ofGetHeight() - font.stringHeight("string"));
    
    vector <ofTTFCharacter> characterPaths = font.getStringAsPoints("string");
    
    for (auto &characterPath : characterPaths) {
        vector <ofPolyline> linesPreSample = characterPath.getOutline();
        
        // Resample spacing.
        for (int i = 0; i < linesPreSample.size(); i++){
            ofPolyline line = linesPreSample[i];
            line = line.getResampledBySpacing(20);
            
            for (auto &point : line) {
                point.x += xOffset;
                point.y += yOffset;
            }
            
            lines.push_back(line);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines[i].size(); j++){
            lines[i][j].x += 0.3 * (sin(ofGetElapsedTimef() * 4 + j*0.4) +
                                    sin(ofGetElapsedTimef() * 3 + j*0.9) +
                                    sin(ofGetElapsedTimef() * 7 + j*0.1));
        }
        
        lines[i].draw();
        
        for (int j = 0; j < lines[i].size(); j++){
            lines[i][j].y += 25 * sin(ofGetElapsedTimef() * 3);
        }
        
        lines[i].draw();
        
        for (int j = 0; j < lines[i].size(); j++){
            lines[i][j].y += 25 * sin(ofGetElapsedTimef() * 3);
        }
        
        lines[i].draw();
        
        for (int j = 0; j < lines[i].size(); j++){
            lines[i][j].y += 25 * sin(ofGetElapsedTimef() * 3);
        }
        
        lines[i].draw();
        
        for (int j = 0; j < lines[i].size(); j++){
            lines[i][j].y += 25 * sin(ofGetElapsedTimef() * 3);
        }
        
        lines[i].draw();
        
        for (int j = 0; j < lines[i].size(); j++){
            lines[i][j].y -= 100 * sin(ofGetElapsedTimef() * 3);
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
