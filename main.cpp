#include "User.h"
#include "Message.h"
#include <string>
#include <iostream>
int main()
{
	User user;
	std::cout << "Inial user " << std::endl;
	std::cout << "name " << user.getName() << std::endl;
	std::cout << "login " << user.getLogin() << std::endl;
	std::cout << "password " << user.getPass() << std::endl;

	const std::string  newName = "Grinko";
	user.set_newName(newName);
	const std::string  newLogin = "Grisha";
	user.set_newLogin(newLogin);
	const std::string  newPassword = "111111";
	user.set_newPassword(newPassword);
	//user.writeUser();

	std::cout << "Current user " << std::endl;
	std::cout << "name " << user.getName() << std::endl;
	std::cout << "login " << user.getLogin() << std::endl;
	std::cout << "password " << user.getPass() << std::endl;
	//-------------------------------------------------
	Message message;
	std::cout << "Inial message " << std::endl;
	std::cout << "text " << message.getText() << std::endl;
	std::cout << "sender " << message.getSender() << std::endl;
	std::cout << "resiver " << message.getResiver() << std::endl;

	const std::string  newText = "Hi_everybody";
	message.set_newText(newText);
	const std::string  newSender = "Sasha";
	message.set_newSender(newSender);
	const std::string  newResiver = "Grisha";
	message.set_newResiver(newResiver);
	//message.writeMessage();

	std::cout << "Current  message " << std::endl;
	std::cout << "text " << message.getText() << std::endl;
	std::cout << "sender " << message.getSender() << std::endl;
	std::cout << "resiver " << message.getResiver() << std::endl;

}
