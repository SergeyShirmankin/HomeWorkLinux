#include "User.h"
#include <fstream>
#include <filesystem>
User::User()
{
	readUser();
}
User::~User()
{
  writeUser();
}
void User::set_newName(const std::string& newName)
{
	name_ = newName;
}
void User::set_newLogin(const std::string& newLogin)
{
	login_ = newLogin;
}
void User::set_newPassword(const std::string& newPassword)
{
	password_ = newPassword;
}
std::string& User::getName()
{
	return name_;
}
std::string& User::getLogin()
{
	return login_;
}
std::string& User::getPass()
{
	return password_;
}
void User::writeUser()
{
	std::fstream file("user.txt", std::ios::out);
	file << "_name:" << name_<<"\n";
	file << "_login:" << login_<<"\n";
	file << "_pass:" << password_<<"\n";
	file.close();
}
void User::readUser()
{
	std::fstream file("user.txt", std::ios::in);
	
	auto permission = std::filesystem::perms::group_all |
         std::filesystem::perms::others_all;
     std::filesystem::permissions("user.txt", permission,
         std::filesystem::perm_options::remove);
     
    const std::string delimetr = ":";
	if (file.is_open())
	{
		std::string line;
		std::string name;
		std::string value;

		while (std::getline(file, line))
		{
			size_t delimetrPosition = line.find(delimetr);
			if (delimetrPosition > 0)
			{
				name = line.substr(0, delimetrPosition);
				value = line.substr(delimetrPosition + 1);
				if (name == "_name")
					name_ = value;
				else if (name == "_login")
					login_ = value;
				else if (name == "_pass")
					password_ = value;
			}
		}
	}
	file.close();
}
