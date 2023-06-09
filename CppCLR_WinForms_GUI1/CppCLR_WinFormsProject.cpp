
using namespace System;
#include <iostream>
#include <memory>
#include "Header.h"
// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "CallPythonForm.h"
#include <string>

using namespace System::Windows::Forms;

[STAThread]
int main()
{

    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    
    Application::Run(gcnew CppCLRWinFormsProject::Form1());
    
    return 0;
}