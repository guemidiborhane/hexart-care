// Copyright John Main
#include <Wire.h>
#include "cardio.c"

#define sensorPin A0

#define MEASURE_TIME 1000
#define NOISE_THRESHOLD 3
#define recordTime 10
#define DLY_IGNORE 130
#define PSEP Serial.print(" ")

int period = 0, cline = 0;
int num_peaks,max_peak,avg_peak;
unsigned long time_was,ctimer;
unsigned long peak_time;
unsigned long raw_tot,raw_num;
unsigned long threshold;
hearbeat *hb = NULL;



void setup() {
  Serial.begin(9600);
  tone(11,1000,50);
  tone(11,500,150);
  peak_time = time_was = millis();
  num_peaks = 0;

  threshold = 0;
  raw_tot = raw_num = 0;
  ctimer = millis();

  hb = (struct hearbeat *)malloc(sizeof(struct hearbeat));
  startCapture(hb, millis(), recordTime);
}

void loop() {
   static int up=1;
   unsigned long ms;
   int period=0;
   int avg = 0; // temp var.
   int rawValue = analogRead (sensorPin);

   if(hb == NULL){exit(1);}

   raw_tot += rawValue;
   raw_num++;
   avg = raw_tot/raw_num;

   // Decay max peak to allow change to lower peak values.
   // debug plot (millis()-peak_time) - not algo. shows delay on plot = straight line.
   if ( (millis()-peak_time)>DLY_IGNORE ) max_peak--;

   // Capture max peak.
   if (rawValue>max_peak  ) max_peak = rawValue;

   // Set the threshold 1/8th below the max peak.
   threshold = (max_peak-(max_peak>>4));

   delay(15);

   // Value must be > minimum,
   // and bigger than a fraction below the max measured peak,
   // and not found within x ms of the last peak (100ms :max 300bpm).
   //
   
    if (up==1 && rawValue-avg > NOISE_THRESHOLD) {
      ms = millis();
      peak_time = ms;
      up = 0;

      // Check n second timeout after a peak
      period = (ms-time_was);

      
     num_peaks++;
     // Since this is not an interrupt driven timer, nominal n sec period will be larger than 5000 ms.
     // so work out beats in period for 1min
     hb->period = period;
     hb->beats = num_peaks;
     stopCapture(hb);
     Serial.println(hb->bpm);


   } else if (up==0 && rawValue<threshold)  up = 1;
}
