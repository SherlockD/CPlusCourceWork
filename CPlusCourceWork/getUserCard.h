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

	/// <summary>
	/// —водка дл€ getUserCard
	/// </summary>
	public ref class getUserCard : public System::Windows::Forms::Form
	{
	public:
		getUserCard(String^ userLogin)
		{
			InitializeComponent();
			_userLogin = userLogin;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~getUserCard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: String^ _userLogin;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(13, 13);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(611, 472);
			this->listBox1->TabIndex = 0;
			// 
			// getUserCard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 492);
			this->Controls->Add(this->listBox1);
			this->Name = L"getUserCard";
			this->Text = L"getUserCard";
			this->Load += gcnew System::EventHandler(this, &getUserCard::getUserCard_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void getUserCard_Load(System::Object^  sender, System::EventArgs^  e)
	{
		MySqlDataReader^ dataReader = MySqlWork::ExecuteQuery("SELECT * FROM user_card WHERE user_login='" + _userLogin + "'");
		if (dataReader != nullptr) {
			while (dataReader->Read())
			{
				listBox1->Items->Add(dataReader->GetString(1) + " " + dataReader->GetString(2) + " " + dataReader->GetString(3) + " " + dataReader->GetString(4));
			}
		}
	}
	};
}
