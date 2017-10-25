#pragma once

struct bolt *bolt_construct(float x, float y, struct link *link);

void bolt_animate(struct bolt *b, struct link *link);
void bolt_draw(struct bolt *b);
bool bolt_onscreen(struct bolt *b);
void bolt_delete(struct bolt *b);