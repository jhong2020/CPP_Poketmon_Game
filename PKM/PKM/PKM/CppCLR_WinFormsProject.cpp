#include "pch.h"
#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    String^ player1Poketmon = "���̸�";
    String^ player2Poketmon = "���α�";
    int player1HP = 100;
    int player2HP = 100;

    Application::Run(gcnew CppCLRWinFormsProject::Form1(player1Poketmon, player2Poketmon, player1HP, player2HP));
    return 0;
}
