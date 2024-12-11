#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <cstdlib>
#include <ctime>
using namespace std;

// Skill Ŭ����
class Skill
{
public:
    virtual tuple<string, double> hydro() = 0;  // �� ��ų
    virtual tuple<string, double> Pyro() = 0;   // �� ��ų
    virtual tuple<string, double> Glass() = 0;  // Ǯ ��ų
    virtual double Normal() = 0;                // �Ϲ� ����
    virtual double Heal() = 0;                  // ȸ��
    virtual bool Guard() = 0;                   // ���
};

// Poketmon Ŭ����
class Poketmon : public Skill
{
private:
    string lmage_Name;
    string Poketmon_Name;
    string type;
    double full_hp;
    double hp;
    double attack;
    double defense;
    double speed;

public:
    // ������
    Poketmon(string lmage_Name, string Poketmon_Name, string type, double full_hp, double attack, double defense, double speed);

    // ���ϸ� ���� getter �Լ�
    string GetImage_Name();
    string GetPoketmon_Name();
    string GetType();
    double GetFull_hp();
    double GetHp();
    double GetAttack();
    double GetDefense();
    double GetSpeed();

    // �� ��ų (�� Ÿ�Ը� ��� ����)
    virtual tuple<string, double> hydro();

    // �� ��ų (�� Ÿ�Ը� ��� ����)
    virtual tuple<string, double> Pyro();

    // Ǯ ��ų (Ǯ Ÿ�Ը� ��� ����)
    virtual tuple<string, double> Glass();

    // ���� ��ų
    virtual double Normal();
    virtual bool Guard();
    virtual double Heal();

    // HP ���� �Լ�
    void setHp(double newHp);

    // ���ϸ��� ���� ���
    void PoketmonInfo();
};

// Battle Ŭ����
class Battle
{
private:
    Poketmon* player1;
    Poketmon* player2;
    bool player1Guarded;
    bool player2Guarded;
    Poketmon* first;
    Poketmon* second;
    // �� ����
    double TypeEffect(Poketmon* attacker, Poketmon* defender, double damage);

public:
    Battle(Poketmon* p1, Poketmon* p2);

    // ��ų ����
    int chooseSkill(Poketmon* player);

    // ���� ��� ó�� �Լ�
    double processAttack(Poketmon* attacker, Poketmon* defender, int skill_choice, bool& guarded);

    // �� ó�� �Լ�
    void processTurn(Poketmon* attacker, Poketmon* defender, int attackerSkill, int defenderSkill, bool& attackerGuarded, bool& defenderGuarded);

    // ù�� ���� �Լ�
    void FirstAttack(Poketmon*& first, Poketmon*& second);

    // ��Ʋ �Լ�
    void startBattle();
};
