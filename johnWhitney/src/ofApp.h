#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

const static int nPoints = 8;

class ofApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	int lastPitch;
    int currentPitch;
    int volume;
    
    int r;
    int kickFlash;
	
    int keyChannel;
    int drumChannel;
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
    
    Point points[nPoints];
};
