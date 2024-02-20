#include <Geode/Geode.hpp>
#include <Geode/modify/CharacterColorPage.hpp>

using namespace geode::prelude;

bool frozen = Mod::get()->getSavedValue<bool>("frozen");

int frozen_cube = Mod::get()->getSavedValue<int64_t>("frozen_cube", 0);
int frozen_ship = Mod::get()->getSavedValue<int64_t>("frozen_ship", 0);
int frozen_ball = Mod::get()->getSavedValue<int64_t>("frozen_ball", 0);
int frozen_ufo = Mod::get()->getSavedValue<int64_t>("frozen_ufo", 0);
int frozen_wave = Mod::get()->getSavedValue<int64_t>("frozen_wave", 0);
int frozen_robot = Mod::get()->getSavedValue<int64_t>("frozen_robot", 0);
int frozen_spider = Mod::get()->getSavedValue<int64_t>("frozen_spider", 0);
int frozen_swing = Mod::get()->getSavedValue<int64_t>("frozen_swing", 0);
int frozen_jetpack = Mod::get()->getSavedValue<int64_t>("frozen_jetpack", 0);
int frozen_color1 = Mod::get()->getSavedValue<int64_t>("frozen_color1", 0);
int frozen_color2 = Mod::get()->getSavedValue<int64_t>("frozen_color2", 0);
int frozen_color3 = Mod::get()->getSavedValue<int64_t>("frozen_color3", 0);
bool frozen_glow = Mod::get()->getSavedValue<bool>("frozen_glow");

int cube;
int ship;
int ball;
int ufo;
int wave;
int robot;
int spider;
int swing;
int jetpack;
int color1;
int color2;
int color3;
bool glow;

class $modify(FreezeIcons, CharacterColorPage) {

CCSprite* blue_dot;
CCMenuItemSpriteExtra* button;
SimplePlayer* p_cube;
CCLabelBMFont* fi;
CCLabelBMFont* plus_7;

	bool init() {
		bool result = CharacterColorPage::init();

		CCLayer* layer = static_cast<CCLayer*>(getChildren()->objectAtIndex(0));

		CCMenu* menu = CCMenu::create();
		menu->setPosition({0,0});

		m_fields->blue_dot = CCSprite::createWithSpriteFrameName("gj_navDotBtn_on_001.png");

		if (!frozen) m_fields->blue_dot->setColor({ 116, 116, 116 });

		m_fields->button = CCMenuItemSpriteExtra::create(m_fields->blue_dot, this, menu_selector(FreezeIcons::freeze_click));

		m_fields->button->setPosition({61, 248});
		m_fields->button->setScale(1.150);
		menu->addChild(m_fields->button);
		layer->addChild(menu);

		m_fields->plus_7 = CCLabelBMFont::create("+7", "bigFont.fnt");
		m_fields->fi = CCLabelBMFont::create("Frozen\n Icons:", "goldFont.fnt");

		GameManager* gm = GameManager::sharedState();
		m_fields->p_cube = SimplePlayer::create(frozen_cube);

		m_fields->p_cube->m_firstLayer->setColor(gm->colorForIdx(frozen_color1));
		m_fields->p_cube->m_secondLayer->setColor(gm->colorForIdx(frozen_color2));
		m_fields->p_cube->setGlowOutline(gm->colorForIdx(frozen_color3));
		
		if (frozen_glow) m_fields->p_cube->enableCustomGlowColor(gm->colorForIdx(frozen_color3));
		else m_fields->p_cube->disableGlowOutline();

		m_fields->p_cube->updateColors();

		m_fields->p_cube->setPosition({30,182});

		m_fields->fi->setPosition({32,220});
		m_fields->fi->setScale(.525);

		m_fields->plus_7->setScale(.425);
		m_fields->plus_7->setPosition({43,198});

		layer->addChild(m_fields->fi);
		layer->addChild(m_fields->plus_7, 2);
		layer->addChild(m_fields->p_cube);
		if (!frozen) {
			m_fields->fi->setVisible(false);
			m_fields->p_cube->setVisible(false);
			m_fields->plus_7->setVisible(false);
		}
		return result;

	}

	void freeze_click(CCObject*) {

		GameManager* gm = GameManager::sharedState();

		if (frozen) {
			m_fields->p_cube->updatePlayerFrame(gm->getPlayerFrame(), static_cast<IconType>(gm->m_playerIconType));
			m_fields->p_cube->m_firstLayer->setColor(gm->colorForIdx(gm->getPlayerColor()));
			m_fields->p_cube->m_secondLayer->setColor(gm->colorForIdx(gm->getPlayerColor2()));
			m_fields->p_cube->setGlowOutline(gm->colorForIdx(gm->getPlayerGlowColor()));
			m_fields->p_cube->enableCustomGlowColor(gm->colorForIdx(gm->getPlayerGlowColor()));
			
			if (gm->getPlayerGlow()) m_fields->p_cube->enableCustomGlowColor(gm->colorForIdx(gm->getPlayerGlowColor()));
			else m_fields->p_cube->disableGlowOutline();

			m_fields->fi->setVisible(false);
			m_fields->p_cube->setVisible(false);
			m_fields->plus_7->setVisible(false);

			m_fields->blue_dot->setColor({ 116, 116, 116 });

			frozen = false;

			Mod::get()->setSavedValue<bool>("frozen", frozen);
		}
		else {
	
			m_fields->fi->setVisible(true);
			m_fields->p_cube->setVisible(true);
			m_fields->plus_7->setVisible(true);

			m_fields->blue_dot->setColor({255,255,255});
			frozen = true;
			frozen_cube = gm->getPlayerFrame();
			frozen_ship = gm->getPlayerShip();
			frozen_ball = gm->getPlayerBall();
			frozen_ufo = gm->getPlayerBird();
			frozen_wave = gm->getPlayerDart();
			frozen_robot = gm->getPlayerRobot();
			frozen_spider = gm->getPlayerSpider();
			frozen_swing = gm->getPlayerSwing();
			frozen_jetpack = gm->getPlayerJetpack();
			frozen_color1 = gm->getPlayerColor();
			frozen_color2 = gm->getPlayerColor2();
			frozen_color3 = gm->getPlayerGlowColor();		
			frozen_glow = gm->m_playerGlow;

			Mod::get()->setSavedValue<int64_t>("frozen_cube", gm->getPlayerFrame());
			Mod::get()->setSavedValue<int64_t>("frozen_ship", gm->getPlayerShip());
			Mod::get()->setSavedValue<int64_t>("frozen_ball", gm->getPlayerBall());
			Mod::get()->setSavedValue<int64_t>("frozen_ufo", gm->getPlayerBird());
			Mod::get()->setSavedValue<int64_t>("frozen_wave", gm->getPlayerDart());
			Mod::get()->setSavedValue<int64_t>("frozen_robot", gm->getPlayerRobot());
			Mod::get()->setSavedValue<int64_t>("frozen_spider", gm->getPlayerSpider());
			Mod::get()->setSavedValue<int64_t>("frozen_swing", gm->getPlayerSwing());
			Mod::get()->setSavedValue<int64_t>("frozen_jetpack", gm->getPlayerJetpack());
			Mod::get()->setSavedValue<int64_t>("frozen_color1", gm->getPlayerColor());
			Mod::get()->setSavedValue<int64_t>("frozen_color2", gm->getPlayerColor2());
			Mod::get()->setSavedValue<int64_t>("frozen_color3", gm->getPlayerGlowColor());
			Mod::get()->setSavedValue<bool>("frozen_glow", gm->m_playerGlow);

			Mod::get()->setSavedValue<bool>("frozen", frozen);

			Notification::create("Froze Icons", CCSprite::createWithSpriteFrameName("GJ_completesIcon_001.png"), 2.5f)->show();

		}

		m_fields->button->setScale(1.150);
	}
};