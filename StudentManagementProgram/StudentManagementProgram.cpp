#include <iostream>

#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_NUMBER_SIZE 14

#define STUDENT_MAX 10

#define PrintArrow cout << ">> "
#define PrintLine cout << "==================================" << endl


using namespace std;

struct _tagStudent {

    char strName[NAME_SIZE];
    char strAdress[ADDRESS_SIZE];
    char strPhoneNumber[PHONE_NUMBER_SIZE];
    int iNumber;
    int iKor;
    int iMath;
    int iEng;
    int iTotal;
    float fAvg;

};

enum MENU {

    MENU_NONE,
    MENU_INSERT,
    MENU_DELETE,
    MENU_SEARCH,
    MENU_OUTPUT,
    MENU_EXIT

};

int main()
{
    
    _tagStudent tStudentArr[STUDENT_MAX] = {};

    int iStudentCount = 0;
    int iStdNumber = 1;

    char strName[NAME_SIZE] = {};

    while (true) {

        system("cls");

        cout << "[1] 학생 정보 등록" << endl;
        cout << "[2] 학생 정보 삭제" << endl;
        cout << "[3] 학생 정보 탐색" << endl;
        cout << "[4] 학생 정보 출력" << endl;
        cout << "[5] 종료" << endl;
        PrintLine;
        cout << "[!] 메뉴를 선택하세요." << endl;
        PrintArrow;

        int iMenu;

        cin >> iMenu;

        if (cin.fail()) {

            cin.clear();

            cin.ignore(1024, '\n');

            continue;

        }

        if (iMenu == MENU_EXIT) {

            cout << "[!] 프로그램을 종료합니다." << endl;

            break;

        }

        switch (iMenu) {

        case MENU_INSERT:

            cout << "[!] 학생 정보 등록 메뉴입니다." << endl;
            PrintLine;

            system("cls");

            if (iStudentCount == STUDENT_MAX) {

                break;

            }

            cout << "[!] 이름을 입력해주세요." << endl;
            PrintArrow;
            cin >> tStudentArr[iStudentCount].strName;

            cin.ignore(1024, '\n');

            cout << "[!] 주소를 입력해주세요." << endl;;
            PrintArrow;
            cin.getline(tStudentArr[iStudentCount].strAdress, ADDRESS_SIZE);

            cout << "[!] 전화번호를 입력해주세요." << endl;
            PrintArrow;
            cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_NUMBER_SIZE);

            cout << "[!] 국어 점수를 입력해주세요." << endl;
            PrintArrow;
            cin >> tStudentArr[iStudentCount].iKor;

            cout << "[!] 수학 점수를 입력해주세요." << endl;
            PrintArrow;
            cin >> tStudentArr[iStudentCount].iMath;

            cout << "[!] 영어 점수를 입력해주세요." << endl;
            PrintArrow;
            cin >> tStudentArr[iStudentCount].iEng;

            tStudentArr[iStudentCount].iNumber = iStdNumber;

            tStudentArr[iStudentCount].iTotal = 
                tStudentArr[iStudentCount].iKor
                + tStudentArr[iStudentCount].iMath
                + tStudentArr[iStudentCount].iEng;

            tStudentArr[iStudentCount].fAvg = 
                tStudentArr[iStudentCount].iTotal / 3.f;

            ++iStdNumber;
            ++iStudentCount;

            cout << "[!] 학생 등록이 완료되었습니다." << endl;

            break;

        case MENU_DELETE:

            cout << "[!] 학생 정보 삭제 메뉴입니다." << endl;
            PrintLine;

            cout << "[!] 삭제하고자 하는 학생의 이름을 입력해주세요." << endl;
            PrintArrow;

            cin.ignore(1024, '\n');
            cin.getline(strName, NAME_SIZE);

            system("cls");

            for (int i = 0; i < iStudentCount; ++i) {

                if (strcmp(tStudentArr[i].strName, strName) == 0) {

                    for (int j = i; j < iStudentCount - 1; ++j) {

                        tStudentArr[i] = tStudentArr[i + 1];

                    }

                    --iStudentCount;

                    cout << "[!] 해당 학생의 정보를 삭제했습니다." << endl;

                    break;
                }
            }

            PrintLine;

            break;

        case MENU_SEARCH:

            cout << "[!] 학생 정보 탐색 메뉴입니다." << endl;
            PrintLine;

            system("cls");

            cout << "[!] 탐색하고자 하는 학생의 이름을 입력해주세요." << endl;
            PrintArrow;

            cin.ignore(1024, '\n');
            cin.getline(strName, NAME_SIZE);

            for (int i = 0; i < iStudentCount; ++i) {

                if (strcmp(tStudentArr[i].strName, strName) == 0) {

                    cout << "[!] 해당 학생의 정보입니다." << endl;
                    PrintLine;

                    cout << "[!] 이름 : " << tStudentArr[i].strName << endl;
                    cout << "[!] 주소 : " << tStudentArr[i].strAdress << endl;
                    cout << "[!] 전화 번호 : " << tStudentArr[i].strPhoneNumber << endl;
                    cout << "[!] 학번 : " << tStudentArr[i].iNumber << endl;
                    cout << "[!] 국어 점수 : " << tStudentArr[i].iKor << endl;
                    cout << "[!] 수학 점수 : " << tStudentArr[i].iMath << endl;
                    cout << "[!] 영어 점수 : " << tStudentArr[i].iEng << endl;
                    cout << "[!] 총점 : " << tStudentArr[i].iTotal << endl;
                    cout << "[!] 평균 점수 : " << tStudentArr[i].fAvg << endl;

                    break;

                }
            }

            PrintLine;

            break;

        case MENU_OUTPUT:

            system("cls");

            cout << "[!] 학생 정보 출력 메뉴입니다." << endl;
            PrintLine;
            
            for (int i = 0; i < iStudentCount; ++i) {

                cout << "[!] 이름 : " << tStudentArr[i].strName << endl;
                cout << "[!] 주소 : " << tStudentArr[i].strAdress << endl;
                cout << "[!] 전화 번호 : " << tStudentArr[i].strPhoneNumber << endl;
                cout << "[!] 학번 : " << tStudentArr[i].iNumber << endl;
                cout << "[!] 국어 점수 : " << tStudentArr[i].iKor << endl;
                cout << "[!] 수학 점수 : " << tStudentArr[i].iMath << endl;
                cout << "[!] 영어 점수 : " << tStudentArr[i].iEng << endl;
                cout << "[!] 총점 : " << tStudentArr[i].iTotal << endl;
                cout << "[!] 평균 점수 : " << tStudentArr[i].fAvg << endl;

                PrintLine;

                break;

            }

            break;

        default:

            cout << "[!] 잘못된 번호를 입력했습니다." << endl;

            break;

        }

        system("pause");

    }

    return 0;

}
