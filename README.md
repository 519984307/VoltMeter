ע��: ��master��֧ΪQtʵ�ְ汾��MFCʵ�ְ汾���ƶ�����֧`MFC_Ver`
# VoltMeter���򵥵�GUI��ѹ�ɼ����

8051MCU����ֿ⣺[VoltMeter_C51](https://github.com/SignedWhiskeyXD/VoltMeter_C51)

## ���

����WHUT����ѧԺ��ؼ���������רҵ�Ŀγ���Ƶ�һ����

�òֿ����ѧϰ�о�ʹ�ã����߱�̫��ʵ�ü�ֵ


## ��;

��������MCU�Ĳɼ����ݣ����ӻ���ʾ�����ǰ̨

��MCU����ָ�ִ��У׼�Ȳ���



## ����

- MSVC (֧��ISO C++11)
- Qt 6.2.4
- [CSerialPort](https://github.com/itas109/CSerialPort)
- [fmt](https://github.com/fmtlib/fmt)

�����ʹ��vcpkg��װ��CSerialPort��fmt��

~~~shell
vcpkg install cserialport fmt
~~~



## ����
ʹ��Git��¡���ֿ⣺
~~~shell
git clone https://github.com/SignedWhiskeyXD/VoltMeter.git
~~~


ʹ��CMake������Ŀ��
- ͨ��֧��CMake��IDE�򿪱���Ŀ������VSCode CLion�ȣ�����ͨ��`CMakeLists.txt`����Ŀ��������
- ���ߣ������ͨ�������������
~~~shell
mkdir build
cd build
cmake ..
cmake --build .
~~~
��Ȼ����Qtд�ˣ������һ�û��������ƽ̨�µĿ���ֲ��

~~Ȼ���ұ�����ȥ�����ˣ�����ıʼǱ�ֻ�з�������Linux�������ò���~~