import qrcode 
data = "https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/description/"

qr = qrcode.make(data)

qr.save("qrcode.png")

print("QR Code created Successfully")