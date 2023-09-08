#pragma once
#include "Menu_2.h";
namespace Menu_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Menu_1_Form
	/// </summary>
	public ref class Menu1 : public System::Windows::Forms::Form
	{
	public:
		Menu1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Menu1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_start;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
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
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->AutoSize = true;
			this->btn_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_start->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->btn_start->FlatAppearance->BorderSize = 2;
			this->btn_start->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->btn_start->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->btn_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_start->Location = System::Drawing::Point(400, 343);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(200, 66);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Начать";
			this->btn_start->UseVisualStyleBackColor = true;
			this->btn_start->Click += gcnew System::EventHandler(this, &Menu1::funStart);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(194, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(623, 58);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Добро пожаловать в игру\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(388, 205);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(222, 69);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Уголки";
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(853, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Menu1::funClose);
			// 
			// Menu1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(145)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)));
			this->ClientSize = System::Drawing::Size(1000, 700);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_start);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Menu1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu_1_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void funStart(System::Object^ sender, System::EventArgs^ e) {
		 
		 
		  Menu_2::Menu2^ frm = gcnew Menu_2::Menu2;
		  this->Hide();
		  if (frm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			 
		  }
		  this->Close();
		  
	}
	private: System::Void funClose(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
