# Comunicacion RPi con Arduino a través de GCODE usando SERIAL
import serial
import serial.tools.list_ports
from time import sleep
from config import ARDUINO

arduino = None
baud = ARDUINO['baud']
port = None
timeout = ARDUINO['timeout']


def abrir_comunicacion():
    global arduino, port
    # Buscar puerto
    for puerto in serial.tools.list_ports.comports():
        print('Dispositivo encontrado = {}')
        print("\tdescription   = {}".format(puerto.description))
        print("\tdevice        = {}".format(puerto.device))
        print("\thwid          = {}".format(puerto.hwid))
        print("\tinterface     = {}".format(puerto.interface))
        print("\tlocation      = {}".format(puerto.location))
        print("\tmanufacturer  = {}".format(puerto.manufacturer))
        print("\tname          = {}".format(puerto.name))
        print("\tpid           = {}".format(puerto.pid))
        print("\tproduct       = {}".format(puerto.product))
        print("\tserial_number = {}".format(puerto.serial_number))
        print("\tvid           = {}".format(puerto.vid))
        # Abrir comunicación
        port = puerto.device
        if port == '/dev/ttyUSB0':
            try:
                arduino = serial.Serial(port=port, baudrate=baud, timeout=timeout)
                sleep(1)
                print('Envio "HOLA"')
                while(1):
                    tx('HOLA')
                    respuesta = arduino.readline()
                    print('{}'.format(respuesta))
            except serial.SerialException as e:
                print('Error RX = {}'.format(e))
            else:
                print('RX = {}'.format(respuesta))
                if respuesta == 'HOLA':
                    print('Arduino comunicado')
                    break
                arduino.close()


def tx(mensaje):
    global arduino
    if arduino:
        print('TX = {}'.format(mensaje))
        arduino.reset_input_buffer()
        arduino.reset_output_buffer()
        try:
            arduino.write(mensaje.encode())
        except (serial.SerialException, serial.SerialTimeoutException, TypeError) as e:
            print('Error TX = {}'.format(e))

if __name__ == '__main__':
    abrir_comunicacion()
