/*
����ģʽ: �ṩһ�ִ��������ƶ���������ķ���
*/

#include <iostream>
#include <cstdlib>
using namespace std;


class AbstractCommoinInterface {
public:
    virtual void run() = 0;

};


// ���Ѿ�д�õ�ϵͳ
class MySystem :public AbstractCommoinInterface{
public:
    virtual void run() {
        cout << "ϵͳ����..." << endl;
    }
};

// ����Ҫ��Ȩ����֤,���������˶����������ҵ�����,�ṩ�û���������.

class MySystemProxy :public AbstractCommoinInterface{
public:
    MySystemProxy(string username, string password) {
        this->mUsername = username;
        this->mPassword = password;
        pSystem = new MySystem;
    }

    bool checkUsernameAndPassoword() {
        if (mUsername == "admin" && mPassword == "admin") {
            return true;
        }
        return false;
    }

    virtual void run() {
        if (checkUsernameAndPassoword()) {
            cout << "�û�����������֤ͨ��" << endl;
            this->pSystem->run();
        }
        else {
            cout << "�û��������������,Ȩ�޲���" << endl;
        }
    }

    ~MySystemProxy() {
        if (pSystem != NULL) {
            delete pSystem;
            pSystem = NULL;
        }
    }

public:
    MySystem* pSystem;
    string mUsername;
    string mPassword;

};

void test01() {
    MySystemProxy* proxy = new MySystemProxy("admin", "admin");
    proxy->run();


}


int main(void) {

    test01();

    system("pause");
    return 0;
}