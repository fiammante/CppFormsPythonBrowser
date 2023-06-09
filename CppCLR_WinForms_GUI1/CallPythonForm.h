#pragma once
#include "Header.h"
// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used



namespace CppCLRWinFormsProject {

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
      this->webBrowser1->ScriptErrorsSuppressed = true;
      std::cout << "Python Embedded C++ Template" << std::endl;
      std::unique_ptr<SomeClass> p = std::make_unique<SomeClass>();
      const char* returned = p->callScript();
      String^ url = gcnew String(returned);
      this->webBrowser1->Navigate(url);
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

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




  private: System::Windows::Forms::MenuStrip^ menuStrip1;
  private: System::Windows::Forms::ToolStripMenuItem^ fichierToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ ouvrirToolStripMenuItem;
  private: System::Windows::Forms::WebBrowser^ webBrowser1;
  private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;































  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
        this->fichierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->ouvrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
        this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
        this->menuStrip1->SuspendLayout();
        this->SuspendLayout();
        this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
        this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fichierToolStripMenuItem });
        this->menuStrip1->Location = System::Drawing::Point(0, 0);
        this->menuStrip1->Name = L"menuStrip1";
        this->menuStrip1->Size = System::Drawing::Size(379, 28);
        this->menuStrip1->TabIndex = 4;
        this->menuStrip1->Text = L"menuStrip1";
        this->fichierToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ouvrirToolStripMenuItem });
        this->fichierToolStripMenuItem->Name = L"fichierToolStripMenuItem";
        this->fichierToolStripMenuItem->Size = System::Drawing::Size(66, 24);
        this->fichierToolStripMenuItem->Text = L"Fichier";
        this->fichierToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fichierToolStripMenuItem_Click);
        this->ouvrirToolStripMenuItem->Name = L"ouvrirToolStripMenuItem";
        this->ouvrirToolStripMenuItem->Size = System::Drawing::Size(224, 26);
        this->ouvrirToolStripMenuItem->Text = L"Ouvrir";
        this->ouvrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ouvrirToolStripMenuItem_Click);
        this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->webBrowser1->Location = System::Drawing::Point(0, 28);
        this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
        this->webBrowser1->Name = L"webBrowser1";
        this->webBrowser1->Size = System::Drawing::Size(379, 293);
        this->webBrowser1->TabIndex = 5;
        this->openFileDialog1->FileName = L"openFileDialog1";
        this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(379, 321);
        this->Controls->Add(this->webBrowser1);
        this->Controls->Add(this->menuStrip1);
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"Form1";
        this->Text = L"Form1";
        this->menuStrip1->ResumeLayout(false);
        this->menuStrip1->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.

  

  private: System::Void fichierToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
  }
    private: System::Void ouvrirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        this->openFileDialog1->InitialDirectory = "c:\\";
        this->openFileDialog1->Filter = "EEG files (*.eeg)|*.eeg|EDF files (*.edf)|*.edf|All files (*.*)|*.*";
        this->openFileDialog1->FilterIndex = 2;
        this->openFileDialog1->RestoreDirectory = true;
        if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {::
            //Get the path of specified file
            String^ filePath = this->openFileDialog1->FileName;
            MessageBox::Show(filePath);
            
        }

    }
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

