#pragma once

class Sound : SoundEngine {
private:
	LPCTSTR fileName;
	HANDLE hFile;
	XAUDIO2_BUFFER buffer;
	WAVEFORMATEXTENSIBLE wfx;
	HRESULT checkForValidFile(HANDLE name);
	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset);
	IXAudio2SourceVoice *pSourceVoice;
	HRESULT prepWave();
	HRESULT checkHandleError();
public:
	Sound(LPCTSTR name);
	LPCTSTR getName();
	HRESULT play();

};