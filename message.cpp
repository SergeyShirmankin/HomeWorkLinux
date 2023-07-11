#include "Message.h"
#include <fstream>
#include <filesystem>
const std::string fileNameM = "message.txt";
Message::Message()
{
	readMessage();
}
Message::~Message()
{
	writeMessage();
}
void Message::set_newText(const std::string& newText)
{
	text_ = newText;
}
void Message::set_newSender(const std::string& newSender)
{
	sender_ = newSender;
}
void Message::set_newResiver(const std::string& newResiver)
{
	resiver_ = newResiver;
}
std::string& Message::getText()
{
	return text_;
}
std::string& Message::getSender()
{
	return sender_;
}
std::string& Message::getResiver()
{
	return resiver_;
}

void Message::writeMessage()
	{
	    //std::fstream file("message.txt", std::ios::out);
		std::fstream file(fileNameM, std::ios::out);
        file << "_text:" << text_ << "\n";
		file << "_sender:" << sender_ << "\n";
		file << "_receiver:" << resiver_ << "\n";
		file.close();
	}

void Message::readMessage()
{
	//std::fstream file("message.txt", std::ios::in);
    std::fstream file(fileNameM, std::ios::in);

	auto permission = std::filesystem::perms::group_all |
		std::filesystem::perms::others_all;
	//std::filesystem::permissions("message.txt", permission,
        std::filesystem::permissions(fileNameM, permission,
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
				if (name == "_text")
					text_ = value;
				else if (name == "_sender")
					sender_ = value;
				else if (name == "_receiver")
					resiver_ = value;
			}
		}
	}
	file.close();
}




