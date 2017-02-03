#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <random>
//
#include <boost/asio.hpp>
//
#include "queue_test.h"
#include "MsgParser.h"

using namespace std;
using namespace queue_test;



void HandleConnections(map<int, queue<string>>& mapRef)
{
	char buff[1024];
	boost::asio::io_service service;
	auto parser = MsgParser();

	boost::asio::ip::udp::socket sock(service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8001));

	cout << "Starting server loop ..." << endl;
	while (true)
	{
		boost::asio::ip::udp::endpoint sender_ep;

		int bytes = sock.receive_from(boost::asio::buffer(buff), sender_ep);
		string msg(buff, bytes);
		cout << "Echo: got msg = " << msg << endl;
		auto prodId = parser.ParseMsg(msg);
		string cmd = GetCurrentCmd(mapRef, prodId);
		sock.send_to(boost::asio::buffer(cmd), sender_ep);
	}
}


using namespace queue_test;


int main(int argc, char *argv[])
{
	map<int, queue<string>> CmdQueueMap;

	cout << "Number of available commands = " << gCmds.size() << endl << endl;

	// Generate 5x queues - each 7 commands long.
	CmdQueueMap = GenerateCmdQueues(5, 7);

	PrintCmdQueues(CmdQueueMap);

	// Regenerate a larger map(100x keys) of queues - eah w. 5x cmds

	HandleConnections(CmdQueueMap);

	return 0;
}

