#pragma once
#include "Battle.h"
namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Resources;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        void UpdateConsole(System::String^ message);
        Form1(String^ player1Poketmon, String^ player2Poketmon, int player1HP, int player2HP);
        ~Form1();

    private:
        System::ComponentModel::Container^ components;
        PictureBox^ pictureBox1;  // 1P 포켓몬 이미지
        PictureBox^ pictureBox2;  // 2P 포켓몬 이미지
        Label^ label1PName;       // 1P 포켓몬 이름
        Label^ label2PName;       // 2P 포켓몬 이름
        ProgressBar^ progressBar1P;  // 1P 체력바
        ProgressBar^ progressBar2P;  // 2P 체력바
        // 추가할 멤버 변수들
        int player1SelectedSkill = 0;  // 1P가 선택한 스킬을 저장
        int player2SelectedSkill = 0;  // 2P가 선택한 스킬을 저장
        bool isPlayer1SkillSelected = false;  // 1P가 스킬을 선택했는지 여부
        bool isPlayer2SkillSelected = false;  // 2P가 스킬을 선택했는지 여부
        TextBox^ consoleOutput;   // 콘솔 출력 텍스트 박스
        cli::array<Button^>^ player1Buttons;
        cli::array<Button^>^ player2Buttons;
        Label^ label1PHealth;  // 1P 체력 표시 라벨
        Label^ label2PHealth;  // 2P 체력 표시 라벨
        Poketmon* player1;  // 1P 포켓몬 객체
        Poketmon* player2;  // 2P 포켓몬 객체
        bool player1Turn;
        bool player2Turn;

        Battle* battle;  // 배틀 객체
        void UpdateHealthBar(ProgressBar^ progressBar, Label^ healthLabel, Poketmon* player);
        void InitializeComponent(void);
        void AddPoketmonElements(String^ player1Poketmon, String^ player2Poketmon, int player1HP, int player2HP);
        void CreateButtons(cli::array<Button^>^% buttons, Poketmon* player, int x, int y);
        void OnSkillButtonClick(System::Object^ sender, System::EventArgs^ e);
        void RunBattle(int player1Skill, int player2Skill); // 스킬 인덱스를 인자로 받음
        void SwitchTurn();
        void DisableAllButtons();  // 모든 버튼 비활성화 함수
        void CloseGame();          // 게임 종료 함수
        void EnableCurrentPlayerButtons();
        void DisableCurrentPlayerButtons();
        Image^ GetPoketmonImage(ResourceManager^ rm, String^ poketmonName);
        void UpdateBattleUI();
    };
}
