//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include <string>
#include <corecrt_wstring.h>
#include "SoundEngine.h"
#include "Sound.h"
#include "MainPage.xaml.h"

using namespace XAudio2UWP;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

StorageFolder^ localFolder = ApplicationData::Current->LocalFolder;
String^ path = localFolder->Path + "\\";

MainPage::MainPage()
{
	InitializeComponent();
}


void XAudio2UWP::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	greetingOutput->Text = "Hello, " + nameInput->Text + "!";
}


void XAudio2UWP::MainPage::Music_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	std::wstring wstr = L"batman.wav";
	LPCTSTR newString = wstr.c_str();
	String ^ tempPath = path;
	path += L"batman.wav";

	greetingOutput->Text = path;
	Sound *batman = new Sound(path->Data());
	batman->play();
	/*
		BIG Problemo here:
		It will only play a heap allocated sound, because when I create it on the stack, it immediately deletes the object, 
		and can't play anymore.

		Problem here is where I need to choose to delete the sound object. I dont want to delete until the end of the project, 
		but I don't want any memory leaks, or to hog up memory.

		Check out XAudio2's GetState method, to check before deleting
	*/
	path = tempPath;
	//Make the paths look cuter

}
