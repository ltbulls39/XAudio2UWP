#include "pch.h"

#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")
#include "SoundEngine.h"

IXAudio2 *SoundEngine::pXAudio2;
IXAudio2MasteringVoice *SoundEngine::pMasteringVoice;
SoundEngine::SoundEngine()
{
	if (pXAudio2 == nullptr) {
		XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
		pXAudio2->CreateMasteringVoice(&pMasteringVoice);
	}

}

SoundEngine::~SoundEngine()
{
	if (pXAudio2) {
		pXAudio2->Release();
		pXAudio2 = nullptr;
	}
}

