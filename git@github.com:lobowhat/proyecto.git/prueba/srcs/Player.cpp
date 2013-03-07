/*
 * Player.cpp
 *
 *  Created on: 07/03/2013
 *      Author: jose
 */

#include "Player.h"

Player::Player() {
	this->score = 0;
	this->highSpeed = 0;
	this->highTrack = 0;
	this->highTraction = 0;
	this->mediumTrack = 0;
	this->invincible = 0;
	this->destroy = false;
	this->posX = 0;
	this->posY = 0;
	this->reset = false;
}

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
