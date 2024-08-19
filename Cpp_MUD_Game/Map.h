#pragma once

#include<string>
#include<vector>
using namespace std;

class NPC{
public:
	string name;
};

class Cell {
public:
	
	vector<NPC>NPCs;
	
	void AddNPC(NPC npc);
	void RemoveNPC(NPC npc);

};



class Map {
public:
	int pos[19][100] = {};
	Cell Place1;
	Cell Place2;
	Cell Place3;
	Cell Place4;
	Cell Place5;
	Cell Place6;
	Cell Place7;

	Map();
	Map(int p);//����λ����Ϣ�ģ����ڶ�ȡ�浵
	~Map();


	void ShowWorldMap();
	void GenerateCell(Cell cell);
};

