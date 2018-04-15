#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
    
    keyMidiIn.openPort("MPKmini2");
    drumMidiIn.openPort("UM-ONE");
	
	// add ofApp as a listener
	keyMidiIn.addListener(this);
    drumMidiIn.addListener(this);
    
    lastPitch = 20;
    currentPitch = 22;
    
    kickFlash = 0;
    r = 50;
    volume = r;
}

//--------------------------------------------------------------
void ofApp::update() {
    if (kickFlash) --kickFlash;
    
         if (r < volume) ++r;
    else if (r > volume) --r;
}

//--------------------------------------------------------------
void ofApp::draw() {
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    float cX = w / 2;
    float cY = h / 2;
    float t = ofGetElapsedTimef() / 20;
    
    ofSetBackgroundColor(ofMap(kickFlash, 0, 20, 0, 255));
    ofSetColor(255);
    
    for (int i = 0; i < nPoints; ++i) {
        ofPoint pt;
        pt.x = cX + r * sin(lastPitch * t + TWO_PI * i / nPoints);
        pt.y = cY + r * sin(currentPitch * t + TWO_PI * i / nPoints);
        
        ofDrawCircle(pt, 2);
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
	// clean up
	keyMidiIn.closePort();
    drumMidiIn.closePort();
	keyMidiIn.removeListener(this);
    drumMidiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
	midiMessage = msg;

    if (msg.status == MIDI_NOTE_ON and msg.velocity) {
        if (!msg.portName.compare("MPKmini2")) {
            lastPitch = currentPitch;
            currentPitch = msg.pitch;
            volume = ofMap(msg.velocity, 0, 127, 40, 80);
        } else if (!msg.portName.compare("UM-ONE")) {
            kickFlash = 16;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased() {
}
