#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS, 10, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500
int i = 0;
int j = 0;
int h = 0;
int k = 0;
int z = 0;
int u = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int pickNumber = 0;
int randNumber = 0;
int lose = 0;
volatile int game = 1;
volatile int ledcolor = 0;
volatile int buttonRead = 0;
volatile int level = 1;
volatile int f = 1;
long last_micros = 0;
void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
  pixels5.begin();
  pixels.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
  pixels.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();
  attachInterrupt (0, blueButton, RISING);
  attachInterrupt (2, redButton, FALLING);
  attachInterrupt (3, greenButton, FALLING);
  attachInterrupt (4, yellowButton, RISING);
  attachInterrupt (5, whiteButton, RISING);
  Serial.begin (9600);
}

void loop() {
  pixels.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
  pixels.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();

  while (game == 1) {
    pixels.clear();
    pixels2.clear();
    pixels3.clear();
    pixels4.clear();
    pixels5.clear();
    Serial.println ("game =");
    Serial.println (game);
    delay(500);
    randNumber = random (1, 5);
    Serial.println (randNumber);
    delay (500);

    if ((randNumber == 1) && (buttonRead == 1)) {
      pixels.clear();
      pixels2.clear();
      pixels3.clear();
      pixels4.clear();
      pixels5.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 50));
      pixels.setPixelColor(1, pixels.Color(0, 0, 50));
      pixels2.setPixelColor(0, pixels.Color(0, 0, 50));
      pixels2.setPixelColor(1, pixels.Color(0, 0, 50));
      pixels3.setPixelColor(0, pixels.Color(0, 0, 50));
      pixels3.setPixelColor(1, pixels.Color(0, 0, 50));
      pixels4.setPixelColor(0, pixels.Color(0, 0, 50));
      pixels4.setPixelColor(1, pixels.Color(0, 0, 50));
      pixels5.setPixelColor(0, pixels.Color(0, 0, 50));
      pixels5.setPixelColor(1, pixels.Color(0, 0, 50));
      pixels.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
      pixels5.show();
      ledcolor = 1;
      buttonRead = 0;
    }

    if ((randNumber == 2) && (buttonRead == 1)) {
      pixels.clear();
      pixels2.clear();
      pixels3.clear();
      pixels4.clear();
      pixels5.clear();
      pixels.setPixelColor(2, pixels.Color(50, 0, 0));
      pixels.setPixelColor(3, pixels.Color(50, 0, 0));
      pixels2.setPixelColor(2, pixels.Color(50, 0, 0));
      pixels2.setPixelColor(3, pixels.Color(50, 0, 0));
      pixels3.setPixelColor(2, pixels.Color(50, 0, 0));
      pixels3.setPixelColor(3, pixels.Color(50, 0, 0));
      pixels4.setPixelColor(2, pixels.Color(50, 0, 0));
      pixels4.setPixelColor(3, pixels.Color(50, 0, 0));
      pixels5.setPixelColor(2, pixels.Color(50, 0, 0));
      pixels5.setPixelColor(3, pixels.Color(50, 0, 0));
      pixels.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
      pixels5.show();
      ledcolor = 2;
      buttonRead = 0;
    }

    if ((randNumber == 3) && (buttonRead == 1)) {
      pixels.clear();
      pixels2.clear();
      pixels3.clear();
      pixels4.clear();
      pixels5.clear();
      pixels.setPixelColor(4, pixels.Color(0, 50, 0));
      pixels.setPixelColor(5, pixels.Color(0, 50, 0));
      pixels2.setPixelColor(4, pixels.Color(0, 50, 0));
      pixels2.setPixelColor(5, pixels.Color(0, 50, 0));
      pixels3.setPixelColor(4, pixels.Color(0, 50, 0));
      pixels3.setPixelColor(5, pixels.Color(0, 50, 0));
      pixels4.setPixelColor(4, pixels.Color(0, 50, 0));
      pixels4.setPixelColor(5, pixels.Color(0, 50, 0));
      pixels5.setPixelColor(4, pixels.Color(0, 50, 0));
      pixels5.setPixelColor(5, pixels.Color(0, 50, 0));
      pixels.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
      pixels5.show();
      ledcolor = 3;
      buttonRead = 0;
    }

    if ((randNumber == 4) && (buttonRead == 1)) {
      pixels.clear();
      pixels2.clear();
      pixels3.clear();
      pixels4.clear();
      pixels5.clear();
      pixels.setPixelColor(6, pixels.Color(100, 50, 0));
      pixels.setPixelColor(7, pixels.Color(100, 50, 0));
      pixels2.setPixelColor(6, pixels.Color(100, 50, 0));
      pixels2.setPixelColor(7, pixels.Color(100, 50, 0));
      pixels3.setPixelColor(6, pixels.Color(100, 50, 0));
      pixels3.setPixelColor(7, pixels.Color(100, 50, 0));
      pixels4.setPixelColor(6, pixels.Color(100, 50, 0));
      pixels4.setPixelColor(7, pixels.Color(100, 50, 0));
      pixels5.setPixelColor(6, pixels.Color(100, 50, 0));
      pixels5.setPixelColor(7, pixels.Color(100, 50, 0));
      pixels.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
      pixels5.show();
      ledcolor = 4;
      buttonRead = 0;
    }
  }
  pixels.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
  pixels.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();

  while (game == 2) {
    Serial.println ("game =");
    Serial.println (game);
    delay (500);
    while ((level == 1) && (game == 2)) { //checks to see if the button has been pressed
      for ( i = 0; i <= 6; i++) {//sets up i as a variable that starts at 0 and goes up to 6
        if ((pickNumber == 0) && (game == 2)) {
          randomSeed(analogRead(0));
          randNumber = random (1, 5);
          delay (500);
          pickNumber = 1;
          Serial.println (randNumber);
        }
        if ((randNumber == 1) && (game == 2)) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
          pixels.show();
          ledcolor = 2;
          Serial.println (ledcolor);
        }
        else if ((randNumber == 2) && (game == 2)) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
          pixels.show();
          ledcolor = 3;
          Serial.println (ledcolor);
        }
        else if ((randNumber == 3) && (game == 2)) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
          pixels.show();
          ledcolor = 1;
          Serial.println (ledcolor);
        }
        else if ((randNumber == 4) && (game == 2)) {
          pixels.clear();
          pixels.setPixelColor(i, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
          pixels.show();
          ledcolor = 4;
          Serial.println (ledcolor);
        }

        delay(DELAYVAL);
        if (f == 2) //if the button is pressed
        {
          delay(1000);
          Serial.println ("breaking out of the while loop");
          break;

        }


      }
      if ((f == 1) && (game == 2)) {
        for (j = 7; j >= 1; j--) {
          if ((randNumber == 1) && (game == 2)) {
            pixels.clear();
            pixels.setPixelColor(j, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
            pixels.show();
            ledcolor = 2;
            Serial.println (ledcolor);
          }
          else if ((randNumber == 2) && (game == 2)) {
            pixels.clear();
            pixels.setPixelColor(j, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
            pixels.show();
            ledcolor = 3;
            Serial.println (ledcolor);
          }
          else if ((randNumber == 3) && (game == 2)) {
            pixels.clear();
            pixels.setPixelColor(j, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
            pixels.show();
            ledcolor = 1;
            Serial.println (ledcolor);
          }
          else if ((randNumber == 4) && (game == 2)) {
            pixels.clear();
            pixels.setPixelColor(j, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
            pixels.show();
            ledcolor = 4;
            Serial.println (ledcolor);
          }
          delay(DELAYVAL);
          if (f == 2)
          {
            delay(1000);
            Serial.println ("breaking out of the while loop");
            break;


          }

        }
      }
    }
    pixels2.clear();
    pixels2.show();
    f = 1;
    pickNumber == 0;
    while ((level == 2) && ( f == 1) && (lose == 0) && (game == 2)) {
      for (h = 0; h <= 6; h++) {
        if ((pickNumber == 0) && (game == 2)) {
          randomSeed(analogRead(0));
          randNumber = random (1, 5);
          delay (500);
          pickNumber = 1;
        }
        if ((randNumber == 1) && (game == 2)) {
          pixels2.clear();
          pixels2.setPixelColor(h, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
          pixels2.show();
          ledcolor = 2;
        }
        else if ((randNumber == 2) && (game == 2)) {
          pixels2.clear();
          pixels2.setPixelColor(h, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
          pixels2.show();
          ledcolor = 3;
        }
        else if ((randNumber == 3) && (game == 2)) {
          pixels2.clear();
          pixels2.setPixelColor(h, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
          pixels2.show();
          ledcolor = 1;
        }
        else if ((randNumber == 4) && (game == 2)) {
          pixels2.clear();
          pixels2.setPixelColor(h, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
          pixels2.show();
          ledcolor = 4;
        }

        delay(DELAYVAL);
        if ((f == 2) && (game == 2))
        { delay(1000);
          Serial.println("i is ");
          Serial.println(i);
          Serial.println("j is ");
          Serial.println(j);
          Serial.println("H is ");
          Serial.println(h);
          Serial.println("K is ");
          Serial.println(k);
          if ((h != i) || (k != j))
          { endgame();

          }

          h = 7;
        }




      }
      if ((f == 1) && (lose == 0) && (game == 2)) {
        for (k = 7; k >= 1; k--) {
          if ((randNumber == 1) && (game == 2)) {
            pixels2.clear();
            pixels2.setPixelColor(k, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
            pixels2.show();
            ledcolor = 2;
          }
          else if ((randNumber == 2) && (game == 2)) {
            pixels2.clear();
            pixels2.setPixelColor(k, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
            pixels2.show();
            ledcolor = 3;
          }
          else if ((randNumber == 3) && (game == 2)) {
            pixels2.clear();
            pixels2.setPixelColor(k, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
            pixels2.show();
            ledcolor = 1;
          }
          else if ((randNumber == 4) && (game == 2)) {
            pixels2.clear();
            pixels2.setPixelColor(k, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
            pixels2.show();
            ledcolor = 4;
          }

          delay(DELAYVAL);
          if ((f == 2) && (game == 2))
          { delay(1000);
            Serial.println("i is ");
            Serial.println(i);
            Serial.println("j is ");
            Serial.println(j);
            Serial.println("H is ");
            Serial.println(h);
            Serial.println("K is ");
            Serial.println(k);
            if ((h != i) || (k != j))
            { endgame();
            }

            k = 0;

          }
        }
      }
    }
    f = 1;
    pickNumber = 0;
    while ((level == 3) && ( f == 1) && (lose == 0) && (game == 2)) {
      for (z = 0; z <= 6; z++) {
        if ((pickNumber == 0) && (game == 2)) {
          randomSeed(analogRead(0));
          randNumber = random (1, 5);
          delay (500);
          pickNumber = 1;
        }
        if ((randNumber == 1) && (game == 2)) {
          pixels3.clear();
          pixels3.setPixelColor(z, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
          pixels3.show();
          ledcolor = 2;
        }
        else if ((randNumber == 2) && (game == 2)) {
          pixels3.clear();
          pixels3.setPixelColor(z, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
          pixels3.show();
          ledcolor = 3;
        }
        else if ((randNumber == 3) && (game == 2)) {
          pixels3.clear();
          pixels3.setPixelColor(z, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
          pixels3.show();
          ledcolor = 1;
        }
        else if ((randNumber == 4) && (game == 2)) {
          pixels3.clear();
          pixels3.setPixelColor(z, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
          pixels3.show();
          ledcolor = 4;
        }

        delay(DELAYVAL);
        if ((f == 2) && (game == 2))
        { delay(1000);
          Serial.println("i is ");
          Serial.println(i);
          Serial.println("j is ");
          Serial.println(j);
          Serial.println("z is ");
          Serial.println(z);
          Serial.println("u is ");
          Serial.println(u);
          if ((z != i) || (u != j))
          { endgame();
          }

          z = 7;

        }


      }
      if ((f == 1) && (lose == 0) && (game == 2)) {
        for (u = 7; u >= 1; u--) {

          if ((randNumber == 1) && (game == 2)) {
            pixels3.clear();
            pixels3.setPixelColor(u, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
            pixels3.show();
            ledcolor = 2;
          }
          else if ((randNumber == 2) && (game == 2)) {
            pixels3.clear();
            pixels3.setPixelColor(u, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
            pixels3.show();
            ledcolor = 3;
          }
          else if ((randNumber == 3) && (game == 2)) {
            pixels3.clear();
            pixels3.setPixelColor(u, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
            pixels3.show();
            ledcolor = 1;
          }
          else if ((randNumber == 4) && (game == 2)) {
            pixels3.clear();
            pixels3.setPixelColor(u, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
            pixels3.show();
            ledcolor = 4;
          }

          delay(DELAYVAL);
          if ((f == 2) && (game == 2))
          { delay(1000);
            Serial.println("i is ");
            Serial.println(i);
            Serial.println("j is ");
            Serial.println(j);
            Serial.println("z is ");
            Serial.println(z);
            Serial.println("u is ");
            Serial.println(u);
            if ((z != i) || (u != j))
            { endgame();
            }

            u = 0;

          }
        }
      }
    }
    f = 1;
    pickNumber = 0;
    while ((level == 4) && ( f == 1) && (lose == 0) && (game == 2)) {
      for (a = 0; a <= 6; a++) {
        if ((pickNumber == 0) && (game == 2)) {
          randomSeed(analogRead(0));
          randNumber = random (1, 5);
          delay (500);
          pickNumber = 1;
        }
        if ((randNumber == 1) && (game == 2)) {
          pixels4.clear();
          pixels4.setPixelColor(a, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
          pixels4.show();
          ledcolor = 2;
        }
        else if ((randNumber == 2) && (game == 2)) {
          pixels4.clear();
          pixels4.setPixelColor(a, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
          pixels4.show();
          ledcolor = 3;
        }
        else if ((randNumber == 3) && (game == 2)) {
          pixels4.clear();
          pixels4.setPixelColor(a, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
          pixels4.show();
          ledcolor = 1;
        }
        else if ((randNumber == 4) && (game == 2)) {
          pixels4.clear();
          pixels4.setPixelColor(a, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
          pixels4.show();
          ledcolor = 4;
        }

        delay(DELAYVAL);
        if ((f == 2) && (game == 2))
        { delay(1000);
          Serial.println("i is ");
          Serial.println(i);
          Serial.println("j is ");
          Serial.println(j);
          Serial.println("a is ");
          Serial.println(a);
          Serial.println("b is ");
          Serial.println(b);
          if ((a != i) || (b != j))
          { endgame();
          }

          a = 7;

        }


      }
      if ((f == 1) && (lose == 0) && (game == 2)) {
        for (b = 7; b >= 1; b--) {
          if ((randNumber == 1) && (game == 2)) {
            pixels4.clear();
            pixels4.setPixelColor(b, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
            pixels4.show();
            ledcolor = 2;
          }
          else if ((randNumber == 2) && (game == 2)) {
            pixels4.clear();
            pixels4.setPixelColor(b, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
            pixels4.show();
            ledcolor = 3;
          }
          else if ((randNumber == 3) && (game == 2)) {
            pixels4.clear();
            pixels4.setPixelColor(b, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
            pixels4.show();
            ledcolor = 1;
          }
          else if ((randNumber == 4) && (game == 2)) {
            pixels4.clear();
            pixels4.setPixelColor(b, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
            pixels4.show();
            ledcolor = 4;
          }

          delay(DELAYVAL);
          if ((f == 2) && (game == 2))
          { delay(1000);
            Serial.println("i is ");
            Serial.println(i);
            Serial.println("j is ");
            Serial.println(j);
            Serial.println("a is ");
            Serial.println(a);
            Serial.println("b is ");
            Serial.println(b);
            if ((a != i) || (b != j))
            { endgame();
            }

            b = 0;

          }
        }
      }
    }
    f = 1;
    pickNumber = 0;
    while ((level == 5) && (f == 1) && (lose == 0) && (game == 2)) {
      for (c = 0; c <= 6; c++) {
        if ((pickNumber == 0) && (game == 2)) {
          randomSeed(analogRead(0));
          randNumber = random (1, 5);
          delay (500);
          pickNumber = 1;
        }
        if ((randNumber == 1) && (game == 2)) {
          pixels5.clear();
          pixels5.setPixelColor(c, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
          pixels5.show();
          ledcolor = 2;
        }
        else if ((randNumber == 2) && (game == 2)) {
          pixels5.clear();
          pixels5.setPixelColor(c, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
          pixels5.show();
          ledcolor = 3;
        }
        else if ((randNumber == 3) && (game == 2)) {
          pixels5.clear();
          pixels5.setPixelColor(c, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
          pixels5.show();
          ledcolor = 1;
        }
        else if ((randNumber == 4) && (game == 2)) {
          pixels5.clear();
          pixels5.setPixelColor(c, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
          pixels5.show();
          ledcolor = 4;
        }

        delay(DELAYVAL);
        if ((f == 2) && (game == 2))
        { delay(1000);
          Serial.println("i is ");
          Serial.println(i);
          Serial.println("j is ");
          Serial.println(j);
          Serial.println("c is ");
          Serial.println(c);
          Serial.println("d is ");
          Serial.println(d);
          if ((c != i) || (d != j))
          { endgame();
            c = 5;
          }
          if (((c == i) || (d == j) && (lose == 0)))
          {
            wingame();
            c = 7;
          }
        }


      }
      if ((f == 1) && (lose == 0) && (game == 2)) {
        for (d = 7; d >= 1; d--) {
          if ((randNumber == 1) && (game == 2)) {
            pixels5.clear();
            pixels5.setPixelColor(d, pixels.Color(50, 0, 0)); //makes a red light go up to the 6th pixel, corresponding to i
            pixels5.show();
            ledcolor = 2;
          }
          else if ((randNumber == 2) && (game == 2)) {
            pixels5.clear();
            pixels5.setPixelColor(d, pixels.Color(0, 50, 0)); //makes a green light go up to the 6th pixel, corresponding to i
            pixels5.show();
            ledcolor = 3;
          }
          else if ((randNumber == 3) && (game == 2)) {
            pixels5.clear();
            pixels5.setPixelColor(d, pixels.Color(0, 0, 50)); //makes a blue light go up to the 6th pixel, corresponding to i
            pixels5.show();
            ledcolor = 1;
          }
          else if ((randNumber == 4) && (game == 2)) {
            pixels5.clear();
            pixels5.setPixelColor(d, pixels.Color(100, 50, 0)); //makes a yellow light go up to the 6th pixel, corresponding to i
            pixels5.show();
            ledcolor = 4;
          }

          delay(DELAYVAL);
          if ((f == 2) && (game == 2))
          { delay(1000);
            Serial.println("i is ");
            Serial.println(i);
            Serial.println("j is ");
            Serial.println(j);
            Serial.println("c is ");
            Serial.println(c);
            Serial.println("d is ");
            Serial.println(d);
            if ((c != i) || (d != j))
            {
              endgame();
              d = 0;
            }
            if (((c == i) || (d == j) && (lose == 0)))
            {
              wingame();
              d = 0;
            }
          }
        }
      }
    }
  }
}

void blueButton() {
  if (((micros() - last_micros) >= 250000) && (ledcolor == 1))

  {
    if (game == 1) {
      buttonRead = 1;

    }
    else {
      f = 2;
      level++;
    }
    last_micros = micros ();
  }
}

void redButton() {
  if (((micros() - last_micros) >= 25000) && (ledcolor == 2))

  {
    if (game == 1)
    {
      buttonRead = 1;
    }
    else {
      f = 2;
      level++;
    }
    last_micros = micros ();
  }
}

void greenButton() {
  if (((micros() - last_micros) >= 25000) && (ledcolor == 3))

  {
    if (game == 1)
    {
      buttonRead = 1;
    }
    else {
      f = 2;
      level++;
    }
    last_micros = micros ();
  }
}

void yellowButton() {
  if (((micros() - last_micros) >= 25000) && (ledcolor == 4))

  {
    if (game == 1)
    {
      buttonRead = 1;
    }
    else {
      f = 2;
      level++;
    }
    last_micros = micros ();
  }
}

void whiteButton() {
  if ((micros() - last_micros) >= 25000)

  {

    if (game == 1) {
      game = 2;
    }
    else {
      game = 1;
    }
    last_micros = micros ();
  }
}

void endgame() {

  lose = 1;
  Serial.println ("You lose!");
  return;

}

void wingame() {

  Serial.println ("You win! Congrats");
  return;
}
