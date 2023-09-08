#pragma once
#include "Playing_field.h"

namespace Menu_2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Menu2 : public System::Windows::Forms::Form
	{
	public:
		Menu2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

		}

		int width = 9;
		int height = 9;
		int countFigures = 9;
		int gameMode = 2;
 
		
		 
		 

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Menu2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button3;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(853, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Menu2::button1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(19, 25);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(275, 40);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"9х9 (по 9 шашек)";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &Menu2::radioButton_CheckedGroup1);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(18, 71);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(326, 40);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Text = L"12х12 (по 12 шашек)";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &Menu2::radioButton_CheckedGroup1);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(18, 117);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(326, 40);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->Text = L"15х15 (по 15 шашек)";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Click += gcnew System::EventHandler(this, &Menu2::radioButton_CheckedGroup1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(270, 575);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(442, 46);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Выберите режим игры";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(251, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(467, 46);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Выберите игровое поле";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton4->Location = System::Drawing::Point(25, 32);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(242, 40);
			this->radioButton4->TabIndex = 8;
			this->radioButton4->Text = L"Игрок - Игрок";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Click += gcnew System::EventHandler(this, &Menu2::radioButton_CheckedGroup2);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Checked = true;
			this->radioButton5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton5->Location = System::Drawing::Point(25, 78);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(321, 40);
			this->radioButton5->TabIndex = 9;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Компьютер - Игрок";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->Click += gcnew System::EventHandler(this, &Menu2::radioButton_CheckedGroup2);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton6->Location = System::Drawing::Point(25, 124);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(400, 40);
			this->radioButton6->TabIndex = 10;
			this->radioButton6->Text = L"Компьютер - Компьютер";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->Click += gcnew System::EventHandler(this, &Menu2::radioButton_CheckedGroup2);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(761, 901);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(218, 65);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Начать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Menu2::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Location = System::Drawing::Point(259, 206);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox1->Size = System::Drawing::Size(429, 309);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(18, 229);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(355, 64);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Ввести размеры самому";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->radioButton5);
			this->groupBox2->Controls->Add(this->radioButton6);
			this->groupBox2->Location = System::Drawing::Point(259, 633);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(462, 186);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			// 
			// Menu2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(145)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)));
			this->ClientSize = System::Drawing::Size(1000, 1000);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Menu2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		  
		   private: System::Void radioButton_CheckedGroup1(System::Object^ sender, System::EventArgs^ e)
		   {
			   RadioButton^ radioButton = safe_cast<RadioButton^>(sender);

			   if (radioButton == this->radioButton1) {
				   this->width = 9;
				   this->height = 9;
				   this->countFigures = 9;
			   } 
			   else if (radioButton == this->radioButton2) {
				   this->width = 12;
				   this->height = 12;
				   this->countFigures = 12;
			   }
			   else if (radioButton == this->radioButton3) {
				   this->width = 15;
				   this->height = 15;
				   this->countFigures = 15;
			   }
			   else { //Произвольный размер
				  
			   }
			  
			  
		   }
		   private: System::Void radioButton_CheckedGroup2(System::Object^ sender, System::EventArgs^ e)
		   {
			   RadioButton^ radioButton = safe_cast<RadioButton^>(sender);

			   if (radioButton == this->radioButton4) {
				   this->gameMode = 1;
			   }
			   else if (radioButton == this->radioButton5) {
				   this->gameMode = 2;
			   }
			   else if (radioButton == this->radioButton6) {
				   this->gameMode = 3;
			   }

		   }
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	 
		if (this->width > 0 && this->height > 0 && this->countFigures > 0 ) { //Если выбрано игровое поле
			if (this->gameMode > 0 || true) { //Если выбран режим игры

				Playing_field_box::Playing_field^ frm = gcnew Playing_field_box::Playing_field(this->width, this->height, this->countFigures, this->gameMode);
				this->Hide(); 
				if (frm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					frm->GameRun();
				}
				this->Close();
			}
		}
	}
};
}
