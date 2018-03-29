#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // We "zoom in" on the webcam image for the actual points we draw,
    // so that the particles near the edge don't exhibit strange behaviour.
    padding = 6;
    screenWidth = static_cast< float >(ofGetWidth());
    screenHeight = static_cast< float >(ofGetHeight());
    grabber.setPixelFormat(OF_PIXELS_GRAY);  // Linux optimization.
    grabber.setup(screenWidth, screenHeight);
    
    ofBackground(0);
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPixels camPixels = grabber.getPixels();
    camPixels.setImageType(OF_IMAGE_GRAYSCALE);
    camPixels.resize(screenWidth / 10, screenHeight / 30);
    camPixels.mirror(false, true);
    ofImage camImg = ofImage(camPixels);
    int w = camImg.getWidth();
    int h = camImg.getHeight();
    
    float xScale = screenWidth / w;
    float yScale = screenHeight / h;
    float channelOffset = yScale / 3;
    
    for (int y = padding, yMax = h - padding; y < yMax; ++y) {
        ofPolyline row = ofPolyline();
        
        for (int x = padding, xMax = w - padding; x < xMax; ++x) {
            ofPoint origin = ofPoint(x, y);
            ofPoint offset = ofPoint(0, 0);
            
            for (int attractorX = x - padding, attractorXMax = x + padding; attractorX < attractorXMax; ++attractorX) {
                for (int attractorY = y - padding, attractorYMax = y + padding; attractorY < attractorYMax; ++attractorY) {
                    ofPoint attractor = ofPoint(attractorX, attractorY);
                    ofPoint direction = (origin - attractor).getNormalized();
                    direction.y *= 3;
                    float dist2 = attractor.squareDistance(origin);
                    
                    float strength = ofMap(camImg.getColor(attractorX, attractorY).getLightness(), 0, 255, -12, 12);
//                    float strength = 60 * ofNoise(20 * sin(float(attractorX * attractorX) / w / w * PI), 20 * sin(float(attractorY * attractorY) / h / h * PI * 2 * 2));
                    offset += strength * direction / dist2;
                }
            }
            
            int canvasX = xScale * (float(x - padding) / (w - padding * 2) * (w + padding) - padding / 2);
            int canvasY = yScale * (float(y - padding) / (h - padding * 2) * (h + padding) - padding / 2);
            ofPoint canvasOrigin = ofPoint(canvasX, canvasY);
            row.addVertex(canvasOrigin + offset);
        }
        
        ofPolyline smoothed = row.getSmoothed(6);
        ofPath path;
        path.moveTo(smoothed[0]);
        for (int i = 1; i < smoothed.size(); ++i) {
            path.lineTo(smoothed[i]);
        }
        path.lineTo(screenWidth, screenHeight);
        path.lineTo(0, screenHeight);
        path.close();
        ofSeedRandom(10000 + y);
        ofRandom(255);  // First one is always zero?
        path.setStrokeWidth(2);
        path.setStrokeColor(ofColor(y % 2 ? 255 : 0));
//        path.setFillColor(ofColor(floor(ofRandom(255)), floor(ofRandom(255)), floor(ofRandom(255))));
        path.setFillColor(ofColor(y % 2 ? 0 : 255));
        path.draw();
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
