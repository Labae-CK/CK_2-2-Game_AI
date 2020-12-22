#pragma once

class GameMap
{
public:
	GameMap(size_t w, size_t h);
	~GameMap();

	void Draw();

	__forceinline size_t GetWidth() const { return _width; }
	__forceinline size_t GetHeight() const { return _height; }

	__forceinline int GetMapValue(const size_t& x, const size_t& y) const { return _map[y][x]; }
	__forceinline void SetMapValue(const size_t& x, const size_t& y, const int& value) { _map[y][x] = value; }

	__forceinline bool GetVisitInfo(const size_t& x, const size_t& y) const { return _visitInfo[y][x]; }
	__forceinline void SetVisitInfo(const size_t& x, const size_t& y, const int& value) { _visitInfo[y][x] = value; }

	void SetMap(int** map);

private:
	void Initialize();

private:
	int** _map;
	bool** _visitInfo;
	size_t _width;
	size_t _height;
};

