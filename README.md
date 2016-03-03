# U.G.M.S
University Games Management System

大学校运会管理系统

An Assignment of Data Structure

# Design

* 易用的界面
* 报名（注册）
* 查询
  * 参赛信息查询
    * 按项目
    * 按个人
    * 按学院
  * 参赛成绩查询
    * 按学院（总排名和总积分）
    * 按个人
* 录入（成绩、运动项目）
* 输出
  * 秩序册（比赛安排表）
  * 成绩排行榜
* 修改（成绩）
* 多用户与用户权限系统

## Structs

* 运动员
  * 姓名
  * 性别
  * 学号
  * 年级
  * 专业
  * 项目名称
  * 项目成绩
    * 实际成绩、名次、积分

* 运动项目
  * 名次
  * 序号（ID）
  * 时间
    * 开始时刻
    * 持续时长
  * 场地
    * 名称
    * ID\* （包含于运动项目序号中）
  * 报名限制条件
    * 人数
    * 性别

# License
[GPLv3](https://github.com/BigPa/U.G.M.S/blob/master/LICENSE)
