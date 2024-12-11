#include "pch.h"
#include "Form1.h"
#include "Battle.h"
using namespace System::Resources;
using namespace System::Drawing;
using namespace System::Reflection;
using namespace System::Threading::Tasks;
using namespace System::Media;
using namespace System::IO;

CppCLRWinFormsProject::Form1::Form1(String^ player1Poketmon, String^ player2Poketmon, int player1HP, int player2HP)
{
    InitializeComponent();
    ResourceManager^ rm = gcnew ResourceManager("PKM.Resources", System::Reflection::Assembly::GetExecutingAssembly());

    // ��׶��� �̹��� ����
    this->BackgroundImage = (Image^)rm->GetObject(L"fightroom");
    this->BackgroundImageLayout = ImageLayout::Stretch;

    // ��Ʋ ��ü �ʱ�ȭ
    player1 = new Poketmon("���̸�", "���̸�", "��", 150, 52, 43, 65);
    player2 = new Poketmon("���α�", "���α�", "��", 150, 48, 65, 63);
    battle = new Battle(player1, player2);  
    
    // ���ϸ� ��� �߰� �� UI ����
    AddPoketmonElements(player1Poketmon, player2Poketmon, player1HP, player2HP);

    // �� �ʱ�ȭ
    player1Turn = player1->GetSpeed() > player2->GetSpeed();  // �ӵ��� ���� �� ����
    player2Turn = !player1Turn;

    EnableCurrentPlayerButtons();
}

CppCLRWinFormsProject::Form1::~Form1()
{
    if (components)
    {
        delete components;
    }

    if (battle != nullptr) {
        delete battle;
    }
}

void CppCLRWinFormsProject::Form1::InitializeComponent(void)
{
    this->SuspendLayout();
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1423, 900);
    this->Name = L"Form1";
    this->Text = L"Form1";

    // 1P ü�� �� ����
    label1PHealth = gcnew Label();
    label1PHealth->Location = System::Drawing::Point(200, 500);  // ü�¹� �ٷ� �ؿ� ��ġ
    label1PHealth->Size = System::Drawing::Size(150, 20);
    label1PHealth->ForeColor = System::Drawing::Color::White;
    label1PHealth->BackColor = System::Drawing::Color::Transparent;
    this->Controls->Add(label1PHealth);

    // 2P ü�� �� ����
    label2PHealth = gcnew Label();
    label2PHealth->Location = System::Drawing::Point(1200, 230);  // ü�¹� �ٷ� �ؿ� ��ġ
    label2PHealth->Size = System::Drawing::Size(150, 20);
    label2PHealth->ForeColor = System::Drawing::Color::White;
    label2PHealth->BackColor = System::Drawing::Color::Transparent;
    this->Controls->Add(label2PHealth);

    this->ResumeLayout(false);
}


void CppCLRWinFormsProject::Form1::AddPoketmonElements(String^ player1Poketmon, String^ player2Poketmon, int player1HP, int player2HP)
{
    ResourceManager^ rm = gcnew ResourceManager("PKM.Resources", System::Reflection::Assembly::GetExecutingAssembly());

    // 1P ���ϸ� �̹��� ����
    pictureBox1 = gcnew PictureBox();
    pictureBox1->Location = System::Drawing::Point(400, 420);
    pictureBox1->Size = System::Drawing::Size(150, 150);
    pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
    pictureBox1->BackColor = System::Drawing::Color::Transparent;
    pictureBox1->Image = GetPoketmonImage(rm, player1Poketmon);
    this->Controls->Add(pictureBox1);

    // 2P ���ϸ� �̹��� ����
    pictureBox2 = gcnew PictureBox();
    pictureBox2->Location = System::Drawing::Point(850, 170);
    pictureBox2->Size = System::Drawing::Size(150, 150);
    pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
    pictureBox2->BackColor = System::Drawing::Color::Transparent;
    pictureBox2->Image = GetPoketmonImage(rm, player2Poketmon);
    this->Controls->Add(pictureBox2);

    // 1P ���ϸ� �̸� �� ����
    label1PName = gcnew Label();
    label1PName->Text = player1Poketmon;
    label1PName->Location = System::Drawing::Point(200, 430);
    label1PName->ForeColor = System::Drawing::Color::White;
    label1PName->BackColor = System::Drawing::Color::Transparent;
    label1PName->Font = gcnew System::Drawing::Font("Arial", 16);
    this->Controls->Add(label1PName);

    // 2P ���ϸ� �̸� �� ����
    label2PName = gcnew Label();
    label2PName->Text = player2Poketmon;
    label2PName->Location = System::Drawing::Point(1000, 160);
    label2PName->ForeColor = System::Drawing::Color::White;
    label2PName->BackColor = System::Drawing::Color::Transparent;
    label2PName->Font = gcnew System::Drawing::Font("Arial", 16);
    this->Controls->Add(label2PName);

    // 1P ü�¹� ����
    progressBar1P = gcnew ProgressBar();
    progressBar1P->Location = System::Drawing::Point(200, 470);
    progressBar1P->Size = System::Drawing::Size(150, 20);
    progressBar1P->Maximum = 100;
    progressBar1P->Value = player1HP;
    this->Controls->Add(progressBar1P);

    // 2P ü�¹� ����
    progressBar2P = gcnew ProgressBar();
    progressBar2P->Location = System::Drawing::Point(1000, 200);
    progressBar2P->Size = System::Drawing::Size(150, 20);
    progressBar2P->Maximum = 100;
    progressBar2P->Value = player2HP;
    this->Controls->Add(progressBar2P);

    // 1P�� 2P ��ų ��ư �߰�
    CreateButtons(player1Buttons, player1, 200, 500);
    CreateButtons(player2Buttons, player2, 1020, 240);

    // �ܼ� ��¿� �ؽ�Ʈ �ڽ� ����
    consoleOutput = gcnew TextBox();
    consoleOutput->Location = System::Drawing::Point(50, 50);
    consoleOutput->Size = System::Drawing::Size(500, 300);
    consoleOutput->Multiline = true;
    consoleOutput->ScrollBars = ScrollBars::Vertical;
    consoleOutput->BackColor = System::Drawing::Color::LightSkyBlue;
    consoleOutput->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Regular);
    this->Controls->Add(consoleOutput);

    // ��Ʋ ���� ��� ����
    System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
    player->Stream = rm->GetStream("��Ʋ���");
    player->PlayLooping();  // ������ �ݺ� ���
}

void CppCLRWinFormsProject::Form1::CreateButtons(cli::array<Button^>^% buttons, Poketmon* player, int x, int y)
{
    buttons = gcnew cli::array<Button^>(4);  // 4���� ��ų ��ư ����
    for (int i = 0; i < 4; i++)
    {
        buttons[i] = gcnew Button();
        buttons[i]->Location = System::Drawing::Point(x, y + (i * 30));
        buttons[i]->Size = System::Drawing::Size(100, 30);

        // ���ϸ� Ÿ�Կ� ���� ��ų ��ư �̸� ����
        switch (i)
        {
        case 0:
            buttons[i]->Text = "�����ġ��";
            break;
        case 1:
            buttons[i]->Text = "��";
            break;
        case 2:
            buttons[i]->Text = "����";
            break;
        case 3:
            if (player->GetType() == "��")
                buttons[i]->Text = "Pyro Attack";
            else if (player->GetType() == "��")
                buttons[i]->Text = "Hydro Attack";
            else if (player->GetType() == "Ǯ")
                buttons[i]->Text = "Glass Attack";
            break;
        }

        buttons[i]->Click += gcnew EventHandler(this, &Form1::OnSkillButtonClick);
        this->Controls->Add(buttons[i]);
    }
}

// ��ų ��ư Ŭ�� �̺�Ʈ ó�� �Լ�
void CppCLRWinFormsProject::Form1::OnSkillButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Button^ clickedButton = dynamic_cast<Button^>(sender);
    consoleOutput->AppendText("��ų ���: " + clickedButton->Text + "\r\n");

    // ��ų �ε��� ���� (��ư�� ����)
    int skillIndex = 0;
    for (int i = 0; i < 4; i++)
    {
        if (clickedButton == player1Buttons[i])
        {
            player1SelectedSkill = i + 1;  // 1P�� ��ų ����
            isPlayer1SkillSelected = true; // 1P ��ų ���� �Ϸ� �÷���
            break;
        }
        else if (clickedButton == player2Buttons[i])
        {
            player2SelectedSkill = i + 1;  // 2P�� ��ų ����
            isPlayer2SkillSelected = true; // 2P ��ų ���� �Ϸ� �÷���
            break;
        }
    }

    // 1P�� 2P �� �� ��ų�� ������ ��� �� ����
    if (isPlayer1SkillSelected && isPlayer2SkillSelected)
    {
        RunBattle(player1SelectedSkill, player2SelectedSkill);  // ��Ʋ ����
        SwitchTurn();  // �� ��ü

        // ��ų ���� ���� �ʱ�ȭ
        isPlayer1SkillSelected = false;
        isPlayer2SkillSelected = false;
    }
    else
    {
        // 1P�� ��ų ���� ���� ��� 2P�� ��ư ��Ȱ��ȭ, �ݴ�� 2P�� ��ų ���� ���̸� 1P ��ư ��Ȱ��ȭ
        if (isPlayer1SkillSelected)
        {
            for each (Button ^ button in player1Buttons)
                button->Enabled = false;  // 1P ��ư ��Ȱ��ȭ
            for each (Button ^ button in player2Buttons)
                button->Enabled = true;   // 2P ��ư Ȱ��ȭ
        }
        else if (isPlayer2SkillSelected)
        {
            for each (Button ^ button in player2Buttons)
                button->Enabled = false;  // 2P ��ư ��Ȱ��ȭ
            for each (Button ^ button in player1Buttons)
                button->Enabled = true;   // 1P ��ư Ȱ��ȭ
        }
    }
}



void CppCLRWinFormsProject::Form1::RunBattle(int player1Skill, int player2Skill)
{
    bool player1Guarded = false;
    bool player2Guarded = false;
    double damage = 0;
    String^ skillMessage;

    // 1P ��� ���� ó��
    if (player1Skill == 3) {
        battle->processAttack(player1, player2, player1Skill, player1Guarded);
        skillMessage = player1Guarded ? gcnew String(player1->GetPoketmon_Name().c_str()) + "�� �� �����߽��ϴ�!" :
            gcnew String(player1->GetPoketmon_Name().c_str()) + "�� �� �����߽��ϴ�!";
        UpdateConsole(skillMessage);
    }

    // 2P ��� ���� ó��
    if (player2Skill == 3) {
        battle->processAttack(player2, player1, player2Skill, player2Guarded);
        skillMessage = player2Guarded ? gcnew String(player2->GetPoketmon_Name().c_str()) + "�� �� �����߽��ϴ�!" :
            gcnew String(player2->GetPoketmon_Name().c_str()) + "�� �� �����߽��ϴ�!";
        UpdateConsole(skillMessage);
    }

    // �� �������� ���� �÷��̾�Ը� ���� ����
    if (!player2Guarded) {
        switch (player1Skill)
        {
        case 1:  // Normal Attack
            damage = battle->processAttack(player1, player2, player1Skill, player1Guarded);
            skillMessage = gcnew String(player1->GetPoketmon_Name().c_str()) + "�� �Ϲ� ����!";
            break;
        case 2:  // Heal
            battle->processAttack(player1, player2, player1Skill, player1Guarded);  // ��
            skillMessage = gcnew String(player1->GetPoketmon_Name().c_str()) + "�� ü���� ȸ���߽��ϴ�!";
            break;
        case 3:  // Guard�� �̹� ó����
            break;
        default:  // Special Skill
            damage = battle->processAttack(player1, player2, player1Skill, player1Guarded);
            skillMessage = gcnew String(player1->GetPoketmon_Name().c_str()) + "�� Ư�� ����!";
            break;
        }
        UpdateConsole(skillMessage);

        if (damage > 0)
        {
            UpdateConsole("������: " + damage.ToString() + "\r\n");
        }
    }

    if (!player1Guarded) {
        switch (player2Skill)
        {
        case 1:  // Normal Attack
            damage = battle->processAttack(player2, player1, player2Skill, player2Guarded);
            skillMessage = gcnew String(player2->GetPoketmon_Name().c_str()) + "�� �Ϲ� ����!";
            break;
        case 2:  // Heal
            battle->processAttack(player2, player1, player2Skill, player2Guarded);  // ��
            skillMessage = gcnew String(player2->GetPoketmon_Name().c_str()) + "�� ü���� ȸ���߽��ϴ�!";
            break;
        case 3:  // Guard�� �̹� ó����
            break;
        default:  // Special Skill
            damage = battle->processAttack(player2, player1, player2Skill, player2Guarded);
            skillMessage = gcnew String(player2->GetPoketmon_Name().c_str()) + "�� Ư�� ����!";
            break;
        }
        UpdateConsole(skillMessage);

        if (damage > 0)
        {
            UpdateConsole("������: " + damage.ToString() + "\r\n");
        }
    }

    // ü�¹� ������Ʈ
    UpdateHealthBar(progressBar1P, label1PHealth, player1);
    UpdateHealthBar(progressBar2P, label2PHealth, player2);

    // ü���� 0 ������ ���ϸ��� �ִ��� Ȯ��
    if (player1->GetHp() <= 0)
    {
        UpdateConsole(gcnew String(player1->GetPoketmon_Name().c_str()) + "�� ���������ϴ�! " + gcnew String(player2->GetPoketmon_Name().c_str()) + "�� �¸�!");
        DisableAllButtons();  // ��� ��ư ��Ȱ��ȭ
        CloseGame();          // ���� ����
    }
    else if (player2->GetHp() <= 0)
    {
        UpdateConsole(gcnew String(player2->GetPoketmon_Name().c_str()) + "�� ���������ϴ�! " + gcnew String(player1->GetPoketmon_Name().c_str()) + "�� �¸�!");
        DisableAllButtons();  // ��� ��ư ��Ȱ��ȭ
        CloseGame();          // ���� ����
    }
    else
    {
        // ���� ���� �� ���� �� �غ�
        SwitchTurn();
    }
}




// ��� ��ų ��ư ��Ȱ��ȭ
void CppCLRWinFormsProject::Form1::DisableAllButtons()
{
    for each (Button ^ button in player1Buttons)
        button->Enabled = false;
    for each (Button ^ button in player2Buttons)
        button->Enabled = false;
}
// ���� ���� �Լ�
void CppCLRWinFormsProject::Form1::CloseGame()
{
    // ���� ���� �� �޽��� �ڽ� ���
    MessageBox::Show("������ ����˴ϴ�.", "���� ����", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // �� ���� (���� ����)
    this->Close();
}



void CppCLRWinFormsProject::Form1::UpdateHealthBar(ProgressBar^ progressBar, Label^ healthLabel, Poketmon* player)
{
    // ü�� �ۼ�Ʈ ������Ʈ
    int healthPercentage = static_cast<int>((player->GetHp() / player->GetFull_hp()) * 100);
    progressBar->Value = healthPercentage;

    // ü�� �� ������Ʈ
    healthLabel->Text = "ü��: " + healthPercentage.ToString() + "%";
}


void CppCLRWinFormsProject::Form1::SwitchTurn()
{
    player1Turn = !player1Turn;  // ���� ��ü
    EnableCurrentPlayerButtons();  // ���� �Ͽ� �´� ��ư Ȱ��ȭ
}


void CppCLRWinFormsProject::Form1::EnableCurrentPlayerButtons()
{
    if (player1Turn)
    {
        // 1P�� ��: 1P ��ų ��ư Ȱ��ȭ, 2P ��ų ��ư ��Ȱ��ȭ
        for each (Button ^ button in player1Buttons)
        {
            button->Enabled = true;
        }
        for each (Button ^ button in player2Buttons)
        {
            button->Enabled = false;
        }
    }
    else
    {
        // 2P�� ��: 2P ��ų ��ư Ȱ��ȭ, 1P ��ų ��ư ��Ȱ��ȭ
        for each (Button ^ button in player1Buttons)
        {
            button->Enabled = false;
        }
        for each (Button ^ button in player2Buttons)
        {
            button->Enabled = true;
        }
    }
}


void CppCLRWinFormsProject::Form1::DisableCurrentPlayerButtons()
{
    if (player1Turn)
    {
        for each (Button ^ button in player2Buttons)
        {
            button->Enabled = false;
        }
    }
    else
    {
        for each (Button ^ button in player1Buttons)
        {
            button->Enabled = false;
        }
    }
}


Image^ CppCLRWinFormsProject::Form1::GetPoketmonImage(ResourceManager^ rm, String^ poketmonName)
{
    if (poketmonName == "�̻��ؾ�")
        return (Image^)rm->GetObject(L"�̻��ؾ�");
    else if (poketmonName == "���̸�")
        return (Image^)rm->GetObject(L"���̸�");
    else if (poketmonName == "���α�")
        return (Image^)rm->GetObject(L"���α�");
    else
        return nullptr;
}

void CppCLRWinFormsProject::Form1::UpdateBattleUI()
{
    label1PName->Text = gcnew String(player1->GetPoketmon_Name().c_str());
    label2PName->Text = gcnew String(player2->GetPoketmon_Name().c_str());

    progressBar1P->Value = static_cast<int>((player1->GetHp() / player1->GetFull_hp()) * 100);
    progressBar2P->Value = static_cast<int>((player2->GetHp() / player2->GetFull_hp()) * 100);

}
void CppCLRWinFormsProject::Form1::UpdateConsole(System::String^ message)
{
    // UI�� TextBox (consoleOutput) �� �޽��� ���
    consoleOutput->AppendText(message + "\r\n");
}
