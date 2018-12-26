#pragma once
#include "record.h"
#include "MyRecords.h"

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace MySql::Data::MySqlClient;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: String^ connectionInfo = "datasource=localhost;port=3306;username=root;password=admin;database=cpluscource";

	private: String^ userLogin;
	private: bool isLogin = false;
	private: record^ newRecord;
	private: MyRecords^ newMyRecords;

	private: String^ userRole;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::IO::FileSystemWatcher^  fileSystemWatcher1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(203, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(336, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(216, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите логин администратора и пароль";
			this->label1->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(339, 61);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(213, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"login";
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(339, 87);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(213, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"password";
			this->textBox2->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(339, 113);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(213, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Войти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(34, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 48);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Записаться на прием";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(339, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 6;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(34, 161);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(200, 49);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Мои записи";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(34, 227);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(200, 44);
			this->button5->TabIndex = 8;
			this->button5->Text = L"(Админ) Добавить врача";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(440, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(339, 61);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(213, 20);
			this->textBox3->TabIndex = 10;
			this->textBox3->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(339, 87);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(213, 20);
			this->textBox4->TabIndex = 11;
			this->textBox4->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(339, 34);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(171, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Введите имя врача и должность";
			this->label4->Visible = false;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(339, 114);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(213, 23);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Добавить";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 292);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"Запись на прием";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void ShowSimpleUsersForms() 
		{
			button3->Show();
			button4->Show();
		}

		void HideSimpleUsersForms() 
		{
			button3->Hide();
			button4->Hide();
		}

		bool loginInto(String^ login,String^ pass) 
		{
			String^ query = "SELECT * FROM users WHERE user_login = '" + login + "'";
			MySqlDataReader^ dataReader = ExecuteQuery(query);
			if (dataReader != nullptr) 
			{
				dataReader->Read();
				if (login == dataReader->GetString(1) && pass == dataReader->GetString(2))
				{
					label3->Text = "Добро пожаловать:" + login;
					userLogin = login;
					userRole = dataReader->GetString(3);

					return true;
				}
			}
			else 
			{
				label2->Text = "Неверный логин или пароль";
			}
			return false;
		}

		void addDoctor(String^ fio, String^ profession) 
		{
			String^ query = "INSERT INTO doctors(doctor_fio,doctor_profession) VALUES('" + fio + "','" + profession + "')";
			MySqlDataReader^ dataReader = ExecuteQuery(query);
			MessageBox::Show("Доктор успешно добавлен");
		}

		MySqlDataReader^ ExecuteQuery(String^ query)
		{
			MySqlConnection^ connection = gcnew MySqlConnection(connectionInfo);
			MySqlCommand^ connectionCmd = gcnew MySqlCommand(query,connection);
			MySqlDataReader^ dataReader;

			try 
			{
				connection->Open();
				dataReader = connectionCmd->ExecuteReader();
				
				if (dataReader->HasRows) 
				{
					return dataReader;
				}
				else 
				{
					return nullptr;
				}
				
				dataReader->Close();
			}
			catch (Exception^ex) 
			{
				MessageBox::Show(ex->Message);
			}
		}

#pragma endregion
	private: void HideLoginForm() 
	{
		label1->Hide();
		label2->Hide();
		textBox1->Hide();
		textBox2->Hide();
		button2->Hide();

		label2->Text = "";
		textBox2->Text = "";
	}
	private: void ShowLoginForm() 
	{
		label1->Show();
		label2->Show();
		textBox1->Show();
		textBox2->Show();
		button2->Show();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (isLogin) 
		{
			isLogin = false;
			userRole = "";
			label3->Text = "";
			HideSimpleUsersForms();
			button5->Hide();
			ShowLoginForm();
		}
		else 
		{
			ShowLoginForm();
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ login = textBox1->Text->ToString();
		String^ password = textBox2->Text->ToString();
		if (loginInto(login, password)) 
		{
			isLogin = true;
			HideLoginForm();
			ShowSimpleUsersForms();
			if (userRole == "admin") 
			{
				button5->Show();
			}
			button1->Text = "Выйти";
		}
		else 
		{
			label2->Text = "Неверный логин или пароль";
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (textBox3->Text != "" && textBox4->Text != "") 
		{
			addDoctor(textBox3->Text, textBox4->Text);
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		newRecord = gcnew record();
		newRecord->login = userLogin;
		newRecord->Show();
	}

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		label4->Show();
		textBox3->Show();
		textBox4->Show();
		button6->Show();
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
	newMyRecords = gcnew MyRecords(userLogin);
	newMyRecords->Show();
}
};
}
