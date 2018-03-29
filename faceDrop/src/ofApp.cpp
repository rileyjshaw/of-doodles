#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lineWidth = 4;
    baseValue = 255 / lineWidth;
    screenWidth = static_cast< float >(ofGetWidth());
    screenHeight = static_cast< float >(ofGetHeight());
//    grabber.setPixelFormat(OF_PIXELS_GRAY);  // Linux optimization.
    grabber.setup(screenWidth, screenHeight);
    
    ofBackground(0);
    ofSetColor(255);
    ofSetLineWidth(lineWidth);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPixels camPixels = grabber.getPixels();
//    camPixels.setImageType(OF_IMAGE_GRAYSCALE);
    camPixels.resize(screenWidth / 5, screenHeight / 5);
    ofImage camImg = ofImage(camPixels);
    int w = camImg.getWidth();
    int h = camImg.getHeight();
    
    float xScale = screenWidth / w;
    float yScale = screenHeight / h;
    float channelOffset = yScale / 3;
    
    for (int y = 0; y < h; ++y) {
//        ofPolyline row = ofPolyline();
        ofPolyline r = ofPolyline();
        ofPolyline g = ofPolyline();
        ofPolyline b = ofPolyline();
        for (int x = 0; x < w; ++x) {
//            float yOffset = ofMap(camImg.getColor(x, y).getLightness(), 0, 255, -14, 14);
            float rOffset = ofMap(camImg.getColor(x, y).r, 0, 255, -14, 14) - channelOffset;
            float gOffset = ofMap(camImg.getColor(x, y).g, 0, 255, -14, 14);
            float bOffset = ofMap(camImg.getColor(x, y).b, 0, 255, -14, 14) + channelOffset;
//            row.addVertex(x * xScale, y * yScale + yOffset);
            r.addVertex(x * xScale, y * yScale + rOffset);
            g.addVertex(x * xScale, y * yScale + gOffset);
            b.addVertex(x * xScale, y * yScale + bOffset);
        }
        ofSetColor(baseValue, 0, 0);
        r.draw();
        ofSetColor(0, baseValue, 0);
        g.draw();
        ofSetColor(0, 0, baseValue);
        b.draw();
    }
    
//    camImg.draw(0, 0, screenWidth, screenHeight);
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
