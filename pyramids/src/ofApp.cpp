#include "ofApp.h"

bool showingPlacement = false;
bool spaceDown = false;

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

void addTriangle(ofMesh &mesh, ofPoint drawOffset, ofPoint a, ofPoint b, ofPoint c, ofColor color = ofColor(255)) {
    mesh.addVertex(a - drawOffset);
    mesh.addTexCoord(a);
    // mesh.addColor(color);
    mesh.addVertex(b - drawOffset);
    mesh.addTexCoord(b);
    // mesh.addColor(color);
    mesh.addVertex(c - drawOffset);
    mesh.addTexCoord(c);
    // mesh.addColor(color);
}

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("HelveticaNeueMed.ttf", 80);
    
    int gridSize = 10;
    int sideLength = 50;
    int peakHeight = 40;
    
    // light.enable();
    grabber.setup(640, 480);
    
    ofPoint v0; // Peak.
    ofPoint v1; // Top left.
    ofPoint v2; // Bottom left.
    ofPoint v3; // Bottom right.
    ofPoint v4; // Top right.
    
    ofColor c1 = ofColor(0, 255, 255);
    ofColor c2 = ofColor(255, 0, 255);
    ofColor c3 = ofColor(255, 255, 0);
    ofColor c4 = ofColor(255, 0, 0);
    
    vector <ofColor> colors = {c1, c2, c3, c4};
    
    int offsetLength = sideLength * gridSize / 2;
    ofPoint offset = ofPoint(offsetLength, offsetLength);
    
    for (int y = 0; y < gridSize; ++y) {
        int yTop = y * sideLength;
        int yBottom = yTop + sideLength;
        int yMid = (yTop + yBottom) / 2;
        
        v4 = ofPoint(0, yTop, 0);
        v3 = ofPoint(0, yBottom, 0);
        
        for (int x = 0; x < gridSize; ++x) {
            int xMid = (x + 0.5) * sideLength;
            int xRight = (x + 1) * sideLength;
            
            v0 = ofPoint(xMid, yMid, peakHeight);
            v1 = v4;
            v2 = v3;
            v3 = ofPoint(xRight, yBottom, 0);
            v4 = ofPoint(xRight, yTop, 0);

//            // Random colors.
//            c1 = colors[rand() % 4];
//            c2 = colors[rand() % 4];
//            c3 = colors[rand() % 4];
//            c4 = colors[rand() % 4];
            
            addTriangle(mesh, offset, v0, v1, v2);
            addTriangle(mesh, offset, v0, v2, v3);
            addTriangle(mesh, offset, v0, v3, v4);
            addTriangle(mesh, offset, v0, v4, v1);
        }
    }
    
    mesh.setupIndicesAuto();
//    setNormals(mesh);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    ofBackgroundGradient(ofColor(255), ofColor(128));
    
    float time = ofGetElapsedTimef();
    float angle = time * 30;
    
    cam.begin();
    grabber.bind();
    mesh.draw();
    grabber.unbind();
    cam.end();
    
    // See walkFlutterby for what to do next.
    if (showingPlacement) {
        ofSetColor(0);
        ofRectangle boundingBox = font.getStringBoundingBox("SFPC", 0, 0);
        font.drawString("SFPC", (ofGetWidth() - boundingBox.getWidth()) / 2, (ofGetHeight() + boundingBox.getHeight()) / 2);
        ofSetColor(255);
    }
    
//    ofPushMatrix();
////        ofRotate(angle, 3, 1, 1);
////        mesh.drawWireframe();
//        mesh.draw();
//    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (!spaceDown && key == ' ') {
        spaceDown = true;
        showingPlacement = !showingPlacement;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' ') spaceDown = false;
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
