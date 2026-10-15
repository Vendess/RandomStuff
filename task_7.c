#include <superkarel.h>

void turn_right();
void fill_hall();//fill beepers 
void pass_room();
int main(){
    turn_on("task_7.kw");
    set_step_delay(100);
    fill_hall();
    while(1){
        pass_room();



        if(front_is_blocked() && right_is_blocked() && facing_east()){
            
            turn_left();
            turn_left();
            
           while(front_is_clear()){
               step();                            
           }
           turn_left();
           turn_left();
           while(1){
               pass_room();
               if(front_is_blocked() && right_is_blocked() && facing_east()){
                turn_left();
                turn_left();
                while(front_is_clear()){
                    while(beepers_present()){
                        pick_beeper();
                        
                    }
                    step();
                }
                if(beepers_present()){
                    pick_beeper();
                }
                
                turn_left();
                turn_left();

                while(front_is_clear()){
                    step();
                }
                if(beepers_present()){
                    pick_beeper();
                } 
                turn_off();

               }
               
           }
           

        }
    }

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
void fill_hall(){
    while(front_is_clear()){
        put_beeper();
        step();
    }
    if(front_is_blocked() && no_beepers_present()){
        put_beeper();
    }
    turn_left();
    turn_left();
    while(front_is_clear()){
        step();
    }
    if(front_is_blocked() && no_beepers_present()){
        put_beeper();
    }

    while(!facing_east()){
        turn_left();
    }

}
void pass_room(){
    
    if(left_is_clear()){
        turn_left();
        step();
        if(no_beepers_present()){
            put_beeper();
        }else{
            turn_left();
            turn_left();
            step();
            turn_left();
            if(front_is_clear()){
                step();
            }
            return;
        }
        
        step();
        while(no_beepers_present()){
            if(right_is_blocked() && front_is_clear() && no_beepers_present()){
                step();
            }
            if(front_is_blocked() && right_is_blocked() && no_beepers_present()){
                turn_left();
            }
            if(front_is_clear() && right_is_clear() && no_beepers_present()){
                turn_right();
                step();
            }
            if(front_is_blocked() && right_is_clear() && no_beepers_present()){
                turn_right();
                step();
            }
            if(front_is_blocked() && right_is_blocked() && left_is_blocked() && no_beepers_present()){
                turn_left();
                turn_left();
            }
            if(beepers_present()){
                break;
            }
        }
        if(front_is_blocked()){
            turn_left();
            turn_left();
            step();
            put_beeper();
            turn_left();
            turn_left();
            step();
            turn_left();
            if(front_is_blocked()){
                return;
            }else{step();}

        }else{
            pick_beeper();
            step();
            turn_left();
            if(front_is_blocked()){
                return;
            }else{step();}
        }
    

    }else{
        while(left_is_blocked()){
            step();

        }
        
    }    
}
