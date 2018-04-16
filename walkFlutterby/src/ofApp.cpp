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
        if (ofRandom(1) > 0.9) {
            struct Butterfly butterfly;
            butterfly.position = ofPoint(data3d[i].x, data3d[i].y, data3d[i].z - 50);
            butterfly.velocity = ofPoint(ofRandom(-1, 1), ofRandom(6), ofRandom(-3, -1)).normalize();
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
            butterfly->position.y += butterfly->velocity.y + ofRandom(-0.5, 0.5);
            butterfly->position.x += butterfly->velocity.x + ofRandom(-0.5, 0.5);
            butterfly->position.z += butterfly->velocity.z + ofRandom(-0.5, 0.5);
        }
    }
    
    // Probably a way to delete all at once.
    for (int i = 0; i < numDead; ++i) { butterflies.pop_front(); }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //----------------------------- 3d
    float angle = fmod(ofGetElapsedTimef() / 2.0, 2 * PI);
    cam.setGlobalPosition(sin(angle) * 600.0, ofGetElapsedTimef(), cos(angle) * 600.0);
    cam.setTarget(ofPoint(0, 0, 0));
    cam.begin();
    ofSetDepthTest(true);
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
    
    // Bicep.
    body.addVertex(data3d[13]);
    body.addVertex(data3d[3]);
    body.addVertex(data3d[12]);
    body.draw();
    
    // Bicep.
    body.addVertex(data3d[3]);
    body.addVertex(data3d[4]);
    body.addVertex(data3d[5]);
    body.draw();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < butterflies.size(); ++i) {
        // Butterflies fade in *and* out, with max opacity at MAX_AGE / 2.
        float opacity = 1.0 - (float)abs(2 * butterflies[i].age - MAX_AGE) / MAX_AGE;
        ofSetColor(ofColor(255, 255, 255, opacity * 255));
        ofPushMatrix();
        ofTranslate(butterflies[i].position);
        ofDrawSphere(0, 0, 0, 4);
//        ofMatrix4x4 mat;
//        mat.makeLookAtMatrix(butterflies[i].position, cam.getPosition(), ofPoint(0, 1, 0));
//        ofMultMatrix(mat);
        
//        gifloader.pages[(butterflies[i].age / 4) % gifFrames].draw(0, 0, gifWidth, gifHeight);
        ofPopMatrix();
    }

    ofSetRectMode(OF_RECTMODE_CORNER);
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
