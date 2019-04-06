/* 
 ��������ģʽ: ����Ĺ������Ͽ���ԭ��,���Ǵ����ǳ���
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


// ������ ˮ������ �Ͽ���ԭ��
class AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() = 0;   // ����һ�������ˮ��
};

// ƻ������
class  AppleFactory : public AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() {
        return new Apple;
    }
};

// �㽶����
class  BananaFactory : public AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() {
        return new Banana;
    }
};

// Ѽ�湤��
class  PearFactory : public AbstractFruitFactory {
public:
    virtual AbstractFruit* CreateFruit() {
        return new Pear;
    }
};

void test01() {

    AbstractFruitFactory* factory = NULL;
    AbstractFruit* fruit = NULL;

    // ����һ��ƻ������
    factory = new AppleFactory;   
    fruit = factory->CreateFruit();  //Ȼ�󴴽���һ��ƻ��
    fruit->ShowName();

    delete[] fruit;
    delete[] factory;


    // ����һ���㽶����
    factory = new BananaFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();

    delete[] fruit;
    delete[] factory;


    // ����һ���㽶����
    factory = new PearFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();

    delete[] fruit;
    delete[] factory;


}


int main(void) {

    test01();

    system("pause");
    return 0;
}