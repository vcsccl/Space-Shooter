#include "ofMain.h"

struct star {
	float x;
	float y;
	float w;
	float h;
	ofColor c;
};

struct star* star_construct(float x, float y, float w, float h, float c) {
	struct star *thisStar = (struct star*)malloc(sizeof(struct star));
	thisStar->x = x;
	thisStar->y = y;
	thisStar->w = w;
	thisStar->h = h;
	thisStar->c = ofColor(ofRandom(200, 255), ofRandom(150, 250), ofRandom(150, 250));
	return thisStar;
}

void star_draw(struct star* star) {
	ofSetColor(star->c);
	ofDrawRectangle(star->x, star->y, star->w, star->h);
	ofSetColor(ofColor(255, 255, 255));
}

void star_animate(struct star* star) {
	star->y += ofRandom(0.7, 1.0);
	if (star->y >= ofGetHeight()) {
		star->y = 0;
		star->x = ofRandomWidth();
	};
}

void star_animate1(struct star* star) {
	star->y += ofRandom(0.3, 0.7);
	if (star->y >= ofGetHeight()) {
		star->y = 0;
		star->x = ofRandomWidth();
	};
}

void star_animate2(struct star* star) {
	star->y += ofRandom(0.0, 0.3);
	if (star->y >= ofGetHeight()) {
		star->y = 0;
		star->x = ofRandomWidth();
	};
}