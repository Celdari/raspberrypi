# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

__author__="t4suar00"
__date__ ="$26.9.2014 12:44:24$"

import smbus

i2c = smbus.SMBus(1)
i2c.write_byte_data(0x70, 0, 81)
print i2c.read_word_data(0x70, 2) / 255
