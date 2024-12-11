//#pragma once
//#include <iostream>
//#include <string>
//#include <tuple>
//#include <cstdlib>
//#include <ctime>
//#include "MyForm1.h"
//#include "MyForm.h"
//
//using namespace std;
//using namespace System;
//// Skill Ŭ����
//namespace Project2 {
//    class Skill
//    {
//    public:
//        virtual tuple<string, double> hydro() = 0;  // �� ��ų
//        virtual tuple<string, double> Pyro() = 0;   // �� ��ų
//        virtual tuple<string, double> Glass() = 0;  // Ǯ ��ų
//        virtual double Normal() = 0;                // �Ϲ� ����
//        virtual double Heal() = 0;                  // ȸ��
//        virtual bool Guard() = 0;                   // ���
//    };
//
//    // Poketmon Ŭ����
//    public class Poketmon : public Skill
//    {
//    private:
//        string lmage_Name;//�̹��� �̸�
//        string Poketmon_Name;//���ϸ� �̸�
//        string type;//Ÿ��
//        double full_hp;//�ִ�ü��
//        double hp;//���� ü��
//        double attack;//���ݷ�
//        double defense;//����
//        double speed;//���ǵ�
//
//    public:
//        // ������: ���ϸ� �ʱ� ���� ����
//        Poketmon(string lmage_Name, string Poketmon_Name, string type, double full_hp, double attack, double defense, double speed)
//        {
//            this->lmage_Name = lmage_Name;
//            this->Poketmon_Name = Poketmon_Name;
//            this->type = type;
//            this->full_hp = full_hp;
//            this->hp = full_hp;//���� ü���� �ִ� ü������ ����
//            this->attack = attack;
//            this->defense = defense;
//            this->speed = speed;
//        }
//
//        // ���ϸ� ���� getter �Լ�
//        string GetImage_Name() { return this->lmage_Name; }
//        string GetPoketmon_Name() { return this->Poketmon_Name; }
//        string GetType() { return this->type; }
//        double GetFull_hp() { return this->full_hp; }
//        double GetHp() { return this->hp; }
//        double GetAttack() { return this->attack; }
//        double GetDefense() { return this->defense; }
//        double GetSpeed() { return this->speed; }
//
//        // �� ��ų (�� Ÿ�Ը� ��� ����)
//        virtual tuple<string, double> hydro()
//        {
//            if (type == "��")
//            {
//                string skillType = "��";
//                double damage = attack * 1.7;
//                return make_tuple(skillType, damage);
//            }
//            else
//            {
//                return make_tuple("��� �Ұ�", 0);
//            }
//        }
//
//        // �� ��ų (�� Ÿ�Ը� ��� ����)
//        virtual tuple<string, double> Pyro()
//        {
//            if (type == "��")
//            {
//                string skillType = "��";
//                double damage = attack * 1.7;
//                return make_tuple(skillType, damage);
//            }
//            else
//            {
//                return make_tuple("��� �Ұ�", 0);
//            }
//        }
//
//        // Ǯ ��ų (Ǯ Ÿ�Ը� ��� ����)
//        virtual tuple<string, double> Glass()
//        {
//            if (type == "Ǯ")
//            {
//                string skillType = "Ǯ";
//                double damage = attack * 1.7;
//                return make_tuple(skillType, damage);
//            }
//            else
//            {
//                return make_tuple("��� �Ұ�", 0);
//            }
//        }
//
//        // ���� ��ų
//        virtual double Normal() { return attack * 1.5; }//�Ϲ� ����
//
//        virtual bool Guard()//��� ��ų
//        {
//            srand(time(NULL));
//            int num = rand() % 4;
//            return num < 2;
//        }
//
//        virtual double Heal()//ü�� ȸ��
//        {
//            double heal = full_hp / 2.0;
//            if ((hp + heal) > full_hp)
//            {
//                return full_hp;
//            }
//            else
//            {
//                return hp + heal;
//            }
//        }
//
//        // HP ���� �Լ�
//        void setHp(double newHp) { hp = newHp; }
//
//        // ���ϸ��� ���� ���
//        void PoketmonInfo()
//        {
//            cout << "���ϸ� �̸�: " << Poketmon_Name << endl;
//            cout << "Ÿ��: " << type << endl;
//            cout << "HP: " << hp << "/" << full_hp << endl;
//            cout << "�ӵ�: " << speed << endl;
//        }
//    };
//
//
//    class Battle
//    {
//    private:
//        Poketmon* player1;
//        Poketmon* player2;
//        bool player1Guarded = false;
//        bool player2Guarded = false;
//        Poketmon* first;
//        Poketmon* second;
//
//        // �� ����
//        double TypeEffect(Poketmon* attacker, Poketmon* defender, double damage)
//        {
//            string attackerType = attacker->GetType();
//            string defenderType = defender->GetType();
//
//            if (attackerType == "��" && defenderType == "Ǯ")
//            {
//                cout << "ȿ���� �����ߴ�!" << endl;
//                damage *= 1.5;
//            }
//            else if (attackerType == "��" && defenderType == "��")
//            {
//                cout << "ȿ���� �����ߴ�!" << endl;
//                damage *= 1.5;
//            }
//            else if (attackerType == "Ǯ" && defenderType == "��")
//            {
//                cout << "ȿ���� �����ߴ�!" << endl;
//                damage *= 1.5;
//            }
//            return damage;
//        }
//
//    public:
//
//        Battle(Poketmon* p1, Poketmon* p2)
//        {
//            player1 = p1;
//            player2 = p2;
//        }
//
//        // ��ų ����
//        int chooseSkill(Poketmon* player)
//        {
//            int choice;
//            cout << player->GetPoketmon_Name() << "�� ���Դϴ�." << endl;
//            cout << "1. �����ġ��\n";
//            cout << "2. ��\n";
//            cout << "3. ���\n";
//            if (player->GetType() == "��")
//                cout << "4. Hydro Attack\n";
//            if (player->GetType() == "��")
//                cout << "5. Pyro Attack\n";
//            if (player->GetType() == "Ǯ")
//                cout << "6. Glass Attack\n";
//            cout << "��ų�� �����ϼ���: ";
//            cin >> choice;
//            return choice;
//        }
//
//        // ���� ��� ó�� �Լ�
//        double processAttack(Poketmon* attacker, Poketmon* defender, int skill_choice, bool& guarded)
//        {
//            double damage = 0;
//            string skillType;
//
//            // ��ų ���ÿ� ���� ������ ���
//            switch (skill_choice)
//            {
//            case 1:
//                damage = attacker->Normal();
//                skillType = "�Ϲ� ����";
//                break;
//            case 2:
//                attacker->setHp(attacker->Heal());
//                cout << attacker->GetPoketmon_Name() << "�� ü���� ȸ���߽��ϴ�!" << endl;
//                cout << attacker->GetPoketmon_Name() << "�� ���� ü��: " << attacker->GetHp() << "/" << attacker->GetFull_hp() << endl;
//                return 0;
//            case 3:
//                if (attacker->Guard())
//                {
//                    cout << attacker->GetPoketmon_Name() << "�� �� �����߽��ϴ�!" << endl;
//                    guarded = true;
//                }
//                else
//                {
//                    cout << attacker->GetPoketmon_Name() << "�� �� �����߽��ϴ�!" << endl;
//                }
//                return 0;
//            case 4:
//                tie(skillType, damage) = attacker->hydro();
//                break;
//            case 5:
//                tie(skillType, damage) = attacker->Pyro();
//                break;
//            case 6:
//                tie(skillType, damage) = attacker->Glass();
//                break;
//            default:
//                cout << "�߸��� �����Դϴ�!" << endl;
//                return 0;
//            }
//
//            // �� ����
//            damage = TypeEffect(attacker, defender, damage);
//
//            return damage;
//        }
//
//        // �� ó�� �Լ�
//        void processTurn(Poketmon* attacker, Poketmon* defender, int attackerSkill, int defenderSkill, bool& attackerGuarded, bool& defenderGuarded)
//        {
//            // ���� �÷��̾ ��� ��ų�� ������ ��� ���� ó��
//            if (defenderSkill == 3) {
//                if (defender->Guard()) {
//                    cout << defender->GetPoketmon_Name() << "��(��) �� �����߽��ϴ�!" << endl;
//                    defenderGuarded = true;
//                }
//                else {
//                    cout << defender->GetPoketmon_Name() << "��(��) �� �����߽��ϴ�!" << endl;
//                    defenderGuarded = false;
//                }
//            }
//
//            // ���� �÷��̾��� ����/��ų ó��
//            double attackerDamage = processAttack(attacker, defender, attackerSkill, attackerGuarded);
//
//            // ���� �÷��̾ ������� �ʾҰ� �������� �߻��� ��� ó��
//            if (!defenderGuarded && attackerDamage > 0) {
//                attackerDamage = attackerDamage - defender->GetDefense();
//                defender->setHp(defender->GetHp() - (attackerDamage > 0 ? attackerDamage : 0));
//                cout << attacker->GetPoketmon_Name() << "�� ����! " << (attackerDamage > 0 ? attackerDamage : 0) << " ����!" << endl;
//                cout << defender->GetPoketmon_Name() << "�� ���� HP: " << defender->GetHp() << endl;
//            }
//
//            // ���� �÷��̾��� ����/��ų ó�� (���� ��ų�� ��츸 ó��)
//            if (defenderSkill != 3) {
//                double defenderDamage = processAttack(defender, attacker, defenderSkill, defenderGuarded);
//
//                // ���� �÷��̾ ������� �ʾҰ� �������� �߻��� ��� ó��
//                if (!attackerGuarded && defenderDamage > 0) {
//                    defenderDamage = defenderDamage - attacker->GetDefense();
//                    attacker->setHp(attacker->GetHp() - (defenderDamage > 0 ? defenderDamage : 0));
//                    cout << defender->GetPoketmon_Name() << "�� ����! " << (defenderDamage > 0 ? defenderDamage : 0) << " ����!" << endl;
//                    cout << attacker->GetPoketmon_Name() << "�� ���� HP: " << attacker->GetHp() << endl;
//                }
//            }
//
//            cout << endl;
//        }
//
//
//
//        // ù��
//        void FirstAttack(Poketmon*& first, Poketmon*& second)
//        {
//            if (player1->GetSpeed() > player2->GetSpeed())
//            {
//                first = player1;
//                second = player2;
//                cout << player1->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
//            }
//            else if (player2->GetSpeed() > player1->GetSpeed())
//            {
//                first = player2;
//                second = player1;
//                cout << player2->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
//            }
//            else
//            {
//                srand(time(NULL));
//                if (rand() % 2 == 0)
//                {
//                    first = player1;
//                    second = player2;
//                    cout << player1->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
//                }
//                else
//                {
//                    first = player2;
//                    second = player1;
//                    cout << player2->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
//                }
//            }
//        }
//
//        // ��Ʋ�Լ�
//        void startBattle()
//        {
//            // ù ��
//            FirstAttack(first, second);
//
//            while (player1->GetHp() > 0 && player2->GetHp() > 0)
//            {
//                int firstSkill = chooseSkill(first);
//                int secondSkill = chooseSkill(second);
//
//                player1Guarded = false;
//                player2Guarded = false;
//
//                processTurn(first, second, firstSkill, secondSkill, player1Guarded, player2Guarded);
//
//                if (player1Guarded || player2Guarded)
//                {
//                    swap(first, second);
//                }
//
//                if (player1->GetHp() <= 0)
//                {
//                    cout << player1->GetPoketmon_Name() << "��(��) ���������ϴ�!" << endl;
//                    cout << player2->GetPoketmon_Name() << "�� �¸�!" << endl;
//                    break;
//                }
//
//                if (player2->GetHp() <= 0)
//                {
//                    cout << player2->GetPoketmon_Name() << "��(��) ���������ϴ�!" << endl;
//                    cout << player1->GetPoketmon_Name() << "�� �¸�!" << endl;
//                    break;
//                }
//            }
//        }
//
//        Poketmon createcharmander()
//        {
//            return Poketmon("���̸�.webp", "���̸�", "�Ҳ�", 39, 52, 43, 65);
//        }
//        Poketmon createsquirtle()
//        {
//            return Poketmon("���α�.webp", "���α�", "��", 44, 48, 65, 43);
//        }
//        Poketmon createbulbasaur()
//        {
//            return Poketmon("�̻��ؾ�.webp", "�̻��ؾ�", "Ǯ", 45, 49, 49, 45);
//        }
//    };
//}
