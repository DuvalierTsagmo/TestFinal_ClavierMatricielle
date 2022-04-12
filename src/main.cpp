/*
  Titre      : Clavier Matricielle
  Auteur     : Duvalier Tsagmo
  Date       : 12/04/2022
  Description: controler un servo moteur avec un clavier maticielle
  Version    : 0.0.1
*/

#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>

#define ROWS 4
#define COLS 4

// Declaration des variables

const char kp4x4Keys[ROWS][COLS] = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
byte rowKp4x4Pin[4] = {9, 8, 7, 6};
byte colKp4x4Pin[4] = {5, 4, 3, 2};

Keypad kp4x4 = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);
char boutton;
// fonctions setup
void setup()
{
    Serial.begin(9600);
    Wire.begin();
}

// developpement des fonctions
void loop()
{

    // choix de la LED
    boutton = kp4x4.getKey();

    if (boutton)
    {
        Serial.println(boutton);
        // Envoie de la lettre à l'autre uC
        Wire.beginTransmission(7);
        Wire.write(boutton);
        Wire.endTransmission();
    }
}