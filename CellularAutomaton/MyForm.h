#pragma once
#include <cmath>
#include "LifeSquare.h"



namespace CellularAutomaton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace MyCell;
	using namespace System::Data::SqlClient;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  DrawCubPanel;
	private: array<LifeSquare^, 2>^ cell;
	private: int myLifeDim = 10;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  button5;

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
			this->DrawCubPanel = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(331, 486);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// DrawCubPanel
			// 
			this->DrawCubPanel->BackColor = System::Drawing::SystemColors::Control;
			this->DrawCubPanel->Location = System::Drawing::Point(28, 36);
			this->DrawCubPanel->Name = L"DrawCubPanel";
			this->DrawCubPanel->Size = System::Drawing::Size(420, 420);
			this->DrawCubPanel->TabIndex = 1;
			this->DrawCubPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::DrawCubPanel_MouseClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(28, 486);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 39);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Create Field";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(185, 486);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(113, 40);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(270, 533);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(99, 35);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Save";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(494, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 20);
			this->label1->TabIndex = 5;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(123, 533);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 35);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Load";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(784, 580);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->DrawCubPanel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Name = L"MyForm";
			this->Text = L"Cellar Automation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}



		void InitMyCellArray()
		{

			cell = gcnew array<LifeSquare^, 2>(myLifeDim, myLifeDim);
			for (int i = 0; i < myLifeDim; i++)
				for (int j = 0; j < myLifeDim; j++)
					cell[i, j] = gcnew LifeSquare(i, j);

			for (int i = 0; i < myLifeDim; i++)
			{
				for (int j = 0; j < myLifeDim; j++)
				{
					if (i == 0)
					{
						cell[i, j]->neibors[0] = cell[myLifeDim - 1, j];
						cell[i, j]->neibors[4] = cell[i + 1, j];
						if (j == 0)
						{
							cell[i, j]->neibors[1] = cell[myLifeDim - 1, j + 1];
							cell[i, j]->neibors[2] = cell[i, j + 1];
							cell[i, j]->neibors[3] = cell[i + 1, j + 1];
							cell[i, j]->neibors[5] = cell[i + 1, myLifeDim - 1];
							cell[i, j]->neibors[6] = cell[i, myLifeDim - 1];
							cell[i, j]->neibors[7] = cell[myLifeDim - 1, myLifeDim - 1];
						}
						else if (j == myLifeDim - 1)
						{
							cell[i, j]->neibors[1] = cell[myLifeDim - 1, 0];
							cell[i, j]->neibors[2] = cell[i, 0];
							cell[i, j]->neibors[3] = cell[i + 1, 0];
							cell[i, j]->neibors[5] = cell[i + 1, j - 1];
							cell[i, j]->neibors[6] = cell[i, j - 1];
							cell[i, j]->neibors[7] = cell[myLifeDim - 1, j - 1];
						}
						else
						{
							cell[i, j]->neibors[1] = cell[myLifeDim - 1, j + 1];
							cell[i, j]->neibors[2] = cell[i, j + 1];
							cell[i, j]->neibors[3] = cell[i + 1, j + 1];
							cell[i, j]->neibors[5] = cell[i + 1, j - 1];
							cell[i, j]->neibors[6] = cell[i, j - 1];
							cell[i, j]->neibors[7] = cell[myLifeDim - 1, j - 1];
						}
					}
					else if (i == myLifeDim - 1)
					{
						cell[i, j]->neibors[0] = cell[i - 1, j];
						cell[i, j]->neibors[4] = cell[0, j];
						if (j == 0)
						{
							cell[i, j]->neibors[1] = cell[i - 1, j + 1];
							cell[i, j]->neibors[2] = cell[i, j + 1];
							cell[i, j]->neibors[3] = cell[0, j + 1];
							cell[i, j]->neibors[5] = cell[0, myLifeDim - 1];
							cell[i, j]->neibors[6] = cell[i, myLifeDim - 1];
							cell[i, j]->neibors[7] = cell[i - 1, myLifeDim - 1];
						}
						else if (j == myLifeDim - 1)
						{
							cell[i, j]->neibors[1] = cell[i - 1, 0];
							cell[i, j]->neibors[2] = cell[i, 0];
							cell[i, j]->neibors[3] = cell[0, 0];
							cell[i, j]->neibors[5] = cell[0, j - 1];
							cell[i, j]->neibors[6] = cell[i, j - 1];
							cell[i, j]->neibors[7] = cell[i - 1, j - 1];
						}
						else
						{
							cell[i, j]->neibors[1] = cell[i - 1, j + 1];
							cell[i, j]->neibors[2] = cell[i, j + 1];
							cell[i, j]->neibors[3] = cell[0, j + 1];
							cell[i, j]->neibors[5] = cell[0, j - 1];
							cell[i, j]->neibors[6] = cell[i, j - 1];
							cell[i, j]->neibors[7] = cell[i - 1, j - 1];
						}
					}
					else if (j == 0)
					{
						cell[i, j]->neibors[0] = cell[i - 1, j];
						cell[i, j]->neibors[1] = cell[i - 1, j + 1];
						cell[i, j]->neibors[2] = cell[i, j + 1];
						cell[i, j]->neibors[3] = cell[i + 1, j + 1];
						cell[i, j]->neibors[4] = cell[i + 1, j];
						cell[i, j]->neibors[5] = cell[i + 1, myLifeDim - 1];
						cell[i, j]->neibors[6] = cell[i, myLifeDim - 1];
						cell[i, j]->neibors[7] = cell[i - 1, myLifeDim - 1];
					}
					else if (j == myLifeDim - 1)
					{
						cell[i, j]->neibors[0] = cell[i - 1, j];
						cell[i, j]->neibors[1] = cell[i - 1, 0];
						cell[i, j]->neibors[2] = cell[i, 0];
						cell[i, j]->neibors[3] = cell[i + 1, 0];
						cell[i, j]->neibors[4] = cell[i + 1, j];
						cell[i, j]->neibors[5] = cell[i + 1, j - 1];
						cell[i, j]->neibors[6] = cell[i, j - 1];
						cell[i, j]->neibors[7] = cell[i - 1, j - 1];
					}
					else
					{
						cell[i, j]->neibors[0] = cell[i - 1, j];
						cell[i, j]->neibors[1] = cell[i - 1, j + 1];
						cell[i, j]->neibors[2] = cell[i, j + 1];
						cell[i, j]->neibors[3] = cell[i + 1, j + 1];
						cell[i, j]->neibors[4] = cell[i + 1, j];
						cell[i, j]->neibors[5] = cell[i + 1, j - 1];
						cell[i, j]->neibors[6] = cell[i, j - 1];
						cell[i, j]->neibors[7] = cell[i - 1, j - 1];
					}
				}

			}

			/*cell[2, 3]->curState = true;
			cell[3, 4]->curState = true;
			cell[4, 2]->curState = true;
			cell[4, 3]->curState = true;
			cell[4, 4]->curState = true;*/
		}

		void InitStartPosition()
		{


			Graphics^ g = this->DrawCubPanel->CreateGraphics();
			SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
			Pen^ p = gcnew Pen(Color::Black);


			int myWidth, myHeight;
			float myWidthf, myHeightf;
			modf(float(((this->DrawCubPanel->Width) - 1) / myLifeDim), &myWidthf);
			modf(float(((this->DrawCubPanel->Height) - 1) / myLifeDim), &myHeightf);
			myHeight = myHeightf;
			myWidth = myWidthf;

			int county = 0;

			for (int y = 1; y < this->DrawCubPanel->Height - 1; y += myHeight)
			{
				int countx = 0;
				for (int x = 1; x < this->DrawCubPanel->Width - 1; x += myWidth)
				{
					cell[county, countx]->rec->X = x;
					cell[county, countx]->rec->Y = y;
					cell[county, countx]->rec->Width = myWidth;
					cell[county, countx]->rec->Height = myHeight;

					/*cell[county, countx]->drawBorder(DrawCubPanel);*/
					g->DrawRectangle(p, cell[county, countx]->rec->X,
						cell[county, countx]->rec->Y,
						cell[county, countx]->rec->Width,
						cell[county, countx]->rec->Height);
					/*g->DrawRectangle(p, x, y, myWidth, myHeight);*/

					//вставить код, который раскрашивает клетки от текущей позиции
					//это и есть метод
					/*if (cell[county, countx]->curState)
						g->FillRectangle(blackBrush, Rectangle(x + 1, y + 1, myWidth - 1, myHeight - 1));*/

					if ((countx++) == (myLifeDim - 1)) break;
				}
				if ((county++) == (myLifeDim - 1)) break;
			}

		}

		void brushRectangles()
		{
			Graphics^ g = this->DrawCubPanel->CreateGraphics();
			SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
			SolidBrush^ whiteBrush = gcnew SolidBrush(Color::White);

			for (int i = 0; i < myLifeDim; i++)
			{
				for (int j = 0; j < myLifeDim; j++)
				{
					if (cell[i, j]->curState)
						g->FillRectangle(blackBrush, Rectangle(cell[i, j]->rec->X + 1, cell[i, j]->rec->Y + 1,
							cell[i, j]->rec->Width - 1, cell[i, j]->rec->Height - 1));
					else
						g->FillRectangle(whiteBrush, Rectangle(cell[i, j]->rec->X + 1, cell[i, j]->rec->Y + 1,
							cell[i, j]->rec->Width - 1, cell[i, j]->rec->Height - 1));
				}
			}

			delete blackBrush, whiteBrush, g;
		}

		void countCurState()
		{
			for (int i = 0; i < myLifeDim; i++)
				for (int j = 0; j < myLifeDim; j++)
					cell[i, j]->recount();

			for (int i = 0; i < myLifeDim; i++)
			{
				for (int j = 0; j < myLifeDim; j++)
				{
					if (cell[i, j]->isGoingToLive())
						cell[i, j]->curState = true;
				}

			}

		}

#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Start();

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		InitStartPosition();//тут рисует
	}

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		SqlConnection^ myConn = gcnew SqlConnection("Data Source=DESKTOP-ICHGA08\\SQLEXPRESS;Integrated Security=False;User ID=sa;Password=1234509876;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False");
		myConn->Open();
		SqlCommand^ myCommand = gcnew SqlCommand("use CellularAutomation", myConn);
		myCommand->ExecuteNonQuery();
		myCommand->CommandText = "select * from CellInfo";
		SqlDataReader^ myReader = myCommand->ExecuteReader();
		int X_int, Y_int;
		while (myReader->Read())
		{
			X_int = Convert::ToInt64(myReader["X"]->ToString());
			Y_int = Convert::ToInt64(myReader["Y"]->ToString());
			Convert::ToInt64(myReader["stat"]->ToString()) == 1 ? cell[X_int, Y_int]->curState = true : cell[X_int, Y_int]->curState = false;	
		}
		InitStartPosition();
		brushRectangles();


	}



	private: System::Void DrawCubPanel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		System::Drawing::Point pt = System::Windows::Forms::Cursor::Position;	//относительно экрана
		System::Drawing::Point newPt;
		newPt = DrawCubPanel->PointToClient(pt);	//относительно клиенткой области

		bool flag = false;

		//здесь нужно определить, какой именно квадрат
		for (int i = 0; i < myLifeDim; i++)
		{
			if (cell[i, 0]->rec->Y < newPt.Y &&
				(cell[i, 0]->rec->Y + cell[i, 0]->rec->Height) > newPt.Y)
			{
				for (int j = 0; j < myLifeDim; j++)
				{
					if (cell[i, j]->rec->X < newPt.X &&
						(cell[i, j]->rec->X + cell[i, 0]->rec->Width) > newPt.X)
					{
						if (cell[i, j]->curState)
							cell[i, j]->curState = false;	//можно добавить проверку, закрашен ли
						else
							cell[i, j]->curState = true;
						flag = true;
					}
				}
			}
			if (flag)
				break;
		}
		brushRectangles();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		countCurState();
		brushRectangles();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Stop();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ path = Directory::GetCurrentDirectory();
		String^ target = "CellularAutomation.mdf";
		SqlConnection^ myConn = gcnew SqlConnection("Data Source=DESKTOP-ICHGA08\\SQLEXPRESS;Integrated Security=False;User ID=sa;Password=1234509876;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False");
		myConn->Open();
		SqlCommand^ myCommand = gcnew SqlCommand();
		myCommand->Connection = myConn;


		if (!File::Exists(target))
		{

			String^ filename = "FILENAME = '" + path + "\\CellularAutomation.mdf" + "', ";
			String^ filename_log = "FILENAME = '" + path + "\\CellularAutomation.ldf" + "', ";


			try
			{
				myCommand->CommandText = "CREATE DATABASE CellularAutomation ON PRIMARY " +
					"(NAME = CellularAutomation_data, " +
					filename +
					"SIZE = 2MB, MAXSIZE = 10MB, FILEGROWTH = 10%) " +
					"LOG ON (NAME = CellularAutomation_Log, " +
					filename_log +
					"SIZE = 1MB, " +
					"MAXSIZE = 5MB, " +
					"FILEGROWTH = 10%)";
				myCommand->ExecuteNonQuery();
				label1->Text = "DataBase is Created Successfully";

				myCommand->CommandText = "use CellularAutomation";
				myCommand->ExecuteNonQuery();
				myCommand->CommandText = "create table CellInfo (X int,  Y int, stat tinyint)";
				myCommand->ExecuteNonQuery();
			}
			catch (Exception^ msg)
			{
				label1->Text = msg->ToString();
				if (myConn->State == ConnectionState::Open)
				{
					myConn->Close();
				}
				return;
			}
		}
		
		try
		{
			myCommand->CommandText = "use CellularAutomation";
			myCommand->ExecuteNonQuery();
			myCommand->CommandText = "TRUNCATE TABLE CellInfo";
			myCommand->ExecuteNonQuery();
		}
		catch (Exception^ msg)
		{
			label1->Text = msg->ToString();
			if (myConn->State == ConnectionState::Open)
			{
				myConn->Close();
			}
			return;
		}

		try
		{
			myCommand->CommandText = "use CellularAutomation";
			myCommand->ExecuteNonQuery();

			for (int i = 0; i < myLifeDim; i++)
			{
				for (int j = 0; j < myLifeDim; j++)
				{
					myCommand->CommandText = "INSERT INTO CellInfo values (" + i.ToString() + "," + j.ToString() + "," +
						(cell[i, j]->curState ? 1 : 0).ToString() + ")";
					myCommand->ExecuteNonQuery();
				}
			}
		}
		catch (Exception^ msg)
		{
			label1->Text = msg->ToString();
			
		}
		if (myConn->State == ConnectionState::Open)
		{
			myConn->Close();
		}
	}

	};


}


