#include <SoftwareSerial.h> // 시리얼 포트가 부족한 경우, 다른 기기와 시리얼 통신을 위한 아두이노 라이브러리

SoftwareSerial mySerial(0, 1); // RX, TX

String str1 = "640522710850";
String str = "";    //시리얼수신 문자열 저장
int intStr;

void setup() {
  Serial.begin(115200);
 // while (!Serial) {
 //   ; // wait for serial port to connect. Needed for native USB port only
 // }
  Serial.println("Ready.");
  mySerial.begin(115200);
}

void loop() {
  if(Serial.available())
  {
    str = mySerial.readString();
    str = str.substring(0, str.length()-2);
    Serial.print(str);
    Serial.println();
    delay(2000);
  }
  
  
// available문 안에서 동시 확인
/*
if(mySerial.available()){
    str = mySerial.readString();             //read()가 아닌 readString()으로 읽기 :: 문자열로 읽기
                                             //왜? 웬만한 교과서에는 read()로 한 문자만 읽어오는 것만 설명하는지 모르겠음
    str = str.substring(0, str.length()-2);  //시리얼모니터에서 엔터 치면서 마지막에 송신한 '\n' 제거
    Serial.print(str);                       // 수신 데이터 확인
    Serial.print("--------( ");                // 구분선
    Serial.print(str.length());              // 수신 받은 문자열 길이 확인
    Serial.print(" )--------// ");              // 구분선
    intStr = str1.compareTo(str);            // 방식1 - 문자열 비교 :: 명령어이용 --> 같으면 0, 다르면 다른 갯수 수치 표시
    Serial.println(intStr);                  // 수치값 확인
    
    if(str == "640522710850") Serial.println("ok");  // 방식2 - 문자열 비교 :: 단순비교 --> 
    else Serial.println("no~~");                     // 만약 문자열이 같으면 ok, 다르면 no~~
  }
  */
}
