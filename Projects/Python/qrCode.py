import pyqrcode 
from pyqrcode import QRCode 
'''To generate QR Codes with Python you need to install only one Python library for this task'''
# String which represent the QR code 

s = input("Enter the link (paste the link)")
  
# Generate QR code 
url = pyqrcode.create(s) 
  
# Create and save the png file naming "myqr.png" 
url.svg("myyoutube.svg", scale = 8) 
