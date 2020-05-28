//-----------------------------------------------------------------------------------------------
//  SỬ DỤNG 2 ĐÈN LED:  chip Atmega không trực tiếp điều khiển 2 led mà thông qua một IC dịch 
//  Tham khảo các hàm và tham số trong file thư viện WeMake/WMRGBLed.h  

//    @param[in]  Green   mức màu xanh lá, từ 0-->255                
//    @param[in]  Red     mức màu đỏ, từ 0-->255
//    @param[in]  Blue    mức màu xanh dương, từ 0-->255
//    rgbLED.setColor(chỉ số đèn, Green, Red, Blue)

//  Các bước:
//    1. rgbLED.setColor(0,0);  Xóa vùng nhớ tạm chưa màu của các đèn
//    2. rgbLED.setColor(x,...); Thiết lập màu của từng đèn led trong vùng nhớ tạm
//    3. rgbLED.show(); Đẩy giá trị màu trong vùng nhớ tạm tới IC điều khiển led
//-----------------------------------------------------------------------------------------------
#include<Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

// Chỉ số của đèn led bên trái
#define   LEFT_LED  1
// Chỉ số của đèn led bên phải
#define   RIGHT_LED 2
// Báo hiệu áp dụng cho cả 2 đèn led
#define   BOTH_LEDS  0

/// Tạo handler phụ trách điều khiển đèn led với 2 tham số  Chân vào, Số lượng led
WMRGBLed rgbLED(0,2);


void setup() {
}

void loop() {
  ///  Tắt đèn
  rgbLED.setColor(0,0);       // Cả 2 đèn: mã màu 0 = đen
  rgbLED.show();              //Hiện thi led
  delay(1000);
  
  /// Đèn 1:  màu xanh dương
  rgbLED.setColor(LEFT_LED,0,0,255);  // Thiết lập bộ đệm màu cho led 1
  rgbLED.show();                      // Hiển thị led
  delay(1000);

  /// Đèn 2:  màu xanh lá 
  rgbLED.setColor(BOTH_LEDS,0);       // Cả 2 đèn: mã màu 0 = đen
  rgbLED.setColor(RIGHT_LED,250,0,0); // Thiết lập bộ đệm màu cho led 2
  rgbLED.show();                      // Hiển thị led
  delay(1000);  

  /// Đèn 2:  màu xanh lá 
  rgbLED.setColor(BOTH_LEDS,0xFF66FF);// Cả 2 đèn: mã màu viết ở hệ 16
  rgbLED.show();                      // Hiển thị led
  delay(1000);  
}
