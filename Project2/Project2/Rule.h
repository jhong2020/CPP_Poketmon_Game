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
//// Skill 클래스
//namespace Project2 {
//    class Skill
//    {
//    public:
//        virtual tuple<string, double> hydro() = 0;  // 물 스킬
//        virtual tuple<string, double> Pyro() = 0;   // 불 스킬
//        virtual tuple<string, double> Glass() = 0;  // 풀 스킬
//        virtual double Normal() = 0;                // 일반 공격
//        virtual double Heal() = 0;                  // 회복
//        virtual bool Guard() = 0;                   // 방어
//    };
//
//    // Poketmon 클래스
//    public class Poketmon : public Skill
//    {
//    private:
//        string lmage_Name;//이미지 이름
//        string Poketmon_Name;//포켓몬 이름
//        string type;//타입
//        double full_hp;//최대체력
//        double hp;//현재 체력
//        double attack;//공격력
//        double defense;//방어력
//        double speed;//스피드
//
//    public:
//        // 생성자: 포켓몬 초기 상태 설정
//        Poketmon(string lmage_Name, string Poketmon_Name, string type, double full_hp, double attack, double defense, double speed)
//        {
//            this->lmage_Name = lmage_Name;
//            this->Poketmon_Name = Poketmon_Name;
//            this->type = type;
//            this->full_hp = full_hp;
//            this->hp = full_hp;//현재 체력은 최대 체력으로 설정
//            this->attack = attack;
//            this->defense = defense;
//            this->speed = speed;
//        }
//
//        // 포켓몬 정보 getter 함수
//        string GetImage_Name() { return this->lmage_Name; }
//        string GetPoketmon_Name() { return this->Poketmon_Name; }
//        string GetType() { return this->type; }
//        double GetFull_hp() { return this->full_hp; }
//        double GetHp() { return this->hp; }
//        double GetAttack() { return this->attack; }
//        double GetDefense() { return this->defense; }
//        double GetSpeed() { return this->speed; }
//
//        // 물 스킬 (물 타입만 사용 가능)
//        virtual tuple<string, double> hydro()
//        {
//            if (type == "물")
//            {
//                string skillType = "물";
//                double damage = attack * 1.7;
//                return make_tuple(skillType, damage);
//            }
//            else
//            {
//                return make_tuple("사용 불가", 0);
//            }
//        }
//
//        // 불 스킬 (불 타입만 사용 가능)
//        virtual tuple<string, double> Pyro()
//        {
//            if (type == "불")
//            {
//                string skillType = "불";
//                double damage = attack * 1.7;
//                return make_tuple(skillType, damage);
//            }
//            else
//            {
//                return make_tuple("사용 불가", 0);
//            }
//        }
//
//        // 풀 스킬 (풀 타입만 사용 가능)
//        virtual tuple<string, double> Glass()
//        {
//            if (type == "풀")
//            {
//                string skillType = "풀";
//                double damage = attack * 1.7;
//                return make_tuple(skillType, damage);
//            }
//            else
//            {
//                return make_tuple("사용 불가", 0);
//            }
//        }
//
//        // 공용 스킬
//        virtual double Normal() { return attack * 1.5; }//일반 공격
//
//        virtual bool Guard()//방어 스킬
//        {
//            srand(time(NULL));
//            int num = rand() % 4;
//            return num < 2;
//        }
//
//        virtual double Heal()//체력 회복
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
//        // HP 설정 함수
//        void setHp(double newHp) { hp = newHp; }
//
//        // 포켓몬의 정보 출력
//        void PoketmonInfo()
//        {
//            cout << "포켓몬 이름: " << Poketmon_Name << endl;
//            cout << "타입: " << type << endl;
//            cout << "HP: " << hp << "/" << full_hp << endl;
//            cout << "속도: " << speed << endl;
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
//        // 상성 적용
//        double TypeEffect(Poketmon* attacker, Poketmon* defender, double damage)
//        {
//            string attackerType = attacker->GetType();
//            string defenderType = defender->GetType();
//
//            if (attackerType == "불" && defenderType == "풀")
//            {
//                cout << "효과는 굉장했다!" << endl;
//                damage *= 1.5;
//            }
//            else if (attackerType == "물" && defenderType == "불")
//            {
//                cout << "효과는 굉장했다!" << endl;
//                damage *= 1.5;
//            }
//            else if (attackerType == "풀" && defenderType == "물")
//            {
//                cout << "효과는 굉장했다!" << endl;
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
//        // 스킬 선택
//        int chooseSkill(Poketmon* player)
//        {
//            int choice;
//            cout << player->GetPoketmon_Name() << "의 턴입니다." << endl;
//            cout << "1. 몸통박치기\n";
//            cout << "2. 힐\n";
//            cout << "3. 방어\n";
//            if (player->GetType() == "물")
//                cout << "4. Hydro Attack\n";
//            if (player->GetType() == "불")
//                cout << "5. Pyro Attack\n";
//            if (player->GetType() == "풀")
//                cout << "6. Glass Attack\n";
//            cout << "스킬을 선택하세요: ";
//            cin >> choice;
//            return choice;
//        }
//
//        // 공격 결과 처리 함수
//        double processAttack(Poketmon* attacker, Poketmon* defender, int skill_choice, bool& guarded)
//        {
//            double damage = 0;
//            string skillType;
//
//            // 스킬 선택에 따른 데미지 계산
//            switch (skill_choice)
//            {
//            case 1:
//                damage = attacker->Normal();
//                skillType = "일반 공격";
//                break;
//            case 2:
//                attacker->setHp(attacker->Heal());
//                cout << attacker->GetPoketmon_Name() << "가 체력을 회복했습니다!" << endl;
//                cout << attacker->GetPoketmon_Name() << "의 현재 체력: " << attacker->GetHp() << "/" << attacker->GetFull_hp() << endl;
//                return 0;
//            case 3:
//                if (attacker->Guard())
//                {
//                    cout << attacker->GetPoketmon_Name() << "가 방어에 성공했습니다!" << endl;
//                    guarded = true;
//                }
//                else
//                {
//                    cout << attacker->GetPoketmon_Name() << "가 방어에 실패했습니다!" << endl;
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
//                cout << "잘못된 선택입니다!" << endl;
//                return 0;
//            }
//
//            // 상성 적용
//            damage = TypeEffect(attacker, defender, damage);
//
//            return damage;
//        }
//
//        // 턴 처리 함수
//        void processTurn(Poketmon* attacker, Poketmon* defender, int attackerSkill, int defenderSkill, bool& attackerGuarded, bool& defenderGuarded)
//        {
//            // 후턴 플레이어가 방어 스킬을 선택한 경우 먼저 처리
//            if (defenderSkill == 3) {
//                if (defender->Guard()) {
//                    cout << defender->GetPoketmon_Name() << "이(가) 방어에 성공했습니다!" << endl;
//                    defenderGuarded = true;
//                }
//                else {
//                    cout << defender->GetPoketmon_Name() << "이(가) 방어에 실패했습니다!" << endl;
//                    defenderGuarded = false;
//                }
//            }
//
//            // 선턴 플레이어의 공격/스킬 처리
//            double attackerDamage = processAttack(attacker, defender, attackerSkill, attackerGuarded);
//
//            // 선턴 플레이어가 방어하지 않았고 데미지가 발생한 경우 처리
//            if (!defenderGuarded && attackerDamage > 0) {
//                attackerDamage = attackerDamage - defender->GetDefense();
//                defender->setHp(defender->GetHp() - (attackerDamage > 0 ? attackerDamage : 0));
//                cout << attacker->GetPoketmon_Name() << "의 공격! " << (attackerDamage > 0 ? attackerDamage : 0) << " 피해!" << endl;
//                cout << defender->GetPoketmon_Name() << "의 남은 HP: " << defender->GetHp() << endl;
//            }
//
//            // 후턴 플레이어의 공격/스킬 처리 (공격 스킬일 경우만 처리)
//            if (defenderSkill != 3) {
//                double defenderDamage = processAttack(defender, attacker, defenderSkill, defenderGuarded);
//
//                // 선턴 플레이어가 방어하지 않았고 데미지가 발생한 경우 처리
//                if (!attackerGuarded && defenderDamage > 0) {
//                    defenderDamage = defenderDamage - attacker->GetDefense();
//                    attacker->setHp(attacker->GetHp() - (defenderDamage > 0 ? defenderDamage : 0));
//                    cout << defender->GetPoketmon_Name() << "의 공격! " << (defenderDamage > 0 ? defenderDamage : 0) << " 피해!" << endl;
//                    cout << attacker->GetPoketmon_Name() << "의 남은 HP: " << attacker->GetHp() << endl;
//                }
//            }
//
//            cout << endl;
//        }
//
//
//
//        // 첫턴
//        void FirstAttack(Poketmon*& first, Poketmon*& second)
//        {
//            if (player1->GetSpeed() > player2->GetSpeed())
//            {
//                first = player1;
//                second = player2;
//                cout << player1->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
//            }
//            else if (player2->GetSpeed() > player1->GetSpeed())
//            {
//                first = player2;
//                second = player1;
//                cout << player2->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
//            }
//            else
//            {
//                srand(time(NULL));
//                if (rand() % 2 == 0)
//                {
//                    first = player1;
//                    second = player2;
//                    cout << player1->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
//                }
//                else
//                {
//                    first = player2;
//                    second = player1;
//                    cout << player2->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
//                }
//            }
//        }
//
//        // 배틀함수
//        void startBattle()
//        {
//            // 첫 턴
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
//                    cout << player1->GetPoketmon_Name() << "이(가) 쓰러졌습니다!" << endl;
//                    cout << player2->GetPoketmon_Name() << "의 승리!" << endl;
//                    break;
//                }
//
//                if (player2->GetHp() <= 0)
//                {
//                    cout << player2->GetPoketmon_Name() << "이(가) 쓰러졌습니다!" << endl;
//                    cout << player1->GetPoketmon_Name() << "의 승리!" << endl;
//                    break;
//                }
//            }
//        }
//
//        Poketmon createcharmander()
//        {
//            return Poketmon("파이리.webp", "파이리", "불꽃", 39, 52, 43, 65);
//        }
//        Poketmon createsquirtle()
//        {
//            return Poketmon("꼬부기.webp", "꼬부기", "물", 44, 48, 65, 43);
//        }
//        Poketmon createbulbasaur()
//        {
//            return Poketmon("이상해씨.webp", "이상해씨", "풀", 45, 49, 49, 45);
//        }
//    };
//}
