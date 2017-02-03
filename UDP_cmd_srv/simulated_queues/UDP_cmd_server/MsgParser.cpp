#include "MsgParser.h"

using namespace std;

MsgParser::MsgParser()
{
}


MsgParser::~MsgParser()
{
}


int MsgParser::ParseMsg(string msg)
{
	int prodId;
	float sensorVal;
	istringstream istrm(msg);

	istrm >> prodId >> sensorVal;
	cout << "ProductID=" << prodId << " sensor value=" << sensorVal;

	return prodId;
}

