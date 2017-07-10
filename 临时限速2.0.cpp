static int* flag_safe = 0;
static int* flag_effcient = 0;
static int* manual_control_flag = 0;//手动控制策略信号
static int* use_safe_opt_flag = 0;
static int* use_effcient_opt_flag = 0;

if(flag_safe == 0 && flag_effcient == 0 && 距离临时限速起点A <= 某个值){
  //调节为手动控制
  manual_control_flag = 1;
}else if(flag_safe == 0 && flag_effcient == 0 && 距离临时限速起点A > 某个值)
{
  //调用tmp_safe_opt线程进行计算
  //得到返回结果
}

if(flag_safe == 1 && flag_effcient == 0 && 距离安全策略临时限速曲线与原优化曲线交点C1 > 某个值){
  //调用tmp_efficient_opt线程进行计算
  //得到返回结果
}else if(flag_safe == 1 && flag_effcient == 0 && 距离安全策略临时限速曲线与原优化曲线交点C1 <= 某个值){
  //走安全策略曲线flag = 1
  use_safe_opt_flag = 1;
}

if(flag_safe==1 && flag_effcient==1 && 距离节能策略临时限速曲线与原优化曲线交点C2 >= 0){
  //走节能策略曲线flag = 1
  use_effcient_opt_flag = 1;
}else if(flag_safe==1 && flag_effcient==1 && 距离节能策略临时限速曲线与原优化曲线交点C2 < 0){
  //走安全策略曲线flag = 1
  use_safe_opt_flag = 1;
}

if(manual_control_flag == 1){
  //手动控制
}else if(use_safe_opt_flag == 1 && 当前index大于C1点index 小于D点index){
  //安全策略
}else if(use_effcient_opt_flag == 1 && 当前index大于C2点index 小于D点index){
  //节能策略
}else{
  //走原优化曲线
}
