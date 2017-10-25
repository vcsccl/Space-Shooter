#pragma once

struct beam *beam_construct(float x, float y, float h, float w);
void beam_draw(struct beam* beam);
void beam_animate(struct beam* beam, bool fir2, struct link* link);