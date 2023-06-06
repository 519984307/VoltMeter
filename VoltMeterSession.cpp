#include "pch.h"
#include "VoltMeterSession.h"


void VoltMeterSession::onReadEvent(const char* portName, unsigned int readBufferLen)
{
    if (readBufferLen > 0)
    {
        // ���Ϸ�����ܻ������������������ݶ��뻺����
        char* data = new char[readBufferLen + 1];
        int recLen = pListenerPort->readData(data, (int)readBufferLen);

        //У������֡
        if (recLen == 6 && data[0] == 'W' && data[1] == 'S' && data[2] == 'K') {
            meterMode = data[3] - '0';
            // �������ֽڻָ�Ϊ16λ�޷�������
            uint16_t tempVal = ((unsigned char)data[4] << 8) | (unsigned char)data[5];
            rawValue = tempVal;
        }
        // ��Ƭ���Ͽ�
        else {
            meterMode = 4;
            rawValue = 0;
        }

        delete[] data;  //�ͷŶ��ϻ�����
    }
}