
#include "Contact.hpp"

void Contact::setFirstname(std::string first_name) {
    this->first_name = first_name;
}

void Contact::setLastname(std::string last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(std::string nick_name) {
    this->nick_name = nick_name;
}

void Contact::setPhonenumber(std::string phone_number) {
    this->phone_number = phone_number;
}

void Contact::setSecret(std::string secret) {
    this->secret = secret;
}

std::string Contact::getFirstname() {
    return first_name;
}

std::string Contact::getLastname() {
    return last_name;
}

std::string Contact::getNickname() {
    return nick_name;
}

std::string Contact::getPhonenumber() {
    return phone_number;
}

std::string Contact::getSecret() {
    return secret;
}
