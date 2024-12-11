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
        PictureBox^ pictureBox1;  // 1P ���ϸ� �̹���
        PictureBox^ pictureBox2;  // 2P ���ϸ� �̹���
        Label^ label1PName;       // 1P ���ϸ� �̸�
        Label^ label2PName;       // 2P ���ϸ� �̸�
        ProgressBar^ progressBar1P;  // 1P ü�¹�
        ProgressBar^ progressBar2P;  // 2P ü�¹�
        // �߰��� ��� ������
        int player1SelectedSkill = 0;  // 1P�� ������ ��ų�� ����
        int player2SelectedSkill = 0;  // 2P�� ������ ��ų�� ����
        bool isPlayer1SkillSelected = false;  // 1P�� ��ų�� �����ߴ��� ����
        bool isPlayer2SkillSelected = false;  // 2P�� ��ų�� �����ߴ��� ����
        TextBox^ consoleOutput;   // �ܼ� ��� �ؽ�Ʈ �ڽ�
        cli::array<Button^>^ player1Buttons;
        cli::array<Button^>^ player2Buttons;
        Label^ label1PHealth;  // 1P ü�� ǥ�� ��
        Label^ label2PHealth;  // 2P ü�� ǥ�� ��
        Poketmon* player1;  // 1P ���ϸ� ��ü
        Poketmon* player2;  // 2P ���ϸ� ��ü
        bool player1Turn;
        bool player2Turn;

        Battle* battle;  // ��Ʋ ��ü
        void UpdateHealthBar(ProgressBar^ progressBar, Label^ healthLabel, Poketmon* player);
        void InitializeComponent(void);
        void AddPoketmonElements(String^ player1Poketmon, String^ player2Poketmon, int player1HP, int player2HP);
        void CreateButtons(cli::array<Button^>^% buttons, Poketmon* player, int x, int y);
        void OnSkillButtonClick(System::Object^ sender, System::EventArgs^ e);
        void RunBattle(int player1Skill, int player2Skill); // ��ų �ε����� ���ڷ� ����
        void SwitchTurn();
        void DisableAllButtons();  // ��� ��ư ��Ȱ��ȭ �Լ�
        void CloseGame();          // ���� ���� �Լ�
        void EnableCurrentPlayerButtons();
        void DisableCurrentPlayerButtons();
        Image^ GetPoketmonImage(ResourceManager^ rm, String^ poketmonName);
        void UpdateBattleUI();
    };
}
