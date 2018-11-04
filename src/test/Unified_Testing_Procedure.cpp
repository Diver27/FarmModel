//
// Created by 潜水人 on 2018/11/4.
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
    cout<<"请选择要测试的设计模式："<<endl;
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
                cout << "创建两个指向AbstractAnimal对象的指针" << endl;
                AbstractAnimal *animal_A;
                AbstractAnimal *animal_B;
                cout << "第一个对象创建为奶牛还是绵羊？输入Cow或者Sheep，回车键确认：" << endl;
                string choice;
                cin >> choice;
                if (choice == "Cow") {
                    animal_A = new Cow();
                    animal_B = new Sheep();
                    cout << "创建完成，另一对象自动创建为绵羊" << endl;
                } else if (choice == "Sheep") {
                    animal_A = new Sheep();
                    animal_B = new Cow();
                    cout << "创建完成，另一对象自动创建为奶牛" << endl;
                }
                cout << "\n开始对两个对象分别调用harvest()函数\n\n对象A：" << endl;
                animal_A->harvest();
                cout << "\n\n对象B";
                animal_B->harvest();
                break;
            }
            case 2: {
                cout << "初始化一个5平方米大小的Cotton对象，请选择要对其进行操作(1——焚烧；2——洒水)"<<endl;
                Cotton cotton(5);
                int tempOpt;
                cin >> tempOpt;
                cotton.doAction(tempOpt);
                break;
            }
            case 3: {
                cout<<"初始化一个PlantField对象，内部使用实现了迭代器的自定义容器存储AbstractPlant对象"<<endl;
                PlantsField plantsField;
                cout<<"希望添加几块田地（测试方便起见，默认为3平方米的棉花田）？输入整数";
                int tempOpt;
                cin>>tempOpt;
                while(tempOpt--!=0){
                    Cotton cotton(3);
                    cotton.setMature(true);
                    plantsField.add(&cotton);
                }
                cout<<"使用迭代器输出田地状况:"<<endl;
                plantsField.print();
                break;
            }
            case 4: {
                cout<<"初始化一块大小为8的小麦田Wheat对象"<<endl;
                Wheat wheat(8);
                cout<<"请选择对其施加的Visit操作（1——售卖；2——加工）"<<endl;
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
                cout<<"请输入要建造的建筑类型：（1——农场；2——房屋）"<<endl;
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
                cout<<"初始化工厂实例，自动为其建立Flyweight标签。请输入要生产的产品(1-4)："<<endl;
                int tempOpt;
                cin>>tempOpt;
                ProductFactory myFactory;
                Product* myGoods1 = myFactory.productGoods(tempOpt);
                break;
            }
            case 8: {
                cout<<"初始化工厂实例并生产产品，之后通过代理获取市场价格:"<<endl;
                cout<<"请输入要生产的产品(1-4)："<<endl;
                int tempOpt;
                cin>>tempOpt;
                ProductFactory myFactory;
                Product* myGoods1 = myFactory.productGoods(tempOpt);
                myGoods1->SellProduct();
                break;
            }
            case 9: {
                cout<<"实例化农场主对象。输入1以使用类初始化方法，输入2以使用getInstance方法："<<endl;
                int tempOpt;
                cin>>tempOpt;
                if(tempOpt==1){
                    try{
                        Singleton newMaster();
                    }catch(...){
                        cout<<"异常！此对象为单实例！"<<endl;
                    }
                }else if(tempOpt==2){
                    cout<<"获取两个instance，其中单独设置一个instance的属性，检查是否为单实例："<<endl;
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
                cout << "测试结束" << endl;
                return 0;
            }
        }
    }
}