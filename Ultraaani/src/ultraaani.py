#!/usr/bin/env python
# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

__author__="t4suar00"
__date__ ="$26.9.2014 12:44:24$"

import smbus
import time

bus = smbus.SMBus(1)
address = 0x70

def write(value):
    bus.write_byte_data(address, 0, value)
    return -1

def range():
    range1 = bus.read_byte_data(address, 2)
    range2 = bus.read_byte_data(address, 3)
    range3 = (range1 << 8) + range2
    return range3

while True:
    write(0x51)
    time.sleep(0.7)
    rng = range()
    print rng
