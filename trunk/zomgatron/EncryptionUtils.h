#ifndef __ENCRYPTIONUTILS_H__
#define __ENCRYPTIONUTILS_H__

class EncryptionUtils{
public:
	static void EncryptDecryptShort(short& val);

	static void DecryptBuf(char* buf, int len);

	static void EncryptBuf(char* buf, int len);

	static unsigned long GetEncryptDecryptUL(unsigned long val);

	static int GetEncryptedFloat(float val);
	static float GetDecryptedFloat(int val);
	static short GetEncryptDecryptShort(short val);
	static unsigned int GetEncryptDecryptUI(unsigned int val);
};

#endif
