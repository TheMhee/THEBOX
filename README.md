# Thebox
ทางเลือกในการเข้ารหัสล็อคกล่อง

## บทคัดย่อ
 ทุกๆคนล้วนมีสิ่งของสำคัญ ไม่ว่าจะเป็นของขวัญจากคนรัก ของเล่นในอดีต หรืองานๆที่เราอยากเก็บไว้ในตู้ล็อค แต่เมื่อเวลาผ่านไป ดันลืมกุญแจไว้ที่ไหนไม่รู้ ไม่สามารถปลดล็อคได้ เสียเวลามากมายในการหาสิ่งกุญแจเพื่อมาเปิด เราจึงจะหาทางแก้ไขปัญหานี้ โดยการสร้างวิธีการเก็บรหัสอีกแลลนึง เพื่อใช้ในการปลดล็อคกล่อง โดยรหัสนั้นจะเกี่ยวกับ ระยะห่างระหว่างกล่องกับวัตถุที่เราจะใช้ อย่างเช่น มือถือ หรือกระเป๋าเงิน

## อุปกรณ์
| รูป   |      ชื่อ      |
|----------|:-------------:|
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/r3.jpg" width="150" height="100"/> | Arduino R3 Uno |
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/sr05.jpg" width="150" height="100"/> |  Module Ultrasonic SR05 |
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/lcd.jpg" width="150" height="100"/> | LCD 16x2 |
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/sw1.jpg" width="150" height="100"/> | Switch กดติดปล่อยดับ x 3|
| <img src="https://github.com/TheMhee/THEBOX/blob/master/pic/swr.jpg" width="150" height="100"/> | Switch กดติดปล่อยดับสีแดง x1 |


## ภาพรวมระบบ
<img src="https://github.com/TheMhee/THEBOX/blob/master/pic/Untitled.png" width="800" height="200"/>

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
 
 ## วิดีโอสาธิต
  (ใส่วิดีโอ)
 ## สมาชิก
| รูป | ชื่อ | รหัสนักศึกษา | Github |
|----------|:-------------|:---------|:---------:|
| <img src="https://scontent.fbkk8-3.fna.fbcdn.net/v/t1.0-9/39525966_1851771524904165_7145607038192582656_n.jpg?_nc_cat=100&_nc_eui2=AeElfjwbnrzoMf3w9uDbfpemY4hbXbEPo1RQpMZ-6DdXfkKjOepyLdN9c0HEAhKHi7XLgFApIQQvX1o4wbo5xRAgo_wJ22eYkgwLfISysDGnTg&_nc_ht=scontent.fbkk8-3.fna&oh=e683564beab6353bff3f39030475d867&oe=5D30175A" width="170" height="200"> | ธนกฤต แซ่ลี้ | 61070068 | TheMhee |
| <img src="https://scontent.fbkk12-2.fna.fbcdn.net/v/t1.0-9/56119408_929299900794625_1260594998982737920_n.jpg?_nc_cat=105&_nc_eui2=AeE7s-B5PAG6ifdQT3FlfkNkw5AuIPk8QwV2uvUQVNYDzsgWm8B0UHigdfTPfV7-sROQFWv-uM9yXgyu22t5E6UN9f43g1ZZKTe6Z7xW68B-FQ&_nc_ht=scontent.fbkk12-2.fna&oh=614455010cda6080ab341ee55d37fee8&oe=5D6B3FE0" width="170" height="200"> | ธนิศร์ สัลเลขนันท์ | 61070081 |  |
| <img src="https://scontent.fbkk12-2.fna.fbcdn.net/v/t1.0-9/55498759_2225253327550460_1214317306188922880_n.jpg?_nc_cat=104&_nc_eui2=AeEMQJhKiJv2jmBo0yHZxKQGCZjnuXSTnReHhvqb1fTU0qcgXfJnQI-Pgc7KXD14jaSvFilfP6R8WduaSNs1Bcfge52HJrS4wuIDnAPkRvnG5g&_nc_ht=scontent.fbkk12-2.fna&oh=cbf067060a18fc5949cef0f112967718&oe=5D7367C9" width="170" height="200"> | ธัญเทพ อินรุ่ง | 61070086 |  |
| <img src="https://scontent.fbkk8-2.fna.fbcdn.net/v/t1.0-1/c0.0.890.890a/51814829_1843939045735034_2131151699849510912_n.jpg?_nc_cat=103&_nc_eui2=AeGFmEvWQQxLQTrnAJXWIuWu59mVxwKbEZl7k0Ntrpwpl_Z_QbmADj10v4OiSP9WbXjezA0nL6EPcptJvqxIXCrqfTgvy3F0BbC1iisKKaRydg&_nc_ht=scontent.fbkk8-2.fna&oh=f09110e7ccd543ec0408bc875c614f8b&oe=5D2AC01F" width="170" height="200"> | รุ่งวราพร คุตะนนท์ | 61070190 |  |

 ## Adviso
 | <img src="https://scontent.fbkk8-3.fna.fbcdn.net/v/t1.0-9/14611010_10153805956002331_6002362915012083123_n.jpg?_nc_cat=111&_nc_eui2=AeFqpu8EDtg7jMN42r_6uuaFBvlGSHndvzQki6CZE4hPbOIppe1Otj_IFS7B9BAyhZLGYCn-zDneXYd4WC9kioAa5QBcDCC1LA9rd1-ebOdNqw&_nc_ht=scontent.fbkk8-3.fna&oh=611aa033d0ed16b8300e4b9cd490feab&oe=5D2AFF8F" width="170" height="200"/> | <img src="https://scontent.fbkk12-1.fna.fbcdn.net/v/t1.0-9/45577837_10156055460607532_5297625766278725632_n.jpg?_nc_cat=106&_nc_eui2=AeEUiMe76UWXpc0YvNOrpz6rTqE_jcVJgMXg0iY0c37G23x_RsEdLlIVF4PadM603MG1syxFfddltGbjrDvmg7S1lMo7Z3vpikwW9B7Nk2oABA&_nc_ht=scontent.fbkk12-1.fna&oh=871c8dbc2cf1dff1d8f732ddb794a7a9&oe=5D66B613" width="170" height="200"/> |
|----------|:------------:|
| รศ.ดร. กิติ์สุชาต พสุภา | รศ.ดร. ปานวิทย์ ธุวะนุติ |


