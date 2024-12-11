#pragma once
#include "Rule.h"
#include "MyForm.h"
#include "MyForm2.h"
#include "Poketmon.h"
#include <list>
#include <string>
#include <format>
#include <vector>
#include <vcclr.h>
#include "MyForm1.h"
namespace Project2 {

	using namespace Project2;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// MyForm2�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{

	private:
		Generic::List<Poketmon^>^ poketList;
		Poketmon^ selectedPoketmon1;
		Poketmon^ selectedPoketmon2;
		Poketmon^ selectedPoketmon3;
	//�Էµ� ���� ������ label�� ������ ����
	//�� ���������� ���õ� ���ڸ� ȭ�鿡 �����
	public:
		MyForm2(Poketmon^ selectedPoketmon1, Poketmon^ selectedPoketmon2, Poketmon^ selectedPoketmon3)
		{
			InitializeComponent();
			this->selectedPoketmon1 = selectedPoketmon1;
			this->selectedPoketmon2 = selectedPoketmon2;
			this->selectedPoketmon3 = selectedPoketmon3;
			if (String::IsNullOrEmpty(this->label1->Text)) {
				this->label1->Visible-=false;
			}
			if (String::IsNullOrEmpty(this->label2->Text)) {
				this->label2->Visible = false;
			}
			if (String::IsNullOrEmpty(this->label3->Text)) {
				this->label3->Visible = false;
			}
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(128, 172);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(307, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(526, 172);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 504);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
