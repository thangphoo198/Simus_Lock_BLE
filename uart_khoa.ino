
void uart_khoa()
{
  if (Serial.available() > 0)
  {
    String cmd = "";
    delay(10);
    while (Serial.available() > 0)
    {
      cmd = Serial.readString();
      delay(1);
    }
    if (cmd.length() > 2)
    {
      Serial.print("UART2=>: ");
      Serial.println(cmd);
      //String RSP_khoa = xuly_json_khoa(cmd);
//      if (RSP_khoa.indexOf("EVENT") != -1)
//      {
//        JsonObject &root = jsonBuffer.parseObject(cmd);
//        root["SERIAL"] = chip_ID;
//        String output;
//        root.printTo(output);
//        client.publish(topic_event, output.c_str());   
//      }
      
//
//      if (cmd.indexOf(CMD_STT) != -1)
//      {
//        if (WiFi.status() != WL_CONNECTED)
//        {
//          Serial.println("Da gui MODE BLE cho khoa");
//          Serial.print(STT_BLE);
//        }
//        else
//        {
//          Serial.println("Da gui MODE WIfi +MQTT cho khoa");
//          Serial.print(STT_WIFI);
//          delay(200);
//          Serial.print(RSP_MQTT);
//        }
//        // client.publish(topic_rec.c_str(),RSP_OK);
//      }

 if (cmd.indexOf(CMD_REQUEST) != -1)
      {
        Serial.print(RSP_OK);
     //   client.publish(topic_rec.c_str(), CMD_REQUEST);
        // bleTask();
        // gửi yêu cầu nên app
      }
//      else if (cmd.indexOf(CMD_CONNECT_INFO) != -1)
//      {
//        Serial.print(out_connect_json().c_str());
//        client.publish(topic_rec.c_str(), out_connect_json().c_str());
//        // bleTask();
//        // gửi yêu cầu nên app
//      }

      else if (cmd.indexOf(APP_ISONLINE) != -1)
      {
        // Serial.print(APP_ONLINE);
//        client.publish(topic_rec.c_str(), APP_ISONLINE);
      }

      //     if(cmd.length()>2) {client.publish(topic_rec.c_str(),cmd.c_str());}
//      if (deviceConnected)
//      {
//        Serial.println("gui len app qua BLE");
//        App_Notify_Char.setValue(cmd.c_str());
//        App_Notify_Char.notify();
//        // data_BLE="";
//      }
    }
  }
}
