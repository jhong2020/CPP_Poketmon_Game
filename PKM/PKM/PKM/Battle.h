#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <cstdlib>
#include <ctime>
using namespace std;

// Skill 클래스
class Skill
{
public:
    virtual tuple<string, double> hydro() = 0;  // 물 스킬
    virtual tuple<string, double> Pyro() = 0;   // 불 스킬
    virtual tuple<string, double> Glass() = 0;  // 풀 스킬
    virtual double Normal() = 0;                // 일반 공격
    virtual double Heal() = 0;                  // 회복
    virtual bool Guard() = 0;                   // 방어
};

// Poketmon 클래스
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
    // 생성자
    Poketmon(string lmage_Name, string Poketmon_Name, string type, double full_hp, double attack, double defense, double speed);

    // 포켓몬 정보 getter 함수
    string GetImage_Name();
    string GetPoketmon_Name();
    string GetType();
    double GetFull_hp();
    double GetHp();
    double GetAttack();
    double GetDefense();
    double GetSpeed();

    // 물 스킬 (물 타입만 사용 가능)
    virtual tuple<string, double> hydro();

    // 불 스킬 (불 타입만 사용 가능)
    virtual tuple<string, double> Pyro();

    // 풀 스킬 (풀 타입만 사용 가능)
    virtual tuple<string, double> Glass();

    // 공용 스킬
    virtual double Normal();
    virtual bool Guard();
    virtual double Heal();

    // HP 설정 함수
    void setHp(double newHp);

    // 포켓몬의 정보 출력
    void PoketmonInfo();
};

// Battle 클래스
class Battle
{
private:
    Poketmon* player1;
    Poketmon* player2;
    bool player1Guarded;
    bool player2Guarded;
    Poketmon* first;
    Poketmon* second;
    // 상성 적용
    double TypeEffect(Poketmon* attacker, Poketmon* defender, double damage);

public:
    Battle(Poketmon* p1, Poketmon* p2);

    // 스킬 선택
    int chooseSkill(Poketmon* player);

    // 공격 결과 처리 함수
    double processAttack(Poketmon* attacker, Poketmon* defender, int skill_choice, bool& guarded);

    // 턴 처리 함수
    void processTurn(Poketmon* attacker, Poketmon* defender, int attackerSkill, int defenderSkill, bool& attackerGuarded, bool& defenderGuarded);

    // 첫턴 결정 함수
    void FirstAttack(Poketmon*& first, Poketmon*& second);

    // 배틀 함수
    void startBattle();
};
