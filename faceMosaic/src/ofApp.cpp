#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenWidth = static_cast< float >(ofGetWidth());
    screenHeight = static_cast< float >(ofGetHeight());
    mosaicWidth = sqrt(screenWidth * 2) + 1;
    mosaicHeight = sqrt(screenHeight * 2) + 2;
    sliceWidth = mosaicWidth / 2;
    sliceHeight = mosaicHeight / 2;
    
    cout << screenWidth << endl;
    cout << mosaicWidth * sliceWidth << endl;
    cout << screenHeight << endl;
    cout << mosaicHeight * sliceHeight << endl;
    
    grabber.setup(mosaicWidth, mosaicHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPixels camPixels = grabber.getPixels();
    camPixels.mirror(false, true);
    camPixels.resize(mosaicWidth, mosaicHeight);
    
    // Cooler idea: take slices over time!
    // Program has an initial "Loading..."
    // ohase where it's gathering stuff,
    // then pushes old images out slowly
    // to replace them with the current img.
    // TODO(riley): Could be array[9]s...
    vector<ofImage> slices;
    vector<ofColor> sliceColors;

    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            ofPixels slice = ofPixels(camPixels);
            slice.crop(x * mosaicWidth / 4, y * mosaicHeight / 4, sliceWidth, sliceHeight);

            int nPx = sliceHeight * sliceWidth;
            int r = 0;
            int g = 0;
            int b = 0;
            for (int pxY = 0; pxY < sliceHeight; pxY++) {
                for (int pxX = 0; pxX < sliceWidth; pxX++) {
                    ofColor color = slice.getColor(pxX, pxY);
                    r += color.r;
                    g += color.g;
                    b += color.b;
                }
            }

            sliceColors.push_back(ofColor(r / nPx, g / nPx, b / nPx));
            slices.push_back(ofImage(slice));
        }
    }

    for (int y = 0; y < mosaicHeight; ++y) {
        for (int x = 0; x < mosaicWidth; ++x) {
            ofColor camColor = camPixels.getColor(x, y);
            
            int record = 256 * 3;
            int winner;
            for (int i = 0; i < sliceColors.size(); ++i) {
                ofColor sliceColor = sliceColors[i];
                int distance = abs(camColor.r - sliceColor.r) + abs(camColor.g - sliceColor.g) + abs(camColor.b - sliceColor.b);
                if (distance < record) {
                    record = distance;
                    winner = i;
                }
                slices[winner].draw(x * sliceWidth, y * sliceHeight);
            }
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
