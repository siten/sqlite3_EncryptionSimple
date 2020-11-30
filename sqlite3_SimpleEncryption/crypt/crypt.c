#include "crypt.h"



//TODO ����ʹ�ü򵥵�������ӽ�����ʾ�ᱩ¶��Կ
int MyEnFn(void* pData, size_t dataLen, unsigned char* pkey, int nKey)
{
    if (pData) {
        unsigned char* pbuf = (unsigned char*)pData;
        for (size_t i = 0; i < dataLen; i++) {
            pbuf[i] ^= pkey[i % nKey];
        }
    }
    
    return 0;
}

int MyDeFn(void* pData, size_t dataLen, unsigned char* pkey, int nKey)
{
    if (pData) {
        unsigned char* pbuf = (unsigned char*)pData;
        for (size_t i = 0; i < dataLen; i++) {
            pbuf[i] ^= pkey[i % nKey];
        }
    }

    return 0;
}

