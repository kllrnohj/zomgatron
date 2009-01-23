#include "EncryptionUtils.h"

void EncryptionUtils::EncryptDecryptShort(short& val){
	val = val ^ 0x321F;
}

void EncryptionUtils::DecryptBuf(char* buf, int len){
	short sign = 1;
	for(int i = 0; i < len; i++){
		if(!buf[i])
			return;
		buf[i] -= (((i+1) % 15) * sign);
		
		sign = 0 - sign;
	}
}

void EncryptionUtils::EncryptBuf(char* buf, int len){
	short sign = 1;
	for(int i = 0; i < len; i++){
		if(!buf[i])
			return;
		buf[i] += (((i+1) % 15) * sign);

		sign = 0 - sign;
	}
}

int EncryptionUtils::GetEncryptedFloat(float val){
	int* lol = (int*)&val;
	*lol ^= 0x12345678;
	return *lol;
}
float EncryptionUtils::GetDecryptedFloat(int val){
	val ^= 0x12345678;
	float* lol = (float*)&val;
	return *lol;
}

unsigned long EncryptionUtils::GetEncryptDecryptUL(unsigned long val){
	return val ^ 0x87654321;
}

short EncryptionUtils::GetEncryptDecryptShort(short val){
	return val ^ 0x321F;
}

unsigned int EncryptionUtils::GetEncryptDecryptUI(unsigned int val){
	return val ^ 0x12348765;
}