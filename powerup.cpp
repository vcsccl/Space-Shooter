#include "ofMain.h"

struct powerup {
	float x;
	float y;
	float z;
	float w;
	float h;
};

struct link {
	float linkX;
	float linkY;
};

struct powerup* powerup_construct(float x, float y, float z, float w, float h) {
	struct powerup *greenPowerup = (struct powerup*)malloc(sizeof(struct powerup));
	greenPowerup->x = x;
	greenPowerup->y = y;
	greenPowerup->z = z;
	greenPowerup->h = w;
	greenPowerup->w = h;
	return greenPowerup;
}

void powerup_draw(struct powerup* powerup, ofImage powerupImage) {
	powerupImage.draw(powerup->x, powerup->y, powerup->z, powerup->w, powerup->h);
}

void powerup_animate(struct powerup* powerup) {
	powerup->y += 0.5;
}

bool powerup_onscreen(struct powerup *powerup){
	return powerup->y < ofGetScreenHeight();
}

void powerup_delete(struct powerup *powerup) {
	free(powerup);
}