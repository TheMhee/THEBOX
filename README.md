# Thebox
ทางเลือกในการเข้ารหัสล็อคกล่อง

## บทคัดย่อ

## อุปกรณ์
| รูป   |      ชื่อ      |
|----------|:-------------:|
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/r3.jpg" width="150" height="100"> | Arduino R3 Uno |
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/sr05.jpg" width="150" height="100"> |  Module Ultrasonic SR05 |
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/lcd.jpg" width="150" height="100"> | LCD 16x2 |
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/sw1.jpg" width="150" height="100"> | Switch กดติดปล่อยดับ x 3|
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/swr.jpg" width="150" height="100"> | Switch กดติดปล่อยดับสีแดง x1 |


## ภาพรวมระบบ
<img src="https://github.com/TheMhee/THEBOX/blob/master/pic/Untitled.png" width="800" height="200">
## วิธีการใช้
- การปลดล็อคกล่องนี้ได้ ต้องใช้รหัสความห่างของวัตถุกับด้านซ้ายของกล่อง 5ค่า เพื่อปลดล็อค
- ปุ่มด้านล่างจอ LCD เป็นปุ่มกดเลือกเมนู โดนปุ่มซ้ายคือเลื่อนไปทางซ้าย ปุ่มกลางคือตกลง ปุ่มขวาคือเลื่อนไปทางขวา
- ปุ่มสีแดงคือบันทึกพาสเวิด 1 ค่า
- Default password : 10 10 10 10 10
- ถ้าผิดครบ 5 ครั้งกล่องจะล็อคตัวเอง 5นาที
 ### ใส่พาสเวิด
 1. เลือก Unlock
 2. เมื่อหน้าจอขึ้นให้ใส่พาสเวิดให้นำวัตถุมาวัดระยะห่างกับเซ็นเซอร์ด้านซ้ายของกล่อง
 3. กดปุ่มสีแดงเพื่อบันทึก
 4. ทำซ้ำไปเรื่อยๆจนครบ 5 ค่า
 5. ถ้าถูกต้องกล่องจะปลดล็อค
 ### เปลี่ยนพาสเวิด
 1. เลือก Set password
 2. ใส่พาสเวิดเก่า (วืธีเดียวกันกับตอนใส่พาสเวิดเพื่อปลดล็อค)(ถ้าพาสเวิดเป็นค่า Default จะข้ามขั้นตอนนี้ไป)
 3. ใส่พาวเวิดใหม่

