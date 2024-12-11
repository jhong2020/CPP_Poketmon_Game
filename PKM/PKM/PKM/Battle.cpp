#include "pch.h"
#include "Battle.h"

// Poketmon ������
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

// ���ϸ� ���� getter �Լ���
string Poketmon::GetImage_Name() { return this->lmage_Name; }
string Poketmon::GetPoketmon_Name() { return this->Poketmon_Name; }
string Poketmon::GetType() { return this->type; }
double Poketmon::GetFull_hp() { return this->full_hp; }
double Poketmon::GetHp() { return this->hp; }
double Poketmon::GetAttack() { return this->attack; }
double Poketmon::GetDefense() { return this->defense; }
double Poketmon::GetSpeed() { return this->speed; }

// �� ��ų (�� Ÿ�Ը� ��� ����)
tuple<string, double> Poketmon::hydro()
{
    if (type == "��")
    {
        string skillType = "��";
        double damage = attack * 1.7;
        return make_tuple(skillType, damage);
    }
    else
    {
        return make_tuple("��� �Ұ�", 0);
    }
}

// �� ��ų (�� Ÿ�Ը� ��� ����)
tuple<string, double> Poketmon::Pyro()
{
    if (type == "��")
    {
        string skillType = "��";
        double damage = attack * 1.7;
        return make_tuple(skillType, damage);
    }
    else
    {
        return make_tuple("��� �Ұ�", 0);
    }
}

// Ǯ ��ų (Ǯ Ÿ�Ը� ��� ����)
tuple<string, double> Poketmon::Glass()
{
    if (type == "Ǯ")
    {
        string skillType = "Ǯ";
        double damage = attack * 1.7;
        return make_tuple(skillType, damage);
    }
    else
    {
        return make_tuple("��� �Ұ�", 0);
    }
}

// ���� ��ų
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

// HP ���� �Լ�
void Poketmon::setHp(double newHp) { hp = newHp; }

// �� ȿ�� ��� �Լ�
double Battle::TypeEffect(Poketmon* attacker, Poketmon* defender, double damage)
{
    string attackerType = attacker->GetType();
    string defenderType = defender->GetType();

    if (attackerType == "��" && defenderType == "Ǯ")
    {
        damage *= 1.5;
    }
    else if (attackerType == "��" && defenderType == "��")
    {
        damage *= 1.5;
    }
    else if (attackerType == "Ǯ" && defenderType == "��")
    {
        damage *= 1.5;
    }
    return damage;
}

// Battle Ŭ���� ������
Battle::Battle(Poketmon* p1, Poketmon* p2)
{
    player1 = p1;
    player2 = p2;
}

// ��ų ���� �Լ�
int Battle::chooseSkill(Poketmon* player)
{
    // �� �κп����� Form1�� UpdateConsole�� �� �̻� ������� �ʽ��ϴ�.
    int choice;
    cout << player->GetPoketmon_Name() << "�� ���Դϴ�." << endl;
    cout << "1. �����ġ��\n2. ��\n3. ���\n";
    if (player->GetType() == "��")
        cout << "4. Hydro Attack\n";
    if (player->GetType() == "��")
        cout << "5. Pyro Attack\n";
    if (player->GetType() == "Ǯ")
        cout << "6. Glass Attack\n";
    cout << "��ų�� �����ϼ���: ";
    cin >> choice;
    return choice;
}

// processAttack �Լ� (���� ó��)
double Battle::processAttack(Poketmon* attacker, Poketmon* defender, int skill_choice, bool& guarded)
{
    double damage = 0;
    string skillType;

    switch (skill_choice)
    {
    case 1:
        damage = attacker->Normal();
        skillType = "�Ϲ� ����";
        break;
    case 2:
        attacker->setHp(attacker->Heal());
        cout << attacker->GetPoketmon_Name() << "�� ü���� ȸ���߽��ϴ�!" << endl;
        return 0;
    case 3:
        if (attacker->Guard())
        {
            cout << attacker->GetPoketmon_Name() << "�� �� �����߽��ϴ�!" << endl;
            guarded = true;
        }
        else
        {
            cout << attacker->GetPoketmon_Name() << "�� �� �����߽��ϴ�!" << endl;
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
        cout << "�߸��� �����Դϴ�!" << endl;
        return 0;
    }

    // �� ����
    damage = TypeEffect(attacker, defender, damage);

    // ü�� ���� ó�� (��� ���� ���ο� ����)
    if (!guarded) {
        defender->setHp(defender->GetHp() - damage);
        cout << defender->GetPoketmon_Name() << "�� ���� ü��: " << defender->GetHp() << endl;
        if (defender->GetHp() < 0) defender->setHp(0);  // ü���� 0 ���Ϸ� �������� �ʵ��� ó��
    }
    else {
        // �� �����ϸ� �����ڴ� �������� ���� ����
        cout << defender->GetPoketmon_Name() << "�� ������ ������ ����߽��ϴ�!" << endl;
    }

    return damage;
}


void Battle::processTurn(Poketmon* attacker, Poketmon* defender, int attackerSkill, int defenderSkill, bool& attackerGuarded, bool& defenderGuarded)
{
    // ���� �÷��̾ ��� ��ų�� ������ ��� ���� ó��
    if (defenderSkill == 3) {
        if (defender->Guard()) {
            cout << defender->GetPoketmon_Name() << "��(��) �� �����߽��ϴ�!" << endl;
            defenderGuarded = true;
        }
        else {
            cout << defender->GetPoketmon_Name() << "��(��) �� �����߽��ϴ�!" << endl;
            defenderGuarded = false;
        }
    }

    // ���� �÷��̾��� ����/��ų ó��
    double attackerDamage = 0;

    // ��� ���� ���ο� ���� ���� ó��
    if (!defenderGuarded) {
        attackerDamage = processAttack(attacker, defender, attackerSkill, attackerGuarded);

        if (attackerDamage > 0) {
            attackerDamage -= defender->GetDefense();  // ������ ������ ������ ���
            defender->setHp(defender->GetHp() - (attackerDamage > 0 ? attackerDamage : 0));  // 0 ������ ������ ����
            cout << attacker->GetPoketmon_Name() << "�� ����! " << (attackerDamage > 0 ? attackerDamage : 0) << " ����!" << endl;
            cout << defender->GetPoketmon_Name() << "�� ���� HP: " << defender->GetHp() << endl;
        }
    }

    // ���� �÷��̾��� ����/��ų ó�� (���� ��ų�� ��츸 ó��)
    if (defenderSkill != 3) {
        double defenderDamage = processAttack(defender, attacker, defenderSkill, defenderGuarded);

        if (!attackerGuarded && defenderDamage > 0) {
            defenderDamage -= attacker->GetDefense();  // ������ ������ ������ ���
            attacker->setHp(attacker->GetHp() - (defenderDamage > 0 ? defenderDamage : 0));  // 0 ������ ������ ����
            cout << defender->GetPoketmon_Name() << "�� ����! " << (defenderDamage > 0 ? defenderDamage : 0) << " ����!" << endl;
            cout << attacker->GetPoketmon_Name() << "�� ���� HP: " << attacker->GetHp() << endl;
        }
    }

    cout << endl;  // ���� ���� ������ �ٹٲ� ���
}





// ù�� ���� �Լ�
void Battle::FirstAttack(Poketmon*& first, Poketmon*& second)
{
    if (player1->GetSpeed() > player2->GetSpeed())
    {
        first = player1;
        second = player2;
        cout << player1->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
    }
    else if (player2->GetSpeed() > player1->GetSpeed())
    {
        first = player2;
        second = player1;
        cout << player2->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
    }
    else
    {
        srand(time(NULL));
        if (rand() % 2 == 0)
        {
            first = player1;
            second = player2;
            cout << player1->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
        }
        else
        {
            first = player2;
            second = player1;
            cout << player2->GetPoketmon_Name() << "��(��) ���������մϴ�!" << endl;
        }
    }
}

// ��Ʋ �Լ�
void Battle::startBattle() {
    FirstAttack(first, second);

    while (player1->GetHp() > 0 && player2->GetHp() > 0) {
        int firstSkill = chooseSkill(first);
        int secondSkill = chooseSkill(second);

        player1Guarded = false;
        player2Guarded = false;

        processTurn(first, second, firstSkill, secondSkill, player1Guarded, player2Guarded);

        cout << "1P ü��: " << player1->GetHp() << " | 2P ü��: " << player2->GetHp() << endl;

        // 1P ü�� Ȯ��
        if (first->GetHp() <= 0) {
            cout << first->GetPoketmon_Name() << "��(��) ���������ϴ�!" << endl;
            cout << second->GetPoketmon_Name() << "�� �¸�!" << endl;
            break;
        }

        // 2P ü�� Ȯ��
        if (second->GetHp() <= 0) {
            cout << second->GetPoketmon_Name() << "��(��) ���������ϴ�!" << endl;
            cout << first->GetPoketmon_Name() << "�� �¸�!" << endl;
            break;
        }

        // �� ��ü
        swap(first, second);
    }
}

