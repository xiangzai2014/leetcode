rt_process.c函数：

分不开

rt_controller.c函数：
//可以将if(local_ctr_flag == 1)语句中对档位的调节以及，对坡段类型对档位的影响情况等这部分抽取出来
void operation_for_gear(float delta_v, float speed_change_pitch, int gear, float flag_reset_threshold, int road_type
, int power_short_flag, int over_speed_flag)){
  //减少档位改变操作
与源代码一样
  //调节档位操作
与源代码一样
}

void judge_brake_gear(int gear, int road_type, int next_type, int crnt_end, int road_len, float rt_velocity, float opt_v,
  int opt_gear, RT_INPUT rt_in, int ahead_opt_gear, int power_short_flag, int over_speed_flag){
//针对坡段为缓下坡及以上的情况，对制动档位判断
与源代码一样
//针对下坡和超陡下坡，减少牵引和制动过程
与源代码一样
}
