//#pragma once
//#include <iostream>
//#include <string>
//#include "myform.h"
//#include "myform1.h"
//using namespace std;
//namespace project2 {
//    // poketmon 클래스 정의
//    public class poketmon1
//    {
//        // 포켓몬의 멤버 변수
//    private:
//        string image_name;  // 포켓몬의 이미지 파일 이름
//        string poketmon_name;   // 포켓몬 이름
//        string type;    // 포켓몬의 타입
//        double full_hp; // 포켓몬의 최대 hp
//        double hp;  // 포켓몬의 현재 hp
//        double attack;  // 포켓몬의 공격력
//        double defense; // 포켓몬의 방어력
//        double speed;   // 포켓몬의 속도
//
//    public:
//        //생성자
//        poketmon1(string image_name, string poketmon_name, string type, double full_hp, double hp, double attack, double defense, double speed)
//        {
//            // 멤버 변수 초기화
//            this->image_name = image_name;
//            this->poketmon_name = poketmon_name;
//            this->type = type;
//            this->full_hp = full_hp;
//            this->hp = hp;
//            this->attack = attack;
//            this->defense = defense;
//            this->speed = speed;
//        }
//        //  각 멤버 변수의 값을 반환
//        string getname()
//        {
//            return poketmon_name;
//        }
//        string getimagename()
//        {
//            return image_name;
//        }
//        string gettype()
//        {
//            return type;
//        }
//        double getfullhp()
//        {
//            return full_hp;
//        }
//        double gethp()
//        {
//            return hp;
//        }
//        double getattack()
//        {
//            return attack;
//        }
//        double getdefense()
//        {
//            return defense;
//        }
//        double getspeed()
//        {
//            return speed;
//        }
//
//        //각 멤버 변수의 값을 설정
//        void setname(string poketmon_name)
//        {
//            this->poketmon_name = poketmon_name;
//        }
//        void setimagename(string image_name)
//        {
//            this->image_name = image_name;
//        }
//        void settype(string type)
//        {
//            this->type = type;
//        }
//        void setfullhp(double full_hp)
//        {
//            this->full_hp = full_hp;
//        }
//        void sethp(double hp)
//        {
//            this->hp = hp;
//        }
//        void setattack(double attack)
//        {
//            this->attack = attack;
//        }
//        void setdefense(double defense)
//        {
//            this->defense = defense;
//        }
//        void setspeed(double speed)
//        {
//            this->speed = speed;
//        }
//        //포켓몬의 정보 출력 함수
//        void poketmoninfo() {
//          /*  cout << "이미지 이름: " << image_name << endl;
//            cout << "포켓몬 이름: " << poketmon_name << endl;
//            cout << "타입: " << type << endl;
//            cout << "최대 hp: " << full_hp << endl;
//            cout << "현재 hp: " << hp << endl;
//            cout << "공격력: " << attack << endl;
//            cout << "방어력: " << defense << endl;
//            cout << "속도: " << speed << endl;*/
//        }
//    };
//
//    // 포켓몬 객체 생성 함수
//    poketmon1 createcharmander()
//    {
//        return poketmon1("파이리.webp", "파이리", "불꽃", 39, 39, 52, 43, 65);
//    }
//    poketmon1 createsquirtle()
//    {
//        return poketmon1("꼬부기.webp", "꼬부기", "물", 44, 44, 48, 65, 43);
//    }
//    poketmon1 createbulbasaur()
//    {
//        return poketmon1("이상해씨.webp", "이상해씨", "풀", 45, 45, 49, 49, 45);
//    }
//}
