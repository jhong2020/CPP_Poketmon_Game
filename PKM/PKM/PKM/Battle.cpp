#include "pch.h"
#include "Battle.h"

// Poketmon 생성자
Poketmon::Poketmon(string lmage_Name, string Poketmon_Name, string type, double full_hp, double attack, double defense, double speed)
{
    this->lmage_Name = lmage_Name;
    this->Poketmon_Name = Poketmon_Name;
    this->type = type;
    this->full_hp = full_hp;
    this->hp = full_hp;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
}

// 포켓몬 정보 getter 함수들
string Poketmon::GetImage_Name() { return this->lmage_Name; }
string Poketmon::GetPoketmon_Name() { return this->Poketmon_Name; }
string Poketmon::GetType() { return this->type; }
double Poketmon::GetFull_hp() { return this->full_hp; }
double Poketmon::GetHp() { return this->hp; }
double Poketmon::GetAttack() { return this->attack; }
double Poketmon::GetDefense() { return this->defense; }
double Poketmon::GetSpeed() { return this->speed; }

// 물 스킬 (물 타입만 사용 가능)
tuple<string, double> Poketmon::hydro()
{
    if (type == "물")
    {
        string skillType = "물";
        double damage = attack * 1.7;
        return make_tuple(skillType, damage);
    }
    else
    {
        return make_tuple("사용 불가", 0);
    }
}

// 불 스킬 (불 타입만 사용 가능)
tuple<string, double> Poketmon::Pyro()
{
    if (type == "불")
    {
        string skillType = "불";
        double damage = attack * 1.7;
        return make_tuple(skillType, damage);
    }
    else
    {
        return make_tuple("사용 불가", 0);
    }
}

// 풀 스킬 (풀 타입만 사용 가능)
tuple<string, double> Poketmon::Glass()
{
    if (type == "풀")
    {
        string skillType = "풀";
        double damage = attack * 1.7;
        return make_tuple(skillType, damage);
    }
    else
    {
        return make_tuple("사용 불가", 0);
    }
}

// 공용 스킬
double Poketmon::Normal() { return attack * 1.5; }

bool Poketmon::Guard()
{
    srand(time(NULL));
    int num = rand() % 4;
    return num < 2;
}

double Poketmon::Heal()
{
    double heal = full_hp / 2.0;
    if ((hp + heal) > full_hp)
    {
        return full_hp;
    }
    else
    {
        return hp + heal;
    }
}

// HP 설정 함수
void Poketmon::setHp(double newHp) { hp = newHp; }

// 상성 효과 계산 함수
double Battle::TypeEffect(Poketmon* attacker, Poketmon* defender, double damage)
{
    string attackerType = attacker->GetType();
    string defenderType = defender->GetType();

    if (attackerType == "불" && defenderType == "풀")
    {
        damage *= 1.5;
    }
    else if (attackerType == "물" && defenderType == "불")
    {
        damage *= 1.5;
    }
    else if (attackerType == "풀" && defenderType == "물")
    {
        damage *= 1.5;
    }
    return damage;
}

// Battle 클래스 생성자
Battle::Battle(Poketmon* p1, Poketmon* p2)
{
    player1 = p1;
    player2 = p2;
}

// 스킬 선택 함수
int Battle::chooseSkill(Poketmon* player)
{
    // 이 부분에서는 Form1의 UpdateConsole을 더 이상 사용하지 않습니다.
    int choice;
    cout << player->GetPoketmon_Name() << "의 턴입니다." << endl;
    cout << "1. 몸통박치기\n2. 힐\n3. 방어\n";
    if (player->GetType() == "물")
        cout << "4. Hydro Attack\n";
    if (player->GetType() == "불")
        cout << "5. Pyro Attack\n";
    if (player->GetType() == "풀")
        cout << "6. Glass Attack\n";
    cout << "스킬을 선택하세요: ";
    cin >> choice;
    return choice;
}

// processAttack 함수 (공격 처리)
double Battle::processAttack(Poketmon* attacker, Poketmon* defender, int skill_choice, bool& guarded)
{
    double damage = 0;
    string skillType;

    switch (skill_choice)
    {
    case 1:
        damage = attacker->Normal();
        skillType = "일반 공격";
        break;
    case 2:
        attacker->setHp(attacker->Heal());
        cout << attacker->GetPoketmon_Name() << "가 체력을 회복했습니다!" << endl;
        return 0;
    case 3:
        if (attacker->Guard())
        {
            cout << attacker->GetPoketmon_Name() << "가 방어에 성공했습니다!" << endl;
            guarded = true;
        }
        else
        {
            cout << attacker->GetPoketmon_Name() << "가 방어에 실패했습니다!" << endl;
        }
        return 0;
    case 4:
        tie(skillType, damage) = attacker->hydro();
        break;
    case 5:
        tie(skillType, damage) = attacker->Pyro();
        break;
    case 6:
        tie(skillType, damage) = attacker->Glass();
        break;
    default:
        cout << "잘못된 선택입니다!" << endl;
        return 0;
    }

    // 상성 적용
    damage = TypeEffect(attacker, defender, damage);

    // 체력 감소 처리 (방어 성공 여부에 따라)
    if (!guarded) {
        defender->setHp(defender->GetHp() - damage);
        cout << defender->GetPoketmon_Name() << "의 남은 체력: " << defender->GetHp() << endl;
        if (defender->GetHp() < 0) defender->setHp(0);  // 체력이 0 이하로 떨어지지 않도록 처리
    }
    else {
        // 방어에 성공하면 공격자는 데미지를 입지 않음
        cout << defender->GetPoketmon_Name() << "가 공격을 완전히 방어했습니다!" << endl;
    }

    return damage;
}


void Battle::processTurn(Poketmon* attacker, Poketmon* defender, int attackerSkill, int defenderSkill, bool& attackerGuarded, bool& defenderGuarded)
{
    // 후턴 플레이어가 방어 스킬을 선택한 경우 먼저 처리
    if (defenderSkill == 3) {
        if (defender->Guard()) {
            cout << defender->GetPoketmon_Name() << "이(가) 방어에 성공했습니다!" << endl;
            defenderGuarded = true;
        }
        else {
            cout << defender->GetPoketmon_Name() << "이(가) 방어에 실패했습니다!" << endl;
            defenderGuarded = false;
        }
    }

    // 선턴 플레이어의 공격/스킬 처리
    double attackerDamage = 0;

    // 방어 성공 여부에 따라 공격 처리
    if (!defenderGuarded) {
        attackerDamage = processAttack(attacker, defender, attackerSkill, attackerGuarded);

        if (attackerDamage > 0) {
            attackerDamage -= defender->GetDefense();  // 방어력을 차감한 데미지 계산
            defender->setHp(defender->GetHp() - (attackerDamage > 0 ? attackerDamage : 0));  // 0 이하의 데미지 방지
            cout << attacker->GetPoketmon_Name() << "의 공격! " << (attackerDamage > 0 ? attackerDamage : 0) << " 피해!" << endl;
            cout << defender->GetPoketmon_Name() << "의 남은 HP: " << defender->GetHp() << endl;
        }
    }

    // 후턴 플레이어의 공격/스킬 처리 (공격 스킬일 경우만 처리)
    if (defenderSkill != 3) {
        double defenderDamage = processAttack(defender, attacker, defenderSkill, defenderGuarded);

        if (!attackerGuarded && defenderDamage > 0) {
            defenderDamage -= attacker->GetDefense();  // 방어력을 차감한 데미지 계산
            attacker->setHp(attacker->GetHp() - (defenderDamage > 0 ? defenderDamage : 0));  // 0 이하의 데미지 방지
            cout << defender->GetPoketmon_Name() << "의 공격! " << (defenderDamage > 0 ? defenderDamage : 0) << " 피해!" << endl;
            cout << attacker->GetPoketmon_Name() << "의 남은 HP: " << attacker->GetHp() << endl;
        }
    }

    cout << endl;  // 턴이 끝날 때마다 줄바꿈 출력
}





// 첫턴 결정 함수
void Battle::FirstAttack(Poketmon*& first, Poketmon*& second)
{
    if (player1->GetSpeed() > player2->GetSpeed())
    {
        first = player1;
        second = player2;
        cout << player1->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
    }
    else if (player2->GetSpeed() > player1->GetSpeed())
    {
        first = player2;
        second = player1;
        cout << player2->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
    }
    else
    {
        srand(time(NULL));
        if (rand() % 2 == 0)
        {
            first = player1;
            second = player2;
            cout << player1->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
        }
        else
        {
            first = player2;
            second = player1;
            cout << player2->GetPoketmon_Name() << "이(가) 선제공격합니다!" << endl;
        }
    }
}

// 배틀 함수
void Battle::startBattle() {
    FirstAttack(first, second);

    while (player1->GetHp() > 0 && player2->GetHp() > 0) {
        int firstSkill = chooseSkill(first);
        int secondSkill = chooseSkill(second);

        player1Guarded = false;
        player2Guarded = false;

        processTurn(first, second, firstSkill, secondSkill, player1Guarded, player2Guarded);

        cout << "1P 체력: " << player1->GetHp() << " | 2P 체력: " << player2->GetHp() << endl;

        // 1P 체력 확인
        if (first->GetHp() <= 0) {
            cout << first->GetPoketmon_Name() << "이(가) 쓰러졌습니다!" << endl;
            cout << second->GetPoketmon_Name() << "의 승리!" << endl;
            break;
        }

        // 2P 체력 확인
        if (second->GetHp() <= 0) {
            cout << second->GetPoketmon_Name() << "이(가) 쓰러졌습니다!" << endl;
            cout << first->GetPoketmon_Name() << "의 승리!" << endl;
            break;
        }

        // 턴 교체
        swap(first, second);
    }
}

