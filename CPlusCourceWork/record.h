#pragma once
#include <stdio.h>
#include <ctime>
#include <vector>
#include <string>
#include <msclr\marshal_cppstd.h>

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	/// <summary>
	/// Сводка для record
	/// </summary>
	public ref class record : public System::Windows::Forms::Form
	{
	public:
		record(void)
		{
			InitializeComponent();	
			//mainForm = mainClass;
			MySqlDataReader^ dataReader = ExecuteQuery("SELECT profession FROM professions");
			while (dataReader->Read()) 
			{
				listBox3->Items->Add(dataReader->GetString(0));
			}
		}
	public:String^ login;
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~record()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ connectionInfo = "datasource=localhost;port=3306;username=root;password=admin;database=cpluscource";
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;

	private: String^ choosenTime;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::Label^  label5;


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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(31, 82);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 0;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(31, 39);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &record::dateTimePicker1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выберите день";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Выберите время";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(31, 316);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(200, 95);
			this->listBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 300);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Выберите врача";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 417);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 35);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Записаться";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &record::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 304);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 7;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(31, 200);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(152, 95);
			this->listBox3->TabIndex = 8;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &record::listBox3_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(31, 184);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Должность врача";
			// 
			// record
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(476, 498);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->listBox1);
			this->Name = L"record";
			this->Text = L"record";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ getTimeStamp(DateTime date) 
		{
			return date.ToString("yyyy-MM-dd");
		}

		MySqlDataReader^ ExecuteQuery(String^ query)
		{
			MySqlConnection^ connection = gcnew MySqlConnection(connectionInfo);
			MySqlCommand^ connectionCmd = gcnew MySqlCommand(query, connection);
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

	private: bool VectorExist(const std::vector<std::string> vec,std::string exist) 
	{
		for (const auto element : vec) 
		{
			if (exist == element) {
				return true;
			}
		}
		return false;
	}
	
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{	
		listBox1->Items->Clear();
		std::vector<std::string> blockTimes;
		msclr::interop::marshal_context context;
		if (dateTimePicker1->Value > DateTime::Now) 
		{
			choosenTime = dateTimePicker1->Value.ToShortDateString();
			MySqlDataReader^ dataReader = ExecuteQuery("SELECT record_time FROM records WHERE record_date = '"+ getTimeStamp(dateTimePicker1->Value) +"'");
			if (dataReader != nullptr) {
				while (dataReader->Read())
				{
					blockTimes.push_back(context.marshal_as<std::string>(dataReader->GetString(0)));
				}			
			}	
			for (int i = 6; i < 20; i++)
			{
				if (!VectorExist(blockTimes, context.marshal_as<std::string>(i + ":00")))
				{
					listBox1->Items->Add(i + ":00");
				}
				if (!VectorExist(blockTimes, context.marshal_as<std::string>(i + ":30")))
				{
					listBox1->Items->Add(i + ":30");
				}
			}
		}
		else 
		{
			MessageBox::Show("Нельзя выбрать день позже завтрашнего");
		}
	}
private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	listBox2->Items->Clear();
	MySqlDataReader^ dataReader = ExecuteQuery("SELECT doctor_fio from doctors WHERE doctor_profession='"+listBox3->SelectedItem+"'");
	while (dataReader->Read())
	{
		listBox2->Items->Add(dataReader->GetString(0));
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (listBox2->SelectedItem!="" || getTimeStamp(dateTimePicker1->Value)!= "" || listBox1->SelectedItem!="") 
	{
		ExecuteQuery("INSERT INTO records(user,doctor_name,record_date,record_time) VALUES('" +login + "','" + listBox2->SelectedItem + "','" + getTimeStamp(dateTimePicker1->Value) + "','" + listBox1->SelectedItem + "')");
		listBox1->ClearSelected();
		MessageBox::Show("Вы успешно записались на прием");
		this->Close();
	}
}
};
}
