/*
    License...
*/

#include "serialportinfo.h"
#include "serialportinfo_p.h"
#include "serialport.h"

QT_BEGIN_NAMESPACE_SERIALPORT


/*!
    \class SerialPortInfo

    \brief The SerialPortInfo class gives access to information about
    existing serial ports.

    \ingroup serialport-main
    \inmodule QtAddOnSerialPort
    \since 5.0

    Use the static functions to generate a list of SerialPortInfo
    objects. Each SerialPortInfo object in the list represents a single
    serial port and can be queried for port name, system location,
    description, manufacturer. SerialPortInfo also can be used as an
    input parameter to the method setPort() a class SerialPort.

    \sa SerialPort
*/

/* Public methods */

/*!
    Constructs an empty SerialPortInfo object.

    \sa isNull()
*/
SerialPortInfo::SerialPortInfo()
    : d_ptr(new SerialPortInfoPrivate)
{
}

/*!
    Constructs a copy of \a other.
*/
SerialPortInfo::SerialPortInfo(const SerialPortInfo &other)
    : d_ptr(other.d_ptr ? new SerialPortInfoPrivate(*other.d_ptr) : 0)
{
}

/*!
    Constructs a SerialPortInfo object from serial \a port.
*/
SerialPortInfo::SerialPortInfo(const SerialPort &port)
    : d_ptr(new SerialPortInfoPrivate)
{
    foreach(const SerialPortInfo &info, availablePorts()) {
        if (port.portName() == info.portName()) {
            *this = info;
            break;
        }
    }
}

/*!
    Constructs a SerialPortInfo object from serial port \a name.

    ...
*/
SerialPortInfo::SerialPortInfo(const QString &name)
    : d_ptr(new SerialPortInfoPrivate)
{
    foreach(const SerialPortInfo &info, availablePorts()) {
        if (name == info.portName()) {
            *this = info;
            break;
        }
    }
}

/*!
    Destroys the SerialPortInfo object. References to the values in the
    object become invalid.
*/
SerialPortInfo::~SerialPortInfo()
{
}

/*!
    Bla bla \a other
*/
void SerialPortInfo::swap(SerialPortInfo &other)
{
    d_ptr.swap(other.d_ptr);
}

/*!
    Bla bla \a other
*/
SerialPortInfo& SerialPortInfo::operator=(const SerialPortInfo &other)
{
    SerialPortInfo(other).swap(*this);
    return *this;
}

/*!
    Returns the name of the serial port.
*/
QString SerialPortInfo::portName() const
{
    Q_D(const SerialPortInfo);
    return !d ? QString() : d->portName;
}

/*!
    Returns the system location of the serial port.
*/
QString SerialPortInfo::systemLocation() const
{
    Q_D(const SerialPortInfo);
    return !d ? QString() : d->device;
}

/*!
    Returns the description string of the serial port,
    if available; otherwise return empty string.
*/
QString SerialPortInfo::description() const
{
    Q_D(const SerialPortInfo);
    return !d ? QString() : d->description;
}

/*!
    Returns the manufacturer string of the serial port,
    if available; otherwise return empty string.
*/
QString SerialPortInfo::manufacturer() const
{
    Q_D(const SerialPortInfo);
    return !d ? QString() : d->manufacturer;
}

/*!
    Returns the vendor identifier string of the serial
    port in hexadecimal format, if available; otherwise
    return empty string.
*/
QString SerialPortInfo::vid() const
{
    Q_D(const SerialPortInfo);
    return !d ? QString() : d->vid;
}

/*!
    Returns the product identifier string of the serial
    port in hexadecimal format, if available; otherwise
    return empty string.
*/
QString SerialPortInfo::pid() const
{
    Q_D(const SerialPortInfo);
    return !d ? QString() : d->pid;
}

/*!
    \fn bool SerialPortInfo::isNull() const

    Returns whether this SerialPortInfo object holds a
    serial port definition.
*/

/*!
    \fn bool SerialPortInfo::isBusy() const

    Returns true if serial port is busy;
    otherwise returns false.
*/

/*!
    \fn bool SerialPortInfo::isValid() const

    Returns true if serial port is present on system;
    otherwise returns false.
*/

/*!
    \fn QList<qint32> SerialPortInfo::standardRates() const

    Returns a list of available standard baud rates supported by
    the current serial port.
*/

/*!
    \fn QList<SerialPortInfo> SerialPortInfo::availablePorts()

    Returns a list of available serial ports on the system.
*/

QT_END_NAMESPACE_SERIALPORT
