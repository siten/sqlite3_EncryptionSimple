#include "crypt.h"



//TODO 这里使用简单的异或做加解密演示会暴露密钥
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

