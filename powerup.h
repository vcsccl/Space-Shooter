#pragma once

struct powerup *powerup_construct(float x, float y, float z, float w, float h);

void powerup_draw(struct powerup* powerup, ofImage powerupImage);
void powerup_animate(struct powerup* powerup);
void powerup_delete(struct powerup *powerup);
bool powerup_onscreen(struct powerup *powerup);
