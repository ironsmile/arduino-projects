#define DEBUG (0)

//  пинове за вход и изход
const int ldr_pin = A0;  // показва на кой пин е свързан сензора
const int piezo_pin = 6;

// променливи, използвани в програмата
int ldr_val = 0;        // съхранява стойността получена от сензора
int piezo_freg = 0;

// calibration vars
int cmin = 1023;
int cmax = 0;

void calibrate () {

    int tmp = 0;

    for (int i=0; i < 100; i++) {
        tmp = analogRead(ldr_pin);
        if (tmp > cmax) {
            cmax = tmp;
        }
        if (tmp < cmin) {
            cmin = tmp;
        }
        delay(10);
    }

}

void setup() {
#if DEBUG
    Serial.begin(9600);
    Serial.print("setup");
#endif

    pinMode(ldr_pin, INPUT);
    pinMode(piezo_pin, OUTPUT);

    calibrate();
}

void loop() {

    ldr_val = analogRead(ldr_pin);

    if (ldr_val < cmin-5) {
        piezo_freg     = map(ldr_val, 0, cmax, 1100, 6830);

#if DEBUG
        Serial.print("Num: ");
        Serial.print(led_brightness);
        Serial.print("\n");
        delay(30);
#endif

        // and now the music!
        digitalWrite(piezo_pin, HIGH);
        delayMicroseconds(piezo_freg / 2);

       // DOWN
       digitalWrite(piezo_pin, LOW);
       delayMicroseconds(piezo_freg / 2);
    }

}
