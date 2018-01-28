#include <SoftwareSerial.h>

SoftwareSerial SIM900(5,6); // configure software serial port (RX, TX)


void setup() {     
  
  SIM900.begin(9600);
  Serial.begin(9600); 
  Serial.println("power up" );
  delay(1000); 

}


 
void loop()
{

  Serial.println("SubmitHttpRequest - started" );
  SubmitHttpRequest();
  Serial.println("SubmitHttpRequest - finished" );
  delay(10000);

}

void SubmitHttpRequest()
{
  
 
  SIM900.println("AT+CSQ"); // Signal quality check

  delay(100);
 
  ShowSerialData();// this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.
  
  SIM900.println("AT+CGATT?"); //Attach or Detach from GPRS Support
  delay(100);
 
  ShowSerialData();
  SIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);
 
  ShowSerialData();
 
  SIM900.println("AT+SAPBR=3,1,\"APN\",\"gpinternet\"");//setting the APN, Access point name string
  delay(4000);
 
  ShowSerialData();
 
  SIM900.println("AT+SAPBR=1,1");//setting the SAPBR
  delay(2000);
 
  ShowSerialData();
 
 SIM900.println("AT+HTTPINIT"); //init the HTTP request
 
 delay(2000); 
  ShowSerialData();
 
  SIM900.println("AT+HTTPPARA=\"URL\",\"http://103.199.155.138/rfid/views/php/_add-result.php?id=0A%2085%203E%205B\"");// setting the httppara, the second parameter is the website you want to access
  delay(1000);
 
  ShowSerialData();
  Serial.println("check delay");
  SIM900.println("AT+HTTPACTION=0");//submit the request 
  delay(10000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
  //while(!SIM900.available());
 
  ShowSerialData();
 
  SIM900.println("AT+HTTPREAD");// read the data from the website you access
  delay(3000);
  
  ShowSerialData();
 
  SIM900.println("");
  delay(1000);
}
 


 
void ShowSerialData()
{ 
  
  while(SIM900.available()!=0)
    Serial.write(char (SIM900.read()));
    
}

