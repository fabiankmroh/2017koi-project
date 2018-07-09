#!/usr/bin/env python

# import modules used here -- sys is a very standard one


import sys
import serial
from time import strftime
from pytz import timezone
from datetime import datetime

# Gather our code in a main() function
def main():
    # print 'Hello there', sys.argv[1]
    # Command line args are in sys.argv[1], sys.argv[2] ...
    # sys.argv[0] is the script name itself and can be ignored
    ser = serial.Serial(
        port='/dev/cu.usbmodem1421',
        baudrate=9600,
    )

    if len(sys.argv) < 2:
        print('please type : python3 ' + sys.argv[0] + ' [csv file name]')
        return

    while True:
        if ser.readable():
            f = open(sys.argv[1] + '.csv', 'a')
            res = ser.readline()
            KST = datetime.now(timezone('Asia/Seoul'))
            print(KST.strftime("%Y-%m-%d %H:%M:%S") + ', ' + res.decode()[:len(res)-1])
            f.write(KST.strftime("%Y-%m-%d %H:%M:%S") + ', ' + res.decode()[:len(res)-1] + '\n')
            f.close()

# Standard boilerplate to call the main() function to begin
# the program.
if __name__ == '__main__':
    main()
