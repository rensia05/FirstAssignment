#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main(void) {
    int status[6] = {0, 0, 0, 0, 0, 0}; // HP, MP, 공격력, 방어력, HP 포션 개수, MP 포션 개수
    int Selector = 0;

	while (status[0] <= 49 || status[1] <= 49) {
		cout << "HP와 MP를 입력 해주세요 : ";
		cin >> status[0] >> status[1];
	}

	while (status[2] <= 0 || status[3] <= 0) {
		cout << "공격력과 방어력을 입력 해주세요 : ";
		cin >> status[2] >> status[3];
	}


    setPotion(5, &status[4], &status[5]);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;

    do{
        cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기" << endl;
        cin >> Selector;

        switch (Selector) {
        case 1:
            if (status[4] > 0) {
                status[0] += 20;
                status[4]--;
                cout << "HP가 20 증가하였습니다." << endl;
            }
            else {
                cout << "HP 포션이 없습니다." << endl;
            }
            break;
        case 2:
            if (status[5] > 0) {
                status[1] += 20;
                status[5]--;
                cout << "MP가 20 증가하였습니다." << endl;
            }
            else {
                cout << "MP 포션이 없습니다." << endl;
            }
            break;
        case 3:
            status[2] *= 2;
            cout << "공격력이 2배 증가하였습니다." << endl;
            break;
        case 4:
            status[3] *= 2;
            cout << "방어력이 2배 증가하였습니다." << endl;
            break;
        case 5:
            cout << "현재 능력치 : " << endl;
            cout << "HP : " << status[0] << endl;
            cout << "MP : " << status[1] << endl;
            cout << "공격력 : " << status[2] << endl;
            cout << "방어력 : " << status[3] << endl;
            cout << "HP 포션 개수 : " << status[4] << endl;
            cout << "MP 포션 개수 : " << status[5] << endl;
            break;
        case 6:
            status[4] += 1;
            status[5] += 1;
            cout << "Level Up! 포션이 지급되었습니다." << endl;
            break;
        case 0:
            cout << "게임을 종료합니다." << endl;
            break;
        default:
            cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
            break;
        }
    } while (Selector != 0);
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}