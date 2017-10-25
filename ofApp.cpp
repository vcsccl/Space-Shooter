#include "ofApp.h"
#include "spaceship.h"
#include "bolt.h"
#include "powerup.h"
#include "HUD.h"
#include "starfield.h"
#include "beam.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);

	mainSpaceship = spaceship_construct(B_WIDTH, B_HEIGHT, 0, 100, 100, 0, 0);
	mainBeam = beam_construct(0, 0, 4, 20);
	linkS = link_construct(0, 0);

	myfont.loadFont("font.ttf", 23);
	laser.load("laser.mp3");
	beam.load("beam.mp3");
	background.load("background.mp3");
	bumper.load("bumper.mp3");
	shipImage.load("ship.png");
	powerupImage.load("powerup.png");
	bumper.setVolume(0.5);
	bumper.setSpeed(0.7);
	beam.setSpeed(50);
	background.setVolume(0.3);
	background.setSpeed(0.9);
	background.play();
	background.setLoop(true);

	for (int i = 0; i < 50; ++i) {
		stars[i] = star_construct(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 2, 2.1, 0);
	};
	for (int i = 0; i < 100; ++i) {
		stars1[i] = star_construct(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 1.5, 1.6, 0);
	};
	for (int i = 0; i < 1000; ++i) {
		stars2[i] = star_construct(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 1, 1.1, 0);
	};
}

//--------------------------------------------------------------
void ofApp::update() {
	spaceship_move(mainSpaceship, bumper);
	coord_link(mainSpaceship, linkS);
	beam_animate(mainBeam, fir2, linkS);

	for (int i = 0; i < 50; ++i) {
		star_animate(stars[i]);
	};
	for (int i = 0; i < 100; ++i) {
		star_animate1(stars1[i]);
	};
	for (int i = 0; i < 1000; ++i) {
		star_animate2(stars2[i]);
	};

	if (ofGetFrameNum() > 5000 && ofGetFrameNum() % 5000 == 1) {
		if (mainPowerup == NULL) {
			mainPowerup = powerup_construct(ofRandom(50, ofGetWidth() - 50), -50, 0, 50, 50);
		}
	}
	if (mainPowerup != NULL) {
		powerup_animate(mainPowerup);
		if (!powerup_onscreen(mainPowerup)) {
			powerup_delete(mainPowerup);
			mainPowerup = NULL;
		}
	}
	if (fir == true) {
		if (mainBolt == NULL) {
			mainBolt = bolt_construct(0, 0, linkS);
			laser.play();
		}
	}
	if (mainBolt != NULL) {
		bolt_animate(mainBolt, linkS);
		if (!bolt_onscreen(mainBolt)) {
			bolt_delete(mainBolt);
			mainBolt = NULL;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	hud_overlay(myfont, B_WIDTH);
	beam_draw(mainBeam);

	for (int i = 0; i < 50; ++i) {
		star_draw(stars[i]);
	};
	for (int i = 0; i < 100; ++i) {
		star_draw(stars1[i]);
	};
	for (int i = 0; i < 1000; ++i) {
		star_draw(stars2[i]);
	};

	if (mainPowerup != NULL) {
		powerup_draw(mainPowerup, powerupImage);
	}
	spaceship_draw(mainSpaceship, shipImage);
	if (mainBolt != NULL) {
		bolt_draw(mainBolt);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_RIGHT) {
		spaceship_move_right(mainSpaceship);
	}
	else if (key == OF_KEY_LEFT) {
		spaceship_move_left(mainSpaceship);
	}
	else if (key == OF_KEY_UP) {
		fir = TRUE;
	}
		
	else if (key == OF_KEY_DOWN) {
			fir2 = TRUE;
			beam.play();
			beam.setLoop(true);
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_UP) {
		fir = FALSE;
	}
	else if (key == OF_KEY_DOWN) {
		fir2 = FALSE;
		beam.setLoop(false);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
