/* 
 �򵥹���ģʽ: ����Ĺ����������Ͽ���ԭ��,ֻ��һ������������
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�����ˮ��
class AbstractFruit {
public:
    virtual void ShowName() = 0;
};

// ƻ��
class Apple :public AbstractFruit {
public:
    virtual void ShowName() {
        cout << "����ƻ��!" << endl;
    }
};

// �㽶
class Banana :public AbstractFruit {
public:
    virtual void ShowName() {
        cout << "�����㽶!" << endl;
    }
};

// Ѽ��
class Pear :public AbstractFruit {
public:
    virtual void ShowName() {
        cout << "����Ѽ��!" << endl;
    }
};


// ˮ�� ����  �����Ͽ���ԭ��

class FruitFactory {
public:
    static AbstractFruit* CreateFruit(string flag) {
        if (flag == "Apple") {
            return new Apple;
        }
        else if (flag == "Banana") {
            return new Banana;
        }
        else if (flag == "Pear") {
            return new Pear;
        }
        else {
            return NULL;
        }
    }
};

void test01() {

    //�������̲���Ҫ��ϵ, ֱ�������þͺ���
    FruitFactory* factory = new FruitFactory;
    AbstractFruit* fruit = factory->CreateFruit("Apple");
    fruit->ShowName();
    delete[] fruit;

    fruit = factory->CreateFruit("Pear");
    fruit->ShowName();
    delete[] fruit;

    fruit = factory->CreateFruit("Banana");
    fruit->ShowName();
    delete[] fruit;

    delete[] factory;
}

int main(void) {
 
    test01();

    system("pause");
    return 0;
}