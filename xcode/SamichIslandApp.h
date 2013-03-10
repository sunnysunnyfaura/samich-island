#include "Headers.h"
#include "cinder/Camera.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

using namespace ci;
using namespace ci::app;
using namespace std;
/*
 *  SamichIslandApp.h
 *  SamichIsland
 *
 *  Created by xanthian on 2/3/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SAMICHISLANDAPP_HPP__
#define SAMICHISLANDAPP_HPP__

const size_t NUM_ENEMIES = 10;
const float PI = 3.141592653589793238462643383279502884197;

DrawEngine& DrawEngine::get()
{
    static DrawEngine dg;
    return dg;
}

class SamichIslandApp : public AppBasic {
public:
	//state management
	State appState;
	int count;
    int timeout;
	//window details
	float WIND_H, WIND_W;
	//camera
	CameraPersp mCam;
	//hero details
	Hero hero;
	float JUMP_H;
	//punch details
	Punch punch;
	//bullet details
	float B_RAD, B_VEL; 
	//shooting requirements
	bool leftClick;
	int bullet_counter;
	float shoot_delay;
	//lists
	vector<Bullet> dakka;
	vector<Mook> cannon_fodder;
	vector<Drop> drops;
	//platform things
	AABB bottom_platform, left_platform, right_platform, top_platform;
	
	AABB tower1; //tower on top left
    AABB tower2; //tower on top right
	//tubes for enemies to exit
	AABB tubeA;
	AABB tubeB;
	//others
    //le background
	void prepareSettings( Settings *settings );
	void resize(ResizeEvent event);
	void setup();
	void keyDown( KeyEvent event );
	void keyUp( KeyEvent event );
	void mouseMove( MouseEvent event );
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void update();
	void draw();
};

#endif