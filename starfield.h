#pragma once

struct star *star_construct(float x, float y, float w, float h, float c);

void star_draw(struct star* star);
void star_animate(struct star* star);
void star_animate1(struct star* star);
void star_animate2(struct star* star);