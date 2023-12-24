void pathTrigCheck(){

if(final_run_var == 0){
  int temp_led_state ;
  if(led[0]<=50&&led[1]<=50&&led[2]<=50&&led[3]<=50&&led[4]<=50){
    temp_led_state = 0;
    }
  else{temp_led_state = 1;}
  if(led_path_left==1||led_path_right==1||(led_path_left==0&&led_path_front==0&&led_path_center==0&&led_path_right==0&&temp_led_state==0)){ //to cover all path trigger cases
      if(led_path_left==0&&led_path_front==0&&led_path_center==0&&led_path_right==0&&temp_led_state==0){
        digitalWrite(led_pin,HIGH);
      }
      delay(del_point);
      // ledPathTrigCheck(); //add this function
    if(algo_toggle_var == 0 )
      {
        LSRB();
      }
    if(algo_toggle_var == 1 )
      {
        RSLB();
      }
  }
}

if (final_run_var == 1){    //point is made 0 at final_run_var=1;

  int temp_led_state ;
  if(led[0]<=50&&led[1]<=50&&led[2]<=50&&led[3]<=50&&led[4]<=50){
    temp_led_state = 0;
    }
  else{temp_led_state = 1;}
  if(led_path_left==1||led_path_right==1||(led_path_left==0&&led_path_front==0&&led_path_center==0&&led_path_right==0&&temp_led_state==0)){ //to cover all path trigger cases
      delay(del_point);
    
      
           if(way[point]=='L'){
      left();point++;
    }
    if(way[point]=='R'){
      right();point++;
    }
    if(way[point]=='S'){
      straight();point++;
    }
    if(way[point]=='B'){
      back();point++;
    }
    checkEndLeft();
      
    
  }




    // if(way[point]=='L'){
    //   left();point++;
    // }
    // if(way[point]=='R'){
    //   right();point++;
    // }
    // if(way[point]=='S'){
    //   straight();point++;
    // }
    // if(way[point]=='B'){
    //   back();point++;
    // }
    // checkEndLeft();

}
}

void LSRB(){
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
    path = 'B';back();way[point] = 'B'; point++;digitalWrite(led_pin,LOW);
    }
    // if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){delay(3000 );
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){//digitalWrite(led_pin,HIGH);
    path = 'R';right();way[point] = 'R'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
    path = 'S';straight();way[point] = 'S'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){//digitalWrite(led_pin,HIGH);
    path = 'Q';straight();way[point] = 'S'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
    path = 'L';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){//digitalWrite(led_pin,HIGH);
    path = 'T';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
    path = 'P';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(led_pin,LOW);    //check end left
    checkEndLeft();
    }
    LSRBalgo();
}
// void LSRBfinal(){
//     if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
//     path = 'B';back();way[point] = 'B'; point++;digitalWrite(led_pin,LOW);
//     }
//     // if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){delay(3000 );
//     if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){//digitalWrite(led_pin,HIGH);
//     path = 'R';right();way[point] = 'R'; point++;digitalWrite(led_pin,LOW);
//     }
//     if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
//     path = 'S';straight();way[point] = 'S'; point++;digitalWrite(led_pin,LOW);
//     }
//     if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){//digitalWrite(led_pin,HIGH);
//     path = 'Q';straight();way[point] = 'S'; point++;digitalWrite(led_pin,LOW);
//     }
//     if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
//     path = 'L';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
//     }
//     if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){//digitalWrite(led_pin,HIGH);
//     path = 'T';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
//     }
//     if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){//digitalWrite(led_pin,HIGH);
//     path = 'P';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
//     }
//     if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(led_pin,HIGH);    //check end left
//     checkEndLeft();
//     }
// }
void RSLB(){
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 0 ){digitalWrite(led_pin,HIGH);
    path = 'B';back();way[point] = 'B'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 0 && led_path_front == 0 && led_path_right == 1 ){digitalWrite(led_pin,HIGH);
    path = 'R';right();way[point] = 'R'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 0 ){digitalWrite(led_pin,HIGH);
    path = 'S';straight();way[point] = 'S'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 0 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(led_pin,HIGH);
    path = 'Q';right();way[point] = 'R'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 0 ){digitalWrite(led_pin,HIGH);
    path = 'L';left();way[point] = 'L'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 0 && led_path_right == 1 ){digitalWrite(led_pin,HIGH);
    path = 'T';right();way[point] = 'R'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 0 ){digitalWrite(led_pin,HIGH);
    path = 'P';straight();way[point] = 'S'; point++;digitalWrite(led_pin,LOW);
    }
    if(led_path_left == 1 && led_path_front == 1 && led_path_right == 1 ){digitalWrite(led_pin,LOW);    //check end right
    checkEndRight();
    }
    RSLBalgo();
}

void LSRBalgo(){
  for(int i = 0; i <= point + 5; i++){

    if(way[i] == 'B'){

       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'B';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'R';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'B';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'R';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'B';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'S';point--;point--;way[i]='N';way[i+1]='N';
       }
    }

  }
}

void RSLBalgo(){
  for(int i = 0; i <= point + 5; i++){

    if(way[i] == 'B'){

       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='L'){
          way[i-1] = 'B';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'L';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='L'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'B';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'L';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='S'&&way[i]=='B'&&way[i+1]=='S'){
          way[i-1] = 'B';point--;point--;way[i]='N';way[i+1]='N';
       }
       if(way[i-1]=='R'&&way[i]=='B'&&way[i+1]=='R'){
          way[i-1] = 'S';point--;point--;way[i]='N';way[i+1]='N';
       }
    }

  }
}