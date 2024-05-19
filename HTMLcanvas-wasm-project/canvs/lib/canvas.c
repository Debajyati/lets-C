#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>

// number of circles
#define NUM_CIRCLES 300

// Circle Structure
struct Circle {
  int x; // x coordinate
  int y; // y coordinate
  int r; // circle radius
  int cr; // color RED
  int cg; // color GREEN
  int cb; // color BLUE
};
// Circle Animation Data Structure
struct CircleAnimationData {
  int x; // x coordinate
  int y; // y coordinate
  int r; // circle radius
  int xv; // x axis velocity
  int yv; // y axis velocity
  int xd; // x axis direction ( 1 == forward )
  int yd; // y axis direction ( 1 == forward )
};
// array of 'Circle's
struct Circle circles[NUM_CIRCLES];
struct CircleAnimationData animationData[NUM_CIRCLES];

// random number generator
extern EMSCRIPTEN_KEEPALIVE int getRand(int max) {
  return (rand() % max);
}

// Init circle data and start render - JS
int main()
{
  // seed random number generator
  srand(time(NULL));

  // create circles
  for (int i=0; i<NUM_CIRCLES; i++) {

    // get radius
    int radius = getRand(50);

    // coordinates
    int x = getRand(1000) + radius;
    int y = getRand(1000) + radius;

    // fill animation data struct - i
    animationData[i].x = x;
    animationData[i].y = y;
    animationData[i].r = radius;
    animationData[i].xv = getRand(10); 
    animationData[i].yv = getRand(10);
    animationData[i].xd = 1;
    animationData[i].yd = 1;

    // fill circle struct - i
    circles[i].x = x;
    circles[i].y = y;
    circles[i].r = radius;
    circles[i].cr = getRand(255);
    circles[i].cg = getRand(255);
    circles[i].cb = getRand(255);
  }

  // start JS rendering
  EM_ASM({ render($0, $1); }, NUM_CIRCLES*6, 6);
}

extern EMSCRIPTEN_KEEPALIVE struct Circle* getCircles(int canvasWidth, int canvasHeight) {
  // Update Circle data
  for (int i=0; i< NUM_CIRCLES; i++) {
    // Collision RIGHT - set x direction backwards 0
    if ((animationData[i].x + animationData[i].r) >= canvasWidth) {
      animationData[i].xd = 0;
    }
    // Collision LEFT - set x direction forwards 1
    if ((animationData[i].x - animationData[i].r) <= 0) {
      animationData[i].xd = 1;
    }
    // Collision UP - set y direction backwards 0
    if ((animationData[i].y + animationData[i].r) >= canvasHeight) {
      animationData[i].yd = 0;
    }
    // Collision DOWN - set x direction forwards 1
    if ((animationData[i].y - animationData[i].r) <= 0) {
      animationData[i].yd = 1;
    }

    // Move Circle in the specified direction
    if (animationData[i].xd == 1) {
      animationData[i].x += animationData[i].xv;
    } else {
      animationData[i].x -= animationData[i].xv;
    }
    if (animationData[i].yd == 1) {
      animationData[i].y += animationData[i].yv;
    } else {
      animationData[i].y -= animationData[i].yv;
    }

    // Update matching Circle data
    circles[i].x = animationData[i].x;
    circles[i].y = animationData[i].y;
  }
  // return updated circles 
  return circles;
}

