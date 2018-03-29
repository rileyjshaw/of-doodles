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
    vector<int> brightnesses;
    vector<ofImage> brightnessToSlice;
    brightnessToSlice.resize(256);

    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            ofPixels slice = ofPixels(camPixels);
            slice.crop(x * mosaicWidth / 4, y * mosaicHeight / 4, sliceWidth, sliceHeight);

            int brightness = 0;
            for (int pxY = 0; pxY < sliceHeight; pxY++) {
                for (int pxX = 0; pxX < sliceWidth; pxX++) {
                    brightness += slice.getColor(pxX, pxY).getBrightness();
                }
            }

            ofImage img = ofImage(slice);
            brightnesses.push_back(brightness / sliceHeight / sliceWidth);
            slices.push_back(img);
        }
    }

    for (int brightness = 0; brightness < 256; ++brightness) {
        int record = 256;

        for (int i = 0; i < brightnesses.size(); i++) {
            int diff = abs(brightness - brightnesses[i]);

            if (diff < record) {
                record = diff;
                ofImage slice = slices[i];
                brightnessToSlice[brightness] = slice;
            }
        }
    }

    for (int y = 0; y < mosaicHeight; ++y) {
        for (int x = 0; x < mosaicWidth; ++x) {
            int brightness = camPixels.getColor(x, y).getBrightness();
            ofImage slice = brightnessToSlice[brightness];
            slice.draw(x * sliceWidth, y * sliceHeight);
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
