#include "MysqlWork.h"
#pragma once

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySqlWorkNameSpace;
	using namespace MySql::Data;

	/// <summary>
	/// Сводка для record_on_analyze
	/// </summary>
	public ref class record_on_analyze : public System::Windows::Forms::Form
	{
	public:
		record_on_analyze(String^ login)
		{
			InitializeComponent();
			userLogin = login;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~record_on_analyze()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Button^  button1;
	private: String^ userLogin;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(22, 25);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(348, 199);
			this->listBox1->TabIndex = 0;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(22, 248);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(348, 20);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(67, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Записаться";
			this->button1->UseCompatibleTextRendering = true;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &record_on_analyze::button1_Click);
			// 
			// record_on_analyze
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 320);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->listBox1);
			this->Name = L"record_on_analyze";
			this->Text = L"record_on_analyze";
			this->Load += gcnew System::EventHandler(this, &record_on_analyze::record_on_analyze_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		String^ getTimeStamp(DateTime date)
		{
			return date.ToString("yyyy-MM-dd");
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox1->SelectedItem != "") 
		{
			String^ querry = "INSERT INTO  analyzes(login,type,date) VALUES('" + userLogin + "','" + listBox1->SelectedItem + "','" + getTimeStamp(dateTimePicker1->Value) + "')";
			MySqlWork::ExecuteQuery(querry);
			//MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery("SELECT kabinet FROM analyze_type WHERE type = '"+listBox1->SelectedItem+"'");
		}
	}
	private: System::Void record_on_analyze_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery("SELECT type FROM analyze_type");
		while (dataReader->Read()) 
		{
			listBox1->Items->Add(dataReader->GetString(0));
		}
	}
};
}
