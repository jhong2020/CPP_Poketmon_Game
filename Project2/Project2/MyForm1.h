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
using namespace std;
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
	/// MyForm1에 대한 요약입니다.
	/// </summary>
	public ref class MyForm1 : public Form
	{
	private:
		Generic::List<Poketmon^>^ poketList;
		Poketmon^ selectedPoketmon1;
		Poketmon^ selectedPoketmon2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
		   Poketmon^ selectedPoketmon3;
	//랜덤으로 나올 값을 선언함
	public:
		MyForm1(void)
		{
			InitializeComponent();
			poketList = gcnew Generic::List<Poketmon^>();
			poketList->Add(gcnew Poketmon(L"Squirtle.jpg", "L꼬부기", L"물", 40,40,40,40));
			poketList->Add(gcnew Poketmon(L"Charmander.jpg", L"파이리", L"불", 30, 40, 20, 30));
			poketList->Add(gcnew Poketmon(L"bulbasaur.jgp",L"이상해씨", L"풀", 40, 40, 10, 10));
			//std::vector<Poketmon1> PoketList;
			//PoketList.emplace_back("이름", "꼬부기", "물", 40, 40, 10, 10, 5);
			//PoketList.emplace_back("이름", "파이리", "불", 40, 40, 10, 10, 5);
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;






	
	private:int playerCount = 0;


	private: System::Drawing::Image^ defaultImage;
	private: System::Drawing::Image^ hoverImage;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;



	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(800, 746);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 79);
			this->button1->TabIndex = 3;
			this->button1->Text = L"선택완료";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Location = System::Drawing::Point(29, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(1660, 900);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			// 
			// btn1
			// 
			this->btn1->BackColor = System::Drawing::Color::Transparent;
			this->btn1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1.BackgroundImage")));
			this->btn1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn1->Location = System::Drawing::Point(400, 310);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(200, 200);
			this->btn1->TabIndex = 11;
			this->btn1->UseVisualStyleBackColor = false;
			this->btn1->Click += gcnew System::EventHandler(this, &MyForm1::btn1_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(800, 310);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 200);
			this->button2->TabIndex = 12;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(1200, 310);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 200);
			this->button3->TabIndex = 13;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(400, 76);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(181, 177);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(800, 76);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(181, 177);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(1200, 76);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(181, 177);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 16;
			this->pictureBox3->TabStop = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1582, 853);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox4);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
		void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		}
#pragma endregion
	private: System::Void btn1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (playerCount < 2) {
			
			selectedPoketmon1 = poketList[0];
			playerCount++;
			
			pictureBox1->Image = Image::FromFile(selectedPoketmon1->GetImage());
		}
		else {
			MessageBox::Show(L"더 이상 선택할 수 없습니다.");
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (playerCount < 2) {
		
		selectedPoketmon2 =  (poketList)[1];
		
		playerCount++;
		pictureBox2->Image = Image::FromFile(selectedPoketmon2->GetImage());
	}
	else {
		MessageBox::Show(L"더 이상 선택할 수 없습니다.");
	}

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (playerCount < 2) {
		
		selectedPoketmon3 = (poketList)[2];
		playerCount++;
		
		pictureBox3->Image = Image::FromFile(selectedPoketmon3->GetImage());
	}
	else {
		MessageBox::Show(L"더 이상 선택할 수 없습니다.");
		}

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (playerCount < 2) {
			   MessageBox::Show(L"선택이 완료되지 않았습니다.");
	}
	else {
		MyForm2^ form = gcnew MyForm2(selectedPoketmon1, selectedPoketmon2, selectedPoketmon3);
		form->Show();
		this->Close();
		  }
	   }
	};
}
