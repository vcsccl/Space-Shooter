#pragma once

struct spaceship *spaceship_construct(float x, float y, float z, float h, float w, float velocity, float theta);
struct link *link_construct(float linkX, float linkY);

void coord_link(struct spaceship *spaceship, struct link *link);

void spaceship_draw(struct spaceship* spaceship, ofImage ship);
void spaceship_move(struct spaceship* spaceship, ofSoundPlayer bumper);
void spaceship_move_right(struct spaceship* spaceship);
void spaceship_move_left(struct spaceship* spaceship);

