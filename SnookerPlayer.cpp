#include "SnookerPlayer.h"
#include <iostream>
#include <string>
SnookerPlayer::SnookerPlayer(std::string id, std::string father_id, std::string mother_id, int born_year, std::string phone) {
	this->id = id;
	this->father_id = father_id;
	this->mother_id = mother_id;
	this->born_year = born_year;
	this->phone = phone;
}
bool SnookerPlayer::family(SnookerPlayer other_player) {
	return this->father_id == other_player.id || this->mother_id == other_player.id || 
		this->father_id == other_player.father_id || this->mother_id == other_player.mother_id;
}
std::string SnookerPlayer::to_string() {
	return "ID :" + id + ", FATHER_ID: " + father_id + ", MOTHER_ID: " + mother_id + ", BORN_YEAR: " + std::to_string(born_year)
		+ ", Phone: " + phone;
}

std::string SnookerPlayer::get_id() { return id; }
std::string SnookerPlayer::get_father_id() { return father_id; }
std::string SnookerPlayer::get_phone() { return phone; }
int SnookerPlayer::get_born_year() { return this->born_year; }
int SnookerPlayer::get_age(const int& current_year) { return current_year - born_year; }


