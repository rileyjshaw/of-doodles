#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
	
    // Gets the computer screen size.
    screenWidth = ofGetWidth();
    screenHeight = ofGetHeight();
    
	vidGrabber.setVerbose(true);
    
//    Sets up the webcam to grab a video. We try to record a video at the
//    same resolution as our computer screen, but that's probably too big
//    for the camera. SO...
	vidGrabber.setup(screenWidth, screenHeight);
    
    // After we set it up, we may end up with a different size.
    // So update our variables to reflect that.
    camWidth = vidGrabber.getWidth();
    camHeight = vidGrabber.getHeight();
    
	font.load("Courier New Bold.ttf", 9);

    // This is a list of characters that goes in order from characters that don't
    // make a big visual impact (eg. a period) to ones that take up a lot of space
    // (eg. the letter "Q"). Soon, we'll replace the webcam pixels with these
    // characters; light regions will be replaced with characters like space or period
    // and dark regions with characters like "Q" and "R".
    //
    // This specific set of characters comes from processing:
    // http://processing.org/learning/library/asciivideo.html
    asciiCharacters =  string("{}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
	
    ofEnableAlphaBlending();
    bg = vidGrabber.getPixels();
}


//--------------------------------------------------------------
void ofApp::update(){
	vidGrabber.update();
    
    if (vidGrabber.isFrameNew()) {
        if (bLearnBackground) {
            bg = vidGrabber.getPixels();
            bLearnBackground = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // change background video alpha value based on the mouse position
    float videoAlphaValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    
    // set a white fill color with the alpha generated above
    ofSetColor(255, 255, 255, videoAlphaValue);

    // draw the raw video frame with the alpha value generated above
//    vidGrabber.draw(0, 0, screenWidth, screenHeight);
    ofImage im;
    im.setFromPixels(bg);
    im.draw(0, 0, screenWidth, screenHeight);

	ofPixelsRef pixelsRef = vidGrabber.getPixels();
    
    ofSetColor(0);

    // Loop through the pixel data from our webcam:
    for (int cameraX = 0; cameraX < camWidth; cameraX += 7) {
        for (int cameraY = 0; cameraY < camHeight; cameraY += 9) {
            int screenX = cameraX * screenWidth / camWidth;
            int screenY = cameraY * screenHeight / camHeight;
            ofColor fgColor = pixelsRef.getColor(cameraX, cameraY);
            ofColor bgColor = bg.getColor(cameraX, cameraY);
            int d = abs(fgColor.r - bgColor.r) + abs(fgColor.g - bgColor.g) + abs(fgColor.b - bgColor.b);
            
            if (d < 70) continue;
            
            // get the pixel and its lightness (lightness is the average of its RGB values)
            float lightness = fgColor.getLightness();
            // calculate the index of the character from our asciiCharacters array
            int character = powf( ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();
            // draw the character at the correct location
            font.drawString(ofToString(asciiCharacters[character]), screenX, screenY);
        }
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
    switch (key){
        case ' ':
            bLearnBackground = true;
            break;
        case 's':
        case 'S':
            // in fullscreen mode, on a pc at least, the
            // first time video settings the come up
            // they come up *under* the fullscreen window
            // use alt-tab to navigate to the settings
            // window. we are working on a fix for this...
            vidGrabber.videoSettings();
            break;
    }
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
