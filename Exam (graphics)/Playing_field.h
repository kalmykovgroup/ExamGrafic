#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <string> 
#include <vector> 
#include <thread> 
#include <map> 

#include "Header.h"  
#include "Matrix.h"  
#include "Player.h"  
#include "User.h"  
#include "Bot.h"   

 

namespace Playing_field_box {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	 

	/// <summary>
	/// Сводка для Playing_field
	/// </summary>
	public ref class Playing_field : public System::Windows::Forms::Form
	{

		ref class CoordinateForm {
		public:
			int x, y;
			CoordinateForm(int x, int y) : x{ x }, y{ y } { ; };
		};

	 ref class MapPictureBox {
		private:
			ref class Coordinate {
			public:
				int x, y;
				Coordinate(int x, int y) : x{ x }, y{ y } {};
			};

			int countPictureBox;
			array<PictureBox^>^ pictureBoxArr;
			array<Coordinate^>^ pictureBoxCoordinate;
			array<PictureBox^>^ pictureBoxShashki;

		public:
			MapPictureBox(int countPictureBox) {
				this->pictureBoxArr = gcnew array<PictureBox^>(countPictureBox);
				this->pictureBoxShashki = gcnew array<PictureBox^>(countPictureBox);
				this->pictureBoxCoordinate = gcnew array<Coordinate^>(countPictureBox);
				this->countPictureBox = countPictureBox;
			}

			void setPictureBox(int idx, PictureBox^ pictureBox, int x, int y) {
				if (idx < countPictureBox) {
					pictureBoxArr[idx] = pictureBox;
					pictureBoxCoordinate[idx] = gcnew Coordinate(x, y);
				}
			}

			PictureBox^ operator [](unsigned idx) {
				return pictureBoxArr[idx];
			}

			PictureBox^ getPictureBox(int x, int y) {
				return pictureBoxArr[getId(x, y)];
			}

			void setShashka(int x, int y, PictureBox^ shashka) {
				int id  = getId(x, y);
				this->pictureBoxShashki[id] = shashka;
			}

			PictureBox^ getShashka(int x, int y) {
				int id  = getId(x, y);
				return this->pictureBoxShashki[id];
			}

			int getIdShashka(PictureBox^ shashka) {
				for (int i = 0; i < pictureBoxShashki->Length; i++) {
					if (shashka == pictureBoxShashki[i]) return i;
				} 
			}

			CoordinateForm^ getCoordinateShashka(int id) {
				return gcnew CoordinateForm (pictureBoxCoordinate[id]->x, pictureBoxCoordinate[id]->y);
			}

			void deleteShashka(int x, int y) {
				int id  = getId(x, y);
			   this->pictureBoxShashki[id] = nullptr;
			}

			int getId(int x, int y) {
				for (int i = 0; i < countPictureBox; i++) {
					if (pictureBoxCoordinate[i]->x == x && pictureBoxCoordinate[i]->y == y) {
						return i;
					}
				}
			}
		};

	private: int width, height, countFigures, gameMode;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ToolTip^ toolTip1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::PictureBox^ pictureBox1; 
	private: System::Windows::Forms::Label^ label6;

    
 
  Thread^ gameRunThread = gcnew Thread(gcnew ThreadStart(this, &Playing_field::GameRun));

	public: Playing_field(int width, int height, int countFigures, int gameMode): width{width}, height{ height }, countFigures{countFigures}, gameMode{gameMode}
		{
			InitializeComponent();	 
			InitField(); 	 
			this->userMoveCoordinateStart = new Coordinate();
			this->userMoveCoordinateEnd = new Coordinate();
		 
		}

		  System::Drawing::Color colorFieldWhite = System::Drawing::Color::FromArgb(255, 250, 250);
		  System::Drawing::Color colorFieldBlack = System::Drawing::Color::FromArgb(182, 182, 182);


	protected: 
		~Playing_field(){
			if (components){
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1478, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Playing_field::btnExit);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->panel1->Location = System::Drawing::Point(51, 60);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(981, 981);
			this->panel1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Location = System::Drawing::Point(3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1035, 1044);
			this->panel2->TabIndex = 2;
			// 
			// panel4
			// 
			this->panel4->Location = System::Drawing::Point(3, 60);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(42, 981);
			this->panel4->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(54, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(984, 56);
			this->panel3->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1229, 601);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(228, 148);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Старт";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Playing_field::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1185, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 40);
			this->label1->TabIndex = 6;
			this->label1->Text = L"0";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1053, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 36);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Таймер";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::ForestGreen;
			this->label3->Location = System::Drawing::Point(330, 418);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 58);
			this->label3->TabIndex = 8;
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(1053, 86);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(256, 36);
			this->label4->TabIndex = 9;
			this->label4->Text = L"ход компьютера";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1223, 805);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 36);
			this->label5->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(1223, 859);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 36);
			this->label6->TabIndex = 11;
			// 
			// Playing_field
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1680, 1100);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Playing_field";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Playing_field";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		 

		Matrix* matrix = nullptr;
		Player* player_1 = nullptr; //Ссылка на игрока
		Player* player_2 = nullptr;

		bool startGame = false;
		bool pause = false;
		

	    private: MapPictureBox^ mapPictureBox;

		bool flagUserMove = false;
	
		Coordinate* userMoveCoordinateStart;
		Coordinate* userMoveCoordinateEnd;

	    public: System::Void GameRun() {

			std::vector<Coordinate*> path;
		 		 
					while (startGame) {

					 	this->label4->Text = "Ход черных";

						if (this->pause) { Sleep(100); continue; }
						 
						if (player_1->GetValueType() == typeid(User)) {

							while (true) {	//Нужно отследить ход
								if (!startGame) return; 
								if (!flagUserMove) { Sleep(100); continue; } 
								path.push_back(new Coordinate(*userMoveCoordinateStart));
								path.push_back(new Coordinate(*userMoveCoordinateEnd));
								if (!player_1->move(path)) {
									clearPath(path);
									continue;
								}
								flagUserMove = false;
								break;
								
							}
						
						}
						else {
							player_1->move(path); //Ход компьютера
						}
						
						this->matrix->move(path);  //Передвинуть в системной матрице
						this->AnimateMove(path); //Проанимировать для пользователя
					 
						//Проверка на победу
						if (player_1->isWin()) {
							this->label3->Text = "Player 1 win";
							startGame = false;
							break;
						}

						this->clearPath(path);//Очищаем историю 

						this->label4->Text = "Ход белых"; 
						if (player_2->GetValueType() == typeid(User)) {
							//Нужно отследить ход
							while (true) {	//Нужно отследить ход
								if (!startGame) return;
								if (!flagUserMove) { Sleep(100); continue; }
								path.push_back(new Coordinate(*userMoveCoordinateStart));
								path.push_back(new Coordinate(*userMoveCoordinateEnd));
								if (!player_2->move(path)) { 
									clearPath(path);
									continue;
								} 
								flagUserMove = false;
								break;
								
							}
							
						}
						else player_2->move(path); 

						this->matrix->move(path);  //Передвинуть в системной матрице 
						this->AnimateMove(path); //Проанимировать для пользователя

						//Проверка на победу
						if (player_2->isWin()) {
							this->label3->Text = "Player 2 win";
							startGame = false;
							break;
						}
						clearPath(path); //Очищаем историю
						 
					}
					 
				 

		}

	   private: System::Void AnimateMove(std::vector<Coordinate*>& path) {
 

					//Получаем стартовое поле
					PictureBox^ shashka = this->mapPictureBox->getShashka(path[0]->x, path[0]->y);
					this->mapPictureBox->deleteShashka(path[0]->x, path[0]->y);

					this->mapPictureBox->setShashka(path[path.size() - 1]->x, path[path.size() - 1]->y, shashka);

					int size = path.size();
					//Идем цыклом и перемещаем поле
					for (int i = 0; i < size - 1; i++) {
						PictureBox^ Field = this->mapPictureBox->getPictureBox(path[i]->x, path[i]->y);
						Field->Controls->Clear();

						PictureBox^ FieldSecond = this->mapPictureBox->getPictureBox(path[i + 1]->x, path[i + 1]->y);
						FieldSecond->Controls->Add(shashka);
						this->Update();
						Sleep(200);
					}
 

				}

		private: System::Void clearPath(std::vector<Coordinate*>& path)
		{
			 for (int i = 0; i < path.size(); i++)
			 	delete path[i];
			path.clear();
		}

			   

	private: System::Void btnExit(System::Object^ sender, System::EventArgs^ e) {
 
	    this->startGame = false;
 
		this->Close();
	}
  
		private: System::Void createPlayers() {
			 switch (gameMode)
			 {
			 case 1:{//Игрок - игрок
				 player_1 = new User(this->matrix, PlayerNumber::One);
				 player_2 = new User(this->matrix, PlayerNumber::Two);
				 break;
			 }
			 case 2:{//Игрок - Компьютер
				 this->player_1 = new Bot(this->matrix, PlayerNumber::One);
				 this->player_2 = new User(this->matrix, PlayerNumber::Two);
				 break;
			 }
			 case 3:{//Компьютер - Компьютер
				 this->player_1 = new Bot(this->matrix, PlayerNumber::One);
				 this->player_2 = new Bot(this->matrix, PlayerNumber::Two);
				 break;
			 }
			 default:
				 break;
			 }
		 }
    
		private: System::Void InitField()
		{
			
			this->matrix = new Matrix(this->width, this->height);

			//Важно!!! Расстановка фигур должна быть до добавления игроков, так как bot должен понимать где и сколько его фигур
			this->matrix->setFigures(this->countFigures); //Расставляем фигуры в системе

			this->createPlayers();
			 

			mapPictureBox = gcnew MapPictureBox(this->width * this->height);

			int widthBlock = 65;
			int heightBlock = 65;
			 
			; 
			int k = 0;
			for (int y = 0; y < this->height; y++) {
				for (int x = 0; x < this->width; x++) { 
					mapPictureBox->setPictureBox(k, gcnew System::Windows::Forms::PictureBox(), x, y);
					mapPictureBox[k]->Padding = System::Windows::Forms::Padding(10);
					if (y % 2 == 0)
						if (x % 2 == 0) 
							mapPictureBox[k]->BackColor = colorFieldWhite;
						else 
							mapPictureBox[k]->BackColor = colorFieldBlack;
					
					else 
						if (x % 2 == 0) 
							mapPictureBox[k]->BackColor = colorFieldBlack;
						else 
							mapPictureBox[k]->BackColor = colorFieldWhite;
		

					mapPictureBox[k]->Location = System::Drawing::Point(x * widthBlock, y * heightBlock);
					mapPictureBox[k]->Name = L"pictureBoxMatrix";
					mapPictureBox[k]->Size = System::Drawing::Size(widthBlock, heightBlock);

					mapPictureBox[k]->Click += gcnew System::EventHandler(this, &Playing_field::pictureBoxEnd_Click);

					if (this->matrix->getArray()[y][x] != 0) { 

						//Инициализируем шашку
						PictureBox^ shashka = gcnew System::Windows::Forms::PictureBox();
						shashka->Size = System::Drawing::Size(45, 45);
						shashka->SizeMode = PictureBoxSizeMode::StretchImage;
						shashka->Location = System::Drawing::Point(10, 10); 
						shashka->Click += gcnew System::EventHandler(this, &Playing_field::pictureBoxBegin_Click);
						  
						if (this->matrix->getArray()[y][x] == player_1->getLabel())
							shashka->Image = (Image^) gcnew Bitmap("shashka_black.png");
						else
							shashka->Image = (Image^)  gcnew Bitmap("shashka_white.png");
												 
						mapPictureBox->setShashka(x,y, shashka);
						mapPictureBox[k]->Controls->Add(shashka);		

					}
				 
					this->panel1->Controls->Add(mapPictureBox[k]);
					this->panel1->BringToFront();
					k++;
				}
			}


			  char lyba[] = { "ABCDIFGHIJK" }; 
			  char** arrChar = new char* [9]; 

			for (int i = 0; i < 9; i++) {
				arrChar[i] = new char[2]{lyba[i]}; 
			}

			for (int i = 0; i < 9; i++) {

				System::Windows::Forms::Label^ label;
				label = gcnew System::Windows::Forms::Label();
				label->Location = System::Drawing::Point(25, 20);
				label->Size = System::Drawing::Size(51, 20);
				label->Text = gcnew String(arrChar[i]);
				label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));

				 
				System::Windows::Forms::PictureBox^ pictureBox;
				
				pictureBox = gcnew System::Windows::Forms::PictureBox();
				pictureBox->Location = System::Drawing::Point(i * widthBlock, 0);
				pictureBox->Size = System::Drawing::Size(widthBlock, heightBlock);
				pictureBox->Controls->Add(label);
				this->panel3->Controls->Add(pictureBox);
				this->panel3->BringToFront();

				 
				 System::Windows::Forms::Label^ label2;
				 label2 = gcnew System::Windows::Forms::Label();
				 label2->Location = System::Drawing::Point(5, 25);
				 label2->Size = System::Drawing::Size(51, 20);
				 label2->Text = Convert::ToString(i + 1) + " ";
				 label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				 
				System::Windows::Forms::PictureBox^ pictureBox2;

				pictureBox2 = gcnew System::Windows::Forms::PictureBox();
				pictureBox2->Location = System::Drawing::Point(0, i * heightBlock);				
				pictureBox2->Size = System::Drawing::Size(widthBlock, heightBlock);
				pictureBox2->Controls->Add(label2);
				this->panel4->Controls->Add(pictureBox2);
				this->panel4->BringToFront();
					
			}
			this->Update();

		}


		bool userMoveFromFlag = false; 

		System::Drawing::Color ClickColorOne;
		System::Windows::Forms::PictureBox^ tmpPictureBox;
		PictureBox^ tmpBox;
		//Откуда
	private: System::Void pictureBoxBegin_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::PictureBox^ tmp = safe_cast<PictureBox^>(sender);

		if (userMoveFromFlag) { 
			userMoveFromFlag = false;
			tmpBox->BackColor = ClickColorOne;
			return;
		}

		int id = this->mapPictureBox->getIdShashka(tmp);

		CoordinateForm^ pos = this->mapPictureBox->getCoordinateShashka(id);

		 tmpBox = this->mapPictureBox->getPictureBox(pos->x, pos->y);
		 ClickColorOne = tmpBox->BackColor;
		 tmpBox->BackColor = System::Drawing::Color::FromArgb(136, 245, 123);
		userMoveFromFlag = true;
		this->userMoveCoordinateStart->setData(pos->x, pos->y);
		this->label5->Text = "Откуда: x - " + (this->userMoveCoordinateStart->x + 1) + " | y - " + (this->userMoveCoordinateStart->y + 1);
		
	}

		//Куда
	private: System::Void pictureBoxEnd_Click(System::Object^ sender, System::EventArgs^ e) {

			if (!userMoveFromFlag) { 
				return;
			}
		 
			System::Windows::Forms::PictureBox^ pictureBox = safe_cast<PictureBox^>(sender);
			int x = pictureBox->Location.X / pictureBox->Width;
			int y = pictureBox->Location.Y / pictureBox->Height;

			this->userMoveCoordinateEnd->setData(x, y);

			this->label6->Text = "Куда: x - " + (userMoveCoordinateEnd->x + 1) + " | y - " + (userMoveCoordinateEnd->y + 1);
			tmpBox->BackColor = ClickColorOne;
			this->flagUserMove = true;
			this->userMoveFromFlag = false;
			 	 
	} 
 		
 

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::Button^ btn = safe_cast<Button^>(sender);

	if (!startGame) {

		startGame = true;
		btn->Text = "Пауза";
	
		this->gameRunThread->Start();
		
	}
	else {
		if (!this->pause) {
			this->pause = true;
			btn->Text = "Продолжить";
		}
		else {
			this->pause = false;
			btn->Text = "Пауза";
		}
	}
	
	
}
};


}
