#pragma once

#pragma once

#include <string>
#include <vector>
using namespace std;

class NPC {
public:
    string name;
    NPC(){}
    NPC(string n) {
        name = n;
    }
};

class Cell {
public:
    vector<NPC> NPCs;
    string eventMessage;  // �������¼�����ʱ����Ϣ

    Cell();
    Cell(vector<NPC>npcs);
    ~Cell();
    void AddNPC(NPC npc);
    void RemoveNPC(NPC npc){}
    void SetEventMessage(string message);  // �����������¼���Ϣ
};

class Map {
public:
    vector<string> map = {
        "____________________________________________________________________  ",
        "|                      ______________                               | ",
        "|                     |   ����«��   |                              | ",
        "|                     |       *      |                              | ",
        "|                     |______  ______|                              | ",
        "|                                                                   | ",
        "|         ______       ______  ______       ________   ______       | ",
        "|        |      |     |              |     |��������| |      |      | ",
        "|        |  ��  |     |              |     |    *   | |  ��  |      | ",
        "|        |  ��                *                 ____| |  ��  |      | ",
        "|        |  ţ*           ���Ĳ���             _____  | *ʤ  |      | ",
        "|        |  ��  |     |              |         |����|    ��  |      | ",
        "|        |______|     |______   _____|         |ɽ *   ______|      | ",
        "|                                                                   | ",
        "|                                              |____|               | ",
        "|                      ______  ______                               | ",
        "|                     |       *      |                              | ",
        "|                         �Ϻ�����                                  | ",
        "|                     |______________|                              | ",
        "|___________________________________________________________________| "
        "ʹ��w,a,s,d���ƶ����ƶ���*�ϰ�E���ɽ���                               "
    };

    Cell cellXi;
    Cell cellNanS;
    Cell cellNanH;
    Cell cellBei;
    Cell cellDongH;
    Cell cellHua;
    Cell cellDongS;

    int playerX = 51, playerY = 12;
    //int playerX = 14, playerY = 10;//��ţ
    //int playerX = 30, playerY = 16;//�Ϻ�
    //int playerX = 30, playerY = 9;//�ϲ���
    //int playerX = 30, playerY = 3;//����
    //int playerX = 48, playerY = 8;//����
    //int playerX = 56, playerY = 10;//����





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
