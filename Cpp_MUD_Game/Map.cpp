#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

void Cell::SetEventMessage(string message) {
    this->eventMessage = message;
}

Cell::Cell() {

}

/// <summary>
/// ���ڸ���NPC��ʼ��cell
/// </summary>
Cell::Cell(vector<NPC>npcs) {
    for (auto oneNPC:npcs) {
        this->AddNPC(oneNPC);
    }
}

Cell::~Cell() {

}

void Cell::AddNPC(NPC n) {
    this->NPCs.push_back(n);
}

Map::Map() {
    // ��ʼ���ض�λ�õ��¼���Ϣ
    cellXi.SetEventMessage("�㵽����ţ���ݣ�");
    cellNanS.SetEventMessage("�㵽�����Ĳ��ݣ�");
    cellNanH.SetEventMessage("�㵽���Ϻ�������");
    cellBei.SetEventMessage("�㵽�˱���«�ݣ�");
    cellDongH.SetEventMessage("�㵽�˶���������");
    cellDongS.SetEventMessage("�㵽�˶�ʤ���ݣ�");
    cellHua.SetEventMessage("�㵽�˻���ɽ��");
    cellHua.AddNPC(NPC("����"));
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
    system("cls");
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
    case 'w': if (playerY > 0 &&
        map[playerY - 1][playerX] != '_' &&
        map[playerY - 1][playerX] != '|' && 
        map[playerY - 1][playerX] == ' ' ||
        map[playerY - 1][playerX] == '*')
            playerY--; break; // �����ƶ�
    case 's': if (playerY < map.size() - 1 && 
        map[playerY + 1][playerX] != '_' && 
        map[playerY + 1][playerX] != '|' && 
        map[playerY + 1][playerX] == ' ' || 
        map[playerY + 1][playerX] == '*')
            playerY++; break; // �����ƶ�
    case 'a': if (playerX > 0 && 
        map[playerY][playerX - 1] != '|' && 
        map[playerY][playerX - 1] != '_' && 
        map[playerY][playerX - 1] == ' ' || 
        map[playerY][playerX - 1] == '*')
            playerX--; break; // �����ƶ�
    case 'd': if (playerX < map[0].size() - 1 && 
        map[playerY][playerX + 1] != '|' &&
        map[playerY][playerX + 1] != '_' && 
        map[playerY][playerX + 1] == ' ' || 
        map[playerY][playerX + 1] == '*')
            playerX++; break; // �����ƶ�
    }

    // ��ʾ��λ��
    GotoXY(playerX, playerY);
    cout << "#";
}

void Map::CheckPos() {
    // ���ݵ�ǰλ�ô�����ͬ���¼�
    if (playerX == 14 && playerY == 10) {
        system("cls");
        ShowMessage(cellXi.eventMessage);
        GenerateCell(cellXi);
    }
    else if (playerX == 51 && playerY == 12) {
        system("cls");
        ShowMessage(cellHua.eventMessage);
        GenerateCell(cellHua);
    }
    else if (playerX == 30 && playerY == 9) {
        system("cls");
        ShowMessage(cellNanS.eventMessage);
        GenerateCell(cellNanS);
    }
    else if (playerX == 30 && playerY == 16) {
        system("cls");
        ShowMessage(cellNanH.eventMessage);
        GenerateCell(cellNanH);
    }
    else if (playerX == 30 && playerY == 3) {
        system("cls");
        ShowMessage(cellBei.eventMessage);
        GenerateCell(cellBei);
    }
    else if (playerX == 48 && playerY == 8) {
        system("cls");
        ShowMessage(cellDongH.eventMessage);
        GenerateCell(cellDongH);
    }
    
    else if (playerX == 56 && playerY == 10) {
        system("cls");
        ShowMessage(cellDongS.eventMessage);
        GenerateCell(cellDongS);
    }
}

void Map::ShowMessage(string message) {

    cout << message << endl;

    Sleep(1000);
    //�˴�Ϊ�˳���ͼ�������cell

}

