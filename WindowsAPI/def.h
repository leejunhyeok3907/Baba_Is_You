#pragma once

#define KEY_PREESE(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::UP

enum class eSceneType
{
	Logo,
	Title,
	Play,
	End,
	Tool,
	Max,
};

enum class ePenColor
{
	Red,
	Green,
	Blue,
	End,
};

enum class eBrushColor
{
	Transparent, //≈ı∏Ì
	Black,
	Gray, //167 0 67
	White,
	End,
};

enum class eComponentType
{
	Rigidbody,
	Collider,
	Aimator,
	Sound,
	End,
};

#define _COLLIDER_LAYER 16
enum class eColliderLayer
{
	Default,

	//GameObject
	BackGround,
	Tile,
	Player,
	Player_Projecttile,
	Monster,
	Monster_Projecttile,
	Ground,

	//UI
	BackPack,
	UI = _COLLIDER_LAYER -1,
	End = _COLLIDER_LAYER,
};

enum class eDir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE,
};

const int MoveDir[5][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
	{0, 0}
};

enum class eGameObject
{
	Baba,
	Rock,
	Text_You,
	Text_Baba,
	Text_Rock,
	Text_Is,
	Text_And,
	Text_Pull,
	Text_Push,
	Text_Stop,
	Text_Win,
	End,
};

enum class eCameraEffect
{
	FadeIn,
	FadeOut,
	None,
};

enum class eUIType
{
	HP,
	MP,
	SHOP,
	INVENTORY,
	OPTION,


	END,
};

union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;
};
typedef ColliderID TileID;



#define TILE_SIZE 48
#define TILE_SCALE 1

#define TILE_LINE_X 8
#define TILE_LINE_Y 3


