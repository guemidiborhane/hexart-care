import processing.serial.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
//declare
PrintWriter output;
Serial udSerial;



void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  if (udSerial.available() > 0) {
    String SenVal = udSerial.readString();
    if (SenVal != null) {
      appendInFile(new java.util.Date().getTime() / 1000 + ";" + SenVal);
    }
  }
}
void keyPressed() {
  exit();
}

void appendInFile(String newData){
  BufferedWriter bw = null;
  try {  
    FileWriter fw = new FileWriter(dataPath("../beats.csv"), true);
    bw = new BufferedWriter(fw);
    bw.write(newData + System.getProperty("line.separator"));
  } catch (IOException e) {
  } finally {
    if (bw != null){
      try { 
        bw.close(); 
      } catch (IOException e) {
        System.out.print("error");
      }  
    }
  }
}
