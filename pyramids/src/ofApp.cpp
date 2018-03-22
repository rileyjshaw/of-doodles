#include "ofApp.h"

// Sets normals for a triangle mesh.
void setNormals(ofMesh &mesh) {
    int nV = mesh.getNumVertices();
    int nT = mesh.getNumIndices() / 3;
    
    vector<ofPoint> norm(nV); // Array for the normals.
    
    // Scan all the triangles. For each triangle add its
    // normal to norm's vectors of triangle's vertices.
    for (int t=0; t<nT; t++) {
        // Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        // Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        // Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        // Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}

//--------------------------------------------------------------
void ofApp::setup(){
    light.enable();
    
    ofPoint v0 = ofPoint(-200, -100, 0);
    ofPoint v1 = ofPoint(200, -100, 0);
    ofPoint v2 = ofPoint(0, 200, 0);
    ofPoint v3 = ofPoint(0, 0, 100);
    
    mesh.addVertex(v0);
    mesh.addColor(ofColor(255, 255, 255));
    mesh.addVertex(v1);
    mesh.addColor(ofColor(255, 255, 255));
    mesh.addVertex(v2);
    mesh.addColor(ofColor(255, 255, 255));
    
    mesh.addVertex(v0);
    mesh.addColor(ofColor(255, 0, 0));
    mesh.addVertex(v1);
    mesh.addColor(ofColor(255, 0, 0));
    mesh.addVertex(v3);
    mesh.addColor(ofColor(255, 0, 0));
    
    mesh.addVertex(v0);
    mesh.addColor(ofColor(0, 255, 0));
    mesh.addVertex(v2);
    mesh.addColor(ofColor(0, 255, 0));
    mesh.addVertex(v3);
    mesh.addColor(ofColor(0, 255, 0));
    
    mesh.addVertex(v1);
    mesh.addColor(ofColor(0, 0, 255));
    mesh.addVertex(v2);
    mesh.addColor(ofColor(0, 0, 255));
    mesh.addVertex(v3);
    mesh.addColor(ofColor(0, 0, 255));
    
    mesh.setupIndicesAuto();
    setNormals(mesh);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    ofBackgroundGradient(ofColor(255), ofColor(128));
    
    float time = ofGetElapsedTimef();
    float angle = time * 30;
    
    ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0 );
//        ofRotate(angle, 3, 1, 1);
        ofSetColor(255, 128, 255);
        mesh.setMode(OF_PRIMITIVE_TRIANGLES);
//        mesh.drawWireframe();
        mesh.draw();
    
        mesh.setMode(OF_PRIMITIVE_POINTS);
        glPointSize(40);
        glEnable(GL_POINT_SMOOTH);
        mesh.draw();
    ofPopMatrix();
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
