#pragma once
#include <string>
class Message
{
public:
	Message();
	~Message();

	void set_newText(const std::string& newText);
	void set_newSender(const std::string& newSender);
	void set_newResiver(const std::string& newResiver);

	std::string& getText();
	std::string& getSender();
	std::string& getResiver();
//	void writeMessage();
//	void readMessage();
private:
	std::string text_;
	std::string sender_;
	std::string resiver_;

	void readMessage();
	void writeMessage();

};
