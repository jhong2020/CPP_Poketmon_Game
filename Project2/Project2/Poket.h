//#pragma once
//#include <iostream>
//#include <string>
//#include "myform.h"
//#include "myform1.h"
//using namespace std;
//namespace project2 {
//    // poketmon Ŭ���� ����
//    public class poketmon1
//    {
//        // ���ϸ��� ��� ����
//    private:
//        string image_name;  // ���ϸ��� �̹��� ���� �̸�
//        string poketmon_name;   // ���ϸ� �̸�
//        string type;    // ���ϸ��� Ÿ��
//        double full_hp; // ���ϸ��� �ִ� hp
//        double hp;  // ���ϸ��� ���� hp
//        double attack;  // ���ϸ��� ���ݷ�
//        double defense; // ���ϸ��� ����
//        double speed;   // ���ϸ��� �ӵ�
//
//    public:
//        //������
//        poketmon1(string image_name, string poketmon_name, string type, double full_hp, double hp, double attack, double defense, double speed)
//        {
//            // ��� ���� �ʱ�ȭ
//            this->image_name = image_name;
//            this->poketmon_name = poketmon_name;
//            this->type = type;
//            this->full_hp = full_hp;
//            this->hp = hp;
//            this->attack = attack;
//            this->defense = defense;
//            this->speed = speed;
//        }
//        //  �� ��� ������ ���� ��ȯ
//        string getname()
//        {
//            return poketmon_name;
//        }
//        string getimagename()
//        {
//            return image_name;
//        }
//        string gettype()
//        {
//            return type;
//        }
//        double getfullhp()
//        {
//            return full_hp;
//        }
//        double gethp()
//        {
//            return hp;
//        }
//        double getattack()
//        {
//            return attack;
//        }
//        double getdefense()
//        {
//            return defense;
//        }
//        double getspeed()
//        {
//            return speed;
//        }
//
//        //�� ��� ������ ���� ����
//        void setname(string poketmon_name)
//        {
//            this->poketmon_name = poketmon_name;
//        }
//        void setimagename(string image_name)
//        {
//            this->image_name = image_name;
//        }
//        void settype(string type)
//        {
//            this->type = type;
//        }
//        void setfullhp(double full_hp)
//        {
//            this->full_hp = full_hp;
//        }
//        void sethp(double hp)
//        {
//            this->hp = hp;
//        }
//        void setattack(double attack)
//        {
//            this->attack = attack;
//        }
//        void setdefense(double defense)
//        {
//            this->defense = defense;
//        }
//        void setspeed(double speed)
//        {
//            this->speed = speed;
//        }
//        //���ϸ��� ���� ��� �Լ�
//        void poketmoninfo() {
//          /*  cout << "�̹��� �̸�: " << image_name << endl;
//            cout << "���ϸ� �̸�: " << poketmon_name << endl;
//            cout << "Ÿ��: " << type << endl;
//            cout << "�ִ� hp: " << full_hp << endl;
//            cout << "���� hp: " << hp << endl;
//            cout << "���ݷ�: " << attack << endl;
//            cout << "����: " << defense << endl;
//            cout << "�ӵ�: " << speed << endl;*/
//        }
//    };
//
//    // ���ϸ� ��ü ���� �Լ�
//    poketmon1 createcharmander()
//    {
//        return poketmon1("���̸�.webp", "���̸�", "�Ҳ�", 39, 39, 52, 43, 65);
//    }
//    poketmon1 createsquirtle()
//    {
//        return poketmon1("���α�.webp", "���α�", "��", 44, 44, 48, 65, 43);
//    }
//    poketmon1 createbulbasaur()
//    {
//        return poketmon1("�̻��ؾ�.webp", "�̻��ؾ�", "Ǯ", 45, 45, 49, 49, 45);
//    }
//}
