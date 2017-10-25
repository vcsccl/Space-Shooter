#include "ofMain.h"

struct beam {
	float x;
	float y;
	float h;
	float w;
};

struct link {
	float linkY;
	float linkX;
};

struct beam* beam_construct(float x, float y, float w, float h) {
	struct beam *thisBeam = (struct beam*)malloc(sizeof(struct beam));
	thisBeam->x = x;
	thisBeam->y = y;
	thisBeam->w = w;
	thisBeam->h = h;
	return thisBeam;
}

void beam_draw(struct beam* beam) {
	ofSetColor(ofColor(0, 255, 0));
	ofDrawRectangle(beam->x, beam->y, beam->w, beam->h);
	ofSetColor(ofColor(255, 255, 255));
}


void beam_animate(struct beam* beam, bool fir2, struct link* link) {
	beam->x = link->linkY;
	beam->y = link->linkX;
	if (fir2 == TRUE) {
		beam->y = 0;
		beam->h = link->linkX + 10;
		beam->w = 2 + sin(ofGetFrameNum());
	}
	else {
		beam->w = 0;
		fir2 = FALSE;
	}
}