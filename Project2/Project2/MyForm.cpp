#include "MyForm.h"
#include "Poket.h"
#include "Rule.h";
#include "MyForm1.h"
#include "MyForm2.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace Project2;
[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(% form);
}