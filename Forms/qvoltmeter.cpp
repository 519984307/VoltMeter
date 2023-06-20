//
// Created by WhiskeyXD on 2023/6/18.
//

// You may need to build the project (runYaju Qt uic code generator) to get "ui_QVoltMeter.h" resolved

#include "qvoltmeter.h"
#include "ui_QVoltMeter.h"


QVoltMeter::QVoltMeter(QWidget *parent) :
        QWidget(parent), ui(new Ui::QVoltMeter) {
    ui->setupUi(this);
}

QVoltMeter::~QVoltMeter() {
    delete ui;
}

void QVoltMeter::setLCDValue(double val)
{
    ui->lcdNumber->display(val);
}

void QVoltMeter::on_pushButton_clicked()
{
    availableDevices = CSerialPortInfo::availablePortInfos();
    ui->comboBox->clear();
    for (const auto& dev : availableDevices){
        QString deviceInfo(dev.portName);
        deviceInfo.append(' ');
        deviceInfo.append(dev.description);
        ui->comboBox->addItem(deviceInfo);
    }
}

void QVoltMeter::on_pushButton_2_clicked()
{
    meterPort.writeData("0", 1);
}

void QVoltMeter::on_pushButton_3_clicked()
{
    meterPort.writeData("1", 1);
}

void QVoltMeter::on_pushButton_4_clicked() {

}

void QVoltMeter::on_pushButton_5_clicked() {

}

void QVoltMeter::on_comboBox_activated(int index)
{
    meterPort.disconnectReadEvent();
    meterPort.close();
    meterPort.init(
            availableDevices[index].portName,
            BaudRate9600,	//波特率9600
            ParityNone,		//无校验位
            DataBits8,		//8位数据传输
            StopOne,		//停止位1
            FlowNone,		//无流控制
            4096
    );
    meterPort.setReadIntervalTimeout(0);
    meterPort.open();

    auto pMeterSession = new VoltMeterSession(&meterPort);

    QObject::connect(pMeterSession->getSender(), SIGNAL(notifyLCD(double)),
                     this, SLOT(setLCDValue(double)));
    meterPort.connectReadEvent(pMeterSession);
}