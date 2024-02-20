#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

extern bool frozen;
extern int frozen_cube;
extern int frozen_ship;
extern int frozen_ball;
extern int frozen_ufo;
extern int frozen_wave;
extern int frozen_robot;
extern int frozen_spider;
extern int frozen_swing;
extern int frozen_jetpack;
extern int frozen_color1;
extern int frozen_color2;
extern int frozen_color3;
extern bool frozen_glow;

extern int cube;
extern int ship;
extern int ball;
extern int ufo;
extern int wave;
extern int robot;
extern int spider;
extern int swing;
extern int jetpack;
extern int color1;
extern int color2;
extern int color3;
extern bool glow;

class $modify(ProfilePage) {
	bool init(int accountID, bool ownProfile) {
		GameManager* gm = GameManager::sharedState();
		if (ownProfile) {
			if (frozen) {

				cube = gm->getPlayerFrame();
				ship = gm->getPlayerShip();
				ball = gm->getPlayerBall();
				ufo = gm->getPlayerBird();
				wave = gm->getPlayerDart();
				robot = gm->getPlayerRobot();
				spider = gm->getPlayerSpider();
				swing = gm->getPlayerSwing();
				jetpack = gm->getPlayerJetpack();
				color1 = gm->getPlayerColor();
				color2 = gm->getPlayerColor2();
				color3 = gm->getPlayerGlowColor();		
				glow = gm->m_playerGlow;

				gm->setPlayerFrame(frozen_cube); 
				gm->setPlayerShip(frozen_ship); 
				gm->setPlayerBall(frozen_ball); 
				gm->setPlayerBird(frozen_ufo); 
				gm->setPlayerDart(frozen_wave); 
				gm->setPlayerRobot(frozen_robot); 
				gm->setPlayerSpider(frozen_spider); 
				gm->setPlayerSwing(frozen_swing); 
				gm->setPlayerJetpack(frozen_jetpack); 
				gm->setPlayerColor(frozen_color1); 
				gm->setPlayerColor2(frozen_color2); 
				gm->setPlayerColor3(frozen_color3);
				gm->setPlayerGlow(frozen_glow);
			}
		}
		bool result = ProfilePage::init(accountID, ownProfile);
		return result;
	}

	void onClose(cocos2d::CCObject* sender) {
		ProfilePage::onClose(sender);

		GameManager* gm = GameManager::sharedState();

		if (frozen) {
			gm->setPlayerFrame(cube); 
			gm->setPlayerShip(ship); 
			gm->setPlayerBall(ball); 
			gm->setPlayerBird(ufo); 
			gm->setPlayerDart(wave); 
			gm->setPlayerRobot(robot); 
			gm->setPlayerSpider(spider); 
			gm->setPlayerSwing(swing); 
			gm->setPlayerJetpack(jetpack); 
			gm->setPlayerColor(color1); 
			gm->setPlayerColor2(color2); 
			gm->setPlayerColor3(color3);
			gm->setPlayerGlow(glow);
		}
	}
};