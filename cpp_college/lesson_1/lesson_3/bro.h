#ifndef Monster_h   
#define Monster_h
#include <string>
class Monster {
    public:
        std::string name="Terror Beast";
        int health=100;
        bool is_alive=1;
        Monster() {
             name = "Unknown";
             health=100;
             is_alive=1;
        }
        Monster(std::string n){
            this->name=name;
            this->health=100;
            this->is_alive=1;
        }
        
        std::string get_name(){
            return name;
        }

        void set_name(std::string n){
            name=n;
        }
        void set_health(int h){
            health=h;
        }
        void set_is_alive(bool alive){
            is_alive=alive;
        }
        int get_health(){
            return health;
        }
        bool get_is_alive(){
            return is_alive;
        }   

        int shield_strike(){
            return 5;
        }
        int basic_attack(){
            return 10;
        }
        
        int sword_attack  (){
            return 15;
        }
        int heavy_attack (){
            return 20;
        }

        int heal (){
            return 10;
        }

};
#endif 