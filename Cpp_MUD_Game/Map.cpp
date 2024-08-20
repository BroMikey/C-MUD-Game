


#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

Map::Map() {
    // ��ʼ���ض�λ�õ��¼���Ϣ
    Place1.SetEventMessage("�㵽�˱���«�ݣ�");
    Place2.SetEventMessage("�㵽�����Ĳ��ݣ�");
    Place3.SetEventMessage("�㵽�˻���ɽ��");
    Place4.SetEventMessage("�㵽�˶���������");
    Place5.SetEventMessage("�㵽���Ϻ�������");
    Place5.SetEventMessage("�㵽�˶�ʤ���ݣ�");
    Place5.SetEventMessage("�㵽����ţ���ݣ�");
}

Map::Map(int pX, int pY) {
    playerX = pX;
    playerY = pY;
}

Map::~Map() {}

void Map::GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Map::GenerateCell(Cell cell) {
	cout << "  ___________" << endl;
	for (int i = 0; i < cell.NPCs.size(); i++) {
		cout << " |" << i << "." << cell.NPCs[i].name << "\t " << endl;
	}
	//cout << " |1." << cell.NPCs << "\t " << endl;
	//cout << " |NPC:test\t " << endl;
	//cout << " |2." << monsterName << "\t " << endl;
	cout << " |\t\t" << endl;
	cout << " |\t\t" << endl;
	cout << "  \t\t\t|" << endl;
	cout << "  \t\t________| " << endl;
}

void Map::DrawMap() {
    system("cls");
    for (int y = 0; y < map.size(); y++) {
        cout << map[y] << endl;
    }
    GotoXY(playerX, playerY);
    cout << "#";
}

void Map::InMap() {
    DrawMap();

    bool isRunning = true;
    while (isRunning) {
        if (_kbhit()) {
            char input = _getch();
            if (input == 'q') {
                isRunning = false;  // �˳�
                system("cls");
            }
            else if (input == 'e') {
                CheckPos();  // ����¼�
            }
            else {
                UpdataPos(input);  // �ƶ�����
            }
        }

        Sleep(100);  // ��΢��ͣһ�£����� CPU ����ռ��
    }
}

void Map::UpdataPos(char move) {
    // �����λ��
    GotoXY(playerX, playerY);
    cout << map[playerY][playerX];

    switch (move) {
    case 'w': if (playerY > 0 && map[playerY - 1][playerX] != '_' && map[playerY - 1][playerX] != '|' && map[playerY - 1][playerX] == ' ') playerY--; break; // �����ƶ�
    case 's': if (playerY < map.size() - 1 && map[playerY + 1][playerX] != '_' && map[playerY + 1][playerX] != '|' && map[playerY + 1][playerX] == ' ') playerY++; break; // �����ƶ�
    case 'a': if (playerX > 0 && map[playerY][playerX - 1] != '|' && map[playerY][playerX - 1] != '_' && map[playerY][playerX - 1] == ' ') playerX--; break; // �����ƶ�
    case 'd': if (playerX < map[0].size() - 1 && map[playerY][playerX + 1] != '|' && map[playerY][playerX + 1] != '_' && map[playerY][playerX + 1] == ' ') playerX++; break; // �����ƶ�
    }

    // ��ʾ��λ��
    GotoXY(playerX, playerY);
    cout << "#";
}

void Map::CheckPos() {
    // ���ݵ�ǰλ�ô�����ͬ���¼�
    if (playerX >= 8 && playerY <= 12 && playerY <= 7 && playerX >= 12) {
        ShowMessage(Place1.eventMessage);
    }
    else if (playerX == 25 && playerY == 8) {
        ShowMessage(Place2.eventMessage);
    }
    else if (playerX == 38 && playerY == 10) {
        ShowMessage(Place3.eventMessage);
    }
    else if (playerX == 32 && playerY == 7) {
        ShowMessage(Place4.eventMessage);
    }
    else if (playerX == 29 && playerY == 16) {
        ShowMessage(Place5.eventMessage);
    }
}

void Map::ShowMessage(string message) {
    GotoXY(0, map.size() + 1);  // ������ƶ�����ͼ�·�����ʾ��Ϣ
    cout << message << endl;
    system("pause");  // ��ͣ���ȴ��û�����
}

