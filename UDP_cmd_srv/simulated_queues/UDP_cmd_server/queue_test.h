#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <random>

using namespace std;


namespace queue_test
{
	/// Globals
	const vector<string> gCmds = vector<string>{ "CMD1", "CMD2", "CMD3", "", "CMD4", "CMD5" };	// Use an empty one for realistic sim.


	/// Templates
	template <typename T>
	T GetRandomCmd(vector<T> cmds)
	{
		static random_device rd;
		static mt19937 gen(rd());

		std::uniform_int_distribution<int> dist(0, cmds.size() - 1);    // Limit span to 0-->cmds.size-1

		int rNum = dist(gen);   // Get random number

		return cmds[rNum];
	}

	template <typename T>
	void EmptyCmdQueues(map<int, queue<T>>& mref)
	{
		for (auto k = 0; k<mref.size(); k++)
		{
			while (mref[k].empty() == false)
			{
				T tmp = mref[k].front();
				mref[k].pop();
			}
			cout << "Queue no." << k << " emptied!" << endl;
		}
	}

	/// Protos
	extern map<int, queue<string>> GenerateCmdQueues(int numKeys, int numElements);
	extern void PrintCmdQueues(map<int, queue<string>> cmdMap);
	extern inline string GetCurrentCmd(map<int, queue<string>>& mapRef, int prodId);
}


