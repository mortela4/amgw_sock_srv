
#include "queue_test.h"


	/// Globals - local to this module

	/// ************** UTILITY FUNCTIONS FOR TEST ONLY *****************

	/// Maps integers i=0-->numKeys to (pseudo-random) command string
	map<int, queue<string>> queue_test::GenerateCmdQueues(int numKeys, int numElements)
	{
		map<int, queue<string>> cmdMap;

		for (int i = 0; i < numKeys; i++)
		{
			queue<string> tmpQueue;
			for (int j = 0; j < numElements; j++)
			{
				string cmd = GetRandomCmd(gCmds);
				tmpQueue.push(cmd);
			}
			cmdMap[i] = tmpQueue;
		}

		return cmdMap;
	}

	void queue_test::PrintCmdQueues(map<int, queue<string>> cmdMap)
	{
		cout << "All command-queues" << endl;
		cout << "------------------" << endl;
		for (auto k = 0; k<cmdMap.size(); k++)
		{
			cout << "Cmd-queue for key=" << k << " : ";
			auto cmdQueue = cmdMap[k];

			if (cmdQueue.empty() == true)
			{
				cout << "queue empty!" << endl;
				continue;
			}

			while (cmdQueue.empty() == false)
			{
				string cmd = cmdQueue.front();
				cmdQueue.pop();
				cout << cmd << " ";
			}
			cout << endl;
		}
	}

	inline string queue_test::GetCurrentCmd(map<int, queue<string>>& mapRef, int prodId)
	{
		string cmd = mapRef[prodId].front();

		mapRef[prodId].pop();

		return cmd;
	}


