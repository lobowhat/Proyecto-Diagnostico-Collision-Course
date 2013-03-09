/*
 * Player.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


//Constructor de clase
Player::Player() {
	this->parser = new GetConfig();
	string file = "Configure.xml";
	this->parser->readConfigFile(file);
	this->score = atoi(parser->getScore());
	this->highSpeed = atoi(parser->getHighSpeed());
	this->highTrack = atoi(parser->getHighTrack());
	this->highTraction = atoi(parser->getHighTraction());
	this->mediumTrack = atoi(parser->getMediumTrack());
	this->invincible = atoi(parser->getInvincible());
	this->destroy = false;
	this->posX = 0;
	this->posY = 0;
	this->reset = false;
}

//Destructor de la clase
Player::~Player() {
}

int Player::getHighSpeed() const {
	return this->highSpeed;
}

void Player::setHighSpeed(int highSpeed) {
	this->highSpeed = highSpeed;
}

int Player::getHighTrack() const {
	return this->highTrack;
}

void Player::setHighTrack(int highTrack) {
	this->highTrack = highTrack;
}

int Player::getHighTraction() const {
	return this->highTraction;
}

void Player::setHighTraction(int highTraction) {
	this->highTraction = highTraction;
}

int Player::getInvincible() const {
	return this->invincible;
}

void Player::setInvincible(int invincible) {
	this->invincible = invincible;
}

int Player::getMediumTrack() const {
	return this->mediumTrack;
}

void Player::setMediumTrack(int mediumTrack) {
	this->mediumTrack = mediumTrack;
}

int Player::getPosX() const {
	return this->posX;
}

void Player::setPosX(int posX) {
	this->posX = posX;
}

int Player::getPosY() const {
	return this->posY;
}

void Player::setPosY(int posY) {
	this->posY = posY;
}

int Player::getScore() const {
	return this->score;
}

void Player::setScore(int score) {
	this->score = score;
}

bool Player::HighSpeed() const{
	if (this->highSpeed == 0){
		return false;
	}else{
		return true;
	}
}

bool Player::HighTrack() const{
	if (this->highTrack == 0){
		return false;
	}else{
		return true;
	}
}

bool Player::HighTraction() const{
	if (this->highTraction == 0){
		return false;
	}else{
		return true;
	}
}

bool Player::MediumTrack() const{
	if (this->mediumTrack == 0){
		return false;
	}else{
		return true;
	}
}

bool Player::Invincible() const{
	if (this->invincible == 0){
		return false;
	}else{
		return true;
	}
}
