#pragma once
#include "MySqlWork.h"

namespace CPlusCourceWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySqlWorkNameSpace;

	/// <summary>
	/// Сводка для AddProfession
	/// </summary>
	public ref class AddProfession : public System::Windows::Forms::Form
	{
	public:
		AddProfession(void)
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
		~AddProfession()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите название должности";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(227, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddProfession::button1_Click);
			// 
			// AddProfession
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(447, 92);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddProfession";
			this->Text = L"AddProfession";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (textBox1->Text != "") 
		{
			MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery("INSERT INTO professions(profession) VALUES('" + textBox1->Text + "')");
			MessageBox::Show("Профессия успешно добавлена");
			this->Close();
		}
		else 
		{
			MessageBox::Show("Поле не должно быть пустым");
		}
	}
	};
}
