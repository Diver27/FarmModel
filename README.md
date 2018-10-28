# FarmModel
设计模式课程项目，农场模型的实现

-----
Animal模块：composite  
		完成其主要框架，实现Strategy----------丁宇轩  
		实现iterator与visitor------------------栗廷杰  
		实现prototype------------------------国明涵  
Plants模块:  
		完成其主要框架，实现Template-------------尹刘轩  
		实现prototype-------------------------国明涵  
		实现iterator与visitor-----------------------栗廷杰  
Alarm模块：  
		完成其主要框架，实现Observer与State----------许昊  
		实现命令系统（Command, Memento）---------------尹刘轩  
Product模块：  
		完成其主要框架，实现Factory-------------刘家煊  
		实现proxy与Flyweight----------------- 毕家瑞  
		实现reference counting-------------------陈浩然  
Farm Master：  
		完成其主要框架，实现Singleton--------------陈浩然  
		




Factory: 生产奶制品，面粉等“产品”  
Prototype：增加某一种动物/某一块作物田的实例（增加一头牛，增加一块稻田）  
Iterator：遍历某一种动物（遍历牛群）  
Observer：分散警报器系统的中央开关  
State：警报器系统拥有不同行为模式  
Command: 通过输入不同命令来选择警报器系统的行为模式  
Memento：与Command结合，记录命令历史并允许撤回  
Strategy：一种牲畜有多种“收获方式”（如奶牛有挤奶，屠宰，直接贩卖等等）；  
Template：不同作物有各自的收割步骤（小麦收割，苹果采摘）  
Visitor：可以动态增加牲畜的“收获”方式（出租给游客，制作标本等等）  
Flyweight：在不同产品上附带相应的产品品牌标签（农场名，出产地，产品品名）  
Reference Counting：为品牌标签设置引用计数  
Singleton：农场主人仅有一名  
Proxy：通过中间商来访问市场并贩卖产品  
