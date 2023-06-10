////////////////CODE FOR SMOKE DETECTION AND CAUTION EMAIL SENDING ////////////////////


//////////ADDING ARDUION ,WIFI AND EMAIL CLIENT LIBRARIES///////////////

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>

/////////////////////////////////////////////////////////////////////


//////////Setting up the GPIO pins of ESP01-wifi module//////////////////////


int sen = 0;  // Assigning GPIO 0 of ESP01 pin to sense the circuit
int led = 2;  // Assigning GPIO 2 of ESP01 pin to turn on LED which is on while sending mail


///////////////////////////////////////////////////////////



////////////Connecting to the WiFi Network////////////////////////// 


#define WIFI_SSID "wifi name"    /* ECEF8P */ 
#define WIFI_PASSWORD "wifi password" /* P@55w0rd@#$ */

#define SMTP_server "smtp.office365.com"  // Server Seteup 
#define SMTP_Port 587 //Port number for email reseption


///////////////////////////////////////////////////////////////////



//////////Assiging the Sender and Receptor mail address////////////////////// 


#define sender_email "sendermail@something.com"
#define sender_password "sender password"

#define Recipient_email "receiver@somthing.com"

SMTPSession smtp;


//////////////////////////////////////////////////////////////////////



//////////////////The Sensing and Email Sending ////////////////////


void setup(){
  Serial.begin(115200);
  pinMode(sen, INPUT); //Stating the type of command
  pinMode(led, OUTPUT); //Stating the type of command
}
void loop(){
  delay(8000);
  if(digitalRead(sen)==HIGH){ //If smoke deteced then...
    digitalWrite(led, HIGH);
    Serial.println("Smoke Detected, Sending Mail");  // Printing On Serial Monitor 
    delay(1000);


//////////////////////////////////////////////////////////////////////////
    
    Serial.println();
  Serial.print("Connecting...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  smtp.debug(1);


  ESP_Mail_Session session;


  session.server.host_name = SMTP_server ;
  session.server.port = SMTP_Port;
  session.login.email = sender_email;
  session.login.password = sender_password;
  session.login.user_domain = "";

  /* Declare the message class */
  SMTP_Message message;


  message.sender.name = "ESP01";
  message.sender.email = sender_email;
  message.subject = "SMOKE DETECTED";
  message.addRecipient("Mini Project Team",Recipient_email);

   //Send HTML message
  String htmlMsg = "<div style=\"color:#0000FF;\">Z<h1>CAUTION SMOKE/GAS LEAKEAGE DETECTED BEYOND SAFE DURATION</h1><p>This is the minor project demonstration by Batch-6 ECE-IDP</p></div>";
  message.html.content = htmlMsg.c_str();
  message.html.content = htmlMsg.c_str();
  message.text.charSet = "us-ascii";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit; 


  if (!smtp.connect(&session))
    return;


  if (!MailClient.sendMail(&smtp, &message))
    Serial.println("Error sending Email, " + smtp.errorReason());
 
}
  else{ // When no smoke has been detected by the ESP01
    digitalWrite(led, LOW);
    Serial.println("No Smoke Detected");
    delay(1000);
  }

}
