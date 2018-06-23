import serial

ser = serial.Serial(
    port='/dev/cu.usbmodem1411',
    baudrate=9600,
)

while True:
    if ser.readable():
        res = ser.readline()
        print(res.decode()[:len(res)-1])
