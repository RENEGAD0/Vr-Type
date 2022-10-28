#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Enemy1.h"
#include "Game.h"


#define JUMP_ANGLE_STEP 4
#define JUMP_HEIGHT 96



enum Enemy1Anims
{
	STAND_RIGHT, MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN
};


void Enemy1::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram)
{

	spritesheet.loadFromFile("images/Enemy4.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.25, 0.5), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(1);

	sprite->setAnimationSpeed(STAND_RIGHT, 8);
	sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(MOVE_UP, 3);
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.25f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(MOVE_UP, glm::vec2(0.5f, 0.f));


	sprite->setAnimationSpeed(MOVE_DOWN, 3);
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.25f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));
	sprite->addKeyframe(MOVE_DOWN, glm::vec2(0.50f, 0.5f));


	sprite->setAnimationSpeed(MOVE_LEFT, 4);
	sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.f));


	sprite->setAnimationSpeed(MOVE_RIGHT, 4);
	sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.f, 0.f));


	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));

}

void Enemy1::update(int deltaTime) {
	sprite->update(deltaTime);
	if (Game::instance().getSpecialKey(GLUT_KEY_LEFT)) {
		if (sprite->animation() != MOVE_LEFT)
			sprite->changeAnimation(MOVE_LEFT);
		posPlayer.x -= 2;
		if (map->collisionMoveLeft(posPlayer, glm::ivec2(32, 32))) {
			posPlayer.x += 2;
			sprite->changeAnimation(STAND_RIGHT);
		}
	}
	else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
	{
		if (sprite->animation() != MOVE_RIGHT)
			sprite->changeAnimation(MOVE_RIGHT);
		posPlayer.x += 2;
		if (map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
		{
			posPlayer.x -= 2;
			sprite->changeAnimation(STAND_RIGHT);
		}
	}
	else if (Game::instance().getSpecialKey(GLUT_KEY_UP))
	{
		if (sprite->animation() != MOVE_UP) sprite->changeAnimation(MOVE_UP);
		posPlayer.y -= 2;
		if (map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
		{
			posPlayer.y -= 2;
			sprite->changeAnimation(STAND_RIGHT);
		}
	}
	else if (Game::instance().getSpecialKey(GLUT_KEY_DOWN))
	{
		if (sprite->animation() != MOVE_DOWN)
			sprite->changeAnimation(MOVE_DOWN);
		posPlayer.y += 2;
		if (map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
		{
			posPlayer.x -= 2;
			sprite->changeAnimation(STAND_RIGHT);
		}
	}
	else if (Game::instance().getSpecialKey(GLUT_KEY_UP) && Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
	{
		if (sprite->animation() != MOVE_UP) sprite->changeAnimation(MOVE_UP);
		posPlayer.y -= 2;
		posPlayer.x += 2;
		if (map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
		{
			posPlayer.y -= 2;
			posPlayer.x += 2;
			sprite->changeAnimation(STAND_RIGHT);
		}
	}


	else
	{
		if (sprite->animation() == MOVE_UP)
			sprite->changeAnimation(STAND_RIGHT);
		else if (sprite->animation() == MOVE_DOWN)
			sprite->changeAnimation(STAND_RIGHT);
	}
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}

void Enemy1::render()
{
	sprite->render();
}

void Enemy1::setTileMap(TileMap* tileMap)
{
	map = tileMap;
}

void Enemy1::setPosition(const glm::vec2& pos)
{
	posPlayer = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}




