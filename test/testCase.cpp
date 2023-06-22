//
// Created by WhiskeyXD on 2023/6/22.
//
#include <iostream>
#include <CSerialPort/SerialPort.h>
using namespace std;
using namespace itas109;

int main()
{
    const uint8_t toSend[6] = {'W', 'S', 'K', 1, 'f', 'f'};
    CSerialPort sp15;
    sp15.init(
            "COM15",
            BaudRate9600,	//������9600
            ParityNone,		//��У��λ
            DataBits8,		//8λ���ݴ���
            StopOne,		//ֹͣλ1
            FlowNone,		//��������
            4096
            );
    sp15.open();
    sp15.writeData(toSend, 6);
    return 0;
}