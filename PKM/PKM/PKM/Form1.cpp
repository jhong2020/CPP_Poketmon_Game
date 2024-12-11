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

    // 백그라운드 이미지 설정
    this->BackgroundImage = (Image^)rm->GetObject(L"fightroom");
    this->BackgroundImageLayout = ImageLayout::Stretch;

    // 배틀 객체 초기화
    player1 = new Poketmon("파이리", "파이리", "불", 150, 52, 43, 65);
    player2 = new Poketmon("꼬부기", "꼬부기", "물", 150, 48, 65, 63);
    battle = new Battle(player1, player2);  
    
    // 포켓몬 요소 추가 및 UI 구성
    AddPoketmonElements(player1Poketmon, player2Poketmon, player1HP, player2HP);

    // 턴 초기화
    player1Turn = player1->GetSpeed() > player2->GetSpeed();  // 속도에 따른 턴 설정
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

    // 1P 체력 라벨 설정
    label1PHealth = gcnew Label();
    label1PHealth->Location = System::Drawing::Point(200, 500);  // 체력바 바로 밑에 위치
    label1PHealth->Size = System::Drawing::Size(150, 20);
    label1PHealth->ForeColor = System::Drawing::Color::White;
    label1PHealth->BackColor = System::Drawing::Color::Transparent;
    this->Controls->Add(label1PHealth);

    // 2P 체력 라벨 설정
    label2PHealth = gcnew Label();
    label2PHealth->Location = System::Drawing::Point(1200, 230);  // 체력바 바로 밑에 위치
    label2PHealth->Size = System::Drawing::Size(150, 20);
    label2PHealth->ForeColor = System::Drawing::Color::White;
    label2PHealth->BackColor = System::Drawing::Color::Transparent;
    this->Controls->Add(label2PHealth);

    this->ResumeLayout(false);
}


void CppCLRWinFormsProject::Form1::AddPoketmonElements(String^ player1Poketmon, String^ player2Poketmon, int player1HP, int player2HP)
{
    ResourceManager^ rm = gcnew ResourceManager("PKM.Resources", System::Reflection::Assembly::GetExecutingAssembly());

    // 1P 포켓몬 이미지 설정
    pictureBox1 = gcnew PictureBox();
    pictureBox1->Location = System::Drawing::Point(400, 420);
    pictureBox1->Size = System::Drawing::Size(150, 150);
    pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
    pictureBox1->BackColor = System::Drawing::Color::Transparent;
    pictureBox1->Image = GetPoketmonImage(rm, player1Poketmon);
    this->Controls->Add(pictureBox1);

    // 2P 포켓몬 이미지 설정
    pictureBox2 = gcnew PictureBox();
    pictureBox2->Location = System::Drawing::Point(850, 170);
    pictureBox2->Size = System::Drawing::Size(150, 150);
    pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
    pictureBox2->BackColor = System::Drawing::Color::Transparent;
    pictureBox2->Image = GetPoketmonImage(rm, player2Poketmon);
    this->Controls->Add(pictureBox2);

    // 1P 포켓몬 이름 라벨 설정
    label1PName = gcnew Label();
    label1PName->Text = player1Poketmon;
    label1PName->Location = System::Drawing::Point(200, 430);
    label1PName->ForeColor = System::Drawing::Color::White;
    label1PName->BackColor = System::Drawing::Color::Transparent;
    label1PName->Font = gcnew System::Drawing::Font("Arial", 16);
    this->Controls->Add(label1PName);

    // 2P 포켓몬 이름 라벨 설정
    label2PName = gcnew Label();
    label2PName->Text = player2Poketmon;
    label2PName->Location = System::Drawing::Point(1000, 160);
    label2PName->ForeColor = System::Drawing::Color::White;
    label2PName->BackColor = System::Drawing::Color::Transparent;
    label2PName->Font = gcnew System::Drawing::Font("Arial", 16);
    this->Controls->Add(label2PName);

    // 1P 체력바 설정
    progressBar1P = gcnew ProgressBar();
    progressBar1P->Location = System::Drawing::Point(200, 470);
    progressBar1P->Size = System::Drawing::Size(150, 20);
    progressBar1P->Maximum = 100;
    progressBar1P->Value = player1HP;
    this->Controls->Add(progressBar1P);

    // 2P 체력바 설정
    progressBar2P = gcnew ProgressBar();
    progressBar2P->Location = System::Drawing::Point(1000, 200);
    progressBar2P->Size = System::Drawing::Size(150, 20);
    progressBar2P->Maximum = 100;
    progressBar2P->Value = player2HP;
    this->Controls->Add(progressBar2P);

    // 1P와 2P 스킬 버튼 추가
    CreateButtons(player1Buttons, player1, 200, 500);
    CreateButtons(player2Buttons, player2, 1020, 240);

    // 콘솔 출력용 텍스트 박스 설정
    consoleOutput = gcnew TextBox();
    consoleOutput->Location = System::Drawing::Point(50, 50);
    consoleOutput->Size = System::Drawing::Size(500, 300);
    consoleOutput->Multiline = true;
    consoleOutput->ScrollBars = ScrollBars::Vertical;
    consoleOutput->BackColor = System::Drawing::Color::LightSkyBlue;
    consoleOutput->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Regular);
    this->Controls->Add(consoleOutput);

    // 배틀 음악 재생 설정
    System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
    player->Stream = rm->GetStream("배틀브금");
    player->PlayLooping();  // 음악을 반복 재생
}

void CppCLRWinFormsProject::Form1::CreateButtons(cli::array<Button^>^% buttons, Poketmon* player, int x, int y)
{
    buttons = gcnew cli::array<Button^>(4);  // 4개의 스킬 버튼 생성
    for (int i = 0; i < 4; i++)
    {
        buttons[i] = gcnew Button();
        buttons[i]->Location = System::Drawing::Point(x, y + (i * 30));
        buttons[i]->Size = System::Drawing::Size(100, 30);

        // 포켓몬 타입에 따른 스킬 버튼 이름 설정
        switch (i)
        {
        case 0:
            buttons[i]->Text = "몸통박치기";
            break;
        case 1:
            buttons[i]->Text = "힐";
            break;
        case 2:
            buttons[i]->Text = "가드";
            break;
        case 3:
            if (player->GetType() == "불")
                buttons[i]->Text = "Pyro Attack";
            else if (player->GetType() == "물")
                buttons[i]->Text = "Hydro Attack";
            else if (player->GetType() == "풀")
                buttons[i]->Text = "Glass Attack";
            break;
        }

        buttons[i]->Click += gcnew EventHandler(this, &Form1::OnSkillButtonClick);
        this->Controls->Add(buttons[i]);
    }
}

// 스킬 버튼 클릭 이벤트 처리 함수
void CppCLRWinFormsProject::Form1::OnSkillButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Button^ clickedButton = dynamic_cast<Button^>(sender);
    consoleOutput->AppendText("스킬 사용: " + clickedButton->Text + "\r\n");

    // 스킬 인덱스 결정 (버튼에 따라)
    int skillIndex = 0;
    for (int i = 0; i < 4; i++)
    {
        if (clickedButton == player1Buttons[i])
        {
            player1SelectedSkill = i + 1;  // 1P의 스킬 저장
            isPlayer1SkillSelected = true; // 1P 스킬 선택 완료 플래그
            break;
        }
        else if (clickedButton == player2Buttons[i])
        {
            player2SelectedSkill = i + 1;  // 2P의 스킬 저장
            isPlayer2SkillSelected = true; // 2P 스킬 선택 완료 플래그
            break;
        }
    }

    // 1P와 2P 둘 다 스킬을 선택한 경우 턴 진행
    if (isPlayer1SkillSelected && isPlayer2SkillSelected)
    {
        RunBattle(player1SelectedSkill, player2SelectedSkill);  // 배틀 실행
        SwitchTurn();  // 턴 교체

        // 스킬 선택 상태 초기화
        isPlayer1SkillSelected = false;
        isPlayer2SkillSelected = false;
    }
    else
    {
        // 1P가 스킬 선택 중인 경우 2P의 버튼 비활성화, 반대로 2P가 스킬 선택 중이면 1P 버튼 비활성화
        if (isPlayer1SkillSelected)
        {
            for each (Button ^ button in player1Buttons)
                button->Enabled = false;  // 1P 버튼 비활성화
            for each (Button ^ button in player2Buttons)
                button->Enabled = true;   // 2P 버튼 활성화
        }
        else if (isPlayer2SkillSelected)
        {
            for each (Button ^ button in player2Buttons)
                button->Enabled = false;  // 2P 버튼 비활성화
            for each (Button ^ button in player1Buttons)
                button->Enabled = true;   // 1P 버튼 활성화
        }
    }
}



void CppCLRWinFormsProject::Form1::RunBattle(int player1Skill, int player2Skill)
{
    bool player1Guarded = false;
    bool player2Guarded = false;
    double damage = 0;
    String^ skillMessage;

    // 1P 방어 먼저 처리
    if (player1Skill == 3) {
        battle->processAttack(player1, player2, player1Skill, player1Guarded);
        skillMessage = player1Guarded ? gcnew String(player1->GetPoketmon_Name().c_str()) + "가 방어에 성공했습니다!" :
            gcnew String(player1->GetPoketmon_Name().c_str()) + "가 방어에 실패했습니다!";
        UpdateConsole(skillMessage);
    }

    // 2P 방어 먼저 처리
    if (player2Skill == 3) {
        battle->processAttack(player2, player1, player2Skill, player2Guarded);
        skillMessage = player2Guarded ? gcnew String(player2->GetPoketmon_Name().c_str()) + "가 방어에 성공했습니다!" :
            gcnew String(player2->GetPoketmon_Name().c_str()) + "가 방어에 실패했습니다!";
        UpdateConsole(skillMessage);
    }

    // 방어가 성공하지 않은 플레이어에게만 공격 진행
    if (!player2Guarded) {
        switch (player1Skill)
        {
        case 1:  // Normal Attack
            damage = battle->processAttack(player1, player2, player1Skill, player1Guarded);
            skillMessage = gcnew String(player1->GetPoketmon_Name().c_str()) + "의 일반 공격!";
            break;
        case 2:  // Heal
            battle->processAttack(player1, player2, player1Skill, player1Guarded);  // 힐
            skillMessage = gcnew String(player1->GetPoketmon_Name().c_str()) + "가 체력을 회복했습니다!";
            break;
        case 3:  // Guard는 이미 처리됨
            break;
        default:  // Special Skill
            damage = battle->processAttack(player1, player2, player1Skill, player1Guarded);
            skillMessage = gcnew String(player1->GetPoketmon_Name().c_str()) + "의 특수 공격!";
            break;
        }
        UpdateConsole(skillMessage);

        if (damage > 0)
        {
            UpdateConsole("데미지: " + damage.ToString() + "\r\n");
        }
    }

    if (!player1Guarded) {
        switch (player2Skill)
        {
        case 1:  // Normal Attack
            damage = battle->processAttack(player2, player1, player2Skill, player2Guarded);
            skillMessage = gcnew String(player2->GetPoketmon_Name().c_str()) + "의 일반 공격!";
            break;
        case 2:  // Heal
            battle->processAttack(player2, player1, player2Skill, player2Guarded);  // 힐
            skillMessage = gcnew String(player2->GetPoketmon_Name().c_str()) + "가 체력을 회복했습니다!";
            break;
        case 3:  // Guard는 이미 처리됨
            break;
        default:  // Special Skill
            damage = battle->processAttack(player2, player1, player2Skill, player2Guarded);
            skillMessage = gcnew String(player2->GetPoketmon_Name().c_str()) + "의 특수 공격!";
            break;
        }
        UpdateConsole(skillMessage);

        if (damage > 0)
        {
            UpdateConsole("데미지: " + damage.ToString() + "\r\n");
        }
    }

    // 체력바 업데이트
    UpdateHealthBar(progressBar1P, label1PHealth, player1);
    UpdateHealthBar(progressBar2P, label2PHealth, player2);

    // 체력이 0 이하인 포켓몬이 있는지 확인
    if (player1->GetHp() <= 0)
    {
        UpdateConsole(gcnew String(player1->GetPoketmon_Name().c_str()) + "가 쓰러졌습니다! " + gcnew String(player2->GetPoketmon_Name().c_str()) + "의 승리!");
        DisableAllButtons();  // 모든 버튼 비활성화
        CloseGame();          // 게임 종료
    }
    else if (player2->GetHp() <= 0)
    {
        UpdateConsole(gcnew String(player2->GetPoketmon_Name().c_str()) + "가 쓰러졌습니다! " + gcnew String(player1->GetPoketmon_Name().c_str()) + "의 승리!");
        DisableAllButtons();  // 모든 버튼 비활성화
        CloseGame();          // 게임 종료
    }
    else
    {
        // 턴이 끝난 후 다음 턴 준비
        SwitchTurn();
    }
}




// 모든 스킬 버튼 비활성화
void CppCLRWinFormsProject::Form1::DisableAllButtons()
{
    for each (Button ^ button in player1Buttons)
        button->Enabled = false;
    for each (Button ^ button in player2Buttons)
        button->Enabled = false;
}
// 게임 종료 함수
void CppCLRWinFormsProject::Form1::CloseGame()
{
    // 게임 종료 전 메시지 박스 출력
    MessageBox::Show("게임이 종료됩니다.", "게임 종료", MessageBoxButtons::OK, MessageBoxIcon::Information);

    // 폼 종료 (게임 종료)
    this->Close();
}



void CppCLRWinFormsProject::Form1::UpdateHealthBar(ProgressBar^ progressBar, Label^ healthLabel, Poketmon* player)
{
    // 체력 퍼센트 업데이트
    int healthPercentage = static_cast<int>((player->GetHp() / player->GetFull_hp()) * 100);
    progressBar->Value = healthPercentage;

    // 체력 값 업데이트
    healthLabel->Text = "체력: " + healthPercentage.ToString() + "%";
}


void CppCLRWinFormsProject::Form1::SwitchTurn()
{
    player1Turn = !player1Turn;  // 턴을 교체
    EnableCurrentPlayerButtons();  // 현재 턴에 맞는 버튼 활성화
}


void CppCLRWinFormsProject::Form1::EnableCurrentPlayerButtons()
{
    if (player1Turn)
    {
        // 1P의 턴: 1P 스킬 버튼 활성화, 2P 스킬 버튼 비활성화
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
        // 2P의 턴: 2P 스킬 버튼 활성화, 1P 스킬 버튼 비활성화
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
    if (poketmonName == "이상해씨")
        return (Image^)rm->GetObject(L"이상해씨");
    else if (poketmonName == "파이리")
        return (Image^)rm->GetObject(L"파이리");
    else if (poketmonName == "꼬부기")
        return (Image^)rm->GetObject(L"꼬부기");
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
    // UI의 TextBox (consoleOutput) 에 메시지 출력
    consoleOutput->AppendText(message + "\r\n");
}
