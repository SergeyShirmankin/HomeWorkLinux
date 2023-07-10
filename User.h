#pragma once
//#pragma once
#include <string>
//char  pachFile [] {" user.txt" };
class User
{
public:
	User();
	~User();

	void set_newName(const std::string& newName);
	void set_newLogin(const std::string& newLogin);
	void set_newPassword(const std::string& newPassword);

	std::string& getName();
	std::string& getLogin();
	std::string& getPass();
//	void writeUser();
//	void readUser();
private:
	std::string name_;
	std::string login_;
	std::string password_;

	void readUser();
	void writeUser();
};
