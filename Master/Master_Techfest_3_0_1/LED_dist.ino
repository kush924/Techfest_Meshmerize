void ledUpdateAll(){

  ledCheck();               //check led array status    //
  ledMap();                                             //
  ledPathCheck();           //check path led status     //
  ledPathMap();
  cordCalc();               //calculate line coordinate, assigns to pos //

}

void ledUpdateLineLogic(){
  ledshiftLineLogic();
  ledUpdateAll();
  
  if(led_path[0]<=led_path_cutoff){    //white detected (less than cutoff => white)
  led_line_logic[0][0]=1;
  }
  if(led_path[2]<=led_path_cutoff){
  led_line_logic[6][0]=1;
  }
  if(led[0]>=led_cutoff){             //white detected (greater than cutoff => white)
  led_line_logic[1][0]=1;
  }
  if(led[1]>=led_cutoff){             
  led_line_logic[2][0]=1;
  }
  if(led[2]>=led_cutoff){             
  led_line_logic[3][0]=1;
  }
  if(led[3]>=led_cutoff){             
  led_line_logic[4][0]=1;
  }
  if(led[4]>=led_cutoff){             
  led_line_logic[5][0]=1;
  }

}

void ledshiftLineLogic(){
  for(int j=led_arr_len-1;j<=1;j-- ){
    for(int i=0;i<=6;i++){
      led_line_logic[i][j]=led_line_logic[i][j-1];
    }
  }
}

