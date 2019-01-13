#include "MysqlWork.h"
#include "record_on_analyze.h"
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
	/// Сводка для add_user_card
	/// </summary>
	public ref class add_user_card : public System::Windows::Forms::Form
	{
	public:
		add_user_card(void)
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
		~add_user_card()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: record_on_analyze^ new_analyze_record;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Больной";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(16, 29);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(203, 147);
			this->listBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 183);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Диагноз";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 210);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(203, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 246);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Запись";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(16, 262);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(465, 130);
			this->textBox2->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 418);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 41);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить анализ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &add_user_card::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 484);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(465, 47);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Записать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &add_user_card::button2_Click);
			// 
			// add_user_card
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 558);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Name = L"add_user_card";
			this->Text = L"add_user_card";
			this->Load += gcnew System::EventHandler(this, &add_user_card::add_user_card_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		String^ getTimeStamp(DateTime date)
		{
			return date.ToString("yyyy-MM-dd");
		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox1->SelectedItem != "",textBox1->Text!="",textBox2->Text!="") 
		{
			String^ query = query->Format("INSERT INTO user_card(user_login,diagnosis,prescription,data) VALUES('{0}','{1}','{2}',Now())", listBox1->SelectedItem->ToString(), textBox1->Text, textBox2->Text->ToString());
			MySqlWork::ExecuteQuery(query);
			MessageBox::Show("Запись добавлена");
			this->Close();
		}
	}
private: System::Void add_user_card_Load(System::Object^  sender, System::EventArgs^  e) 
{
	MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery("SELECT user_login FROM users WHERE user_role = 'user'");
	while (dataReader->Read()) 
	{
		listBox1->Items->Add(dataReader->GetString(0));
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (listBox1->SelectedItem) 
	{
		new_analyze_record = gcnew record_on_analyze(listBox1->SelectedItem->ToString());
		new_analyze_record->Show();
	}
}
};
}
