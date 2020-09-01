#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Logger
{
	Logger() {}
	static Logger* obj;
public:
	static Logger* getInsgance();
	void sendMessage(string message);
};

Logger* Logger::obj = nullptr;

Logger* Logger::getInsgance()
{
	if (!obj)
		obj = new Logger;
	return obj;
}

inline void Logger::sendMessage(string message)
{
	ofstream out("log.txt", ios::app);
	out << message << " - " << __DATE__ << "  " << __TIME__ << endl;
	out.close();
}

/*Logger* log = Logger::getInsgance();
	log->sendMessage("Error #12");
	log->sendMessage("Error #15");
	log->sendMessage("Error #24");
	log->sendMessage("Error #14");
	delete log;

	Logger* log2 = Logger::getInsgance();*/