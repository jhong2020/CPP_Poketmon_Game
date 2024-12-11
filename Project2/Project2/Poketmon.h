#pragma once
#include "Rule.h"
#include "MyForm.h"
#include "MyForm2.h"
#include "Poketmon.h"
#include <list>
#include <string>
#include <format>
#include <vector>
#include <vcclr.h>
#include "MyForm1.h"
#include <iostream>
using namespace System;
namespace Project2 {
    public ref class Poketmon {
    private:
        String^ Image;
        String^ name;
        String^ type;
        int health;
        int attack;
        int defense;
        int speed;
    public:
        Poketmon(String^imagePath, String^ name, String^ type, int health, int attack, int defense, int speed) {
            Image = imagePath;
            this->name = name;
            this->type = type;
            this->health = health;
            this->attack = attack;
            this->defense = defense;
            this->speed = speed;
        }

        String^ GetImage()
        {
            return Image;
        }
    };
}