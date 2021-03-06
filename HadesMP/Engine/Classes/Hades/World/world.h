#pragma once

namespace engine::hades
{
	class __declspec(align(16)) World
	{
	public:
		static World*& Instance;
	public:
		bool mRunning;
		bool mPaused;
		bool mResetAppOnBegin;
		bool mResetWorldOnBegin;
		bool mResetBinksOnBegin;
		bool mResetWeaponBinksOnBegin;
		bool mUsePreDrawThread;
		bool mIsInited;
		bool mIsPausedAtLuaBreakPoint;
		bool mResetting;
		bool mRequestResume;
		bool mStepFrame;
		int mFrame;
		int mNextObstacleId;
		int mNextUnitId;
		BYTE mBeginRequest[1];
		float mElapsedTime;
		float mSpeedModifier;
		float mSpeedModifierTarget;
		float mSpeedModifierChangeSpeed;
		float mSpeedModifierDuration;
		float SessionWorldTime;
		engine::misc::Color mLoadBackgroundColor;
		DWORD64* pSortScoreSystem;
		DWORD64* pOutlineSystem;
		DWORD64* pWorkerManager;
		engine::hades::GroupManager* pGroupManager;
		engine::hades::UnitManager* pUnitManager;
		DWORD64* pObstacleManager;
		DWORD64* pProjectileManager;
		engine::misc::Handle mPreDrawWorkHandle;
		engine::hades::Map mMap;
		std::string mNextMap;
		std::vector<engine::hades::MapThing*> mMapThingsToDelete;
		std::vector<engine::hades::Thing*> mToClear;
		std::vector<engine::hades::MapThing*> mMissing;

		// TODO: Finish adding fields

		// Methods
		void LoadNextMap(std::string* map_name, int begin_request, engine::misc::Color load_color)
		{
			return static_cast<void(__fastcall*)(World*, std::string*, int, engine::misc::Color)>
				((PVOID)engine::addresses::world::functions::load_next_map)(this, map_name, begin_request, load_color);
		}

		bool AddOutline(engine::hades::Thing* thing, engine::misc::Color col, float opacity, float thickness, float threshold, float duration, bool overlay, bool all_anims)
		{
			return static_cast<bool(__fastcall*)(World*,engine::hades::Thing*, engine::misc::Color, float, float, float, float, bool, bool)>((PVOID)engine::addresses::world::functions::add_outline)
				(this, thing, col, opacity, thickness, threshold, duration, overlay, all_anims);
		}

		// Custom Methods
		MapData* GetMapData()
		{
			return *(MapData**)((uintptr_t)this + 0xA0);
		}

		Map* GetMap()
		{
			return (Map*)((uintptr_t)this + 0x80);
		}
	};

	engine::hades::World*& engine::hades::World::Instance = *(engine::hades::World**)(engine::addresses::world::instance);
}