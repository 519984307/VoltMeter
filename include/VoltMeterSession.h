#ifndef VOLTMETERSESSION_H
#define VOLTMETERSESSION_H

#include <CSerialPort/SerialPort.h>
#include <CSerialPort/SerialPortListener.h>
#include <string>
#include <QObject>
using namespace itas109;

class SessionSignalSender : public QObject{
    Q_OBJECT
public:
    int getMaxRange(){
        return maxRange;
    }

    signals:
    void notifyLCD(double val);

public slots:
    void setMaxRange(int newMaxRange){
        maxRange = newMaxRange;
    };
private:
    int maxRange = 5000;
};

class VoltMeterSession : public CSerialPortListener{
public:
    VoltMeterSession(CSerialPort* sp) :
        pListenerPort(sp){}

    void onReadEvent(const char* portName, unsigned int readBufferLen) override;

    void convertAndSend(uint16_t rawVal);

    SessionSignalSender* getSender(){
        return &sender;
    }

private:
    CSerialPort* pListenerPort;
    int gain = 0;
    SessionSignalSender sender;
};


#endif // !VOLTMETERSESSION_H
