#include "Map.h"
#include<iostream>
#include<Windows.h>

Map::Map() {

}

/// <summary>
/// ��ȡ�浵ʱ����ĵ�ͼ
/// </summary>
/// <param name="p">
/// ��ȡ�浵��ɫ��λ����Ϣ
/// </param>
Map::Map(int p){
	vector<string> map = {
		"______________________________________________________________________________  "
		"|                                ______________                               | "
		"|                               |              |                              | "
		"|                               |   ����«��   |                              | "
		"|                               |______________|                              | "
		"|                                                                             | "
		"|         ______                 ______________                  ______       | "
		"|        |      |               |              |      ________  |      |      | "
		"|        |  ��  |               |              |     |��������| |  ��  |      | "
		"|        |  ţ  |               |   ���Ĳ���   |     |________| |  ʤ  |      | "
		"|        |  ��  |               |              |      ____      |  ��  |      | "
		"|        |  ��  |               |              |     |����|     |  ��  |      | "
		"|        |______|               |______________|     |ɽ  |     |______|      | "
		"|                                                    |____|                   | "
		"|                                ______________                               | "
		"|                               |              |                              | "
		"|                               |   �Ϻ�����   |                              | "
		"|                               |______________|                              | "
		"|_____________________________________________________________________________| "
	};
}

Map::~Map() {

}

void Map::ShowWorldMap() {
	system("cls");
	cout << "�����ͼ:" << endl;											     
	cout << "                                                                                " << endl;
	cout << "______________________________________________________________________________  " << endl;
	cout << "|                                ______________                               | " << endl;
	cout << "|                               |              |                              | " << endl;
	cout << "|                               |   ����«��   |                              | " << endl;
	cout << "|                               |______________|                              | " << endl;
	cout << "|                                                                             | " << endl;
	cout << "|         ______                 ______________                  ______       | " << endl;
	cout << "|        |      |               |              |      ________  |      |      | " << endl;
	cout << "|        |  ��  |               |              |     |��������| |  ��  |      | " << endl;
	cout << "|        |  ţ  |               |   ���Ĳ���   |     |________| |  ʤ  |      | " << endl;
	cout << "|        |  ��  |               |              |      ____      |  ��  |      | " << endl;
	cout << "|        |  ��  |               |              |     |����|     |  ��  |      | " << endl;
	cout << "|        |______|               |______________|     |ɽ  |     |______|      | " << endl;
	cout << "|                                                    |____|                   | " << endl;
	cout << "|                                ______________                               | " << endl;
	cout << "|                               |              |                              | " << endl;
	cout << "|                               |   �Ϻ�����   |                              | " << endl;
	cout << "|                               |______________|                              | " << endl;
	cout << "|_____________________________________________________________________________| " << endl;
	char choiceDir;		           
	cout << "ѡ����Ҫȥ��λ��" << endl; cin >> choiceDir;

	//switch (this->pos)
	//{
	//case 1:

	//	break;
	//case 2:

	//	break;
	//case 3:

	//	break;
	//case 4:

	//	break;
	//case 5:

	//	break;
	//case 6:
	//	system("cls");
	//	//GenerateCell("��������");
	//	break;
	//case 7:

	//	break;
	//default:

	//	break;
	//}
}

void Map::GenerateCell(Cell cell) {
	cout << "  ___________" << endl;
	for (int i = 0; i < cell.NPCs.size(); i++) {
		cout << " |"<<i<<"." << cell.NPCs[i].name << "\t " << endl;
	}
	//cout << " |1." << cell.NPCs << "\t " << endl;
	//cout << " |NPC:test\t " << endl;
	//cout << " |2." << monsterName << "\t " << endl;
	cout << " |\t\t" << endl;
	cout << " |\t\t" << endl;
	cout << "  \t\t\t|" << endl;
	cout << "  \t\t________| " << endl;
}