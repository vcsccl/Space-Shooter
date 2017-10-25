#include "ofMain.h"

struct spaceship {
	float x;
	float y;
	float z;
	float h;
	float w;
	float velocity;
	float theta;
};

struct link {
	float linkX;
	float linkY;
};


struct spaceship* spaceship_construct(float x, float y, float z, float h, float w, float velocity, float theta) {
	struct spaceship *thisShip = (struct spaceship*)malloc(sizeof(struct spaceship));
	thisShip->x = x;
	thisShip->y = y;
	thisShip->z = z;
	thisShip->h = h;
	thisShip->w = w;
	thisShip->velocity = 0;
	thisShip->theta = 0;
	return thisShip;
}

struct link* link_construct(float linkX, float linkY) {
	struct link *link1 = (struct link*)malloc(sizeof(struct link));
	link1->linkX = linkX;
	link1->linkY = linkY;
	return link1;
};


void spaceship_draw(struct spaceship* spaceship, ofImage shipImage) {
	shipImage.draw(spaceship->x, spaceship->y, spaceship->z, spaceship->h, spaceship->w);
}

void spaceship_move(struct spaceship* spaceship, ofSoundPlayer bumper) {
	spaceship->x += spaceship->velocity;
	spaceship->y += sin(spaceship->theta + 10) / 10;
	spaceship->theta += .01;
	if (spaceship->x <= 0) {
		bumper.play();
		spaceship->x = 1;
		spaceship->velocity *= -0.5;
	}
	else if (spaceship->x >= (ofGetWidth() - 100)) {
		bumper.play();
		spaceship->x = ofGetWidth() - 101;
		spaceship->velocity *= -0.5;
	}
}

void spaceship_move_right(struct spaceship* spaceship) {
	spaceship->velocity += 0.5;
}

void spaceship_move_left(struct spaceship* spaceship) {
	spaceship->velocity -= 0.5;
}

void coord_link(struct spaceship *spaceship, struct link *link) {
	link->linkX = spaceship->x + 48.5;
	link->linkY = spaceship->y + 65;
}