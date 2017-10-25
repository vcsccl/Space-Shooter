#include "ofMain.h"

struct bolt {
	float x;
	float y;
};
struct link {
	float linkX;
	float linkY;
};

struct bolt *bolt_construct(float x, float y, struct link *link) {
	struct bolt *temp = (struct bolt*)malloc(sizeof(struct bolt));
	temp->x = link->linkX;
	temp->y = link->linkY;
	return temp;
}

void bolt_animate(struct bolt *b, struct link *link) {
	b->y -= 5;
}

void bolt_draw(struct bolt *b) {
	ofSetColor(ofColor(255, 0, 0));
	ofDrawRectangle(b->x + 45, b->y, 4, 30);
	ofDrawRectangle(b->x - 45, b->y, 4,  30);
	ofSetColor(ofColor(255, 255, 255));
}

bool bolt_onscreen(struct bolt *b) {
	return b->y > -30;
}

void bolt_delete(struct bolt *b) {
	free(b);
}
