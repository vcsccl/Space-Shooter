#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	struct spaceship *mainSpaceship;
	struct bolt *mainBolt;
	struct beam *mainBeam;
	struct powerup *mainPowerup;
	struct link *linkS;

	int B_WIDTH = ofGetWidth() / 2;
	int B_HEIGHT = ofGetHeight() - 150;

	bool fir;
	bool fir2;

	struct star *stars[50];
	struct star *stars1[100];
	struct star *stars2[1000];

	ofImage shipImage;
	ofImage powerupImage;
	ofTrueTypeFont myfont;
	ofSoundPlayer laser;
	ofSoundPlayer beam;
	ofSoundPlayer background;
	ofSoundPlayer bumper;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

};
