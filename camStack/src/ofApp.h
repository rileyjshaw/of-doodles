#pragma once

#include "ofMain.h"

#define FRAME_DELAY 1
#define GRID_X 8
#define GRID_Y 5

// Valid modes: [0-3]
#define MODE 1

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoGrabber grabber;
    ofImage history[FRAME_DELAY][GRID_X * GRID_Y];
    int screenGridWidth;
    int screenGridHeight;
    int camGridWidth;
    int camGridHeight;
};
