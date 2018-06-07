#pragma once
#include <xaudio2.h>

class SoundEngine {
public:
	static IXAudio2 * pXAudio2;
	static IXAudio2MasteringVoice * pMasteringVoice;
	SoundEngine();
	~SoundEngine();
};