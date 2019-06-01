#pragma once
#include "User.h"

class PowerUser : virtual public User
{
private:
	int reputation;
public:
	PowerUser(const char* uName, const char* Password, const char* Title, int Reputation, const char* ip);
	PowerUser();
	PowerUser(const PowerUser& other);
	PowerUser& operator=(const PowerUser& other);
	~PowerUser();

	void getReputationFrom(const User& u);
	int getReputation() const;

	void print() const;
};