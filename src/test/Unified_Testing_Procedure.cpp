//
// Created by Ǳˮ�� on 2018/11/4.
//
#include <iostream>
#include "../main/animals/AbstractAnimal.h"
#include "../main/animals/Cow.h"
#include "../main/animals/Sheep.h"
#include "../main/plants/Cotton.h"
#include "../main/plants/PlantsField.h"
#include "../main/plants/Wheat.h"
#include "../main/visitor/ConcreteVisitor.h"
#include "../main/building/building.h"
#include "../main/alarm/Alarm.h"
#include "../main/alarm/Alarm_MementoCommand.h"
#include "../main/product/productFactory.h"
#include "../main/FarmMaster/Singleton.h"

using namespace std;

/**
 * A unified method to test all functions
 * @return
 */
int main(void){
    cout<<"��ѡ��Ҫ���Ե����ģʽ��"<<endl;
    int opt;
    while(true) {
        cout<<"1--Template Method\n"
            <<"2--Strategy\n"
            <<"3--Iterator&Prototype\n"
            <<"4--Visitor\n"
            <<"5--Builder\n"
            <<"6--Alarm System(Observer&State&Command&Memento&)\n"
            <<"7--Factory&Flyweight\n"
            <<"8--Proxy\n"
            <<"9--Singleton\n"
            <<"0--Exit\n"
            <<endl;
        cin >> opt;
        switch (opt){
            case 1: {
                cout << "��������ָ��AbstractAnimal�����ָ��" << endl;
                AbstractAnimal *animal_A;
                AbstractAnimal *animal_B;
                cout << "��һ�����󴴽�Ϊ��ţ������������Cow����Sheep���س���ȷ�ϣ�" << endl;
                string choice;
                cin >> choice;
                if (choice == "Cow") {
                    animal_A = new Cow();
                    animal_B = new Sheep();
                    cout << "������ɣ���һ�����Զ�����Ϊ����" << endl;
                } else if (choice == "Sheep") {
                    animal_A = new Sheep();
                    animal_B = new Cow();
                    cout << "������ɣ���һ�����Զ�����Ϊ��ţ" << endl;
                }
                cout << "\n��ʼ����������ֱ����harvest()����\n\n����A��" << endl;
                animal_A->harvest();
                cout << "\n\n����B";
                animal_B->harvest();
                break;
            }
            case 2: {
                cout << "��ʼ��һ��5ƽ���״�С��Cotton������ѡ��Ҫ������в���(1�������գ�2������ˮ)"<<endl;
                Cotton cotton(5);
                int tempOpt;
                cin >> tempOpt;
                cotton.doAction(tempOpt);
                break;
            }
            case 3: {
                cout<<"��ʼ��һ��PlantField�����ڲ�ʹ��ʵ���˵��������Զ��������洢AbstractPlant����"<<endl;
                PlantsField plantsField;
                cout<<"ϣ����Ӽ�����أ����Է��������Ĭ��Ϊ3ƽ���׵��޻������������";
                int tempOpt;
                cin>>tempOpt;
                while(tempOpt--!=0){
                    Cotton cotton(3);
                    cotton.setMature(true);
                    plantsField.add(&cotton);
                }
                cout<<"ʹ�õ�����������״��:"<<endl;
                plantsField.print();
                break;
            }
            case 4: {
                cout<<"��ʼ��һ���СΪ8��С����Wheat����"<<endl;
                Wheat wheat(8);
                cout<<"��ѡ�����ʩ�ӵ�Visit������1����������2�����ӹ���"<<endl;
                int tempOpt;
                cin>>tempOpt;
                if(tempOpt==1){
                    IVisitor *staff = new StaffA();
                    wheat.Accept(staff);
                }else if(tempOpt==2){
                    IVisitor *staff = new StaffB();
                    wheat.Accept(staff);
                }
                break;
            }
            case 5: {
                cout<<"������Ҫ����Ľ������ͣ���1����ũ����2�������ݣ�"<<endl;
                int tempOpt;
                cin>>tempOpt;
                if(tempOpt==1){
                    BuildingBuilder *farm=new BuildFarm();
                    farm->configureDoor();
                    farm->configureFence();
                    farm->configureFloor();
                    farm->configureRoof();
                    farm->configureWall();

                    cout << farm->getResult()->ReturnName() << " " << endl;
                    cout << farm->getResult()->ReturnDoor() << " " << endl;
                    cout << farm->getResult()->ReturnFence() << " " << endl;
                    cout << farm->getResult()->ReturnWall() << " " << endl;
                    cout << farm->getResult()->ReturnRoof() << " " << endl;
                    cout << farm->getResult()->ReturnFloor() << " " << endl;
                }else if(tempOpt==2){
                    BuildingBuilder *house=new BuildHouse;
                    house->configureDoor();
                    house->configureFence();
                    house->configureFloor();
                    house->configureRoof();
                    house->configureWall();

                    cout<<house->getResult()->ReturnName() << " " << endl;
                    cout << house->getResult()->ReturnDoor() << " " << endl;
                    cout << house->getResult()->ReturnFence() << " " << endl;
                    cout << house->getResult()->ReturnWall() << " " << endl;
                    cout << house->getResult()->ReturnRoof() << " " << endl;
                    cout << house->getResult()->ReturnFloor() << " " << endl;
                }
                break;
            }
            case 6: {
                AlarmSys::alarm();
                break;
            }
            case 7: {
                cout<<"��ʼ������ʵ�����Զ�Ϊ�佨��Flyweight��ǩ��������Ҫ�����Ĳ�Ʒ(1-4)��"<<endl;
                int tempOpt;
                cin>>tempOpt;
                ProductFactory myFactory;
                Product* myGoods1 = myFactory.productGoods(tempOpt);
                break;
            }
            case 8: {
                cout<<"��ʼ������ʵ����������Ʒ��֮��ͨ�������ȡ�г��۸�:"<<endl;
                cout<<"������Ҫ�����Ĳ�Ʒ(1-4)��"<<endl;
                int tempOpt;
                cin>>tempOpt;
                ProductFactory myFactory;
                Product* myGoods1 = myFactory.productGoods(tempOpt);
                myGoods1->SellProduct();
                break;
            }
            case 9: {
                cout<<"ʵ����ũ������������1��ʹ�����ʼ������������2��ʹ��getInstance������"<<endl;
                int tempOpt;
                cin>>tempOpt;
                if(tempOpt==1){
                    try{
                        Singleton newMaster();
                    }catch(...){
                        cout<<"�쳣���˶���Ϊ��ʵ����"<<endl;
                    }
                }else if(tempOpt==2){
                    cout<<"��ȡ����instance�����е�������һ��instance�����ԣ�����Ƿ�Ϊ��ʵ����"<<endl;
                    Singleton* farmer = Singleton::getInstance(); // Ok
                    Singleton* farmer1 = Singleton::getInstance();
                    farmer->setName("peter");
                    /* The addresses will be the same. */
                    std::cout << farmer->getName() << std::endl;
                    /* The addresses will be the same. */
                    std::cout << farmer1->getName() << std::endl;
                }
                break;
            }
            case 0: {
                cout << "���Խ���" << endl;
                return 0;
            }
        }
    }
}