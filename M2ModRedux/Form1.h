#pragma once

#define M2Filter L"M2 Files|*.m2|All Files|*.*"
#define M2IFilter L"M2I Files|*.m2i|All Files|*.*"

namespace M2ModRedux {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxInputM2;
	protected: 

	private: System::Windows::Forms::Button^  buttonInputM2Browse;
	private: System::Windows::Forms::Button^  buttonOutputM2Browse;
	private: System::Windows::Forms::TextBox^  textBoxOutputM2;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonInputM2IBrowse;
	private: System::Windows::Forms::TextBox^  textBoxInputM2I;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  buttonGo;




	private: System::Windows::Forms::Button^  buttonOutputM2IBrowse;
	private: System::Windows::Forms::TextBox^  textBoxOutputM2I;






	private: System::Windows::Forms::Label^  label7;






	private: System::Windows::Forms::CheckBox^  checkBoxMergeBones;
	private: System::Windows::Forms::CheckBox^  checkBoxMergeAttachments;
	private: System::Windows::Forms::CheckBox^  checkBoxMergeCameras;




	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;


	private: System::Windows::Forms::ToolTip^  toolTip1;


	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxInputM2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonInputM2Browse = (gcnew System::Windows::Forms::Button());
			this->buttonOutputM2Browse = (gcnew System::Windows::Forms::Button());
			this->textBoxOutputM2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonInputM2IBrowse = (gcnew System::Windows::Forms::Button());
			this->textBoxInputM2I = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonGo = (gcnew System::Windows::Forms::Button());
			this->buttonOutputM2IBrowse = (gcnew System::Windows::Forms::Button());
			this->textBoxOutputM2I = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->checkBoxMergeBones = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxMergeAttachments = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxMergeCameras = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"InputM2";
			this->toolTip1->SetToolTip(this->label1, L"Required. Select an M2 for M2Mod to work with.");
			// 
			// textBoxInputM2
			// 
			this->textBoxInputM2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxInputM2->Location = System::Drawing::Point(78, 22);
			this->textBoxInputM2->Name = L"textBoxInputM2";
			this->textBoxInputM2->Size = System::Drawing::Size(374, 20);
			this->textBoxInputM2->TabIndex = 1;
			// 
			// buttonInputM2Browse
			// 
			this->buttonInputM2Browse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonInputM2Browse->Location = System::Drawing::Point(458, 22);
			this->buttonInputM2Browse->Name = L"buttonInputM2Browse";
			this->buttonInputM2Browse->Size = System::Drawing::Size(75, 20);
			this->buttonInputM2Browse->TabIndex = 2;
			this->buttonInputM2Browse->Text = L"...";
			this->toolTip1->SetToolTip(this->buttonInputM2Browse, L"Browse...");
			this->buttonInputM2Browse->UseVisualStyleBackColor = true;
			this->buttonInputM2Browse->Click += gcnew System::EventHandler(this, &Form1::buttonInputM2Browse_Click);
			// 
			// buttonOutputM2Browse
			// 
			this->buttonOutputM2Browse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonOutputM2Browse->Location = System::Drawing::Point(458, 100);
			this->buttonOutputM2Browse->Name = L"buttonOutputM2Browse";
			this->buttonOutputM2Browse->Size = System::Drawing::Size(75, 20);
			this->buttonOutputM2Browse->TabIndex = 11;
			this->buttonOutputM2Browse->Text = L"...";
			this->toolTip1->SetToolTip(this->buttonOutputM2Browse, L"Browse...");
			this->buttonOutputM2Browse->UseVisualStyleBackColor = true;
			this->buttonOutputM2Browse->Click += gcnew System::EventHandler(this, &Form1::buttonOutputM2Browse_Click);
			// 
			// textBoxOutputM2
			// 
			this->textBoxOutputM2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxOutputM2->Location = System::Drawing::Point(78, 100);
			this->textBoxOutputM2->Name = L"textBoxOutputM2";
			this->textBoxOutputM2->Size = System::Drawing::Size(374, 20);
			this->textBoxOutputM2->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"OutputM2";
			this->toolTip1->SetToolTip(this->label2, L"Optional. If set, this is where M2Mod will save the modified M2.");
			// 
			// buttonInputM2IBrowse
			// 
			this->buttonInputM2IBrowse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonInputM2IBrowse->Location = System::Drawing::Point(458, 74);
			this->buttonInputM2IBrowse->Name = L"buttonInputM2IBrowse";
			this->buttonInputM2IBrowse->Size = System::Drawing::Size(75, 20);
			this->buttonInputM2IBrowse->TabIndex = 8;
			this->buttonInputM2IBrowse->Text = L"...";
			this->toolTip1->SetToolTip(this->buttonInputM2IBrowse, L"Browse...");
			this->buttonInputM2IBrowse->UseVisualStyleBackColor = true;
			this->buttonInputM2IBrowse->Click += gcnew System::EventHandler(this, &Form1::buttonInputM2IBrowse_Click);
			// 
			// textBoxInputM2I
			// 
			this->textBoxInputM2I->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxInputM2I->Location = System::Drawing::Point(78, 74);
			this->textBoxInputM2I->Name = L"textBoxInputM2I";
			this->textBoxInputM2I->Size = System::Drawing::Size(374, 20);
			this->textBoxInputM2I->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"InputM2I";
			this->toolTip1->SetToolTip(this->label3, L"Optional. If set, M2Mod will merge InputM2 with InputM2I to create a modified M2 " 
				L"which will be saved to OutputM2.");
			// 
			// buttonGo
			// 
			this->buttonGo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonGo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->buttonGo->Location = System::Drawing::Point(78, 206);
			this->buttonGo->Name = L"buttonGo";
			this->buttonGo->Size = System::Drawing::Size(374, 38);
			this->buttonGo->TabIndex = 15;
			this->buttonGo->Text = L"Go!";
			this->toolTip1->SetToolTip(this->buttonGo, L"Click this to perform operations.");
			this->buttonGo->UseVisualStyleBackColor = true;
			this->buttonGo->Click += gcnew System::EventHandler(this, &Form1::buttonGo_Click);
			// 
			// buttonOutputM2IBrowse
			// 
			this->buttonOutputM2IBrowse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonOutputM2IBrowse->Location = System::Drawing::Point(458, 48);
			this->buttonOutputM2IBrowse->Name = L"buttonOutputM2IBrowse";
			this->buttonOutputM2IBrowse->Size = System::Drawing::Size(75, 20);
			this->buttonOutputM2IBrowse->TabIndex = 5;
			this->buttonOutputM2IBrowse->Text = L"...";
			this->toolTip1->SetToolTip(this->buttonOutputM2IBrowse, L"Browse...");
			this->buttonOutputM2IBrowse->UseVisualStyleBackColor = true;
			this->buttonOutputM2IBrowse->Click += gcnew System::EventHandler(this, &Form1::buttonOutputM2IBrowse_Click);
			// 
			// textBoxOutputM2I
			// 
			this->textBoxOutputM2I->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxOutputM2I->Location = System::Drawing::Point(78, 48);
			this->textBoxOutputM2I->Name = L"textBoxOutputM2I";
			this->textBoxOutputM2I->Size = System::Drawing::Size(374, 20);
			this->textBoxOutputM2I->TabIndex = 4;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(15, 51);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 13);
			this->label7->TabIndex = 3;
			this->label7->Text = L"OutputM2I";
			this->toolTip1->SetToolTip(this->label7, L"Optional. If set, M2Mod will convert InputM2 to an M2I and save it here.");
			// 
			// checkBoxMergeBones
			// 
			this->checkBoxMergeBones->AutoSize = true;
			this->checkBoxMergeBones->Checked = true;
			this->checkBoxMergeBones->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxMergeBones->Location = System::Drawing::Point(78, 126);
			this->checkBoxMergeBones->Name = L"checkBoxMergeBones";
			this->checkBoxMergeBones->Size = System::Drawing::Size(86, 17);
			this->checkBoxMergeBones->TabIndex = 12;
			this->checkBoxMergeBones->Text = L"MergeBones";
			this->toolTip1->SetToolTip(this->checkBoxMergeBones, L"Check to overwrite bones from InputM2 with those from InputM2I.");
			this->checkBoxMergeBones->UseVisualStyleBackColor = true;
			// 
			// checkBoxMergeAttachments
			// 
			this->checkBoxMergeAttachments->AutoSize = true;
			this->checkBoxMergeAttachments->Checked = true;
			this->checkBoxMergeAttachments->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxMergeAttachments->Location = System::Drawing::Point(78, 149);
			this->checkBoxMergeAttachments->Name = L"checkBoxMergeAttachments";
			this->checkBoxMergeAttachments->Size = System::Drawing::Size(115, 17);
			this->checkBoxMergeAttachments->TabIndex = 13;
			this->checkBoxMergeAttachments->Text = L"MergeAttachments";
			this->toolTip1->SetToolTip(this->checkBoxMergeAttachments, L"Check to overwrite attachments from InputM2 with those from InputM2I.");
			this->checkBoxMergeAttachments->UseVisualStyleBackColor = true;
			// 
			// checkBoxMergeCameras
			// 
			this->checkBoxMergeCameras->AutoSize = true;
			this->checkBoxMergeCameras->Checked = true;
			this->checkBoxMergeCameras->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxMergeCameras->Location = System::Drawing::Point(78, 172);
			this->checkBoxMergeCameras->Name = L"checkBoxMergeCameras";
			this->checkBoxMergeCameras->Size = System::Drawing::Size(97, 17);
			this->checkBoxMergeCameras->TabIndex = 14;
			this->checkBoxMergeCameras->Text = L"MergeCameras";
			this->toolTip1->SetToolTip(this->checkBoxMergeCameras, L"Check to overwrite cameras from InputM2 with those from InputM2I.");
			this->checkBoxMergeCameras->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxInputM2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->buttonOutputM2IBrowse);
			this->groupBox2->Controls->Add(this->checkBoxMergeCameras);
			this->groupBox2->Controls->Add(this->textBoxOutputM2I);
			this->groupBox2->Controls->Add(this->textBoxOutputM2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->buttonInputM2IBrowse);
			this->groupBox2->Controls->Add(this->textBoxInputM2I);
			this->groupBox2->Controls->Add(this->checkBoxMergeAttachments);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->buttonInputM2Browse);
			this->groupBox2->Controls->Add(this->buttonOutputM2Browse);
			this->groupBox2->Controls->Add(this->checkBoxMergeBones);
			this->groupBox2->Controls->Add(this->buttonGo);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(545, 258);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Configuration";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(16)), 
				static_cast<System::Int32>(static_cast<System::Byte>(4)));
			this->toolTip1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(94)), 
				static_cast<System::Int32>(static_cast<System::Byte>(131)));
			this->toolTip1->InitialDelay = 1;
			this->toolTip1->ReshowDelay = 1;
			this->toolTip1->UseAnimation = false;
			this->toolTip1->UseFading = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 282);
			this->Controls->Add(this->groupBox2);
			this->MinimumSize = System::Drawing::Size(500, 320);
			this->Name = L"Form1";
			this->Text = L"M2Mod Redux - v4.5";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
		}
private: System::Void buttonInputM2Browse_Click(System::Object^  sender, System::EventArgs^  e)
		{
			openFileDialog1->Filter = M2Filter;
			openFileDialog1->FileName = textBoxInputM2->Text;
			if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			{
				textBoxInputM2->Text = openFileDialog1->FileName;
			}
		}

private: System::Void buttonOutputM2IBrowse_Click(System::Object^  sender, System::EventArgs^  e)
		{
			saveFileDialog1->Filter = M2IFilter;
			saveFileDialog1->FileName = textBoxOutputM2I->Text;
			if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			{
				textBoxOutputM2I->Text = saveFileDialog1->FileName;
			}
		}

private: System::Void buttonInputM2IBrowse_Click(System::Object^  sender, System::EventArgs^  e)
		{
			openFileDialog1->Filter = M2IFilter;
			openFileDialog1->FileName = textBoxInputM2I->Text;
			if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			{
				textBoxInputM2I->Text = openFileDialog1->FileName;
			}
		}

private: System::Void buttonOutputM2Browse_Click(System::Object^  sender, System::EventArgs^  e)
		{
			saveFileDialog1->Filter = M2Filter;
			saveFileDialog1->FileName = textBoxOutputM2->Text;
			if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			{
				textBoxOutputM2->Text = saveFileDialog1->FileName;
			}
		}

private: System::Void buttonGo_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::String^ SavedText = buttonGo->Text;
			buttonGo->Enabled = false;
			buttonGo->Text = "Working...";
			buttonGo->Refresh();

			// 
			M2Lib::M2* M2 = new M2Lib::M2();

			// import M2
			if ( textBoxInputM2->Text->Length > 0 )
			{
				System::IntPtr StringPointer = System::Runtime::InteropServices::Marshal::StringToHGlobalUni( textBoxInputM2->Text );
				M2Lib::EError Error = M2->Load( (Char16*)StringPointer.ToPointer() );
				System::Runtime::InteropServices::Marshal::FreeHGlobal( StringPointer );
				if ( Error != 0 )
				{
					System::Windows::Forms::MessageBox::Show( gcnew System::String( M2Lib::GetErrorText( Error ) ) );
					buttonGo->Enabled = true;
					return;
				}
			}
			else
			{
				System::Windows::Forms::MessageBox::Show( "Error: No input M2 file Specified." );
			}

			// export M2I
			if ( textBoxOutputM2I->Text->Length > 0 )
			{
				System::IntPtr StringPointer = System::Runtime::InteropServices::Marshal::StringToHGlobalUni( textBoxOutputM2I->Text );
				M2Lib::EError Error = M2->ExportM2Intermediate( (Char16*)StringPointer.ToPointer() );
				System::Runtime::InteropServices::Marshal::FreeHGlobal( StringPointer );
				if ( Error != 0 )
				{
					System::Windows::Forms::MessageBox::Show( gcnew System::String( M2Lib::GetErrorText( Error ) ) );
					buttonGo->Enabled = true;
					return;
				}
			}

			// import M2I
			if ( textBoxInputM2I->Text->Length > 0 )
			{
				System::IntPtr StringPointer = System::Runtime::InteropServices::Marshal::StringToHGlobalUni( textBoxInputM2I->Text );
				M2Lib::EError Error = M2->ImportM2Intermediate( (Char16*)StringPointer.ToPointer(), !checkBoxMergeBones->Checked, !checkBoxMergeAttachments->Checked, !checkBoxMergeCameras->Checked );
				System::Runtime::InteropServices::Marshal::FreeHGlobal( StringPointer );
				if ( Error != 0 )
				{
					System::Windows::Forms::MessageBox::Show( gcnew System::String( M2Lib::GetErrorText( Error ) ) );
					buttonGo->Enabled = true;
					return;
				}
			}

			// export M2
			if ( textBoxOutputM2->Text->Length > 0 )
			{
				System::IntPtr StringPointer = System::Runtime::InteropServices::Marshal::StringToHGlobalUni( textBoxOutputM2->Text );
				M2Lib::EError Error = M2->Save( (Char16*)StringPointer.ToPointer() );
				System::Runtime::InteropServices::Marshal::FreeHGlobal( StringPointer );
				if ( Error != 0 )
				{
					System::Windows::Forms::MessageBox::Show( gcnew System::String( M2Lib::GetErrorText( Error ) ) );
					buttonGo->Enabled = true;
					return;
				}
			}

			delete M2;

			buttonGo->Text = SavedText;
			buttonGo->Enabled = true;
		}
};
}
