#pragma once

#pragma once

#include <string>
#include <vector>
using namespace std;

class NPC {
public:
    string name;
};

class Cell {
public:
    vector<NPC> NPCs;
    string eventMessage;  // �������¼�����ʱ����Ϣ

    void AddNPC(NPC npc){}
    void RemoveNPC(NPC npc){}
    void SetEventMessage(string message) {}  // �����������¼���Ϣ
};

class Map {
public:
    vector<string> map = {
        "____________________________________________________________________  ",
        "|                      ______________                               | ",
        "|                     |   ����«��   |                              | ",
        "|                     |              |                              | ",
        "|                     |______  ______|                              | ",
        "|                                                                   | ",
        "|         ______       ______  ______       ________   ______       | ",
        "|        |      |     |              |     |��������| |      |      | ",
        "|        |  ��  |     |              |     |        | |  ��  |      | ",
        "|        |  ��                                  ____| |  ��  |      | ",
        "|        |  ţ            ���Ĳ���             _____  |  ʤ  |      | ",
        "|        |  ��  |     |              |         |����|    ��  |      | ",
        "|        |______|     |______   _____|         |ɽ     ______|      | ",
        "|                                                                   | ",
        "|                                              |____|               | ",
        "|                      ______  ______                               | ",
        "|                     |              |                              | ",
        "|                         �Ϻ�����                                  | ",
        "|                     |______________|                              | ",
        "|___________________________________________________________________| "
    };

    Cell Place1;
    Cell Place2;
    Cell Place3;
    Cell Place4;
    Cell Place5;
    Cell Place6;
    Cell Place7;

    int playerX = 51, playerY = 12;

    Map();
    Map(int pX, int pY);  // ����λ����Ϣ�ģ����ڶ�ȡ�浵
    ~Map();

    void InMap();
    void GotoXY(int x, int y);
    void DrawMap();
    void UpdataPos(char move);
    void CheckPos();
    void ShowMessage(string message);  // �޸ģ���ʾ�ض���Ϣ
    void GenerateCell(Cell cell);
};
