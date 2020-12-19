#pragma once
#include <enet/include/enet.h>

namespace core::network
{
	enum ClientState
	{
		Connected,
		Connecting,
		Preauth,
		Authorized,
		Disconnected,
		None
	};

	enum PlayerState
	{
		Alive,
		Dead,
		None
	};

	struct NetworkClient
	{
		int guid;
		char name[32];
	};

	struct NetworkPlayer
	{
		NetworkClient client;
		// location
		// animation state
		// velocity
	};

	namespace packet
	{
		struct ServerUpdateOnTick
		{
			int time;
			int tick;
			int player_count;
			// player list
			bool player_update = true;
		};

		struct PlayerUpdate
		{
			// in response to ServerUpdateOnTick::player_update
		};
	}
}