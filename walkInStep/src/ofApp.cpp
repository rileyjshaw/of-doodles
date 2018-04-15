#include "ofApp.h"
#include "data.h"

int MAX_AGE = 400;
ofPoint data3d[24];

//--------------------------------------------------------------
void ofApp::setup(){
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    ofSetColor(255, 255, 255, 0);
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = initialData3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = initialData3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = initialData3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
    ofBackground(0);
    //----------------------------------------------------------------

}

//--------------------------------------------------------------
void ofApp::update(){
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    
    int frameNumber = (int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[frameNumber][i];
    }
    // end do not touch
}

//--------------------------------------------------------------
void ofApp::draw(){
//    //----------------------------- 3d
    cam.begin();
    cam.enableOrtho();
    ofSetDepthTest(true);
    ofRotateY(ofGetElapsedTimef() * 1000 / 30);
    ofSetColor(255);
    
    // Torso.
    ofDrawLine(data3d[0], data3d[1]);
    ofDrawLine(data3d[1], data3d[2]);
    ofDrawLine(data3d[2], data3d[3]);
    
    // Right arm.
    ofDrawLine(data3d[3], data3d[4]);
    ofDrawLine(data3d[4], data3d[5]);
    ofDrawLine(data3d[5], data3d[6]);
    ofDrawLine(data3d[6], data3d[7]);
    
    // Left arm.
    ofDrawLine(data3d[3], data3d[12]);
    ofDrawLine(data3d[12], data3d[13]);
    ofDrawLine(data3d[13], data3d[14]);
    ofDrawLine(data3d[14], data3d[15]);
    
    // Head.
    ofDrawLine(data3d[3], data3d[9]);
    ofDrawLine(data3d[9], data3d[10]);
//    ofDrawSphere(data3d[10], 40);
    
    // Right leg.
    ofDrawLine(data3d[0], data3d[16]);
    ofDrawLine(data3d[16], data3d[17]);
    ofDrawLine(data3d[17], data3d[18]);
    ofDrawLine(data3d[18], data3d[19]);
    
    // Left leg.
    ofDrawLine(data3d[0], data3d[20]);
    ofDrawLine(data3d[20], data3d[21]);
    ofDrawLine(data3d[21], data3d[22]);
    ofDrawLine(data3d[22], data3d[23]);
    
    // Fills.
    ofMesh body;
    body.setMode(OF_PRIMITIVE_TRIANGLES);
    
    // Thigh.
    body.addVertex(data3d[16]);
    body.addVertex(data3d[20]);
    body.addVertex(data3d[21]);
    body.draw();
    
    // Thigh.
    body.addVertex(data3d[20]);
    body.addVertex(data3d[16]);
    body.addVertex(data3d[17]);
    body.draw();

    // Torso.
    body.addVertex(data3d[12]);
    body.addVertex(data3d[4]);
    body.addVertex(data3d[20]);
    body.draw();
    
    // Torso.
    body.addVertex(data3d[20]);
    body.addVertex(data3d[16]);
    body.addVertex(data3d[4]);
    body.draw();
    
    // Neck.
    body.addVertex(data3d[12]);
    body.addVertex(data3d[3]);
    body.addVertex(data3d[4]);
    body.draw();
    
//    // Bicep.
//    body.addVertex(data3d[13]);
//    body.addVertex(data3d[3]);
//    body.addVertex(data3d[12]);
//    body.draw();
//    
//    // Bicep.
//    body.addVertex(data3d[3]);
//    body.addVertex(data3d[4]);
//    body.addVertex(data3d[5]);

    cam.end();
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
