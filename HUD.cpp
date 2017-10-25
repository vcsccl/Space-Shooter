#include "ofMain.h"

void hud_overlay(ofTrueTypeFont myfont, int B_WIDTH) {
	myfont.drawString("SCORE: ", B_WIDTH - 30, 50);
	string fRate = "Frame Rate: " + ofToString(ofGetFrameRate(), 2);
	string fCount = "Frame Count: " + ofToString(ofGetFrameNum(), 2);
	ofDrawBitmapString(fRate, 5, 10);
	ofDrawBitmapString(fCount, 5, 20);
}
