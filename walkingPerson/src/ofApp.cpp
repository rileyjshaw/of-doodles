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
    gifloader.load("butterfly.gif");
    gifFrames = gifloader.pages.size();
    gifWidth = gifloader.pages[0].getWidth() / 10;
    gifHeight = gifloader.pages[0].getHeight() / 10;
    gifOffset = ofPoint(-gifWidth / 2, -gifHeight / 2);
    for (int i = 0; i < gifFrames; ++i) {
        gifloader.pages[i].resize(gifWidth, gifHeight);
    }
    
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
    
    for (int i = 0; i < 24; ++i){
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        
        if (ofRandom(1) > 0.99) {
            struct Butterfly butterfly;
            butterfly.position = ofPoint(x, y, z);
            butterfly.age = 0;
            butterflies.push_back(butterfly);
        }
    }

    int numDead = 0;
    for (int i = 0; i < butterflies.size(); ++i) {
        struct Butterfly* butterfly = &butterflies[i];
        int newAge = ++butterfly->age;
        if (newAge > MAX_AGE) {
            ++numDead;
        } else {
            butterfly->position.y += ofRandom(2) * ofRandom(1);
            --butterfly->position.z;
        }
    }
    
    // Probably a way to delete all at once.
    for (int i = 0; i < numDead; ++i) { butterflies.pop_front(); }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    //----------------------------- 3d
    cam.begin();
    cam.enableOrtho();
    ofSetDepthTest(true);
    ofRotateY(ofGetElapsedTimef() * 1000 / 30);
    ofSetColor(255);
    
    for (int i = 0; i < 24; ++i){
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        
        ofDrawSphere(x, y, x, 6);
    }
    
//    ofRotateY(-ofGetElapsedTimef() * 1000 / 30);
    for (int i = 0; i < butterflies.size(); ++i) {
        ofSetColor((1 - (float) butterflies[i].age / MAX_AGE) * 255);
        ofDrawSphere(butterflies[i].position, 2);
        gifloader.pages[(butterflies[i].age / 4) % gifFrames].draw(butterflies[i].position - gifOffset, gifWidth, gifHeight);
    }

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
